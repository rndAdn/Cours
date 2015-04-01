Select * FROM etapes WHERE nbkm>100;
Select * FROM coureurs WHERE codePays IS NULL;
-- Select  count(distinct(S1.numeroCoureur)), count(distinct(S2.numeroCoureur))  FROM (Select * FROM coureurs WHERE codePays IS NULL) as S1,(Select * FROM coureurs)as S2;
Select count(*) as avecPays , (count(*) - count(codePays)) as sansPays FROM coureurs;
Select numeroCoureur,numeroEtape From temps WHERE numeroEtape in (SELECT numeroEtape FROM etapes) ORDER BY numeroEtape;
Select avg(tempsRealise),sum(nbKm) FROM temps,etapes WHERE etapes.numeroEtape = temps.numeroEtape and numeroCoureur = 31;

Select sum(nbKm)/sum(extract(hour FROM tempsRealise) + extract(minute FROM tempsRealise) / 60 + extract(second FROM tempsRealise) / 3600) as vitesse FROM temps,etapes  WHERE etapes.numeroEtape = temps.numeroEtape GROUP BY numeroCoureur;
-- extract(hour FROM tempsRealise) + extract(minute FROM tempsRealise) / 60 + extract(seconde FROM tempsRealise) / 3600

SELECT count(*),codeEquipe FROM coureurs GROUP BY codeEquipe;
SELECT min(tempsRealise),codeEquipe FROM coureurs,temps Where coureurs.numeroCoureur = temps.numeroCoureur and numeroEtape = 2 Group BY codeEquipe;
SELECT min(tempsRealise),codeEquipe,numeroEtape FROM coureurs,temps Where coureurs.numeroCoureur = temps.numeroCoureur Group BY codeEquipe,numeroEtape ORDER BY codeEquipe;
SELECT avg(tempsRealise),codeEquipe FROM coureurs,temps WHERE  coureurs.numeroCoureur = temps.numeroCoureur and numeroEtape = 3 GROUP BY codeEquipe;
Select count(*),codeEquipe FROM coureurs GROUP BY codeEquipe HAVING count(*)>1;
Select sum(nbKm)/sum(extract(hour FROM tempsRealise) + extract(minute FROM tempsRealise) / 60 + extract(second FROM tempsRealise) / 3600) as vitesse FROM temps,etapes  WHERE etapes.numeroEtape = temps.numeroEtape and nbKm<60 GROUP BY numeroCoureur;
Select sum(nbKm)/sum(extract(hour FROM tempsRealise) + extract(minute FROM tempsRealise) / 60 + extract(second FROM tempsRealise) / 3600) as vitesse FROM temps,etapes  WHERE etapes.numeroEtape = temps.numeroEtape GROUP BY numeroCoureur HAVING count(tempsRealise)>2;

Select numeroEtape FROM etapes where nbKm = (SELECT max(nbKm) FROM etapes);
Select nomCoureur FROM coureurs,temps where coureurs.numeroCoureur = temps.numeroCoureur and numeroEtape = 4  and tempsRealise = (SELECT MIN(tempsRealise) FROM temps WHERE numeroEtape = 4);

Select numeroCoureur FROM temps GROUP BY numeroCoureur HAVING count(tempsRealise) = (SELECT count(*) FROM etapes);
Select coureurs.numeroCoureur FROM temps,coureurs WHERE temps.numeroCoureur = coureurs.numeroCoureur and codePays = 'FRA' GROUP BY coureurs.numeroCoureur HAVING count(tempsRealise) = (SELECT count(*) FROM etapes);
Select codeEquipe FROM coureurs,temps WHERE coureurs.numeroCoureur = temps.numeroCoureur and temps.numeroEtape = (SELECT max(numeroEtape ) FROM etapes) GROUP BY codeEquipe HAVING count(*)>1;
Select nomCoureur FROM coureurs,temps,(SELECT numeroEtape,min(tempsRealise) as tempsRealise FROM temps GROUP BY numeroEtape) as Q WHERE coureurs.numeroCoureur = temps.numeroCoureur and temps.numeroEtape = Q.numeroEtape and temps.tempsRealise = Q.tempsRealise GROUP BY coureurs.nomCoureur HAVING count(*) = (SELECT count(*) FROM etapes);

