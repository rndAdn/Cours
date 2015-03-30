type t = A | B of int | C | D | E of t | F of t * t | G | H of int
let x = D;;
print_string("--------------------------");;
let x = D in let y = G in let z = y in x ;
