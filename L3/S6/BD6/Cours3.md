[TOC]
# Modelisation

## But
Trouver quelles tables créer
## Principes
- Pouvoir mettre toute l'information qu'on a prévu de mettre
- Ne pas mettre plusieurs fois la même information (_redondances_)


##Plusieurs normes:
- merise
- UML
- Crow foot (_proche d'UML_)

### 1er
|Produit |
|----|
| * id_produit |
| desc_produit |
| prix |

|Stock |
|----|
| * id_produit # |
| * id_magasin # |
| quantite |


|Magasin |
|----|
| * id_magasin |
| * magasin  |
| adresse |


##MLD (modèle logique des données )

**_Clef primaire_** :
> attribut ou groupe d'attributs tels que <br>
> * pour une même valeur de la clef on a au plus une seul ligne correspondante **<=> UNIQUE** <br>
> * et elle minimal, c-à-d; on ne peut pas enlever d'attribut sans qu'elle ne perde sa propriété (_représentée par des étoiles ou soulignée_)

**_Clef étrangère_** _représenté par #_ :
> **_sur l'exemple_** : ```id_produit``` est une clef étrangère dans ```stock``` qui dépend de la clef primaire ```id_produit``` de produit<br>
>  **_propriété_** : stock (id_produit) $$\subsetseq$$ produit (id_produit) <br>
>  **_En général_** : les cléfs étrangères se réfèrent à une clef primaire d'une autre table


##MCD(modèle conceptuel des données)
La "vraie modélisation"

AZERTYUIOP


* produit et magasin sont des ___entitées___
    * en général une entité correspond à quelque chose de concret mais pas toujours
* stock est une ___relation___ entre produit et magasin
 * quantité est un attribut de la elation (il donne des informations supplémentaires)



* -0< : indique que un produit donnée peut être en stock dans 0,1 ou plusieurs magasin. C'est une cardinalité de la relation
    * 0 : cardinalité minimum (ici 0)
    * <: cardinalité max (ici plusieurs)
* >0- : indique qu'un magasin peut avoir en stock 0,1 ou pluisieurs produit.

On a ici une relation n_n (plusieurs à plusieurs) en considérant les cardinalités maximum

## Autres cardinalité
```-0-|- : 0 ou 1```<br>
``` --|-| : 1 et 1 seul```<br>
``` --|-< : 1 ou  plusieurs```<br>
