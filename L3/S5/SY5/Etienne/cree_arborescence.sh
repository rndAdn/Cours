#! /bin/bash

mkdir Arborescence
cd Arborescence

mkdir -p A/A

touch A/A/titi
touch A/A/toto
touch A/A/tutu

cp -r A/A/ A/B
cp -r A/A/ A/C
cp -r A B
mkdir C
cp -r A C/A 
cp -r A C/B
cp -r A/A C/C

mkdir -p Vide/.Cachee
cp -r A B C Vide/.Cachee
touch Vide/.coucou
touch Vide/.Cachee/A/.coucou
touch Vide/.Cachee/A/A/.coucou
touch Vide/.Cachee/C/B/.coucou
mv Vide/.Cachee/C Vide/.Cachee/.C
mv Vide/.Cachee/B/C Vide/.Cachee/B/.C


mkdir Protegee
cp -r A B C Protegee

yes "voici un texte un peu répétitif" | head -237 > Protegee/A/toutou

chmod 600 Protegee/A	# pas exec
chmod 500 Protegee/B	# pas ecriture
chmod 300 Protegee/C/A/B
chmod 600 Protegee/C/C
chmod 300 Protegee/C/B
chmod 600 Protegee/C/A/A
chmod 300 Protegee/C	# pas lecture

echo "Ton visage écarlate ton biplan transformable en hydroplan" > hareng

mkdir Profonde
cp -r B/* A/A
cp -r B/* A/A/B
cp -r A B/A
cp -r C B/C
cp -r C/A B/C
cp -r C/B B/C
mv A B C Profonde


cd Profonde
echo "Souriez, vous êtes filmés" > vigile
ln vigile A/A/B/gardien
ln vigile A/A/C/.camera
ln vigile A/A/B/A/camera
ln vigile A/C/infrarouge
ln vigile B/C/B/patrouille
ln vigile B/C/C/A/A/.camera
ln vigile B/C/C/B/enregistreur
ln vigile B/C/.infrarouge
ln vigile B/A/A/A/B/C/.detecteur
ln vigile B/A/A/B/.vigile
ln vigile B/A/A/A/detecteur

touch A/A/B/C/.diamants
touch B/A/A/B/.emeraudes
touch B/C/B/A/.rubis
touch B/C/C/B/C/.saphirs

cd C
rm -rf */C
find . -name 't?t?' -delete

touch C/titi ; ln C/titi A/A/toto ; ln C/titi B/B/titi
touch A/B/titi ; ln A/B/titi A/B/tutu
touch A/B/toto
touch B/toto ; ln B/toto B/A/toto
touch B/A/tutu


