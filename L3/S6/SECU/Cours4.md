[TOC]


# Codes linéaires

* $$ \text{C} $$ s.e.v $$ (\mathbb{Z}/2 \mathbb{Z})^{n}$$
* Dualité $$ \text{C}^{\perp} = \{ u \in (\mathbb{Z}/2 \mathbb{Z})^{n} | \forall v \in \text{C} u.v = \vec{0}\}$$
* $$ \text{dim(C)} + \text{dim(C)}^{\perp} = n $$


$$
u \in \text{C} ^{\perp} \Longleftrightarrow \forall v \in \text{C}$$ $$ u.v = 0
$$


# Matrice de code linéaire

On peut représenter code $$ \text{V} $$ **_(s.e.v)_** comme une matrice : matrice de la base du code $$ \text{C} $$ <br>
si $$ \text{dim C} = k $$

$$
\begin{pmatrix}
 b_{1}\\
 \vdots\\
 b_{k}\\
\end{pmatrix}
$$

vecteur d'une base de $$ \text{C} $$<br>

$$  
\bordermatrix{& \longleftarrow & n & \longrightarrow\cr
    \uparrow & & &\cr
    k & & &\cr
    \downarrow & & &
    }
$$


$$ u \in \text{C} \Longleftrightarrow \exists l_{1}, \cdots, l_{k} | u= l_{1}b{1}, \cdots, l_{k}b_{k}  $$


* Message m
* erreur e
* reçu r

## Forme reduite:
$$ (\text{I}_{k} | \text{A}) = \mathbb{M}_{R}  $$

### Regles :

* permuter des lignes
* remplacer des ligne par des combinaisons linéaire
* multiplier par une constante
* permuter des colonne

$$ \Longrightarrow $$ **matrice equivalente**

### Codage systematique

$$(x_{1},\cdots, c_{k}) \sim  (x_{1},\cdots, c_{k}).\mathbb{M}_{R} = (x_{1},\cdots, c_{k}).(\text{I}_{k} | \text{A}) = (x_{1},\cdots, c_{k}, (x_{1},\cdots, c_{k}).\text{A})$$

$$ (x_{1},\cdots, c_{k}).\text{C}_{\text{R}} = (x_{1},x_{2},x_{3},x_{1}+x_{2}+x_{3},x_{1}+x_{3},x_{2}+x_{3}) $$<br>
$$ <u, p(u)> $$
$$ u $$ mot a coder
$$ p(u) $$ bits de contrôle

$$
\text{C}_{\text{R}} = \bordermatrix{~ \cr
    c_{1} + c_{2} & 1 & 0 & 0 & 1 & 1 & 0  \cr
    c_{1} & 0 & 1 & 0 & 1 & 0 & 1  \cr
    c_{4} & 0 & 0 & 1 & 1 & 1 & 1
}
$$

### Exemple
$$ \text{C'} $$ engendré par:


$$
\bordermatrix{~ \cr
    a & 1 & 1 & 1 & 1   \cr
    b & 1 & 0 & 1 & 0   \cr
    c & 0 & 1 & 0 & 1  \cr
    d & 1 & 1 & 0 & 0
}
$$


$$
\bordermatrix{~ \cr
    a & 1 & 1 & 1 & 0 & 1   \cr
    a + b & 0 & 1 & 0 & 1 & 1   \cr
    d+a & 0 & 0 & 1 & 1 & 1 \cr
    a+b+c & 0 & 0 & 0 & 0 & 0
}
$$

**reduite** $$ \Longrightarrow $$
$$
\left(
    \begin{array}{ccc|cc}
    1 & 0 & 0 & 0 & 1 \\
    0 & 1 & 0 & 1 & 0 \\
    0 & 0 & 1 & 1 & 1 \\
    \end{array}
\right)
$$

$$ \text{G} = $$ ($$ \text{C} $$ engendré par $$ \text{G} $$) = $$ (Id_{k} | \text{A}) $$<br>
Alors $$ \text{H} = (\text{A}^{t}.\text{Id}_{n-k})$$ alors $$ \text{H}^{t} $$ engendre $$ \text{C}^{\perp} $$


$$ \text{H}.\text{G} = (\text{A}^{t}.\text{Id}_{n-k}) (Id_{k} \text{A}^{t}) = (\text{A}^{t}+\text{A}^{t}) = (0)$$

$$
\text{G} =
\left(
    \begin{array}{ccc|cc}
    1 & 0 & 0 & 0 & 1 \\
    0 & 1 & 0 & 1 & 0 \\
    0 & 0 & 1 & 1 & 1 \\
    \end{array}
\right)
$$
$$
\text{H} =
\left(
    \begin{array}{ccc|cc}
    0 & 1 & 1 & 1 & 0 \\
    1 & 1 & 1 & 0 & 1 \\
    \end{array}
\right)
$$
Tout vecteur de $$ \text{H} est orthogonal à tout vecteur de \text{G}.\text{H}^{t}$$ est une matrice de $$\text{C}^{\perp}$$<br>
$$ \text{H}^{t} $$ est une base de l'othogonal de $$ \text{C} $$ <br>
$$ c \in \text{C} \Longleftrightarrow (c) \text{H}.\vec{0} $$



### Exemple


$$ u = 10111 $$ $$ u \in \text{C}$$?

$$ (10111).
\begin{pmatrix}
    0 & 1\\
    1 & 1\\
    1 & 1\\
    1 & 0\\
    0 & 1\\
\end{pmatrix}
 = (0,1)$$

 donc $$u \notin \text{C}$$

 $$ v = 11101 $$ $$ v \in \text{C}$$?

 $$ (11101).
 \begin{pmatrix}
     0 & 1\\
     1 & 1\\
     1 & 1\\
     1 & 0\\
     0 & 1\\
 \end{pmatrix}
  = (0,0)$$

  donc $$v \in \text{C}$$


$$ \text{H}^{t} $$ est une base de l'orthogonal de $$ \text{C} $$

    On a donc :
$$ c \in \text{C} \Longleftrightarrow c.\text{H}^{t} = \vec{0}$$
































# Code cyclique

$$ \text{F} = \mathbb{Z}/2 \mathbb{Z}$$
$$ \text{F}^{n} = (\mathbb{Z}/2 \mathbb{Z})^{n}$$

$$ \text{F}^{n} \longrightarrow \text{F}^{n}$$

Décalage $$ \text{S} : (x_{0},\cdots, x_{n-1}) \longrightarrow (x_{n-1}, x_{0}, x_{1},\cdots, x_{n-2})$$

## Définition

$$ \text{C} $$ est un code cyclique $$\Longleftrightarrow \text{C} $$ est un code linéaire invariant par décalage $$( \text{C} = s(\text{C}) )$$

**exemple:** $$\text{C} = (000),(110),(011),(101) $$
$$ \text{C} $$ est un cycle


$$ \prod :(a_{0}, \cdots, a_{n-1}) \sim a_{0}+ a_{1}\text{X}+ \cdots+ a_{n-1}\text{X}^{n-1}$$

$$ \prod :(a_{0}, \cdots, a_{n-1})$$ le polynome de $$\text{F} [\text{X}/(\text{X}^{n}-1)]$$

##Remarque

dans $$\text{F} [\text{X}/(\text{X}^{n}-1)]$$ le décalage correspond au produit par $$ \text{X} $$.

$$ \text{P}(\text{X}) = a_{0}+,\cdots+a_{n-1}.\text{X}^{n-1} $$

$$  $$


$$
\left\{ \begin{array}{lr}
    \text{X}.\text{P}(\text{X}) = a_{0}.\text{X}+,\cdots+a_{n-1}.\text{X}^{n} \\
    \text{X}.\text{P}(\text{X}) = a_{n-1}+a_{0}.\text{X}+,\cdots+a_{n-2}.\text{X}^{n-1} (\text{mod}[\text{X}^{n}-1])\\
    \text{X}.\text{P}(\text{X}) = \text{S}(\text{p}(\text{X})) & (\text{mod}[\text{X}^{n}-1])\\
    \text{X}.\text{P}(\text{X}) = \prod (\text{S}(\prod ^{-1}(\text{p}))) & (\text{mod}[\text{X}^{n}-1])\\
   \end{array}
\right.
 $$

### Exemple:

$$ \prod (\text{C}) = (0, 1+x, x+x^{2}, 1+x^{2}) $$


$$
\begin{array}{lc}
     & (0, 110, 011, 101) \\
    \prod (\text{C}) = & (0, 1+x, x+x^{2}, 1+x^{2})\\
\end{array}.
 $$


##Remarque
 $$\text{F} [\text{X}/(\text{X}^{n}-1)]$$ est un anneau sur  $$ \text{A} $$


##Ideal
 $$ \text{I} $$ est un **Idéal** $$ \Longleftrightarrow $$

* $$ 0 \in \text{I} $$  
* $$ \forall a,b \in \text{I} \Longrightarrow a\pm b \in \text{I}$$
* $$ \forall r \in \text{A}  $$ et $$ \forall a \in \text{I} \Longrightarrow a.r \in \text{I} $$


$$ \mathbb{Z}  $$ les idéaux de $$ \mathbb{Z}  $$ sont les $$ n \mathbb{Z}  $$<br>
$$ n \mathbb{Z} = \{ p.n | p \in \mathbb{Z} \}  $$


Idéal est ***principal*** $$ \Longleftrightarrow \exists g \in \text{I}$$ tq $$ \text{I} = <g> = \{ g.x | x \in \text{A}\} $$

## Théoreme 1

Dans $$\text{F} [\text{X}/(\text{X}^{n}-1)]$$ tout idéal est principal


## Théoreme 2
$$ \text{C} $$ est un code cyclique $$ \Longleftrightarrow \prod(\text{C}) $$ est principal
