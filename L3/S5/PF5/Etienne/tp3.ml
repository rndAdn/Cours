type 'a tree =
| Nil
| Node of 'a * 'a tree * 'a tree;;

let rec taille t = match t with
| Nil -> 0
| Node(_,g,d) -> 1 + taille g +taille d;;

let rec hauteur t = match t with
| Nil -> 0
| Node(_,g,d) -> 1 + max (hauteur g) (hauteur d);;

let rec mem x t = match t with
| Nil -> false
| Node(y,g,d) -> if y = x then true else (mem x g) || (mem x d);;

let rec complet t = match t with
| Nil -> true
| Node(_,g,d) -> (hauteur g) == (hauteur d) && (complet g) && (complet d);;

let elements t =
let rec aux a l = match a with
| Nil -> l
| Node(x,g,d) -> aux d (x::(aux g l))
in aux t [];;

let rec mem_abr x t = match t with
| Nil -> false
| Node(y,g,d) -> if y = x then true else if x>y then mem_abr x d else mem_abr x g;;

let rec add_abr x t = match t with
| Nil-> Node(x,Nil,Nil)
| Node(y,g,d) -> if y = x then t else if y > x then Node(y,g,(add_abr x d)) else Node(y,(add_abr x g),d);;

let is_abr t =
let rec parc a l1 l2 = match a,l1,List.rev l2 with
| Nil,_,_ -> true
| Node(x,g,d),[],[] -> (parc g (x::l1) l2) && (parc d l1 (x::l2))
| Node(x,g,d),[],p::_ -> if (x < p) then (parc g (x::l1) l2) && (parc d l1 (x::l2)) else false
| Node(x,g,d),q::_,[] -> if (x > q) then (parc g (x::l1) l2) && (parc d l1 (x::l2)) else false
| Node(x,g,d),q::_,p::_ -> if (x > q) && (x < p) then (parc g (x::l1) l2) && (parc d l1 (x::l2)) else false
in parc t [] [];;

let is_abr t =
let rec is_sorted l = match l with | [] -> true | p :: [] -> true | x :: q :: t -> if x <= q then is_sorted (q::t) else false
in is_sorted (elements t);;
