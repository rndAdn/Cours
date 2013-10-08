from tkinter import *
from time import sleep

class Aquarium:
    """gestion d'un aquarium:
    aquarium -- fenetre Tk
    eau -- canvas pour dessiner les poissons
    poissons -- liste de poissons"""
    def __init__(self, largeur=300, hauteur=200):
        """creation de l'aquarium avec de l'eau"""
        self.aquarium = Tk()
        Button(self.aquarium, text="Quitter",
               command=self.aquarium.quit).pack(side=TOP)
        self.eau = Canvas(width=largeur,height=hauteur,background='lightblue')
        self.eau.pack()
        self.eau.create_line(0,hauteur*1/3,largeur,hauteur*1/3)
        self.poissons = []

    def demarrer(self):
        """demarre l'animation de l'aquarium"""
        self.aquarium.mainloop()

    def creer_poisson(self,x=10,y=30,couleur='yellow'):
        """creation d'un poisson dans l'aquarium"""
        self.poissons.append(Poisson(self.eau,x,y,couleur))


class Poisson:
    """un poisson qui se promene dans un aquarium
    poisson -- le dessin du poisson
    eau -- canvas dans lequel se trouve le poisson
    couleur -- couleur du poisson
    x -- abscisse du poisson
    y -- ordonnee du poisson"""
    def __init__(self, eau, x, y, couleur):
        """creation d'un poisson"""
        self.eau = eau
        self.x = x
        self.y = int(self.eau.cget('height'))-y
        self.couleur = couleur
        self.poisson = eau.create_oval(self.x, self.y,
                                            self.x+15, self.y+10, fill=couleur)
        
    def avance(self, x=5, y=0):
        """deplacement relatif du poisson"""
        self.x = self.x+x
        self.y = self.y+y
        self.eau.move(self.poisson, x, y)
        self.eau.update()

if __name__=='__main__':
    A= Aquarium()
    A.creer_poisson(30,40,couleur='blue')
    A.creer_poisson(50,20,couleur='red')

    for i in range(0,30,1):
        sleep(0.3)
        for poisson in A.poissons:
            poisson.avance()
    A.demarrer
