/*\i /ens/laplante/BD6/TP1.sql*/
SELECT * FROM usine; /*EX2.1*/
SELECT * FROM produit;
SELECT * FROM provenance;
SELECT * FROM magasin;

SELECT ville FROM usine; /*EX2.2*/
SELECT nom_prod, couleur FROM produit; /*EX2.3*/
SELECT ref_prod, quantite FROM provenance WHERE ref_mag = 14; /*EX2.4*/
SELECT * FROM usine WHERE UPPER(ville) LIKE UPPER('marseille'); /*EX2.5*/
SELECT ref_mag FROM provenance WHERE ref_usine = 109 AND ref_prod = 1; /*EX2.6*/
SELECT ref_prod, nom_prod FROM produit WHERE couleur = 'rouge'; /*EX2.7*/
SELECT ref_prod, nom_prod FROM produit WHERE nom_prod LIKE ('casse%'); /*EX2.8*/
SELECT DISTINCT(ref_mag) FROM provenance; /*EX2.9*/
SELECT nom_prod FROM produit WHERE poids BETWEEN 15 AND 45;/*EX2.10*/
SELECT nom_prod FROM produit WHERE couleur IN ('jaune','bleu') AND  poids < 20; /*EX2.11*/
SELECT nom_prod FROM produit WHERE couleur = 'jaune' OR (couleur = 'bleu' AND  poids < 20); /*EX2.12*/
SELECT nom_prod FROM produit WHERE nom_prod LIKE '%lampe%' OR  poids > 30; /*EX2.13*/