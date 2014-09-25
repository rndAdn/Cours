
# EX6

## 1

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

## 2

```
ln rep1/rep3/fic2 lp_fic2
ln -s rep1/rep3/fic2 ls_fic2
```
```
805431 -rwxrwxrwx 2 renaud users 0 24 sept. 13:33 rep1/rep3/fic2*

805431 -rwxrwxrwx 2 renaud users    0 24 sept. 13:33 lp_fic2*
805436 lrwxrwxrwx 1 renaud users   14 24 sept. 13:36 ls_fic2 -> rep1/rep3/fic2*
```

## 3
```
chmod 700 ls_fic2                                                                                                              13:42 24/09
```
```
805431 -rwx------ 2 renaud users    0 24 sept. 13:33 lp_fic2*
805436 lrwxrwxrwx 1 renaud users   14 24 sept. 13:36 ls_fic2 -> rep1/rep3/fic2*

805431 -rwx------ 2 renaud users 0 24 sept. 13:33 rep1/rep3/fic2*
```

##4

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

## 5

```
mv rep1/rep3/fic2 rep1

cat  lp_fic2 # OK
cat  ls_fic2 # Aucun fichier ou dossier de ce type

```

## 6

```
echo -e "Tel un phenix, je renais de mes cendres." > rep1/rep3/fic2
cat lp_fic2 # affiche rep1/fic2
cat ls_fic2 # affiche rep1/rep3/fic2
    Tel un phenix, je renais de mes cendres.
```
