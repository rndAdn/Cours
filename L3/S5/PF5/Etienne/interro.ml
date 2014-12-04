41+3-2;;
let a = 1.0 in let b = 2.0 in a<>b;;
let a = 41+3-2;;
let rec f a b = if b = 0 then a else f b (a mod b);;
let add1 = (+.) 1.0;;
let comp f g x = f(g x);;

type 'a ptype = Ground of 'a | Step of ('a ptype);;
Step(Ground(Step(Ground 17)));;
