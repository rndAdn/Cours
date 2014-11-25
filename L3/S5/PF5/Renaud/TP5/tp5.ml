type joueur = Croix | Rond;;
type pion = Joueur of joueur | Vide;;
type ligne = pion * pion * pion;;
type grille = ligne * ligne * ligne;;



let init =
let r = Vide in
    let l = (r,r,r) in
        (l,l,l);;


let affichePion p = match p with
| Joueur(Croix) -> print_string "X"
| Joueur(Rond) -> print_string "O"
| Vide -> print_string " ";;

let afficheLigne l = match l with
| (a,b,c) -> print_string "| ";affichePion a; print_string " | ";
            affichePion b; print_string " | ";
            affichePion c; print_string " | "; print_newline ();;


let afficheGrille gr = match gr with
|(l1,l2,l3) -> (print_string "\n     a   b   c\n   +---+---+---+\n1  ";afficheLigne l1; print_string "   +---+---+---+\n2  ";
                afficheLigne l2; print_string "   +---+---+---+\n3  ";
                afficheLigne l3; print_string "   +---+---+---+\n";);;


exception MoveForbidden;;
exception NoMoreMove;;

let move (l,c) g j =
    let f l = match l with
        | 1 -> 1
        | 2 -> 2
        | 3 -> 3
        | _ -> raise MoveForbidden
    in let u c = match c with
        | 'a' -> 'a'
        | 'b' -> 'b'
        | 'c' -> 'c'
        | _ -> raise MoveForbidden
    in let t g (l,c)= match g[l][c] with
        | Vide -> ()
        | _ -> raise MoveForbidden
    in let _ = g[(f l)][(u c)] = j;;

(*TEST*)

let g = init;;

afficheGrille g;;
