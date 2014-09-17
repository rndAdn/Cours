[SY5]


Wieslas Zielonka<br>
zielonka@liafa.univ-paris-diderot.fr<br>
www.liafa.univ-paris-diderot.fr/~zielonka





# Introduction
## Plan du cours
1. Interaction avec le système de fichiers
1. Processus
1. Communication avec les tubes

## Language et norme
On utilisera le language C dans la norme POSIX et des commandes UNIX

# Rappel de C
## Pointeur
```
int *p-int; //Pointeur
double *p-d;
int x = 5; // Variable
double d = -3,14;
p-int = &x; //Prise d'adresse.
p-d = &d;
int k;
k = *p-int + 5;
*p-int = k + 3;
```
## Tableau et arithmétique de pointeurs
```
int tab[] = {-3,6,8,12,-7,2};
double td[] = {-3,14,-0.1,-7,12,-8.0,2.43};
```
Table
-3  | 6 | 8 | 12 | -7 | 2  


Graph

<dot>
digraph a {
    graph [rankdir=LR]
    0 -> 1 [label="b"]
    0 [color=blue]
}
</dot>


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