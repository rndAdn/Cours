let carree x = x * x;;
let perimetre r = let pie = 3.14159267 in (2.*r.*pie) ;;
let bis r = r^r ;;
let huit_fois r = let p = r^r in let g = p^p in g^g;;
let huit_fois r = bis(bis(bis(r)));;

let est_nul r = r = 0;;
let msg_nul r = if est_nul r then "nul" else "non nul";;
let my_max  a b = if a>b then a else b;;
let max_triple x y z = let m = max x y in max m z ;;
let max_quadruple w x y z = let m1 = max w x and m2 = max y z in max m1 m2;;

let rec sum n = if n < 1 then 0 else n+sum(n-1);;
let rec fibo n = if n < 1 then 0 else if n == 1 then 1 else fibo(n-1)+fibo(n-2);;
let rec ack m n  = if m = 0 then n+1 else if n = 0 then ack (m-1) 1 else let v = ack m (n-1) in ack (m-1) v;;

let vider n = let rec empA n = if n < 1 then 0 else empB(n-1) +1 and empB n = if n < 1 then 0 else if n mod 2 = 0 then empA(n-2)+1 else empA(n-1)+1 in empA(n);;

let x = 2;;
let x = 3
in lety=x+1 in x + y;;
let x = 3 and y = x + 1 in x+y;;
