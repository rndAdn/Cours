#use "/media/data/git/Cours/L3/S6/MV6/Renaud/tp2/mv_myrte_v2.ml";;


let a = Let("x", Const(Int(1)), Binop(Add, Const(Int(2)), Var("x")));;

let e = compil (empty_envexpr, a);;
let d = get_acc (machine (init (Array.of_list e)));;

let a = Let("x",Const(Int(1)),Let("y",Var("x"),Let("x",Binop(Add,Var("y"),Const(Int(3))),Binop(Add,Var("x"),Var("y"))))) in
let e = compil (empty_envexpr, a) in
get_acc (machine (init (Array.of_list e)));;
