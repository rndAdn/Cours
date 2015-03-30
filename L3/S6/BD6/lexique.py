import psycopg2 as dbapi2
import sys

db = dbapi2.connect (database=sys.argv[2], user=sys.argv[1])
curs = db.cursor()
curs.execute("CREATE TABLE lexique (id_mot serial PRIMARY KEY, mot varchar);")

lex = open("lexique.txt","r")
for word in lex.readlines():
    curs.execute("INSERT INTO lexique (mot) VALUES ('+word+');")

db.commit()
curs.close()
db.close()

