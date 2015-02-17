
(** Machine virtuelle *)

type instr = Push | Consti of int | Addi | Eqi | Andi | Pop | Subs | BranchIf of int | Branch of int |Acc of int

type state = {
  mutable acc: int;
  code: instr array;
  mutable pc: int; (* indice de l’instruction courante dans code *)
  stack: int array;
  mutable sp: int; (* indice du sommet de la pile dans stack *)
}

let machine s =
  while s.pc < Array.length s.code do
    print_int(s.pc);
    begin match s.code.(s.pc) with
    | Acc n -> s.acc <- s.stack.(n)
    | Consti n ->
       s.acc <- n;print_string(" -- Consti ");print_int(n);print_string("\n")
    | Push ->
       s.sp <- s.sp + 1;
       s.stack.(s.sp) <- s.acc;print_string(" -- Push");print_string("\n")
    | Addi ->
       s.acc <- s.stack.(s.sp) + s.acc;print_string(" -- Addi");print_string("\n")
    | Subs ->
       s.acc <- s.stack.(s.sp) - s.acc;print_string(" -- Subs");print_string("\n")
    | Andi ->
       s.acc <- s.stack.(s.sp) * s.acc;print_string(" -- Andi");print_string("\n")
    | Eqi ->
       s.acc <- if s.stack.(s.sp) = s.acc then 1 else 0;print_string(" -- Eqi");print_string("\n")
    | Pop ->
       s.sp <- s.sp-1;print_string(" -- Pop");print_string("\n")
    | BranchIf n ->
       if(s.acc = 0) then ()
       else s.sp <- s.pc + (n-1)
    | Branch n -> s.sp <- s.pc + (n-1)
    end;
    s.pc <- s.pc + 1
  done; print_int(s.acc);s

let init c =
  { code = c;
    stack = Array.make 1000 42; (* pourquoi 42 ? *)
    pc = 0;
    sp = -1;   (* pourquoi -1 ? *)
    acc = 52 } (* pourquoi 52 ? *)

let get_acc s = s.acc


(*
let assemble (p :instr array) : string =
  let rec aux p i l = match p.(i) with
      | Push -> aux p (i+1) ((String.make 3 (Char.chr 0))::l)
      | Addi -> aux p (i+1) ((String.make 3 (Char.chr 1))::l)
      | Eqi -> aux p (i+1) ((String.make 3 (Char.chr 2))::l)
      | Andi -> aux p (i+1) ((String.make 3 (Char.chr 3))::l)
      | Consti n -> if(n > 255 || n<-255) then failwith "Erreur"
                    else aux p (i+1) ((String.make 3 (Char.chr 4))::l)
      (*assert (n < 256 && n > -256);
      String.make 3 3;
      Char.chr (4 + n lsl 3);*)
      | Pop -> aux p (i+1) ((String.make 3 (Char.chr 5))::l)
      |_ -> l
  in String.concat "" (aux p 0 []);;
  *)

let assemble (p : instr array) : string =
  let s = String.make ((Array.length p)*3) 'z' in
  for i = 0 to Array.length p - 1 do
    match p.(i) with
    | Push -> s.[3*i]<-Char.chr 0;
    | Addi -> s.[3*i]<-Char.chr 1;
    | Eqi -> s.[3*i]<-Char.chr 2;
    | Andi -> s.[3*i]<-Char.chr 3;
    | Consti n -> assert (n < 256 && n> (-256));
                  if n<0 then ( s.[3*i]<-(Char.chr 4);s.[3*i + 1]<-Char.chr (1);s.[3*i + 2]<-(Char.chr (-n)))
                  else (s.[3*i]<-(Char.chr 4);s.[3*i + 1]<-(Char.chr 0);s.[3*i + 2]<-(Char.chr n))
    | Pop ->  s.[3*i]<-Char.chr 5;
    | Subs -> s.[3*i]<-Char.chr 6;
    | BranchIf n -> s.[3*i]<-Char.chr 7;s.[3*i+1]<-Char.chr 0;s.[3*i+2]<-Char.chr n;
    | Branch n -> s.[3*i]<-Char.chr 8;s.[3*i+1]<-Char.chr 0;s.[3*i+2]<-Char.chr n;
  done; s

let disassemble (s : string) : instr array =
  let p = Array.make ((String.length s)/3) Push in
  for i = 0 to ((String.length s)/3 - 1) do
    p.(i) <- match Char.code s.[3*i] with
    | 0 -> Push
    | 1 -> Addi
    | 2 -> Eqi
    | 3 -> Andi
    | 4 -> if(Char.code s.[3*i +1] == 0)
            then Consti (Char.code s.[3*i +2])
            else Consti (-(Char.code s.[3*i +2]))
    | 5 -> Pop
    | 6 -> Subs
    | 7 -> BranchIf (Char.code s.[3*i +2])
    | 8 -> Branch (Char.code s.[3*i +2])
    | _ -> failwith "invalid byte-code"
  done; p


let exemple1 = [| Consti 1; Push; Consti 2; Addi; Pop |]


(** Langage Myrte *)


type var   = string

type value =
  | Int of int
  | Bool of bool

type envexpr = var -> value

type binop = Add | Eq | And | Mult

type expr =
  | If of expr * expr * expr
  | Const of value
  | Binop of binop * expr * expr
  | Var of var
  | Let of var * expr * expr



(** Interprétation *)

let rec interp : envexpr * expr -> value = function
  | env,Const v -> v
  | env,Binop (b, e1, e2) ->
     (match b, interp (env,e1), interp (env,e2) with
       | Add, Int i, Int j -> Int (i + j)
       | Eq, Int i, Int j -> Bool (i = j)
       | And, Bool i, Bool j -> Bool (i && j)
       | _ -> failwith "type error")
  |env,If (e1,e2,e3) ->
    if interp (env,e1) = Bool (true) then interp (env,e2)
      else interp (env,e3)
  |env,Var (s) -> env s
  |env,Let (s,e2,e3) -> let r = interp (env, e2) in
                    let new_env v = if (v = s) then r else env v in
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
  | Mult -> failwith "Bizarre"

let rec compil = function
  | Const v -> [Consti (repr v)]
  | Binop (Mult,Const(Int 1),e2) -> compil e2
  | Binop (Mult,Const(Int c),e2) -> compil (Binop(Add,e2,Binop(Mult,Const(Int (c-1)),e2)))
  | Binop (o,e1,e2) -> compil e1 @
                       [Push] @
                       compil e2 @
                       [op o; Pop]
  |If (e1,e2,e3) -> let be2 = compil e2 and be3 = compil e3 in
                    compil e1 @ [Branch (List.length be2)] @ be2 @ [BranchIf (List.length be3)]  @ be3
