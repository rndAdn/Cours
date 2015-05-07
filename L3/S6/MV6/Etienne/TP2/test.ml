#use "/Users/etouss/Documents/Cours/L3/S6/MV6/Etienne/TP2/mv_myrte_v2.ml";;

let ex = Let("x",Const(Int(1)),Binop(Add,Const(Int(2)),Var("x")));;
(* let cmp = compil (empty_envcomp,ex);; *)
(* (machine (init (Array.of_list cmp)));; *)
(*let x = 1 in x + 2*)

print_instrs (compil (empty_envcomp,ex));;
assemble_filename "ex1.my" (compil (empty_envcomp,ex));;

let ex = Let("x",Const(Int(1)),Binop(Add,Var("x"),Const(Int(2))));;
(* let cmp = compil (empty_envcomp,ex);; *)
(* (machine (init (Array.of_list cmp)));; *)

assemble_filename "ex2.my" (compil (empty_envcomp,ex));;


(*let x = 1 in let y = x in let x = y + 3 in y + x*)
let ex =
  Let("x",Const(Int(1)),Let("y",Var("x"),Let("x",Binop(Add,Var("y"),Const(Int(3))),Binop(Add,Var("y"),Var("x")))));;
(* let cmp = compil (empty_envcomp,ex);; *)
(* (machine (init (Array.of_list cmp)));; *)

assemble_filename "ex3.my" (compil (empty_envcomp,ex));;


(*let x = (let x = 1 in x + 2) in x + 3*)
let ex =
  Let("x",Let("x",Const(Int(1)),Binop(Add,Var("x"),Const(Int(2)))),Binop(Add,Var("x"),Const(Int(3))));;
(* let cmp = compil (empty_envcomp,ex);; *)
(* (machine (init (Array.of_list cmp)));; *)

assemble_filename "ex4.my" (compil (empty_envcomp,ex));;

let ex = 
  Let("x",
      Let("x",Const(Int(1)),Binop(Add,Var("x"),Const(Int(3)))),
      Binop(Add,
            Let("x",
                Let("x",
                    Binop(Add,Var("x"),Const(Int(4))),
                    Binop(Add,Var("x"),Const(Int(5)))
                    ),
                    Binop(Add,Var("x"),Const(Int(2)))),
            Var("x"))
  );;

(* let cmp = compil (empty_envcomp,ex);; *)
(* (machine (init (Array.of_list cmp)));; *)

assemble_filename "ex5.my" (compil (empty_envcomp,ex));;


