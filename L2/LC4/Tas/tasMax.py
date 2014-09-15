#!/opt/local/bin/python

import struct

dicoH = dict()

def importer(path):
	res = ""
	f = open(path,"r").readlines()
	for s in f:
		res += s
	return res

def creerDico(texte):
	d = dict()
	for c in texte:
		d[c] = d.get(c,0) + 1
	return d

def hauffman(tas):
	arbre1 = tas.extraction_min()
	arbre2 = tas.extraction_min()
	arbre = ArbreHauff(fre = arbre1.freq+arbre2.freq,gauche =arbre1 ,droit = arbre2)

def encode(texte,hauf):
	res = ""
	for c in texte:
		res += hauf[c]
	return res

def decode(texteEncod,hauf):
	hauf = {v:k for k, v in hauf.items()}
	res = ""
	car = ""
	for c in texteEncod:
		car += c
		if car in hauf.keys():
			res += hauf[car]
			car = ""
	return res

class tasMin(list):
	def __init__(self,dico):
		T = dico
		self.extend(self.creer_tas_min(T))

	def creer_tas_min(self,T) :
		for i in range(len(T)//2, -1, -1) :
			self.entasser_min(T, i)
		return T

	def trier(self):
		T = self
		for i in range(len(T)-1,-1, -1) :
				T[0], T[i] = T[i], T[0]
				self.entasser_min(T, 1)
		return T

	def entasser_min(self,T, i) :
		min, l, r = i, 2*i+1, 2*i+2
		print(str(i)+":")
		print("Avant"+str(T))
		if l < len(T) and T[l] < T[min] : min = l
		if r < len(T) and T[r] < T[min] : min = r
		if min != i :
			T[i], T[min] = T[min], T[i]
			print("Aprés"+str(T))
			self.entasser_min(T, min)

	def extraction_min(self) :
		max = self[0]
		if(len(self)==1):
			self.pop()
		else :
			self[0] = self.pop()
		self.entasser_min(self, 0)
		return max

	def ajouter(self,element):
		self.insert(0,element)
		self.entasser_min(self, 0)

	def hauffman(self):
			arbre1 = self.extraction_min()
			arbre2 = self.extraction_min()
			arbre = ArbreHauff(fre = arbre1.freq+arbre2.freq,gauche =arbre1 ,droit = arbre2)
			self.ajouter(arbre)
			if len(self)>1:
				self.hauffman()



class ArbreHauff():
	def __init__(self,fre,gauche=None,droit=None,char=None):
		self.freq = fre
		self.gauche = gauche
		self.droit = droit
		self.char = char

	def __repr__(self):
		return str(self.freq)

	def creerDict(self,string=""):
		if self.char!=None:
			dicoH[self.char]=string
		else:
			self.gauche.creerDict(string+"0")
			self.droit.creerDict(string+"1")
