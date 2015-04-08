let rec sur_deux t = match t with
| [] -> []
| [a] -> [a]
| a::b::c -> [a]@( sur_deux c);;
(*val sur_deux : 'a list -> 'a list = <fun>*)

sur_deux ['a';'b';'c';'d';'e';'f';'g'];;
(*- : char list = ['a'; 'c'; 'e'; 'g'] *)

 let rec groupe_de_deux t = match t with
 | [] -> [[]]
 | [a] -> [[a]]
 | a::b::c -> [[a;b]]@( groupe_de_deux c);;
(*val groupe_de_deux : 'a list -> 'a list list = <fun>*)
groupe_de_deux ['a';'b';'c';'d';'e';'f';'g'];;
(*- : char list list = [['a'; 'b']; ['c'; 'd']; ['e'; 'f']; ['g']]*)

(*janvier 2013*)

let rec is_sum_cons n liste = match liste with
| [] -> false
| [a] -> false
| a::b::c -> if a+b = n then true else is_sum_cons n (b::c);;
(*val is_sum_cons : int -> int list -> bool = <fun>*)

is_sum_cons 8 [2;5;3;5];;
(*- : bool = true*)
is_sum_cons 5 [2;5;3;5];;
(*- : bool = false*)


let is_sum n liste =
let  rec aux n l inc =  match l with
    | [] -> false
    | a::c -> if a + inc = n then  true else aux n c inc in
let rec x ll=  match ll with
    | [] -> false
    | a::b -> if aux n b a = true then true else x b
in x liste
;;
(*val knapsack : int -> int list -> bool = <fun>*)

is_sum 18 [2;5;3;5;15;7];;

(*let rec is_sum l n =
let rec aux l n p = match l with
    |[]->false
    |x::y->if (p + x) = n then true else aux y n p
in match l with
    |[]->false
    |x::y ->if x == n then true else if aux y n x then true else is_sum y n;;

is_sum [2;5;3;5] 2;;*)

let rec knapsack n liste =
    let rec aux n liste = begin
        match liste with
            |[]-> false
            |x::y -> if is_sum n liste then true else aux (n-x) y
        end
    in match liste with
            |[] -> false
            |a::b -> if aux n liste = true then true else knapsack n b
;;
(*val knapsack : int -> int list -> bool = <fun>*)
knapsack 63 [1;2;4;8;16;32];;
(*- : bool = true*)

type heap ={
    mutable min : int;
    mutable tas : int list;
}
(*type heap = { mutable min : int; mutable tas : int list; }*)

let x = {min = -1;tas = []};;
(*val x : heap = {min = -1; tas = []}*)
