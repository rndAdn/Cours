#use "/Users/ByTeK/Documents/Cours/L3/S6/MV6/Etienne/mv_myrte.ml";;

let s = String.make (15) 'z';;
s.[0]<-Char.chr 4;;
s.[1]<-Char.chr 0;;
s.[2]<-Char.chr 3;;
s.[3]<-Char.chr 0;;
s.[4]<-Char.chr 0;;
s.[5]<-Char.chr 0;;
s.[6]<-Char.chr 4;;
s.[7]<-Char.chr 1;;
s.[8]<-Char.chr 1;;
s.[9]<-Char.chr 1;;
s.[10]<-Char.chr 0;;
s.[11]<-Char.chr 0;;
s.[12]<-Char.chr 5;;
s.[13]<-Char.chr 0;;
s.[14]<-Char.chr 0;;
let desa = disassemble s;;
let code = assemble desa;;

let string_of_instr instr =
  assemble (Array.make 1 instr);;

let print_instrs p =
  let rec aux p2 i =
    match p2 with
      | Push::p1 -> print_int(i);print_string(" -- Push");print_string("\n");aux p1 (i+1)
      | Addi::p1 -> print_int(i);print_string(" -- Addi");print_string("\n");aux p1 (i+1)
      | Eqi::p1 -> print_int(i);print_string(" -- Eqi");print_string("\n");aux p1 (i+1)
      | Andi::p1 -> print_int(i);print_string(" -- Andi");print_string("\n");aux p1 (i+1)
      | (Consti n)::p1 -> print_int(i);print_string(" -- Consti ");print_int(n);print_string("\n");aux p1 (i+1)
      | Pop::p1 ->  print_int(i);print_string(" -- Pop");print_string("\n");aux p1 (i+1)
      | Subs::p1 -> print_int(i);print_string(" -- Subs");print_string("\n");aux p1 (i+1)
      | (Branch n)::p1 -> print_int(i);print_string(" -- Branch ");print_int(n);print_string("\n");aux p1 (i+1)
      | (BranchIf n)::p1 -> print_int(i);print_string(" -- BranchIf ");print_int(n);print_string("\n");aux p1 (i+1)
      | []-> ()
  in aux p 0;;

get_acc (machine (init exemple1));;


let e = Binop(Add,Const (Int 2),Const (Int 3));;
let c = compil e;;
print_instrs(c);;

let e = Binop(Add,Binop(Add,Const (Int 1),Const (Int 2)),Const (Int 3));;
let c = compil e;;
print_instrs(c);;

get_acc (machine (init (Array.of_list c)));;

let e = If(Binop(Eq,Const(Int 4),Const(Int 5)),Binop(Add,Const(Int 2),Const(Int 3)),Binop(Add,Const(Int 6),Const(Int 7)));;
let c = compil e;;
print_instrs(c);;

get_acc (machine (init (Array.of_list c)));;
