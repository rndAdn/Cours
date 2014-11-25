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
| Node(x,g,d) -> aux g (x::(aux d l))
in aux t [];;

let rec mem_abr x t = match t with
| Nil -> false
| Node(y,g,d) -> if y = x then true else if x>y then mem_abr x d else mem_abr x g;;

let rec add_abr x t = match t with
| Nil-> Node(x,Nil,Nil)
| Node(y,g,d) -> if y = x then t else if y < x then Node(y,g,(add_abr x d)) else Node(y,(add_abr x g),d);;

let is_abr t =
let rec is_sorted l = match l with | [] -> true | p :: [] -> true | x :: q :: t -> if x < q then is_sorted (q::t) else false
in is_sorted (elements t);;


let rec split l1 l2 i j = if i = j then (l1,l2)
else match l2 with
| [] -> (l1,l2)
| x::q -> split (x::l1) q (i+1) j;;

let rec make_abr l =
let rec aux (l1,l2) a =
match l1,l2 with
|[],[] -> a
|x::q,[] -> aux(split [] q 0 ((List.length q)/2)) (add_abr x a )
|_,y::p -> aux(split [] l1 0 ((List.length l1)/2)) (aux(split [] p 0 ((List.length p)/2)) (add_abr y a ))
in aux (split [] l 0 ((List.length l)/2)) Nil;;


let rec forall_labels p a = match a with
| Nil -> true
| Node(x,g,d) -> (p x) && (forall_labels p g) && (forall_labels p d);;

let is_uniform v a = let uni x = x == v in forall_labels uni a ;;

let rec forall_subtrees p a = match a with
|Nil -> true
|Node(x,g,d) -> p x g d && (forall_subtrees p g) && (forall_subtrees p d);;

let est_peigne_droit a = let f x g d =
match g with |Nil -> true |Node(_,Nil,Nil) -> true | _-> false
in forall_subtrees f a;;

let rec fold_tree fn vf a = match a with
Nil -> vf
| Node(n, g, d) -> fn n (fold_tree fn vf g) (fold_tree fn vf d);;

let somme_etiquettes a = let add x y z = x + y + z in fold_tree add 0 a;;

let map_tree f a = let aux x y z = Node(f x,y,z) in fold_tree aux Nil a;;

let rec space k =
  if k <= 0 then ""
  else " "^(space (k - 1))

let rec line k =
  if k <= 0 then ""
  else "-"^(line (k - 1))
;;


let croisement l1 ls1 ln l2 ls2 =
  let spc_center = space ln in
  let spc_left   = (space l1)^spc_center
  and spc_right  = spc_center^(space l2) in
  let rec aux ls1 ls2 = match ls1, ls2 with
      [], [] -> []
    | s1::ls1', [] -> (s1^spc_right)::(aux ls1' [])
    | [], s2::ls2' -> (spc_left^s2)::(aux [] ls2')
    | s1::ls1', s2::ls2' -> (s1^spc_center^s2)::(aux ls1' ls2')
  in aux ls1 ls2
;;


let rec levels_of_tree t = match t with
    Nil -> ((1, 0), ["*"])
  | Node(n, g, d) ->
    let sn = string_of_int n in
    let ln = String.length sn in
    let (l1, ofs1), ls1 =  levels_of_tree g
    and (l2, ofs2), ls2 =  levels_of_tree d in
    let sr_top =
      (space (ofs1 + 1))^
      (line (l1 - ofs1 - 1))^
      (sn)^
      (line ofs2)^
      (space (l2 - ofs2))  in
    let sr_bot =
      (space ofs1)^"|"^
      (space (l1 - ofs1 - 1))^
      (space ln)^
      (space ofs2)^"|"^
      (space (l2 - ofs2 - 1))  in

    let lc = croisement l1 ls1 ln l2 ls2  in
    ((l1 + ln + l2, l1), sr_top::sr_bot::lc)
;;

let print_tree tree =
    List.iter (fun s -> print_string (s^"\n")) (snd (levels_of_tree tree));;


let arbre= Node(70,Node(60,Node(55,Nil,Nil),Node(65,Nil,Nil)),
 Node(80,Node(75,Nil,Nil),Node(90,Nil,Nil)));;

let l = split [] [1;2;3;4;5;6;7] 0 3
let abr = make_abr [1;2;3;4;5;6;7];;

print_tree abr;;
