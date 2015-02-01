[TOC]
# Code
## Introduction
* $$\text{A} $$ Alphabet fini
* $$\text{A}^* $$ Ensemble des mots sur $$\text{A} $$
* $$\text{w} $$:
    * le mot vide $$\epsilon$$
    * $$w  = a_{1}...a_{n}$$ avec $$a_{1}...a_{n} \in \text{A}$$
* $$\mid w\mid = m$$ longueur de $$w$$
* $$\mid \epsilon\mid = 0$$
* $$u \in \text{A}^*, v \in \text{A}^*$$
    * $$u  = a_{1}...a_{l}$$ et $$v  = b_{1}...b_{k}$$
    * $$u.v = a_{1}...a_{l}.b_{1}...b_{k}$$ **concatenation**
* on as $$u.\epsilon = u = \epsilon .u$$
* $$u,v,t \in \text{A}^*$$
    * $$(u.v).t = u.(v.t)$$
* $$\text{A}^* = \text{A}^*\setminus \{\epsilon\}$$


###Code

$$\text{A} = \{a,b,c,d,e\}$$

$$\text{B} = \{0,1\}$$

Codage : $$\Phi : \text{A} \to \text{B}^{+}$$<br>
$$\Phi : a \to 00$$<br>
$$\Phi : b \to 01$$<br>
$$\Phi : c \to 10$$<br>
$$\Phi : d \to 110$$<br>
$$\Phi : e \to 111$$

$$\Phi (abca) = \Phi (a)\Phi (b)\Phi (c)\Phi (a)$$

#### Remarque

On a :

* $$\Phi(u,v) = \Phi(u).\Phi(v)$$
* $$\Phi(\epsilon) = \epsilon$$

$$\Phi (abca) = 00 01 10 00$$

### Question
$$\Phi^{-1}$$ Bien definie ?

$$  \Phi^{-1}(00 01 10 00) = abca$$ est bien definie (**injective**)

### Definition :
$$\Phi$$ est une fonction de codage **si** $$\Phi$$ est **injective**

($$ \Phi : \text{A} \to \text{B}^{+}$$ etendu à $$ \text{A}$$)

Soit $$ \text{G} = \Phi(\text{A})$$ (ensemble de mot):

$$ \text{C} = \{00, 01, 10, 110, 111\}$$
$$\text{G}$$ est un code **si et seulement si** tout mot de $$\text{C}^{+}$$ a une décomposition unique en mot de $$\text{G}$$.

$$\text{G}$$ est un code **si et seulement si** pour tout mot de $$u \in \text{G}^{+}$$:

* si $$u=u_{1}...u_{m}$$ avec $$u_{1}...u_{m} \in \text{G}$$
* et $$u=u'_{1}...u'_{k}$$ avec $$u'_{1}...u'_{k} \in \text{G}$$
* alors $$ m = k$$ et $$u_{1} = u'_{1}$$  ... $$u_{k} = u'_{k}$$


$$Soit \text{G} = \{00, 01, 10, 110, 111\}$$ est un code.

Supposons que $$u_{1}...u_{k} = u'_{1}...u'_{m}$$

$$u_{1}...u_{k} \in \text{G}$$<br>
$$u'_{1}...u'_{m} \in \text{G}$$

En plus avec $$k$$ minimal

$$u_{1}...u_{k} = u'_{1}...u'_{m}$$
si $$u_{1} = 00$$ alors $$u'_{1} = 00$$
$$u_{2}...u_{k} = u'_{2}...u'_{m}$$

Contredit minimalité de k.

## Ensemble préfix

$$ \text{E}$$ est un préfix:

* Si $$u \in \text{E}$$ et $$ u.v \in  \text{E}$$
* Alors $$v = \epsilon$$

Aucun mot de $$\text{E}$$ n'est le préfix d'un autre mot de $$\text{E}$$

### Proposition
Si $$\text{E}$$ est un préfix alors $$\text{E}$$ est un code.

* $$x \in \text{E}, u \in \text{E}^{*}$$
* $$y \in \text{E}, v \in \text{E}^{*}$$

$$x.u = y.v$$ alors $$x = y$$

### Exercice :
Trouver un code qui n'est ni préfix ni suffix.

_**Préfix**_: sur $$\{0, 1\}$$


<dot>
digraph a {
    r -> 0
    r -> 1
    0 -> 00
    0 -> 01
    1 -> 10
    1 -> 11
    11 -> 110
    11 -> 111

    0 [label="0"]
    1 [label="1"]
    00 [label="0"]
    01 [label="1"]
    10 [label="0"]
    11 [label="1"]
    110 [label="0"]
    111 [label="1"]

}
</dot>

$$\Phi$$ : Codage de taille fixe

$$\forall a, a' \in \text{A} \mid \Phi(a)\mid = \mid \Phi(a')\mid$$

$$\text{G}$$ code $$\forall w, w' \in text{G} \mid w\mid = \mid w'\mid$$


# Code correcteurs d'erreur
## Généralité

On considère uniquement des codes binaires à longueur fixe

$$\{0, 1\}$$ la longeur l

$$m$$ un mot : $$<u_{1},_,u_{e}> u{i} \in \{0,1\}$$

vecteur sur $$\langle \mathbb{Z}/  2 \mathbb{Z} \rangle^{l} $$

$$\langle \mathbb{Z}/  2 \mathbb{Z} \rangle
$$

$$\left\{
  \begin{array}{rcrcr}
    0 + 0 & = & 0 \\
    0 + 1 & = & 1 & = & 1 + 0 \\
    1 + 1 & = & 0 \\
  \end{array}
\right.$$



espace vectoriel $$\langle \mathbb{Z}/  2 \mathbb{Z} \rangle^{l}
$$

$$<u_{1},...,u_{l}>+<u'_{1},...,u'_{l}> = <u_{1}+u'_{1},...,u_{l}+u'_{l}>$$

$$<00010>+<11010> = <11000>$$

$$<u> + <v> = \vec{0}$$<br>
$$0 . <u> = \vec{0}$$<br>
$$1 . <u> = <u>$$

##Distance de Hamming

$$a,b \in \langle \mathbb{Z}/  2 \mathbb{Z} \rangle
$$

$$d(a,b) = 0$$ si $$a = b$$<br>
$$d(a,b) = 1$$ sinon<br>
$$d(<u_{1},...,u_{l}>, <u'_{1},...,u'_{l}> = <u_{1}+u'_{1},...,u_{l}+u'_{l}>) = \sum\limits_{i=1}^l d(u_{i}+u'_{i})$$

$$ u = 00001110$$<br>
$$ v = 01011010$$<br>
$$ d(u,v) = 3$$

###Remarque :
* $$d$$ est une distance
* $$ d(u,u) = 0$$
* $$ d(u,v) = d(v, u)$$
* $$ d(u,u) \leq d(u,x) + d(x,v)$$
* $$ d(u+x,v+x) = d(u, v)$$


<dot>
digraph a {
    graph [rankdir=LR]
    m -> e [label="canal"]
    Emeteur -> recepteur [label="canal"]
    m [label="m = <0111>"]
    e [label="m+e"]
}
</dot>

ou $$e$$ est l'erreur

Le canal peur inverser 1 bit ou plus<br>
$$e = \langle0,0,0,0\rangle$$<br>
$$e = \langle1,0,0,0\rangle$$<br>
$$e = \langle0,1,0,0\rangle$$<br>
$$e = \langle0,0,1,0\rangle$$<br>
$$e = \langle0,0,0,1\rangle$$<br>

$$\text{G}$$ un ensemble (de vecteur)
$$d(\text{G}) = \text{min}\  \text{d}(x,y)$$
$$x,y \in \text{G} x \ne y$$

$$\text{C} = <0001, 1100, 1001>  d(\text{C})  = 1$$


Corriger des erreur ?

recu $$m' = m+e$$

à partir de $$m'$$ (avec des info sur $$e$$)<br>
Trouver $$m$$
