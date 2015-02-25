
CREATE TABLE Client(
    nom text,
    prenom text,
    adresse text,
    ss text
);

INSERT INTO Client Values ('a', 'b', 'ici', 1);
INSERT INTO Client(nom, prenom, adresse, ss) Values ('a', 'b', 'ici', 1);
INSERT INTO Client(ss) Values (1);

SELECT * FROM Client;

DROP TABLE Client;

CREATE TABLE Client(
    id_client SERIAL PRIMARY KEY,
    nom text,
    prenom text,
    adresse text,
    ss text
);

INSERT INTO Client(nom, prenom, adresse, ss) Values ('a', 'b', 'ici', 1);
INSERT INTO Client(nom, prenom, adresse, ss) Values ('a', 'b', 'ici', 1);
--INSERT INTO Client(ss) Values (1);--

SELECT * FROM Client;

-- MOOC Jennifer widown UML--

--ALTER TABLE Client ADD UNIQUE(id_client);--
--ALTER TABLE Client ADD PRIMARY KEY(id_client);--

/*CREATE TABLE data_brut(
    A text,
    B text,
    C text,
    D text,
    E text,
    F text,
    G text,
    H text,
    I text,
    J text,
    K text,
    L text,
    M text,
    N text,
    O text,
    P text,
    Q text,
    R text,
    S text,
    T text,
    U text,
    V text,
    W text,
    X text,
    Y text,
    Z text,
    AA text
);

COPY data_brut FROM '/media/data/git/Cours/L3/S6/BD6/Renaud/tp3/villes.csv' DELIMITER ',' CSV;
*/
