[TOC]

### Exemple
La moyenne de satisfaction par produit sur les factures de plus de 100€

```
SELECT id_produit, AVG(satisfaction)
FROM ligne_commande
WHERE no_facture IN (
    SELECT no_facture
    FROM ligne_commande NATURAL JOIN produit
    GROUP BY no_facture
    HAVING SUM(prix*quant) >=100
    )
GROUP BY id_produit;
```


Avec une requête corrélée.

```
SELECT id_produit, AVG(satisfaction)
FROM ligne_commande AS l
WHERE (
    SELECT SUM(prix*quantite)
    FROM ligne_commande NATURAL JOIN produit
    WHERE no_facture = l.no_facture
    ) >= 100
GROUP BY id_produit;
```


### Exemple
Les clients qui ont une adresse et qui ont fait une commande avant 31 décembre 2013 et qui n'ont pas fait de commande après le 1er Janvier 2014


```
SELECT nom_client, adresse
FROM facture
WHERE adresse IS NOT NULL
AND date <= '2013-12-31'
AND (nom_clinet, adresse NOT IN (
    SELECT nom_client, adresse
    FROM facture
    WHERE date >= '2014-01-01'
    ));
```


# EXIST, NOT EXIST

##Syntaxe
Condition :
```EXIST(requête)```
```NOT EXIST(requête)```

```EXIST``` return ```TRUE``` Si au moins 'une ligne a la requête' ```FALSE``` Sinon
```NOT EXIST``` return ```TRUE``` Si la requête return 0 ligne ```FALSE``` Sinon

### EXEMPLE

Les numéros de facture pour lesquelles tous les produits ont été notés dans la facture
(c'est à dire pour lesquelles il n'existe pas de ligne de commande non notée)

```
SELECT no_facture
FROM facture AS f
WHERE NOT EXIST (
    SELECT *
    FROM ligne_commande
    WHERE no_facture = f.no_facture
    AND satisfaction IS NULL
    )
```


### EXEMPLE
les magasins qui ont en stock tous les produits
(c'est à dire les magasins tels qu'il n'y a pas de produit qui n'est pas en stock dans un magasin)


```
SELECT id_magasin
FROM magasin AS m
WHERE NOT EXISTS (
    SELECT id_produit FROM produit
    WHERE id_produit NOT IN (
        SELECT id_produit
        FROM stock
        WHERE id_magasin = m.magasin
        )
    );
```

```WHERE NOT EXIST (SELECT ____ xxxxx) <=>  WHERE (SELECT COUNT(x) xxxx) = 0```



# Sous-requête dans le HAVING
Idem que pour le ```WHERE```

Les sous requête ne doivent dépendre que des attribut du ```GROUP BY```



### EXEMPLE
Les produits dont le stock est 5 fois superieur à la vente
