#! /usr/local/bin/python3.4


class UnionFind():

    def __init__(self, tableau):
        self.pere = {element: element for element in tableau}
        self.nombreFils = {element: 1 for element in tableau}

    def find(self, u, v):
        return (self.root(u) == self.root(v))

    def root(self, element):
        if(element == self.pere[element]):
            return element
        else:
            rootElement = self.root(self.pere[element])
            self.pere[element] = rootElement
            return rootElement

    def union(self, u, v):
        if self.find(u, v) == False:
            rootU = self.root(u)
            rootV = self.root(v)
            if self.nombreFils[rootU] > self.nombreFils[rootV]:
                self.pere[rootV] = rootU
                self.nombreFils[rootU] += self.nombreFils[rootV]
            else:
                self.pere[rootU] = rootV
                self.nombreFils[rootV] += self.nombreFils[rootU]
