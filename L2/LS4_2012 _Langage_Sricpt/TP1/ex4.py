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

print ('somme bete = '+str(somme_bete(100))+' somme rapide '+str(somme_rapide(100)))