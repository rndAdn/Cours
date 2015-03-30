--1--
SELECT titre
FROM film
WHERE numrealisateur IN (
      SELECT numrealisateur
      FROM realisateur
      WHERE UPPER(nom)||UPPER(prenom) LIKE '%MA_WEN%'
);

--2--
SELECT numrealisateur
FROM realisateur
WHERE UPPER(nom)||UPPER(prenom) LIKE '%MA_WEN%';

--3--
DELETE FROM realisateur
WHERE numrealisateur IN (
      SELECT numrealisateur
      FROM realisateur
      WHERE UPPER(nom)LIKE '%MAIWEN%'
);

--4--
SELECT numrealisateur,nom, prenom
FROM realisateur
WHERE UPPER(nom)||UPPER(prenom) LIKE '%MA_WEN%';


--5--
UPDATE film
SET numrealisateur = 463
WHERE numrealisateur IN (
    SELECT numrealisateur
    FROM realisateur
    WHERE UPPER(nom)||UPPER(prenom) LIKE '%MA_WEN%'
);

--6--
SELECT numrealisateur, nom, prenom
FROM realisateur
WHERE UPPER(nom)||UPPER(prenom) LIKE '%MA_WEN%';

--7--
DELETE FROM realisateur
WHERE numrealisateur IN (
      SELECT numrealisateur
      FROM realisateur
      WHERE UPPER(prenom)LIKE '%MAIWEN%'
);
