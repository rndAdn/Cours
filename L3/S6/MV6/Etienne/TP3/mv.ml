(* [0:[0:[1:2]]] *)
(*[2: [1:0] [0:1]*)
(*
type t1 = A | B | C | D of t1 | E of int | F of t1 * t1;;
let a1 = D(D(E(2)));;
let b1 = F(E(0),D(B));;

type t2 = A of t2 | B | C of t2 | D of t2 * t2 | E | F;;
let a2 = A(A(C(F)));;
let b2 = D(C(B),A(E));;
*)

(*let f x = 2*x in f (3+2);;*)
(*let a = 2 in let f x = a*x in f 4;;*)
(*let g y = y+1 in let f x = x*2 in g (f 3);;*)

(*let rec f x = (f x) + 1 in f 2;; *)
(*let rec add n = (if n == 0 then 0 else n + (add (n-1)));;*)
(*let add n = 
  let rec aux n acc = 
    if n==0 then acc 
    else aux (n-1) (acc + n)
  in aux n 0;;
*)

let f x =
  let rec aux (l,a) =
    if a==0 then []
    else aux (a::l,(a-1))
  in aux([],x);;

