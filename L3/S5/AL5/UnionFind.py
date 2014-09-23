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
            self.pere[element] = self.root(self.pere[element])
            return self.pere[element]

    def union(self, u, v):
        rootU = self.root(u)
        rootV = self.root(v)
        if not(rootU == rootV):
            if self.nombreFils[rootU] > self.nombreFils[rootV]:
                self.pere[rootV] = rootU
                self.nombreFils[rootU] += self.nombreFils[rootV]
            else:
                self.pere[rootU] = rootV
                self.nombreFils[rootV] += self.nombreFils[rootU]
