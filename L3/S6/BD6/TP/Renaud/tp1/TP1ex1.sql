SELECT * FROM Lieu WHERE UPPER(adresse) LIKE 'WATT%' AND arrondissement = 75013; /*EX1.1*/
SELECT numlieu FROM Lieu WHERE adresse LIKE 'WATT%' AND arrondissement = 75013; /*EX1.2*/
SELECT numfilm FROM Evenement WHERE numlieu IN (363,525,2343); /*EX1.3*/
SELECT titre FROM Film WHERE numfilm IN (678, 225, 678, 497);
SELECT numrealisateur FROM Film WHERE numfilm IN (678, 225, 678, 497); /*EX1.4*/
SELECT nom,prenom FROM Realisateur WHERE numrealisateur IN (261, 485, 20);
SELECT * FROM Lieu WHERE UPPER(adresse) LIKE '%IENA%'; /*EX1.6*/
SELECT * FROM Realisateur WHERE UPPER(prenom) LIKE UPPER('%ma_wenn%') OR UPPER(nom) LIKE UPPER('%ma_wenn%'); /*EX1.7*/
SELECT * FROM Realisateur WHERE UPPER(prenom) = ''; /*EX1.8*/
SELECT * FROM Realisateur WHERE (UPPER(Prenom) LIKE UPPER('%OLivier%') OR UPPER(Prenom) LIKE UPPER('%fr_d_ric%')  OR UPPER(Prenom) LIKE '') AND (UPPER(nom) LIKE UPPER('%Nakache%') OR UPPER(nom) LIKE UPPER('%berthe%') OR UPPER(nom) LIKE ''); /*EX1.9*/
SELECT * FROM Lieu WHERE arrondissement = NULL; /*EX1.10*/
SELECT * FROM Lieu WHERE arrondissement IS NULL;
SELECT * FROM Evenement WHERE datedebut + 4 = datefin; /*EX1.11*/
SELECT * FROM Evenement WHERE datefin - datedebut BETWEEN 3 AND 7; /*EX1.12*/
SELECT numfilm, datedebut, datefin, (datefin - datedebut) AS nbjours FROM Evenement WHERE (datefin - datedebut) BETWEEN 3 AND 7; /*EX1.13*/
SELECT numfilm, datedebut, datefin, (datefin - datedebut) AS nbjours FROM Evenement WHERE (datefin - datedebut) BETWEEN 3 AND 7 ORDER BY nbjours; /*EX1.14*/
SELECT COUNT(*) FROM Evenement WHERE (datefin - datedebut) = 2 ; /*EX1.15*/
SELECT MAX(datefin - datedebut) AS nbjours_Max FROM Evenement; /*EX1.16*/
SELECT *, (datefin - datedebut) AS nbjours FROM Evenement WHERE (datefin - datedebut) > 7 ORDER BY nbjours; /*EX1.17*/
SELECT *, (datefin - datedebut) AS nbjours  FROM Evenement WHERE (datefin - datedebut) < 0 ORDER BY nbjours; /*EX1.18*/
DROP TABLE Evenement;
DROP TABLE Lieu;
DROP TABLE Film;
DROP TABLE Realisateur;
