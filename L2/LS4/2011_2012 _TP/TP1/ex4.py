#!/usr/bin/env python3

# Exercice 4

def somme_bete(nombre) :
	'''
		hfoehfehfoeh
	'''
	total=0
	for i in range(0,nombre+1,1) :
		total+=i

	return total

def somme_rapide(nombre) :
	return nombre*(nombre + 1)/2

#print ('somme bete = '+str(somme_bete(100))+' somme rapide '+str(somme_rapide(100)))

autre_liste = [[1, 'a'],[4, 'd'],[7, 'g'],[26, 'z'],] # J'ai étalé la liste sur plusieurs lignes
for nb, lettre in autre_liste:
    print(" La lettre {} est la {}e de l'alphabet.".format(lettre, nb))
