let rec list_sigma x = match x with | t::q->t+list_sigma q | []->0;;
let rec mem x l = match l with | y::q when y = x  -> true | t::q -> mem x q | [] -> false;;
mem 6 [1;4;6;8];;
let rec map2 f l = match l with | [] -> [] | x::q -> f x :: map2 f q ;;
let x = let succ x = x + 2 in map2 succ [1;2;3];;
let rec liste_min l = match l with [] -> failwith "erreur, liste vide !" | x::[] -> x | x :: q -> min x (liste_min q);;
liste_min [2;-30;4;1;8];;
let rec is_sorted l = match l with | [] -> true | p :: [] -> true | x :: q :: t -> if x <= q then is_sorted (q::t) else false;;
is_sorted [1;2;3;4;4;5];;
let rec append u v = match u with | [] -> v | x::w -> x::(append w v);;
append [1;2;3] [4;5;6];;
let rec inverse u = match u with | [] -> u | x::w -> append(inverse w) [x];;
inverse [1;2;3;4];;
let inverse u = let rec aux l p = match l with [] -> p | x::q -> aux q (x::p) in aux u [];; 
let rec flatten u = match u with |[] -> [] | x::q -> append x (flatten q);;
flatten [[2];[];[3;4;5]];;
let rotation_d u = match u with | []->[] | x::[]->u | x::q -> match (inverse q) with y :: p -> y::q@[x];;
rotation_d [1;2;3;4;5];;
let moyenne t = let rec aux l n= match l with [] -> failwith "erreur, liste vide !" | x::[] -> x/n | x::y::q -> aux ((x+y)::q) (n+1) in aux t 1;;
moyenne [1;2;3;4;5];;
let rec insert x l = match l with [] -> [x] | y::q -> if x < y then x::l else if x = y then l else y::(insert x q);;
insert 5 [1;3;8];;
insert 5 [1;3;5;6];;
let sort l = let rec aux u v = match u with [] -> v | x::p -> aux p (insert x v) in aux l [];;
sort [8;12;5;6;3;2;1;5;2;5];;
inverse[1;2;3;4;5];;
List.fold_right (fun x y -> x+y) [2;5;6] 0;;
let rec mem_sorted x l = match l with [] -> false | y::p -> if y = x then true else if y > x then false else mem_sorted x p;;
let union_sorted u v = let rec aux u v w = match u,v with [],v -> (inverse v)@w | u,[] -> (inverse u)@w | x::p,y::q -> if x = y then aux p q (x::w) else if x>y then aux u q (y::w) else aux p v (x::w) in inverse (aux u v []);;
union_sorted [1;2;5;9] [2;3;7;10;11];;
let inter_sorted u v = let rec aux u v w = match u,v with [],v -> w | u,[] -> w | x::p,y::q -> if x = y then aux p q (x::w) else if x>y then aux u q w else aux p v w in aux u v [];;
inter_sorted [1;3;5] [2;5;8];;











