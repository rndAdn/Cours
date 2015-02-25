
# EX6

##

```
mkdir tp1
cd tp1
mkdir rep1 rep2
cd rep1
mkdir rep3
touch fic1
cd rep3
touch fic2
```

##

```
ln rep1/rep3/fic2 lp_fic2
ln -s rep1/rep3/fic2 ls_fic2
```
```
805431 -rwxrwxrwx 2 renaud users 0 24 sept. 13:33 rep1/rep3/fic2*

805431 -rwxrwxrwx 2 renaud users    0 24 sept. 13:33 lp_fic2*
805436 lrwxrwxrwx 1 renaud users   14 24 sept. 13:36 ls_fic2 -> rep1/rep3/fic2*
```

##
```
chmod 700 ls_fic2                                                                                                              13:42 24/09
```
```
805431 -rwx------ 2 renaud users    0 24 sept. 13:33 lp_fic2*
805436 lrwxrwxrwx 1 renaud users   14 24 sept. 13:36 ls_fic2 -> rep1/rep3/fic2*

805431 -rwx------ 2 renaud users 0 24 sept. 13:33 rep1/rep3/fic2*
```

##

```
chmod 000 rep1/rep3
```
```
d--------- 2 renaud users 4096 24 sept. 13:33 rep3/
```

```
cat  lp_fic2 # OK
cat  ls_fic2 # Permission non accordée

chmod 755 rep1/rep3
```

##

```
mv rep1/rep3/fic2 rep1

cat  lp_fic2 # OK
cat  ls_fic2 # Aucun fichier ou dossier de ce type

```

##

```
echo -e "Tel un phenix, je renais de mes cendres." > rep1/rep3/fic2
cat lp_fic2 # affiche rep1/fic2
cat ls_fic2 # affiche rep1/rep3/fic2
    Tel un phenix, je renais de mes cendres.
```

##  

```
mv ls_fic2 rep1
cat rep1/ls_fic2 # Aucun fichier ou dossier de ce type
```

##

```
ln -s rep1/rep3/ ls_rep3
```
```
lrwxrwxrwx 1 renaud users    9 26 sept. 16:31 ls_rep3 -> rep1/rep3/
```

##
```
ln -s ls_rep3 rep2/ls_ls_rep3
```
```
lrwxrwxrwx 1 renaud users 7 26 sept. 16:33 ls_ls_rep3 -> ls_rep3
```

##

```
cd ls_rep3
pwd                                                                                                              6:16 25/09
/home/renaud/SY5/tp1/ls_rep3
pwd -P                                                                                                           6:16 25/09
/home/renaud/SY5/tp1/rep1/rep3




```
