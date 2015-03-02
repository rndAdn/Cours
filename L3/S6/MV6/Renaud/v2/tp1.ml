#use "/media/data/git/Cours/L3/S6/MV6/Renaud/v2/mv_myrte.ml";;


let a = assemble exemple1;;
let b = disassemble a;;

let p = String.make (15) 'z';;
p.[0] <- Char.chr 4;;
p.[1] <- Char.chr 0;;
p.[2] <- Char.chr 3;;
p.[3] <- Char.chr 0;;
p.[4] <- Char.chr 0;;
p.[5] <- Char.chr 0;;
p.[6] <- Char.chr 4;;
p.[7] <- Char.chr 1;;
p.[8] <- Char.chr 1;;
p.[9] <- Char.chr 1;;
p.[10] <- Char.chr 0;;
p.[11] <- Char.chr 0;;
p.[12] <- Char.chr 5;;
p.[13] <- Char.chr 0;;
p.[14] <- Char.chr 0;;

let c = print_instrs exemple1;;

disassemble p;; (* [|Consti 3; Push; Consti (-1); Addi; Pop|] *)


let d = get_acc (machine (init exemple1));;

let exemple1 = [| Consti 2; Push; Consti 3; Addi; Pop |];;
let d = [| Consti 1; Push; Consti 1; Eqi; Pop; BranchIf 3; Consti 3; Branch 2; Consti 1|];;
let d = [| Consti 4; Push; Consti 4; Eqi; Pop; BranchIf 7; Consti 6; Push; Consti 7; Addi; Pop; Branch 6; Consti 2; Push; Consti 3; Addi; Pop|];;
let f = If(Binop(Eq, Const(Int(1)), Const(Int(2))),Const(Int(3)), Const(Int(1)));;
let e = compil f;;
print_instrs (Array.of_list e);;
