let rec map f l = match l with
  | [] -> []
  | t::q -> [f t]@ map f q;;

let succ x = x + 1 in map succ [1;2;3];;

let rec liste_min l = match l with
  | [] -> failwith "liste vide"
  | [a] -> a
  | a::b -> min a (liste_min b);;

liste_min [2;3;4;5;6; -8];;

let rec append l1 l2 = match l1 with
  |[] -> l2
  | t::q -> t::(append q l2);;

append [1;2;3;4] [5;6];;

let rec rev l = match l with
  | [] -> []
  | x::t -> (rev t)@[x];;

rev [1;2;3;4];;

let rev2 l = let rec aux l g = match l with
  [] -> g
  | x::h -> aux h (x::g)
 in aux l [];;

rev2 [1;2;3;4;5;6;7;8;9];;

let rec flatten l = match l with
  | [] -> []
  | t::q -> t@(flatten q);;

flatten [[2]; []; [3;4;5]];;
