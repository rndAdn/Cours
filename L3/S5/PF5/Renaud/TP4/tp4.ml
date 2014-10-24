type unop =
Cos
| Sin;;

type binop =
Plus
| Moins
| Fois;;

type expr =
Num of float
| Var of string
| Unop of unop * expr
| Binop of binop * expr * expr;;


(* EX1.1 *)
let string_of_unop op = match op with
| Cos -> "cos"
| Sin -> "sin";;

let string_of_binop op = match op with
| Plus -> " + "
| Moins -> " - "
| Fois -> " * ";;

(* EX1.2 *)
let rec string_of_expr op = match op with
| Num(a) -> string_of_float a
| Var(a) -> a
| Unop(a,b) -> string_of_unop a ^ string_of_expr b
| Binop(a,g,d) -> "(" ^ string_of_expr g ^string_of_binop a ^ string_of_expr d ^ ")";;

let e0 = Binop (Fois,
Unop (Cos, Binop(Plus, Var "x", Num 0.5)),
Binop(Moins, Var "theta", Num 2.));;

string_of_expr e0;;

(* EX2.3 *)

let val_unop op = match op with
| Cos -> fun x -> cos x
| Sin -> fun x -> sin x;;

let val_binop op = match op with
| Plus -> fun x y -> x+.y
| Moins -> fun x y -> x-.y
| Fois -> fun x y -> x*.y;;


(* EX2.4 *)

let rec eval_expr l ex = match ex with
| Num(a) -> a
| Var(s) -> List.assoc s l
| Unop(a,b) -> (val_unop a) (eval_expr l b)
| Binop(a,g,d) -> (val_binop a) (eval_expr l g) (eval_expr l d);;

eval_expr [("x", -0.5); ("theta", 4.)] e0;;

(* EX3.5 *)
