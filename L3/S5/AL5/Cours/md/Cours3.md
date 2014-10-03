Cours 3 Sophie Laplante 29/09/14

[TOC]

```
def root(u):
    while Pere[u] != u:
        u = Pere[u]
    return u
```

<dot>
    digraph a {
        2 -> 5
        1 -> 5
        12 -> 2
        3 -> 2
        25 -> 2
        10 -> 25
        11 -> 25
    }
</dot>

Ex: root(11)

<dot>
    digraph a {
        2 -> 5
        1 -> 5
        12 -> 2
        3 -> 2
        25 -> 2
        10 -> 25
        11 -> 25
        11-> 5 [color="red"]
        25 -> 5 [color="red"]
    }
</dot>

```
def root2(u):
    while Pere[u] != u:
        Pere[u] = root2(Pere[u])
    return Pere[u]

```

# Compléxité et correction d'un algo

## _Étude de cas_: ABR

### Notations
Étant donné un algo ```A```
```count_A(x) = # étapes élémentaires``` effectu"es lorsqu'on lance ```A``` sur un donnée ```x```
```cout_A(n) = max{cout_A(x) : x de taille n}```




Coût moye que prend A sur un x trié au hasard parmi les x de taille n.
C'est pour obtenir une notion de coût qui est moins sensible aux cas extrêmes.

Ex: Tri rapide :
    x tableau déja trié : O(n) comparaison.
    En moyenne :    O(n*log(n))
    x tableau trié dans l'ordre inverse : O(n²)

## Les ABR:
Definition  des ABR sert à:
1. Consevoir l'algo
2. prouver sa complexité
3. démontrer la correction

#### Définition
1 .Un ABR ```A``` est soit
* Un arbre vide
* Une racine ```A``` avec 2 sous-arbres ```A.droite``` et ```A.gauche```

<dot>
    digraph a {
        2 -> 1
        3 -> 1

        1 [label="A"]
        2 [label="A.droite"]
        3 [label="A.gauche"]


    }
</dot>

2. Un arbre binaire _étiquetté_ a des valeurs à chaque noeud ```A.val```

3. **La propriété ABR**
Pour chaque noeud d'un ABR, ```A```
* ```A.val``` > v Pour toute valeur v dans ```A.gauche```
???**ET**???
* ```A.val``` < v Pour toute valeur v dans ```A.droite```

On suppose toutes les valeurs distinctes

<dot>
    digraph a {
        2 -> 1
        3 -> 1

        1 [label="A"]
        2 [label=">"]
        3 [label="<"]


    }
</dot>

Pour l'implémentation des ABR: (*Python*)
Une classe avec 3 attributs

```
A.val
A.gauche # ABR à gauche
A.droite # ABR à droite
```

```
def trouver_ABR(A, v):

    if A.val == c:
        return A
    if A.val > v:
        return trouver_ABR(A.gauche, v) if A.gauche else None
    if A.val < v:
        return trouver_ABR(A.droite, v) if A.droite else None
```

####On va montrer
Prop 1 L'algo est correct
Preuve Prop 1 : 
