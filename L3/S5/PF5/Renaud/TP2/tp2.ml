let rec list_sigma l = match l with
  | [] -> 0
  | l::q -> l + list_sigma q;;

list_sigma [1;2;3];;

let rec mem l x = match l with
  | [] -> false
  | l::q -> if l = x then true else mem q x;;

mem [1;2;3] 50;;


