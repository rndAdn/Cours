# Jointure général

$$ \text{S} \bowtie_{p} \text{R} = \sigma_{p}(\text{S} \times \text{R}) $$


### Exemple
Les chaises (```id_prod```) plus chères qu'au moins un fauteuil.

$$\prod_{idprod_{1}}(\sigma_{descprod = 'chaise'}(Produit_{1}) \bowtie_{prix_1 > prix_2} \sigma_{desc='fauteuil'}(Produit_{2}))$$

#### Produit1
|  |  |  |
|-------|-----|----|
| 10 | chaise | 70 |

#### Produit2
|  |  |  |
|-------|-----|----|
| 11 | fauteuil | 60 |


```
SELECT *
FROM R,S
WHERE P;

(P = prix1 > prix2)
```


# Opérations ensemblistes
Résultat d'une opération ensembliste est <u>sans doublon</u>

##UNION

``` R U S <=> SELECT * FROM R UNION SELECT * FROM S;```

```R``` et ```S``` on le même nombre de <u>colonnes</u>

### R

| A | B |
|-------|-----|
| x | 1 |
| y | 2 |
| z | 3 |



### S

| A | B |
|-------|-----|
| y | 2 |
| y | 4 |
| z | 5 |



### R U S

| A | B |
|-------|-----|
| x | 1 |
| y | 2 |
| z | 3 |
| y | 4 |
| z | 5 |

Les identifiants et descriptions des chaises en stock >= 4 et les tables en stock >=1 dans le magasin 1

$$\text{A} = \prod_{idprod, descprod}(\sigma_{descprod = 'chaise'}(Produit) \bowtie \sigma_{quant \geq 4 et idmag=1}(Magasin))$$

$$\text{B} = \prod_{idprod, descprod}(\sigma_{descprod = 'table'}(Produit) \bowtie \sigma_{idmag=1}(Magasin))$$
```Resultat = A UNION B```

##INTER

``` R INTER S <=> SELECT * FROM R INERSECT SELECT * FROM S;```

Nom des colonnes resultat = cellesde la première table ($$ \cap, \cup, -  $$)

Même nombre de colonne pour les 2 ensembles ($$ \cap, \cup, -  $$)



### R

| A | B |
|-------|-----|
| x | 1 |
| y | 3 |
| z | 4 |
| z | 5 |



### S

| C | D |
|-------|-----|
| x | 2 |
| y | 2 |
| y | 3 |
| z | 5 |



### R U S

| A | B |
|-------|-----|
| y | 3 |
| z | 5 |


Les tables qui on un prix entre 20 et 40 € et en stock dans un magasin a LYON

$$\text{A} = \prod_{idprod}(\sigma_{0 \leq prix \leq 20 et descprod = 'table'}(Produit)$$

$$\text{B} = \prod_{idprod}((Stock) \bowtie \sigma_{adresse = 'Lyon'}(Magasin))$$

RESULTAT = $$ \text{A} \cap \text{B} $$


## - (moins ensemblistes)

```R - S  <=> SELECT * FROM R EXEPT SELECT * FROM S;```


### R

| A | B |
|-------|-----|
| x | 1 |
| x | 2 |
| y | 1 |
| y | 3 |
| z | 4 |

### S

| A | B |
|-------|-----|
| x | 2 |
| y | 2 |
| y | 3 |
| z | 2 |



### R - S

| A | B |
|-------|-----|
| x | 1 |
| y | 1 |
| z | 4 |



Les chaises (```id_prod, prix```) les moins chères.
C'est à dire: les chaises ayant la propriété de ne pas être plus chère strictement qu'une autres

1ere Etape : les chaises plus chères qu'une autre

$$\text{A} = \prod_{idprod, prix}(\sigma_{descprod = 'chaise'}(Produit_1) \bowtie_{prix_1 > prix_2} \sigma_{descprod='chaise'}(Produit_2))$$

Resultat $$ =  \prod_{idprod, prix}(\sigma_{descprod = 'chaise'}(Produit)) - \text{A}$$


##Division Ensemblistes

```R / S  ```
$$ \text{R} \div \text{S} $$
Soit $$ \text{R} (a_{1}, \cdots, a_{n}, b_{1}, \cdots, b_{p}) $$

$$ \text{S} (b_{1}, \cdots, b_{p}) $$

$$ \text{R}/\text{S}  = \text{T} (a_{1}, \cdots, a_{n})$$

Tel que $$ (x_{1}, \cdots, x_{n}) \in \text{T}$$ ssi $$ \forall \text{ligne}(y_{1}, \cdots, y_{p}) \in \text{S}$$ alors $$ (x_{1}, \cdots, x_{n}, y_{1}, \cdots, y_{p}) \in \text{R}$$


### R

| A | B |
|-------|-----|
| 1 | x |
| 1 | y |
| 1 | z |
| 1 | t |
| 2 | x |
| 2 | z |
| 3 | x |
| 3 | y |
| 3 | z |
| 4 | t |

### S

| B |
|-------|
| x |
| y |
| z |



### R / S

| A |
|-------|
| 1 |
| 3 |

### Exemple
Les chaises (```id_prod``` ) en stock dans touts les magasin de Lyon

$$ \text{A} = \prod_{idprod, idmag}(\sigma_{descprod = 'chaise'}(Produit) \bowtie (Strock)) $$
Chaises et magasin ou elles sont en Stock

$$\text{B} = \prod_{idmag}(\sigma_{adresse = 'Lyon'}(Magasin)$$
Magasin de Lyon

Resultat $$ = \text{A}/\text{B} $$

#### Sans division

Une chaise n'est pas dans le resultat s'il existe au moins un magasin qu'il ne l'a pas

#####1ere Étape
```Couple(id_prod, id_mag)``` avec :<br>
```id_prod``` coresspond a une chaise
```id_mag``` coresspond a un magasin a Lyon
$$ \text{A} = \prod_{idprod}(\sigma_{descprod = 'chaise'}(Produit)) \times \prod_{idmag}(\sigma_{adresse = 'Lyon'}(Magasin)) $$

#####2eme Étape
```Couple(id_prod, id_mag)``` avec :<br>
```id_prod``` coresspond a une chaise
```id_mag``` coresspond a un magasin
$$ \text{B} = \text{A} -  \prod_{idprod, idmag}(Stock)$$


Resultat $$ = \prod_{idprod}(\sigma_{descprod = 'chaise'}(Produit)) - \prod_{idprod}(\text{B}) $$
# SQL
## LOGIQUE TRIVALUÉ

On a 3 valeurs logique possible
```TRUE, FALSE, NULL```

```NULL```  correspond a une valeur <u>**non connu**</u>

Opératons : ```AND, OR, NOT```


| AND | TRUE | NULL | FALSE |
|-------|-----|----|---|
| **TRUE** | TRUE | NULL | FALSE |
| **NULL** | NULL | NULL | FALSE |
| **FALSE** | FALSE | FALSE | FALSE |
