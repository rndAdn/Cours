let rec taille t = match t with
| [] -> 0
| x::l   -> 1 + taille l;;

let tailleTerm t = let rec aux t1 n = match t1 with
|[] -> n
|x::l -> aux l (n+1)
in aux t 0;;

let append' left right = let rec aux l r = match l with
|[] -> r
|x::l1 -> aux l1 (x::r)
in aux left right;;

let append left right = append' (List.rev left) right;;

type 'a tree =
| Nil
| Node of 'a * 'a tree * 'a tree;;

let rec taille' arbre arbreList n = match arbre,arbreList with
|Nil,[] -> n
|Nil,x::l -> taille' x l n
|Node(_,g,d),_ -> taille' Nil (g::d::arbreList) (n+1);;

let taille arbre = taille' arbre [] 0;;
