[TOC]

# Titre 1
???Surligné???
**Gras**
*italique*

<dot>
digraph a {
    graph [rankdir=LR]
    0 -> 1 -> 4 -> 3 -> 2 -> 0 [label="b"]
    0 -> 2 [style=bold,label="a"]
    1 -> 2 [label="c"]
    2 -> 3 [label="d"]
    3 -> 0 [label="e"]
    4 -> 4

    0 [color=blue]
    4 [color=red]
}
</dot>

Math
$$\sqrt{2} \sin x$$,

Code

    public static void main(String[] args){
        System.out.println("Hello");
    }


Liste
1. a
1. b
1. c


* a
* b
* c

# Titre 2


## Sous-titre 1

Table

First Header  | Second Header
------------- | -------------
Content Cell  | Content Cell
Content Cell  | Content Cell

Définition
Apple
:   Pomaceous fruit of plants of the genus Malus in
    the family Rosaceae.

Orange
:   The fruit of an evergreen tree of the genus Citrus.
