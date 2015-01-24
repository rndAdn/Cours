1 +. 3 = 12;;
(* Error: This expression has type int but an expression was expected of type float *)
2. *. (float_of_int (int_of_float 10.));;
(* - : float = 20. *)
"foo"^"bar"^"baz";;
(*- : string = "foobarbaz"*)
let f x = x + 1 in let g = fun x -> x * 2 in g (f 17);;
(*- : int = 36*)
let rec fact2 = function 0 -> 1 | n -> n * fact2 (n - 2);;
(*val fact2 : int -> int = <fun>*)
fact2 5;;
(*Stack overflow during evaluation (looping recursion?).*)
fact2 (-1);;
(*Stack overflow during evaluation (looping recursion?).*)
let g = (+) 42 in g 3;;
(*- : int = 45*)
(1,2,3)::[(4,5,6)];;
(*- : (int * int * int) list = [(1, 2, 3); (4, 5, 6)]*)
match [1;2;3] with
    [] -> 17
    | [x;y] -> 25
    | x::y -> 33
    | _ -> 51;;
(*- : int = 33*)
exception Ex;;
(* exception Ex*)
try raise Ex
with Ex -> raise Ex;;
(*Exception: Ex.*)
type mtype = Base of bool | Ind of mtype;;
(*type mtype = Base of bool | Ind of mtype*)
Ind(Ind (Base true));;
(*- : mtype = Ind (Ind (Base true)) *)
type 'a ptype = Ground of 'a | Step of ('a ptype);;
(*type 'a ptype = Ground of 'a | Step of 'a ptype*)
Step (Ground (Step (Ground 17)));;
(*- : int ptype ptype = Step (Ground (Step (Ground 17)))*)
List.fold_left (fun x y -> y^x) "" ["abc";"def";"ghi"];;
(*- : string = "ghidefabc"*)
List.fold_right (fun a b -> a - b) [1;2;5] (-2);;
(*- : int = 6*)
if (1-1 = 0.0) then true else false;;
(*Error: This expression has type float but an expression was expected of type int*)
type abc = A | B | C;;
(*type abc = A | B | C*)
(fun x -> match x with _ -> C) A;;
(*- : abc = C*)
let f x y z = ((x = y) = z);;
(*val f : 'a -> 'a -> bool -> bool = <fun>*)
let x = 1 in x = 2 || not (2 <> 3) ;;
(*- : bool = false *)
let x = 1 and y = 2 in max x y ;;
(*- : int = 2 *)
let x = 1 and y = x in max x y ;;4.x + 1 ;;
(*Error: Unbound value x *)
let null f = function 0 -> false | n -> f n ;;
(*val null : (int -> bool) -> int -> bool = <fun> *)
null (fun x -> x mod 2 = 0) 4 ;;
(*- : bool = true *)
null (fun x -> x) 4 ;;
(*Error: This expression has type int but an expression was expected of type bool *)
match [1;2] with a :: b :: c -> c | _ -> raise Not_found ;;
(* - : int list = []*)
match [1;2] with [_] -> true | _ :: _ -> false ;;
(* - : bool = false*)
let m = max (0,1) ;;
(*val m : int * int -> int * int = <fun>*)
m (2,3) ;;
(* - : int * int = (2, 3)*)
let r p = let (x, y) = p in (y, x) ;;
(* val r : 'a * 'b -> 'b * 'a = <fun>*)
r (false, 'a') ;;
(*- : char * bool = ('a', false)*)
let pr x = print_string (x ^ "\n") ;;
(*val pr : string -> unit = <fun> *)
pr "je vaux "; 21 ;;
(*je vaux
- : int = 21*)
List.map (fun x -> -1) ["a";"b";"c"];;
(*- : int list = [-1; -1; -1]*)
