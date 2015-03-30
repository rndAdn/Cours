--\i /ens/laplante/BD6/creer-tournage.sql
--SELECT titre FROM Film WHERE numrealisateur in (SELECT numrealisateur FROM Realisateur WHERE nom = 'ALLEN' and prenom = 'WOODY');
--SELECT Count(DISTINCT(numFilm)) FROM Evenement WHERE numlieu in (SELECT numlieu FROM Lieu WHERE arrondissement = 75013);
--SELECT AVG(datefin-datedebut) FROM Evenement WHERE numlieu in (SELECT numlieu FROM Lieu WHERE arrondissement = 75005);
--SELECT SUM(datefin-datedebut) FROM Evenement WHERE numlieu in (SELECT numlieu FROM Lieu WHERE arrondissement = 75013) and EXTRACT(YEAR FROM datefin) =2010 and EXTRACT(YEAR FROM datedebut)=2010 ;
--SELECT AVG(datefin-datedebut) FROM Evenement WHERE EXTRACT(YEAR FROM datefin) BETWEEN 2004 and 2005 and EXTRACT(YEAR FROM datedebut) BETWEEN 2004 and 2005;
--SELECT numFilm FROM Evenement WHERE numlieu in (SELECT numlieu FROM Lieu WHERE arrondissement = '75013') AND EXTRACT(YEAR FROM datedebut) >2009;
--SELECT numFilm FROM Film WHERE numrealisateur in (SELECT numrealisateur FROM Realisateur WHERE nom LIKE 'A%');
--SELECT numFilm FROM Evenement WHERE numfilm in (SELECT numFilm FROM Film WHERE numrealisateur NOT in (SELECT numrealisateur FROM Realisateur WHERE nom LIKE 'A%')) AND numlieu in (SELECT numlieu FROM Lieu WHERE arrondissement = '75013');
--SELECT numFilm FROM Evenement WHERE numlieu in (SELECT numlieu FROM Lieu WHERE arrondissement = '75013') AND EXTRACT(YEAR FROM datedebut) >2009 AND numfilm in (SELECT numFilm FROM Film WHERE numrealisateur in (SELECT numrealisateur FROM Realisateur WHERE nom LIKE 'A%'));

--UPDATE

--SELECT numFilm FROM Film WHERE numrealisateur in (SELECT numrealisateur FROM Realisateur WHERE nom LIKE UPPER('MA%WEN%') OR prenom LIKE UPPER('MA%WEN%'));
--SELECT numrealisateur,nom,prenom FROM Realisateur WHERE nom LIKE UPPER('MA%WEN%') OR prenom LIKE UPPER('MA%WEN%');
--DELETE FROM Realisateur WHERE numrealisateur in (463,623);
--SELECT numFilm FROM Film WHERE numrealisateur in (463,623);
--UPDATE Film SET numrealisateur = 295 WHERE numrealisateur in (SELECT numrealisateur FROM Realisateur WHERE nom LIKE UPPER('MA%WEN%') OR prenom LIKE UPPER('MA%WEN%'));

--LIVRAISON

--SELECT nom_prod,poids * 2 as poids2 FROM produit WHERE couleur = 'rouge';
--SELECT * FROM provenance ORDER BY quantite DESC limit 3;
--SELECT * FROM produit ORDER BY poids;
--SELECT nom_usine FROM usine WHERE ville in (SELECT ville FROM magasin WHERE nom_mag = 'JaiTout');
--SELECT nom_prod,couleur FROM produit WHERE ref_prod in (SELECT ref_prod FROM usine WHERE ref_usine = '302');
--SELECT AVG(poids) FROM produit;
--SELECT DISTINCT(ref_prod) FROM provenance WHERE ref_mag in (SELECT ref_mag FROM magasin WHERE nom_mag = 'PrixBas');
--SELECT produit.poids*provenance.quantite as poids_livraison FROM produit,provenance WHERE provenance.ref_prod = 12 AND ref_mag = 30 AND ref_usine = 189 AND produit.ref_prod = 12;
