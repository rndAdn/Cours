type unop = Cos | Sin;;
type binop = Plus | Moins | Fois;;
type expr =
| Num of float
| Var of string
| Unop of unop * expr
| Binop of binop * expr * expr;;

let string_of_unop x = match x with
|Cos -> "cos"
|Sin -> "sin";;

let string_of_binop x = match x with
|Plus -> "+"
|Moins -> "-"
|Fois -> "*";;

let rec string_of_expr x = match x with
|Num(f) -> string_of_float f
|Var(s) -> s
|Unop(u,e) -> string_of_unop u ^ string_of_expr e
|Binop(b,e1,e2) ->  "(" ^ string_of_expr e1 ^ string_of_binop b ^ string_of_expr e2 ^ ")";;

let e0 = Binop (Fois,
Unop (Cos, Binop(Plus, Num (-0.5), Num 0.5)),
Binop(Moins, Var "theta", Num 2.));;

string_of_expr e0;;

let val_unop u = match u with
|Cos -> (fun x -> cos x)
|Sin -> (fun x -> sin x);;

let val_binop b = match b with
|Plus -> (fun x y -> x +. y)
|Moins -> (fun x y  -> x -. y)
|Fois -> (fun x y  -> x *. y);;

List.assoc ;;

let rec eval_expr l x = match x with
|Num(f) -> f
|Var(s) -> List.assoc s l
|Unop(u,e) -> (val_unop u) (eval_expr l e)
|Binop(b,e1,e2) ->  (val_binop b) (eval_expr l e1) (eval_expr l e2);;

eval_expr [("x", -0.5); ("theta", 4.)] e0;;

let eval_sous_expr y =
let rec aux x = match x with
|Var(_) -> x
|Num(_) -> x
|Unop(u,Num(f)) -> Num((val_unop u) f)
|Binop(b,Num(f1),Num(f2))->Num((val_binop b) f1 f2)
|Binop(b,e1,e2)-> Binop(b,aux e1,aux e2)
|Unop(u,e) -> Unop(u,aux e)
in let rec auxb e1 e2 = if e1 = e2 then e2 else auxb (aux e1) e1
in auxb (aux y) y;;

string_of_expr(eval_sous_expr e0);;
