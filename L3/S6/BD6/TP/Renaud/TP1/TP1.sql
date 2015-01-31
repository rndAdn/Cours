SELECT * FROM Lieu WHERE UPPER(adresse) LIKE 'WATT%' AND arrondissement = 75013; /*EX1.1*/
SELECT numlieu FROM Lieu WHERE adresse LIKE 'WATT%' AND arrondissement = 75013; /*EX1.2*/
SELECT numfilm FROM Evenement WHERE numlieu IN (363,525,2343); /*EX1.3*/
SELECT titre FROM Film WHERE numfilm IN (678, 225, 678, 497);
SELECT numrealisateur FROM Film WHERE numfilm IN (678, 225, 678, 497); /*EX1.4*/
SELECT nom,prenom FROM Realisateur WHERE numrealisateur IN (261, 485, 20);
SELECT * FROM Lieu WHERE UPPER(adresse) LIKE '%IENA%'; /*EX1.6*/
SELECT * FROM Realisateur WHERE UPPER(prenom) LIKE UPPER('%ma_wenn%') OR UPPER(nom) LIKE UPPER('%ma_wenn%'); /*EX1.7*/
SELECT * FROM Realisateur WHERE UPPER(prenom) = ''; /*EX1.8*/
