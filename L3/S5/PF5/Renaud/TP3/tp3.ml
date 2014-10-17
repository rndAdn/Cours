type 'a tree =
| Nil
| Node of 'a * 'a tree * 'a tree;;

let rec taille arbre = match arbre with
|Nil -> 0
|Node(_,g,d) -> 1 + taille g + taille d;;

let rec hauteur arbre = match arbre with
|Nil -> 0
|Node(_,g,d) -> if hauteur g > hauteur d then hauteur g +1 else hauteur d +1;;

let rec mem x arbre = match arbre with
|Nil -> false
|Node(vale,g,d) -> x = vale || (mem x g) || (mem x d);;

let rec complet arbre = match arbre with
|Nil -> true
|Node(x,gauche,droite) -> hauteur gauche = hauteur droite && complet gauche && complet droite;;

let rec element arbre = match arbre with
|Nil -> []
|Node(x,g,d) -> (element g)@[x]@(element d);;

(*
let elements t =
let rec aux a l = match a with
| Nil -> l
| Node(x,g,d) -> aux d (x::(aux g l))
in aux t [];;
*)

let rec mem_abr x abr = match abr with
| Nil -> false
| Node(vale,g,d) -> if x = vale then true
                    else if x < vale then mem_abr x g
                    else mem_abr x d;;


let rec add_abr x abr = match abr with
| Nil -> Node(x,Nil,Nil)
| Node(vale,g,d) -> if x < vale then Node(vale,(add_abr x g),d) else Node(vale,g,(add_abr x d));;


let is_abr abr =
let rec is_sorted l = match l with
| [] -> true
| p :: [] -> true
| x :: q :: t -> if x < q then is_sorted (q::t) else false
 in is_sorted (element abr);;




let rec forall_labels f arbre = match arbre with
| Nil -> true
| Node(x,g,d) -> f x && (forall_labels f g) && (forall_labels f d);;


 let is_uniform v a = let uni x = x = v in forall_labels uni a;;

let rec forall_subtrees f arbre = match arbre with
| Nil -> true
| Node(x,g,d) -> f x g d && (forall_subtrees f g) && (forall_subtrees f d);;


let est_peigne_droit a = let p x g d = match g with
| Nil -> true
| Node(_,Nil,Nil) -> true
| _ -> false
in forall_subtrees p a;;


let rec fold_tree fn vf a = match a with
Nil -> vf
| Node(n, g, d) -> fn n (fold_tree fn vf g) (fold_tree fn vf d);;


(*
val fold_tree : ('a -> 'b -> 'b -> 'b) -> 'b -> 'a tree -> 'b = <fun>
*)


let somme_etiquettes abr = let sum x y z = x+y+z in fold_tree sum 0 abr;;

let map_tree f a = let aux x y z = Node(f x,y,z) in fold_tree aux Nil a;;



let rec make_abr liste









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

 let arbre= Node(70,Node(60,Node(60,Nil,Nil),Node(65,Nil,Nil)),
 Node(80,Node(75,Nil,Nil),Node(90,Nil,Nil)));;
hauteur arbre;;
mem 90 arbre;;
complet arbre;;
element arbre;;
mem_abr 100 arbre;;
let abr = add_abr 66 arbre;;
is_abr arbre;;
print_tree abr;;
