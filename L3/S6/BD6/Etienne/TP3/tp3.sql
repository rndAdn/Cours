/*
CREATE TABLE client(
  nom varchar(30),
  prenom varchar(30),
  adr varchar(50),
  ss varchar(30)
);


INSERT into client values ('a','b','ici','1');
INSERT into client (nom,prenom,ss) values ('a','b','1');
INSERT into client values ('d','e','la','8');


CREATE TABLE client(
  id_client int,
  nom varchar(30),
  prenom varchar(30),
  adr varchar(50),
  ss varchar(30)
);


INSERT into client values (12,'a','b','ici','1');
INSERT into client values (12,'c','d','la','2');
INSERT into client values (15,'e','f','here','3');
*/

DELETE * FROM client WHERE 
ALTER TABLE client ADD UNIQUE(id_client);
