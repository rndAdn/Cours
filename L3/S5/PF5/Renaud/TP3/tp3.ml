type 'a tree =
| Nil
| Node of 'a * 'a tree * 'a tree;;

let rec taille arbre = match arbre with
|Nil -> 0
|Node(_,g,d) -> 1 + taille g + taille d;;

let rec hauteur arbre = match arbre with
|Nil -> 0
|Node(_,g,d) -> if hauteur g > hauteur d then hauteur g +1 else hauteur d +1;;

let rec mem arbre x = match arbre with
|Nil -> false
|Node(vale,g,d) -> x = vale || (mem g x) || (mem d x);;














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
 Node(80,Node(75,Nil,Nil),Node(90,Node(1,Nil,Nil),Nil)));;

hauteur arbre;;
is_abr arbre 90;;
print_tree arbre;;
