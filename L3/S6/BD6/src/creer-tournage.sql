
--titre;realisateur;date_debut_evenement;date_fin_evenement;cadre;lieu;adresse;arrondissement;adresse_complete;geo_coordinates
drop table IF EXISTS donneesbrutes ;

\echo Creation des tables ...

create table donneesbrutes (
  titre varchar,
  realisateur varchar,
  datedebut DATE,
  datefin DATE,
  cadre varchar,
  lieu varchar,
  adresse varchar,
  arrondissement varchar,
  adresse_complete varchar,
  coordinates VARCHAR
);
\copy donneesbrutes from './tournagesdefilmsparis2011.csv' with delimiter ';' csv header ;

DROP TABLE IF EXISTS Evenement;
DROP TABLE IF EXISTS Lieu ;
DROP TABLE IF EXISTS Film;
DROP TABLE IF EXISTS Realisateur ;

CREATE TABLE Realisateur (
  NumRealisateur SERIAL PRIMARY KEY ,
  Nom varchar,
  Prenom varchar,
  CHECK ( (Nom, Prenom) is not null)
);

CREATE TABLE Film (
  numfilm SERIAL PRIMARY KEY,
  Titre varchar NOT NULL,
  NumRealisateur INTEGER NOT NULL REFERENCES Realisateur
);

CREATE TABLE Lieu (
  NumLieu SERIAL PRIMARY KEY,
  Lieu varchar,
  Adresse VARCHAR,
  Arrondissement NUMERIC(5,0),
  Latitude real,
  Longitude real
);

CREATE TABLE Evenement (
  NumEvenement SERIAL PRIMARY KEY,
  NumFilm INTEGER REFERENCES Film DEFERRABLE,
  NumLieu INTEGER REFERENCES Lieu DEFERRABLE,
  Cadre VARCHAR,
  DateDebut DATE,
  DateFin  DATE --,
  --CHECK (DateFin >= DateDebut)
);


\echo
\echo Insertion des donnees ...
\echo
\echo Realisateur ...

INSERT INTO Realisateur(Nom, Prenom)
SELECT DISTINCT
       substring(Realisateur from position(' ' in Realisateur)+1),
       substring(Realisateur from 1 for position(' ' in Realisateur))
  FROM donneesbrutes
;
Select * from realisateur limit 3;

\echo Film ...

INSERT INTO Film (titre, numrealisateur)
WITH F AS (
  SELECT DISTINCT titre, realisateur
    FROM donneesbrutes
)
SELECT titre, (SELECT numrealisateur
                 FROM realisateur
                WHERE realisateur = prenom||nom)
  FROM F;

SELECT * FROM film LIMIT 3;

\echo Lieu ...

INSERT INTO Lieu(Lieu, Adresse, Arrondissement, --Coordonnees,
           latitude, longitude)
WITH TL as (
  SELECT DISTINCT lieu, adresse, arrondissement,
       substring(coordinates from 1 for position(',' in coordinates)-1) as lat,
       substring(coordinates from position(',' in coordinates)+1) as lon
  FROM donneesbrutes
)
SELECT lieu, adresse,
       to_number(arrondissement, '99999'), --POINT( coord ),
       cast (lat as real), cast(lon as real)
  FROM TL;

select * from lieu limit 3;

\echo Evenement ...

\echo Creation des index
CREATE INDEX on film(titre);
CREATE INDEX on lieu(adresse);
CREATE INDEX on realisateur (prenom,nom);

SET CONSTRAINTS ALL DEFERRED;

INSERT INTO Evenement (numFilm, numLieu, Cadre, DateDebut, DateFin)
SELECT (SELECT numFilm
          FROM Film, realisateur
         WHERE Film.NumRealisateur=Realisateur.numRealisateur
           AND Film.Titre = DonneesBrutes.Titre
           AND Realisateur.Prenom||Realisateur.Nom
               =DonneesBrutes.Realisateur
       ),
-- Il faudrait tenir compte des coordonnes sinon pas unique!
       (SELECT min(numLieu )
          FROM Lieu
         WHERE Lieu.lieu   = donneesbrutes.lieu
           AND lieu.adresse= donneesbrutes.adresse
           AND lieu.arrondissement = to_number(donneesbrutes.arrondissement,'99999')
       ),
       cadre, DateDebut, DateFin
  FROM DonneesBrutes;

select * from evenement limit 3;

--test
--select count(*) from evenement;
--SELECT count(*) from evenement where numlieu is null;
--SELECT count(*) from evenement where numfilm is null;

-- Les requetes precedentes ne marcheront pas si on enleve d'abord les espaces
\echo Nettoyage ...
UPDATE realisateur
   SET prenom=trim(prenom);

UPDATE realisateur
   SET nom=trim(nom);

DROP TABLE donneesbrutes ;

\echo Termine
