type joueur =
  |Croix
  |Rond;;

type pion =
  |Joueur of joueur
  |Vide;;

type ligne = pion * pion * pion;;

type grille = ligne * ligne * ligne;;

let affichePion p = match p with
  |Vide -> print_string "   "
  |Joueur(Croix) -> print_string " X "
  |Joueur(Rond) -> print_string " O ";;

let affichageLigne l = match l with
  |(p1,p2,p3) -> print_string "|";affichePion p1;print_string "|";
  affichePion p2;print_string "|";affichePion p3;print_string "|";
  print_endline "";;

let afficherGrille g = match g with
  |(l1,l2,l3)->print_string "    a   b   c ";print_endline "";
               print_string "  +---+---+---+";print_endline "";
               print_string "1 ";affichageLigne l1;
               print_string "  +---+---+---+";print_endline "";
               print_string "2 ";affichageLigne l2;
               print_string "  +---+---+---+";print_endline "";
               print_string "3 "; affichageLigne l3;
               print_string "  +---+---+---+";print_endline "";;

let init () = ((Vide,Vide,Vide),(Vide,Vide,Vide),(Vide,Vide,Vide));;

let g = init ();;
afficherGrille g;;

exception MoveForbidden ;;
exception NoMoreMove ;;

let move (i,c) (l1,l2,l3) j =
  let p = Joueur(j) in
  let aux c l p = match c,l with
      |'a',(Vide,p2,p3)->(p,p2,p3)
      |'b',(p1,Vide,p3)->(p1,p,p3)
      |'c',(p1,p2,Vide)->(p1,p2,p)
      |_->raise MoveForbidden
  in  match i with
      |1->(aux c l1 p,l2,l3)
      |2->(l1,aux c l2 p,l3)
      |3->(l1,l2,aux c l3 p)
      |_->raise MoveForbidden;;

let g = move (2,'a') g Rond;;
afficherGrille g;;

let aVide ((p11,p21,p31),(p12,p22,p32),(p13,p23,p33)) =
    p11 = Vide || p21 = Vide|| p31 = Vide||
    p12 = Vide || p22 = Vide|| p32 = Vide||
    p13 = Vide || p23 = Vide|| p33 = Vide;;
