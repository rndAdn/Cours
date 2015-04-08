drop table temps;
drop table etapes;
drop table coureurs;
drop table pays;
drop table equipes;

create table equipes(codeEquipe char(3),
nomEquipe char(25),
directeurSportif char(25),
primary key(CodeEquipe));

create table pays(codePays char(3),
nomPays char(20),
primary key(codePays));

create table coureurs(numeroCoureur integer,
nomCoureur char(50),
codeEquipe char(3),
codePays char(3),
primary key(numeroCoureur),
foreign key(codeEquipe) references equipes(CodeEquipe),
foreign key(codePays) references pays(codePays));

create table etapes(numeroEtape integer,
dateEtape date,
villeDepart char(20),
villeArrive char(20),
nbKm integer,
primary key(numeroEtape));

create table temps(numeroCoureur integer,
numeroEtape integer,
tempsRealise interval,
primary key(numeroCoureur, numeroEtape),
foreign key(numeroCoureur) references coureurs(numeroCoureur),
foreign key(numeroEtape) references etapes(numeroEtape));

insert into pays values ('ALL','Allemagne');
insert into pays values ('FRA','France');
insert into pays values ('SUI','Suisse');
insert into pays values ('AUT','AUTRICHE');
insert into pays values ('BEL','BELGIQUE');
insert into pays values ('DAN','DANEMARK');
insert into pays values ('ESP','ESPAGNE');
insert into pays values ('G-B','GRANDE BRETAGNE');
insert into pays values ('ITA','ITALIE');
insert into pays values ('P-B','PAYS-BAS');
insert into pays values ('RUS','RUSSIE');

insert into equipes values ('COF','Cofidis','Cyrille GUIMARD');
insert into equipes values ('ONC','O.N.C.E.','Manolo SAIZ');
insert into equipes values ('TEL','Telekom','Walter GODEFROOT');
insert into equipes values ('BAN','BANESTO','Eusebio UNZUE');
insert into equipes values ('CSO','CASINO','Vincent LAVENU');
insert into equipes values ('FDJ','LA FRANCAISE DES JEUX','Marc MADIOT');
insert into equipes values ('FES','FESTINA','Bruno ROUSSEL');
insert into equipes values ('GAN','GAN','Roger LEGEAY');
insert into equipes values ('SAE','SAECO','Claudio CORTI');

insert into coureurs values (8,'ULLRICH Jan','TEL','ALL');
insert into coureurs values (31,'JALABERT Laurent','ONC','FRA');
insert into coureurs values (61,'ROMINGER Tony','COF','SUI');
insert into coureurs values (62,'SASTRE Carlos','COF','ESP');
insert into coureurs values (91,'BOARDMAN Chris','GAN','G-B');
insert into coureurs values (114,'CIPOLLINI Mario','SAE','ITA');
insert into coureurs values (115,'ZABEL Erik','SAE','ALL');
insert into coureurs values (151,'OLANO Abraham','BAN','ESP');
INSERT INTO coureurs VALUES (13,'BIDOCHON Bernard','FDJ','FRA');
INSERT INTO coureurs VALUES (18,'TALON Achille','FDJ','ITA');
INSERT INTO coureurs VALUES (19,'SANSPAYS Bruno','FDJ',NULL);

insert into etapes values (1,'06/07/97','ROUEN','FORGES-LES-EAUX',192);
insert into etapes values (2,'07/07/97','ST-VALERY-EN-CAUX','VIRE',262);
insert into etapes values (3,'08/07/97','VIRE','PLUMELEC',224);
insert into etapes values (4,'09/07/97','MONT ST MICHEL','DINARD',52);

INSERT INTO temps VALUES (13,1,'04:54:33');
INSERT INTO temps VALUES (13,2,'06:54:33');
INSERT INTO temps VALUES (13,3,'04:59:33');
INSERT INTO temps VALUES (13,4,'03:04:33');
INSERT INTO temps VALUES (18,1,'05:04:33');
INSERT INTO temps VALUES (18,2,'06:34:33');
INSERT INTO temps VALUES (18,3,'04:59:43');
INSERT INTO temps VALUES (18,4,'02:04:33');
insert into temps values (8,3,'04:54:33');
insert into temps values (8,1,'04:48:21');
insert into temps values (8,2,'06:27:47');
insert into temps values (8,4,'01:12:19');
insert into temps values (31,3,'04:54:33');
insert into temps values (31,1,'04:48:37');
insert into temps values (31,2,'06:27:47');
insert into temps values (31,4,'01:04:13');
insert into temps values (61,1,'04:48:24');
insert into temps values (61,2,'06:27:47');
insert into temps values (91,3,'04:54:33');
insert into temps values (91,1,'04:48:19');
insert into temps values (91,2,'06:27:47');
insert into temps values (114,3,'04:54:44');
insert into temps values (114,1,'04:48:09');
insert into temps values (114,2,'06:27:47');
insert into temps values (151,3,'04:54:33');
insert into temps values (151,1,'04:48:29');
insert into temps values (151,2,'06:27:47');
insert into temps values (151,4,'01:06:13');
