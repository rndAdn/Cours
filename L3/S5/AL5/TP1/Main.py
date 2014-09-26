#! /usr/bin/python

from PIL import Image
import os
import sys


class Pix():

    def __init__(self, x, y):
        self.coor = (x, y)
        self.pere = self
        self.taille = 1

    def __repr__(self):
        return str(self.coor)+" "+str(self.taille)


def photo_to_list(path):
    """
        Ouvre l'image et renvoi la liste des pixels
    """
    im = Image.open(path)
    im = im.convert("L")
    ens = {a for a in list(im.getdata())}
    print(ens)
    width, height = im.size
    im = list(im.getdata())
    #tab = [[im[y*width+x] for x in range(width)] for y in range(height)]

    tab = [im[y * width:(y + 1) * width] for y in range(height)]
    return tab


def create_Pix_Ens(png):

    ens = []
    for y in range(len(png)):
        for x in range(len(png[y])):
            if png[y][x] == 0:
                ens += [Pix(x, y)]
    print(len(ens))
    return ens


def root(p):
    if p.pere != p:
        p.pere = root(p.pere)
    return p.pere


def find(p1, p2):
    return root(p1) == root(p2)


def union(p1, p2):
    if not find(p1, p2):
        rootP1 = root(p1)
        rootP2 = root(p2)
        if rootP1.taille > rootP2.taille:
            rootP2.pere = rootP1
            rootP1.taille += rootP2.taille
            # rootP2.taille = 1
        else:
            rootP1.pere = rootP2
            rootP2.taille += rootP1.taille
            # rootP1.taille = 1


def r_Voisins(p1, p2):
    if ((p1.coor[1]-p2.coor[1])**2 > int(sys.argv[2])**2):
        return 2
    elif ((p1.coor[0]-p2.coor[0])**2 + (p1.coor[1]-p2.coor[1])**2) <= int(sys.argv[2])**2:
        return 1
    return 0


def algo(ens_Pix):
    for p1 in range(len(ens_Pix)):
        for p2 in ens_Pix[p1:]:
            tmp = r_Voisins(ens_Pix[p1], p2)
            if tmp == 2:
                break
            elif tmp == 1:
                union(ens_Pix[p1], p2)
    i = 0
    for e in ens_Pix:
        if e.taille > int(sys.argv[3]):
            #print(e)
            if e.pere == e:
                i += 1
    return i


if __name__ == '__main__':
    if(len(sys.argv) != 4):
        print("Nb_args")

    png = photo_to_list(sys.argv[1])

    print(algo(create_Pix_Ens(png)))
