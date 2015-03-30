[TOC]

```
UNIQUE              |     PRIMARY KEY
unicité             =     unicité
NULL possible       !=    pas de NULL
(unicité que sur
les valeur
non NULL)
------------------------
autant de UNIQUE    !=     1 seul par table
qu'on veux
```

* ```CHECK```  : contrainte sur une ligne
Après déclaration ```CHECK (cond)``` ne concerne que l'attribut déclaré
* ```[CONTRAINT nom]```: ```CHECK (condition)```
Sur un ou plusieurs attributs

### Exemple

```
val int CHECK(val >= 2 AND val <= 5),

cat text NOT NULL CHECK(cat IN ('preniere', 'seconde'));
```

```
CHECK (x + y < 15)
```

```DEFAULT``` : n'est pas une contrainte, donne une valeur par defaut (pour ```INSERT``` )

### Exemple

```
date_resa date DEFAULT curent_date,
val int DEFAULT NULL
```

### Exemple

```
CREATE TABLE A(
    id SERIAL PRIMARY KEY,
    val int NOT NULL DEFAULT 3,
    x text NOT NULL
    )

INSERT INTO A(x) VALUES('ab') => (1,3,'ab')
INSERT INTO A(val, x) VALUES(4, 'a') => (2,4,'a')
```


Concerption des base de données relationnelles  vuibert jacky akoka, Isabelle comyn_wattiau
NE PAS REGARDER LA MODELISATION

# Algèbre relationnelle

* relation = table
* On note $$ \text{R}(a_{1, \cdots, a_{n}}) $$ table $$ \text{R} $$ qui a comme attribut $$ (a_{1, \cdots, a_{n}}) $$
* n-uplet = tuple = ligne de base


## Opération de base

## Sélection $$ \sigma $$ (sigma)
$$ \text{P}$$ : condition sur une ligne <br>
$$ \sigma _{\text{P}}(\text{R})  \Longleftrightarrow $$ ```SELECT * FROM R WHERE P;```

| A | B |
|---|----|
| 1 | x |
| 1 | y |
| 2 | x |
| 3 | z |
| 3 | t |

$$ \sigma _{\text{B}  = x \text{OU} \text{B} = z}(\text{R}) =$$

| A | B |
|---|----|
| 1 | x |
| 2 | x |
| 3 | z |


```
Produit(*id_produit, desc_prod, prix)
Magasin(*id_mag, nom_mag, adresse)
Stock(*(id_prod#, id_mag#), quantité)
```

### Exemple:
les produits à moins de 50 € $$ \sigma _{\text{prix} \leq 50}(\text{Produit})$$


## Projection $$ \prod $$

* $$ c_{1}, \cdots, c_{n} $$ nom d'attributs

$$ \prod (c_{1}, \cdots, c_{n}) \Longleftrightarrow $$ ```SELECT c_1, ..., c_n FROM R```


```Les meuble( description, prix) de >= 100```

$$ \prod _{descprod, prix}(\sigma _{prix \geq 100} (Produit)) = \sigma_{prix \geq 100}(\prod _{descprod, prix}(Produit)) \Longleftrightarrow$$

```
SELECT desc_prod, prix
FROM produit
WHERE prix >= 100;
```


Les chaises de prix >= 20 (```id_prod, prix```)

$$ \prod _{idprod, prix}(\sigma _{prix \geq 100 and descprod = 'chaise'} (Produit)) $$

###### ON NE PEUT PLUS INVERSER $$ \prod $$ et $$ \sigma $$


## Produit cartésien $$ \times $$

$$ \text{R} \times \text{S} \Longleftrightarrow $$ ``` SELECT * FROM R,S```

## Jointure naturelle
$$ \text{R} \bowtie \text{S}  \Longleftrightarrow$$ ```SELECT * FROM R NATURAL JOIN S```


On suppose
$$ \text{R}(a_{1}, \cdots, a_{n}, b_{1}, \cdots, b_{p}) $$
$$ \text{S}(b_{1}, \cdots, b_{p}, c_{1}, \cdots, c_{m}) $$

Les $$ a_{i},b_{i}, c_{i} $$ sont tous differents (nom d'attributs)


$$ \text{R} \bowtie \text{S}  = \text{T}(a_{1}, \cdots, a_{n}, b_{1}, \cdots, b_{p}, c_{1}, \cdots, c_{m})$$ et contient toute les lignes $$ (x_{1}, \cdots, x_{n}, y_{1}, \cdots, y_{p}, z_{1}, \cdots, z_{m}) $$ tel que:
$$ (x_{1}, \cdots, x_{n}, y_{1}, \cdots, y_{p}) \in \text{R} $$
$$ ( y_{1}, \cdots, y_{p}, z_{1}, \cdots, z_{m}) \in \text{S} $$


| A | B | C |
|-------|-----|----|
| 1 | x | x |
| 2 | x | y |
| 3 | x | z |
| 3 | y | y |



| B | C | D |
|-------|-----|----|
| x | y | a |
| x | y | b |
| y | z | a |
| y | x | c |


$$ \text{R} \bowtie \text{S} $$



| A | B | C | D |
|-------|-----|----|---|
| 1 | x | y | a |
| 1 | x | y | b |
| 3 | x | y | a |
| 3 | x | y | b |
| 3 | x | x | c |




Les chaises en strock en quantité >= 4 dans un magasin et les magasin correspondant (id_prod, prix, id_mag)

$$ \text{A} = \text{Produit} \bowtie \text{Stock} $$

$$ \prod_{id_prod, prix, id_mag} (\sigma _{desc_prod = chaise   AND quantite \Longrightarrow 4)}(A)$$



Autre solution

$$ \text{B} = \sigma_{descprod = 'chaise'}(Produit) $$
$$ \text{C} = \sigma_{quantité \geq 4}(Stock) $$

$$ \prod_{idprod, prix, idmag} (\text{B} \bowtie \text{C})$$
