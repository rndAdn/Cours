let code_lettre c  = match c with
|'A'|'E'|'H'|'I'|'O'|'U'|'W'|'Y' ->""
|'B'|'P'->"1"
|'C'|'K'|'P'->"2"
|'D'|'T'->"3"
|'L'->"4"
|'M'|'N'->"5"
|'R'->"6"
|'G'|'J'->"7"
|'X'|'Z'|'S'->"8"
|'F'|'V'->"9";;

let pad s =
let rec aux s1 result = match String.length s1 with
|0 -> result
|a -> let res = result^(code_lettre (s1.[0])) in aux (String.sub s1 1 (a-1)) res in
let res = aux (String.sub s 1 (String.length s -1)) (Char.escaped(s.[0])) in
if(String.length res >= 4) then res
else (String.sub (res^"0"^"0"^"0"^"0") 0 4);;

pad "ST";;
