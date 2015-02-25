type 'a arbre =
| Feuille of 'a
| Noeud of ('a * 'a arbre * 'a arbre)
| NoeudG of ('a * 'a arbre)
| NoeudD of ('a * 'a arbre);;

let rec taille = function
| Feuille(_) -> 1
| Noeud(_,g,d) -> 1 + (taille g) + (taille d)
| NoeudG(_,g) -> 1 + (taille g)
| NoeudD(_,d) -> 1 + (taille d) ;;

let valeur = function
| Feuille(a) -> a
| Noeud(a,_,_) -> a
| NoeudG(a,_) -> a
| NoeudD(a,_) -> a ;;


let rec tas = function
| Feuille(_)-> true
| Noeud(e,g,d) -> if e >= (valeur g) + (valeur d) then (tas g && tas d) else false
| NoeudG(e,g) -> if e >= (valeur g) then tas g else false
| NoeudD(e,d) -> false ;;
let c x = x*x;;
