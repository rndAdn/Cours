41+3-2;;
let a = 1.0 in let b = 2.0 in a<>b;;
let a = 41+3-2;;
let rec f a b = if b = 0 then a else f b (a mod b);;
let add1 = (+.) 1.0;;
let comp f g x = f(g x);

type 'a ptype = Ground of 'a | Step of ('a ptype);;
Step(Ground(Step(Ground 17)));;

let rec is_sum l n =
let rec aux l n p = match l with
|[]->false
|x::y->if (p + x) = n then true else aux y n p
in match l with
|[]->false
|x::y ->if x == n then true else if aux y n x then true else is_sum y n;;

let rec knapsack n liste =
  let rec aux n liste =
  begino
    match liste with
      |[]-> false
      |x::y -> if is_sum liste n then true else aux (n-x) y
  end
 in match liste with
  |[] -> false
  |a::b -> if aux n liste then true else knapsack n b;;



[2;5;3;5;15;7];;
