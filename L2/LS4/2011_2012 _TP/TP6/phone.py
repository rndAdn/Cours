# telephone - version pour les etudiants

from tkinter import *
import string


class Telephone:
    """representation graphique d'un telephone:
    - appareil : fenetre graphique
    - ecran : champ d'affichage
    - clavier : champ de clavier
    - zone_texte : zone d'affichage du texte
    - touches : listes des lettres correspondant aux touches cliquees
    """
    def __init__(self):
        width = 150
        height = 300
        self.appareil = Tk()
        #initialisation de la zone d'ecriture
        self.ecran = Canvas(self.appareil, width=width, height=height/8)
        self.ecran.grid(row=0)
        self.zone_texte = Label(self.ecran)
        self.zone_texte.grid()
        #initialisation de la zone des touches
        self.clavier = Canvas(self.appareil, width=width, height=height/2, background='yellow')
        self.clavier.grid(row=1)
        for i in range(10):
            Touche(i,self)
        #initialisation de la liste des touches
        self.touches = []

    def complete_mot(self, lettres):
        # a completer
        self.zone_texte.configure(text='mot')

    def demarre(self):
        self.appareil.mainloop()

class Touche:
    """representation et positionnement d'une touche:
    - lettres : lettres associees (chaine de caracteres)
    - touche : objet graphique
    """
    def __init__(self, i, telephone):
        liste_lettres = (' ', '.,?', 'abc', 'def', 'ghi',
                   'jkl', 'mno', 'pqrs', 'tuv', 'wxyz')
        touche = Button(telephone.clavier, width='10',
                             text=str(i)+' '+liste_lettres[i],
                             command=lambda l=liste_lettres[i]: telephone.complete_mot(l))
        if i==0:
            touche.grid(row=3, column=1)
        else:
            touche.grid(row=((i-1)//3), column=(i-1)%3)
            

if __name__ == "__main__":
    t = Telephone()
    t.demarre()

