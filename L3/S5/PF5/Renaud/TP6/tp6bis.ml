type 'a tree =
 | Nil
 | Node of 'a * 'a tree * 'a tree;;


let rec taille t rest n = match t with
| Nil -> let res = match rest with
    | [] -> n
    | a::l -> taille a l n
    in res
| Node(_,g,d) -> taille g (d::rest) (n+1);;

let t a = taille a [] 0;;
