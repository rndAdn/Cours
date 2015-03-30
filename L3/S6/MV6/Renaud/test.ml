let rec add n = (if n == 0 then 0 else n + (add (n-1)))


let a = add 100

a
