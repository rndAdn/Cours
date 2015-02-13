import psycopg2 as dbapi2
import sys

fic = open("tables.txt","w")
db = dbapi2.connect (database=sys.argv[2], user=sys.argv[1])
curs = db.cursor()
curs.execute("""SELECT table_name FROM information_schema.tables
WHERE table_schema='public' AND table_type='BASE TABLE'""")
tables = (x[0] for x in curs.fetchall())
for tbl in tables:
    curs2 = db.cursor()
    curs2.execute("""SELECT * FROM """+tbl+""" limit 2""")
    colnames = [desc[0] for desc in curs2.description]
    results = (x for x in curs2.fetchall())
    fic.write(tbl+" :\n")
    for c in colnames:
        fic.write(c+" | ")
    fic.write("\n")
    for r in results:
        fic.write(str(r)+"\n")
    fic.write("\n")
