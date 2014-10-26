ls -ld #affiche les permision du repertoire
ls #affiche le contenu du repertoire courant
1:droit a l'execution / droit de traverser
2:droit à l'écriture
3:droit a la lecture / droit d'affichage de contenu
chmod UGA nomDeDossierFichier pour modifier

cat -b #lit un fichier texte avec numero de ligne
rm -rf #force et suprime recursivement

ls -Ri #affiche l'arborence complete avec le inode
ln fichier lien #pour creer un lien
cp fichier copier #pour creer une copie

echo "texte" >> fichier #pour ecrire a la fin d'un fichier
find dossier -name nom -type f #pour trouver tout les fichier de nom nom dans dossier f precise seulment des fichier
find dossier -name N -exec rm {} -rf #exec permet d'exécuter une commande
find dossier -iname 2424 #pour rechercher par inode

grep -a string file #recherche et affiche les line ou string apparait dans file
grep REGEX file #recherche et affiche les line ou il y a un match
grep -v REGEX file #recherche et les affiche les lignes ou ca match pas
