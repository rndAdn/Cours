let carre x = x*x;;
carre 5;;

let perimetre r = 2.0 *. 3.14159267 *. r;;
perimetre 10.0;;

let bis ch = ch^ch;;
bis "ab";;

let huitfois ch = bis(bis(bis(ch)));;
huitfois "ab";;

let est_nul i = i = 0;;
est_nul 0;;

let msg_nul i = if i = 0 then "nul" else "non nul";;
msg_nul 0;;

max "a" "b";;
max "ab" "a";;
max 1 2;;
max 1.1 1.2;;

let mmax x y = if x>y then x else y;;

let max_triple x y z = let tmp =  mmax x y  in mmax tmp z;; (* pas de let mmax(mmax(xy) z) *)
max_triple 1 2 3;;

let max_quadruple x y z r = let tmp =  mmax x y and tmp2 = mmax z r  in mmax tmp tmp2;;
max_quadruple 1 2 3 1;;

let rec sum n = if n <= 0 then 0 else n + sum(n-1);;
sum 10;;
