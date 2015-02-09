--1--
SELECT titre FROM film WHERE numrealisateur in (
    SELECT numrealisateur FROM realisateur WHERE UPPER(nom)= 'ALLEN' AND UPPER(prenom) ='WOODY'
); 

--2--
SELECT count(*) 
FROM evenement 
WHERE numlieu IN (
    SELECT numlieu 
    FROM lieu 
    WHERE arrondissement = 75013
);

--3--
SELECT SUM(datefin-datedebut+1) as duree FROM evenement WHERE numlieu IN (
    SELECT numlieu FROM lieu WHERE arrondissement = 75013
);


--4--
SELECT AVG(datefin - datedebut + 1) AS total FROM evenement WHERE numlieu in (
    SELECT numlieu FROM lieu WHERE arrondissement=75005
);


--5--
SELECT SUM(datefin - datedebut + 1) AS total FROM evenement WHERE EXTRACT(year FROM datedebut) = 2010
AND EXTRACT(year FROM datefin) = 2010 AND numlieu in (
    SELECT numlieu FROM lieu WHERE arrondissement=75013
);

--6--
SELECT AVG(datefin - datedebut + 1) AS total FROM evenement WHERE EXTRACT(year FROM datedebut) >= 2004
AND EXTRACT(year FROM datefin) <= 2005;

--7--
SELECT numfilm 
FROM evenement 
WHERE EXTRACT(year FROM datedebut) >= 2010 
      AND numlieu IN (
      	  SELECT numlieu FROM lieu WHERE arrondissement=75013
      	);

--8--
SELECT numfilm 
FROM film
WHERE numrealisateur IN (
      SELECT numrealisateur 
      FROM realisateur
      WHERE UPPER(nom) LIKE 'A%'
);

--9--
SELECT numfilm 
FROM evenement 
WHERE EXTRACT(year FROM datedebut) >= 2010 
      AND numlieu IN (
      	  SELECT numlieu FROM lieu WHERE arrondissement=75013
)
EXCEPT
SELECT numfilm
FROM film
WHERE numrealisateur IN (
      SELECT numrealisateur 
      FROM realisateur
      WHERE UPPER(nom) LIKE 'A%'
);

--10--
SELECT numfilm 
FROM evenement 
WHERE EXTRACT(year FROM datedebut) >= 2010 
      AND numlieu IN (
      	  SELECT numlieu FROM lieu WHERE arrondissement=75013
)
INTERSECT
SELECT numfilm
FROM film
WHERE numrealisateur IN (
      SELECT numrealisateur 
      FROM realisateur
      WHERE UPPER(nom) LIKE 'A%'
);

