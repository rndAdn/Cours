(*
 *  [0: 1 [0: 2 0 0] [0: 3 0 0]]
 * 
 * 
 *)
type 'a tree = Node of 'a * 'a tree * 'a tree | Leaf ;;
(*int*)
Node(1,Node(2,Leaf,Leaf),Node(3,Leaf,Leaf));;
(* (int * bool array * int array) *)
(*(1, Array.make 2 false, Array.make 2 0);; Pas faisable*)

(* (int * (int * bool * unit) * (int * unit * bool)) *)
(1,(2,false,()),(3,(),false));;


10 + (30 + 40) ;;

print_string("--------------------------");;

let x = 1 in x+2 ;;

print_string("--------------------------");;

let y = 1 in let x = y in x+x;;

print_string("--------------------------");;

let f = if(2 < 3) then 1 else 4;;

print_string("--------------------------");;

let x = (1,2) in (snd x) + (fst x);;

print_string("--------------------------");;

let x = 1 in let y = 2 in let z = x in z  ;;

print_string("--------------------------");;

