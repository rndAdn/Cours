
(** Machine virtuelle *)

type instr = Push | Consti of int | Addi | Eqi | Andi | Pop | BranchIf of int | Branch of int | Acc of int

let string_of_instr = function
  | Push -> "Push"
  | Consti i -> "Consti " ^ (string_of_int i)
  | Addi -> "Addi"
  | Eqi ->  "Eqi"
  | Andi -> "Andi"
  | Pop ->  "Pop"
  | Branch i -> "Branch " ^ (string_of_int i)
  | BranchIf i -> "BranchIf " ^ (string_of_int i)
  | Acc n       -> "Acc "^ (string_of_int n)


type state = {
  mutable acc: int;
  code: instr array;
  mutable pc: int; (* indice de l’instruction courante dans code *)
  stack: int array;
  mutable sp: int; (* indice du sommet de la pile dans stack *)
}


let print_state s =
  print_string ("Stack:\n");
  (if (s.sp < 0)
   then print_string "<empty>\n"
   else for i = 0 to s.sp do
          print_string ("#" ^ (string_of_int (s.sp - i)) ^ " -> "
                        ^ (string_of_int (s.stack.(i))) ^ "\n")
        done);
  print_string ("Acc = " ^ (string_of_int s.acc) ^ "\n");
  print_string ("PC = " ^ (string_of_int s.pc) ^ "\n\n")


let machine s =
  let idx = ref 0 in
  begin
    while s.pc < Array.length s.code do
      idx := !idx + 1;
      print_string ("=== Step " ^ (string_of_int !idx) ^ " ===\n");
      print_string ("With PC = " ^ (string_of_int s.pc) ^ " (" ^ (string_of_instr (s.code.(s.pc))) ^ ")\n");
      begin match s.code.(s.pc) with
            | Consti n ->
               s.acc <- n
            | Push ->
               s.sp <- s.sp + 1;
               s.stack.(s.sp) <- s.acc
            | Addi ->
               s.acc <- s.stack.(s.sp) + s.acc
            | Andi ->
               s.acc <- s.stack.(s.sp) * s.acc
            | Eqi ->
               s.acc <- if s.stack.(s.sp) = s.acc then 1 else 0
            | Pop ->
               s.sp <- s.sp-1
            | Branch n ->
               s.pc <- s.pc + n - 1
            | BranchIf n ->
               s.pc <- s.pc + (if (s.acc = 0) then n - 1 else 0);
            | Acc n ->
                s.acc <- s.stack.(n)
      end;
      s.pc <- s.pc + 1;
      print_string ("New state is\n");
      print_state s;
    done;
    print_string ("\n" ^ (string_of_int !idx) ^ " steps in total\n\n")
  end; s

let init c =
  { code = c;
    stack = Array.make 1000 42; (* pourquoi 42 ? *)
    pc = 0;
    sp = -1;   (* pourquoi -1 ? *)
    acc = 52 } (* pourquoi 52 ? *)


let get_acc s = s.acc


let assemble (p : instr array) : string =
  let s = String.make (Array.length p) 'z' in
  for i = 0 to Array.length p - 1 do
    s.[i] <- match p.(i) with
    | Push -> Char.chr 0
    | Addi -> Char.chr 1
    | Eqi -> Char.chr 2
    | Andi -> Char.chr 3
    | Consti n -> assert (n < 32); Char.chr (4 + n lsl 3);
    | Pop -> Char.chr 5
    | _ -> failwith "aaa"
  done; s


let disassemble (s : string) : instr array =
  let p = Array.make (String.length s) Push in
  for i = 0 to String.length s - 1 do
    p.(i) <- match Char.code s.[i] with
    | 0 -> Push
    | 1 -> Addi
    | 2 -> Eqi
    | 3 -> Andi
    | n when (n mod 8 = 4) -> Consti (n lsr 3)
    | 5 -> Pop
    | _ -> failwith "invalid byte-code"
  done; p


let exemple1 = [| Consti 1; Push; Consti 2; Addi; Pop |]


(** Langage Myrte *)

type var = string

type value =
  | Int of int
  | Bool of bool

type binop = Add | Eq | And

type expr =
  | Var of var
  | Const of value
  | Binop of binop * expr * expr
  | If of expr * expr * expr
  | Let of var * expr * expr


(** Environnement *)

type envexpr = (var * value) list
type envcomp = (var * int) list
let empty_envexpr = []

(** Interprétation *)

let rec interp : envexpr * expr -> value = function
  | env, Const v           -> v
  | env, Binop (b, e1, e2) ->
     (match b, interp (env, e1), interp (env, e2) with
     | Add, Int i, Int j   -> Int (i + j)
     | Eq, Int i, Int j    -> Bool (i = j)
     | And, Bool i, Bool j -> Bool (i && j)
     | _ -> failwith "type error")
  | env, If (e1, e2, e3) ->
     (match interp (env, e1) with
      | Bool true  -> interp (env, e2)
      | Bool false -> interp (env, e3)
      | _ -> failwith "type error")
  | env, Var s   -> List.assoc s env
  | env, Let (s, e2, e3) ->
     let r = interp (env, e2) in
     let new_env = (s, r) :: env in
     interp (new_env, e3)


(** Compilation *)

let repr = function
  | Int i      -> i
  | Bool true  -> 1
  | Bool false -> 0

let op = function
  | Add -> Addi
  | Eq  -> Eqi
  | And -> Andi

let succ2 : 'a * int -> 'a * int = function
(a, x) -> (a, x+1)

let rec compil : envcomp * expr -> instr list = function
  | env, Const v -> [Consti (repr v)]
  | env, Binop (o,e1,e2) -> let new_env = (List.map succ2 env) in
                       compil (env, e1)  @
                       [Push] @
                       compil (new_env, e2) @
                       [op o; Pop]
  | env, If (e1, e2, e3) -> let i2 = compil (env, e2) in
                       let i3 = compil (env, e3) in
                       compil (env, e1) @
                       [BranchIf (2 + List.length i3)] @
                       i3 @
                       [Branch (1 + List.length i2)] @
                       i2
  | env, Var s         ->  [Acc (List.assoc s env)]
  | env, Let (s, e1, e2) ->
                        let new_env = (s, 0) :: (List.map succ2 env) in
                            compil (env, e1) @
                            [Push] @
                            compil (new_env, e2) @
                            [Pop]



(* Pretty-print the given list of instructions *)
let print_instrs l =
  let rec aux i = function
    | [] -> ()
    | h :: t ->
       begin
         print_int i;
         print_string " - ";
         print_string (string_of_instr h);
         print_newline ();
         aux (i+1) t
       end
  in aux 0 l
