# Rappel
## Code correcteur d'erreur
$$u = <u_{1}, \cdots, u_{m}>$$ vecteur sur $$\mathbb{Z}/  2 \mathbb{Z}$$

$$v = <v_{1}, \cdots, v_{m}>$$ $$ u_{i} \in \{0,1\}  v_{i} \in \{0,1\}$$


$$d_{\text{H}}(u,v)$$ distance de Hamming
$$ \sum\limits_{i=1}^{n} d(u_{i}, v_{i})$$ où $$ d(0,0)=d(1,1) = 0$$ et $$d(0,1)=d(1,0) = 0$$


$$\text{code} \leq (\mathbb{Z}/2 \mathbb{Z})^{4}$$

Ensemble de vecteur

$$u = 011011 $$
$$v = 011000 $$
$$d(u, v) = 2$$

$$c$$ mot  émis $$c \in \text{C}$$
$$x$$ reçu $$x+e$$ où $$e$$ est l'erreur
si $$e$$ inverse le 2e bit $$e= 010000$$
$$u$$ émis reçu $$u+e = 001011$$

$$\text{C}$$ un code

* détection d'une erreur (ou plusieurs)

$$
\begin{array}{cr}
    <0,0,0,0,0> & \\
    <1,0,0,0,0> & \\
    <0,1,0,0,0> & \\
    <0,0,1,0,0> & \\
    <0,0,0,1,0> & \\
    <0,0,0,0,1> & \\
  \end{array}
  $$
Vecteurs correspondant a une erreur


$$c$$ émis $$x$$ reçu $$x+e$$ pouvoir distinguer entre $$x$$ et $$u$$ pour $$ u \in text{code}$$


# Condition pour détecter une erreur
(sur les mots de c)
$$\forall u,v \in  \text{C} u \neq v, d(u, v) > 1$$

$$u <0111> \in \text{C}$$<br>
$$v <1111> \in \text{C}$$ <br>
si on a reçu $$<1111>$$<br>
$$u$$ avec une erreur ou $$v$$?

## Poids

$$p(u) = d(u,\vec{0})$$<br>
$$d(\text{C}) = \text{min}(u,v) u,v \in \text{C} u \neq v$$

$$ x = c + e $$ où $$ e \in \text{E} $$<br>
$$ d(x, c) = d(e, \vec{0}) = p(e) $$<br>
$$ d(\text{C}) = 1 $$ alors il existe $$ u,v \in \text{C} $$<br>
$$ u+e = v $$ avec $$ p(e) = 1$$ <br>
$$ u+e$$ et $$v $$ indistingables

Réciproquement si $$ d(\text{C}) \geq 2 $$<br>
$$c,c' \in \text{C}$$ $$ c\neq c'$$ $$d(c, c') \geq 2$$<br>

$$ x $$ reçu tel que $$ x = u+e $$ avec $$ p(e) = 1 $$   et $$ u \in \text{C} $$<br>
il n'existe aucun $$ v \in \text{C} $$  tel que $$x \in \text{C}$$ **on peut donc détecter l'erreur $$e$$**

###Théoreme:
$$\text{C}$$ un code,<br>
si $$ d(\text{C})= d $$ alors on peut corriger des erreurs de poids $$  p \leq {d-1 \over2}$$


$$d(\text{C}) \geq 2.v +1$$ alors on peut corriger des erreurs de poids  $$ \leq v$$



## Corriger des erreur de poids p
Ayant reçu $$ x = c + e $$  avec $$ p(e) \leq p $$ et $$ c \in \text{C} $$<br>
On peut retrouver $$ c $$ à partir de $$ x $$


si $$ d(\text{C}) \geq 2.v + 1 $$ on peut corriger des erreurs de poids au plus $$ v $$

Soit $$ c \in \text{C} $$ émis et $$ x $$ reçu <br>
$$ x = c + e $$ avec $$ p(e) \leq v $$<br>
on a $$ d(x, c) \leq v$$  <br>
???Soit $$ c' $$ un element quelconque def de $$ c $$ avec $$ c' \in \text{C} $$  ???<br>
(on a $$ d(c, c') \geq 2.v+1 $$ )<br>
$$ d(c,c') \leq d(c,x) + d(x, c') $$ <br>
$$ d(x,c') \geq d(c,c') - d(c,x) $$ <br>
$$ 2.v+1 -v \geq v+1 > d(x, c) $$

**Reciproquement**:
Sinon $$ (\neg(d(\text{C}) \geq d.v+1)) $$ <br>
$$ d(\text{C}) \leq 2.v $$ <br>
il existe $$ c,c' $$ tel que $$ d(c, c') \leq 2.v $$<br>
il existe $$ e_{1},e_{2} $$ tel que $$ p(e_{1}) \leq v $$ et $$ p(e_{2}) \leq v $$


$$ u_{1} = 000 $$ $$ u_{2} = 101 $$ <br>
$$ u_{3} = 011 $$ $$ u_{4} = 110 $$<br>
$$()\mathbb{Z}/  2 \mathbb{Z})^{3}  <u_{1},u_{2},u_{3}>$$

$$ d(\text{C}) = 2 $$ il faudrait $$ d(\text{C}) = 3 $$ pour pouvoir corriger des erreurs


$$
\left|\begin{matrix}
0 & 0 & 0 & 0 & 0 & 0 \\
0 & 1 & 0 & 1 & 0 & 1 \\
1 & 1 & 0 & 0 & 1 & 1 \\
1 & 0 & 0 & 1 & 1 & 0 \\
0 & 0 & 1 & 1 & 1 & 1 \\
0 & 1 & 1 & 0 & 1 & 0 \\
1 & 1 & 1 & 1 & 0 & 0 \\
1&0 & 1 & 0 & 0 & 1 \\
\end{matrix}
\right|
$$

$$n = 6$$ <br>
$$ |\text{C}|  = 8 $$ <br>
$$ d(\text{C})  = 3$$<br>

Taux d'un code : $$ {\text{log}(|c|) \over n} = 1/2 $$

On peut corriger une erreur

# Codes linéaires

## def
$$ \text{C} $$ est un code linéaire si $$\text{C}$$ est un sous-espace vectoriel de $$\mathbb{Z}/  2 \mathbb{Z}$$

s.e.v:

$$ u,u'  \in \text{C}  u+u' \in \text{C}$$ <br>
$$\lambda \in \mathbb{Z}/  2 \mathbb{Z}$$, $$ u  \in \text{C}$$ $$ \lambda . u \in \text{C}$$<br>
$$ \vec{0} \in \text{C}$$

###Remarque
$$ \text{C} $$  s.e.v <br>
$$ c,c' \in  \text{C} d(c,c') = d(c+c', \vec{0}) = p(c+c')$$ <br>
On en deduit : $$ d(\text{C}) = \text{min} p(c) $$ avec $$ c \in \text{C} $$ et $$ c \neq \vec{0} $$

$$
\bordermatrix{~ \cr
                  c_{0} & 0 & 0 & 0 & 0 & 0 & 0  \cr
                  c_{1} & 0 & 1 & 0 & 1 & 0 & 1  \cr
                  c_{2} & 1 & 1 & 0 & 0 & 1 & 1  \cr
                  c_{3} & 1 & 0 & 0 & 1 & 1 & 0  \cr
                  c_{4} & 0 & 0 & 1 & 1 & 1 & 1  \cr
                  c_{5} & 0 & 1 & 1 & 0 & 1 & 0  \cr
                  c_{6} & 1 & 1 & 1 & 1 & 0 & 0  \cr
                  c_{7} & 1&0 & 1 & 0 & 0 & 1  \cr
                  }
$$

$$
\begin{matrix}
c_{1} & c_{2} & = & c_{3} \\
c_{1} & c_{3} & = & c_{2} \\
c_{2} & c_{3} & = & c_{1} \\
c_{1} & c_{4} & = & c_{5} \\
c_{1} & c_{6} & = & c_{7} \\
c_{2} & c_{4} & = & c_{6} \\
\hdotsfor{4}
 \end{matrix}
 $$

$$ \text{C}$$ est un code linéaire

Base de $$ \text{C} $$

* 8 éléments
* $$ |\text{C}| = 8$$
* $$ dim(\text{C}) = 3 $$
* $$ \mathbb{Z}/  2 \mathbb{Z} ^{n} = 2^{n} $$ elt
* $$ (c _{1}, c _{2}, c _{4}) $$

### Rappels

$$ (w _{1}, \cdots, w _{k}) $$ base de $$ \text{F} $$ ssi:
* $$ (w _{1}, \cdots, w _{k}) $$ engendre
* $$ (w _{1}, \cdots, w _{k}) $$ libre _(Aucun ne peux s'écrire comme **CL** des autres)_

$$ dim(\text{F})$$ : le nombre d'élément de la base (si $$ dim(\text{F}) = k $$ alors $$ \text{F}$$ contient $$ 2^{k}$$ elts)

### Dualité
$$ v = <v _{1}, \cdots, v _{n}> $$<br>
$$ w = <w _{1}, \cdots, w _{n}> $$<br>
$$v.w = \sum\limits_{}^{} v _{i}.w _{i}$$
$$v.w = 0 \Longleftrightarrow v.w  $$ orthogonaux.

Soit $$ \text{S} $$ on notera $$ <\text{S}> $$ (si $$ \text{S} $$ est un s.e.v)

$$ \text{S} ^{\perp} = \{ u \in \mathbb{Z} / 2* \mathbb{Z} | \forall v \in \mathbb{S}    \text{u.v} = 0 \}$$

### Resultat
$$ dim(<\text{S}>) + dim(<\text{S} ^{\perp}>) = n$$


$$ \text{C}  = \{ 0000, 1010, 0101, 1111\}  $$ $$ \text{C} $$ un s.e.v <br>
$$ \text{C} ^{\perp} = \{ 0000, 1010, 0101, 1111\}$$

***__ATTENTION __*** on a pas $$\text{C}  \cap \text{C} ^{\perp} = \{ \vec{0} \}$$


### Propriété:
Si $$ \text{C} $$ est un code linéaire et $$ dim(\text{C}) = k $$ alors $$ |\text{C}| = 2^{k}$$<br>
Si $$ \text{C} $$ est un code linéaire alors $$ dim(\text{C}) = log(|\text{C}|)$$
