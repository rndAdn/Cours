-- 1 --
SELECT *
FROM etapes
WHERE nbKm > 100;

-- 2 --
SELECT *
FROM coureurs
WHERE codepays IS NULL;

-- 3 --
SELECT COUNT(*), COUNT(codePays)
FROM coureurs;

-- 4 --
SELECT numeroCoureur, numeroEtape
FROM temps
ORDER BY numeroEtape, numeroCoureur;

-- 5 --
SELECT AVG(tempsRealise), SUM(nbKm)
FROM etapes, temps
WHERE etapes.numeroEtape = temps.numeroEtape
    AND numeroCoureur = 31;

-- 6 --
SELECT (SELECT (3600 * SUM(nbKm)/SUM(EXTRACT(epoch FROM tempsRealise))) AS VITESSE) AS V, numeroCoureur
FROM temps, etapes
WHERE etapes.numeroEtape = 4 AND etapes.numeroEtape = temps.numeroEtape
GROUP BY numeroCoureur;


-- 7 --
SELECT COUNT(numeroCoureur), codeEquipe
FROM coureurs
GROUP BY codeEquipe;

-- 8 --
SELECT codeEquipe, MIN(tempsRealise)
FROM temps t, coureurs c
WHERE t.numeroCoureur = c.numeroCoureur AND numeroEtape = 2
GROUP BY codeEquipe;

-- 9 --
SELECT codeequipe, numeroetape, MIN(tempsrealise)
FROM temps t , coureurs c
WHERE t.numerocoureur = c.numerocoureur
GROUP BY codeequipe, numeroetape;

-- 10 --
SELECT codeequipe, AVG(tempsrealise)
FROM temps NATURAL JOIN coureurs
WHERE numeroetape = 3
GROUP BY codeequipe;

-- 11 --
--SELECT --

-- 12 --
SELECT numerocoureur, AVG(nbKm / EXTRACT (epoch FROM tempsrealise)) AS vitessemoyenne
FROM temps NATURAL JOIN  etapes
WHERE nbKm < 60
GROUP BY numerocoureur;


-- 13 --
SELECT numerocoureur , 3600 * (SUM(nbKm) / SUM(EXTRACT (epoch FROM tempsrealise)))
FROM temps, etapes
WHERE temps.numeroetape = etape.numeroetape
GROUP BY numerocoureur
HAVING COUNT(temps.numeroetape) <= 3;

-- 14 --
SELECT E.numeroetape, E.nbKm
FROM etapes E
WHERE E.nbKm IN (
    SELECT MAX(nbKm)
    FROM etapes
);


-- 15 --
SELECT numerocoureur, tempsrealise
FROM temps
WHERE numeroetape = 4 AND tempsrealise IN (
    SELECT MIN(tempsrealise)
    FROM temps
    WHERE numeroetape = 4
);

-- 16 --
SELECT numerocoureur
FROM temps
GROUP BY numerocoureur
HAVING COUNT(numeroetape) = (
    SELECT COUNT(*)
    FROM etapes
);

-- 17  --
