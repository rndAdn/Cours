DROP TABLE provenance;
DROP TABLE magasin;
DROP TABLE usine;
DROP TABLE produit;

CREATE TABLE produit (
  ref_prod INTEGER PRIMARY KEY, 
  nom_prod TEXT NOT NULL, 
  couleur TEXT , 
  poids INTEGER
);
CREATE TABLE usine (
  ref_usine INTEGER PRIMARY KEY, 
  nom_usine TEXT NOT NULL, 
  ville TEXT NOT NULL
);
CREATE TABLE magasin (
  ref_mag INTEGER PRIMARY KEY, 
  nom_mag TEXT NOT NULL, 
  ville TEXT NOT NULL
);
CREATE TABLE provenance (
  ref_prod INTEGER REFERENCES produit, 
  ref_usine INTEGER REFERENCES usine, 
  ref_mag INTEGER REFERENCES magasin, 
  quantite INTEGER,
  PRIMARY KEY (ref_prod, ref_usine, ref_mag)
);

-- remplissage des tables

\copy produit from '/ens/laplante/BD6/produit.dat'  delimiter ',' 
\copy usine from '/ens/laplante/BD6/usine.dat' delimiter ','
\copy magasin from '/ens/laplante/BD6/magasin.dat'  delimiter ','
\copy provenance from '/ens/laplante/BD6/provenance.dat' delimiter ','
