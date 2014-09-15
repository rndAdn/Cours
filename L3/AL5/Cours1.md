Cours 1 Sophie Laplante 15/09/14

#Algo

Problème
: Spécification qui associe aux données d'entrée le comportement de sortie.
*Ex : Une matrice de distance, Un point de départ et un point d'arrivé **ENTRÉE**. Quelle est la **distance** entre le point de départ et le point d'arrivée **SORTIE***



<dot>
digraph a {
    graph [rankdir=LR]
    e [label="Entrée"]
    s [label="Sortie"]


    e -> s  
}
</dot>


Structure de données : Une stratégie structurée pour ranger et accéder aux informations.

Algo
: Résoud un problèmesouvent lié à une structure de données.

Programme
: Implémentation de l'algo et des structure de données.

Compléxité
: Mesure théorique de la performance en fonction de la taille des données.

Graph
: Ensemble de points *Sommets* *Ex : des pixels, stations de metro* avec une notion d'adjacence

Union Fsind
: _Entrée_ : un ensemble de points. une relation d'équivalence deux opérations:

**FIND**
: Étant donnés *u*, *v* dire s'il sont équivalents

**UNION**
: Étant donnés 2 points les mettre en relation.
