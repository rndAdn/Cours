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
SELECT 
