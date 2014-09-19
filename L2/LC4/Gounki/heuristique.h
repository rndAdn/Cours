/*
   //  heuristique.h
   //  ProjetRC
   //
   //  Created by Etienne Toussaint on 15/04/2014.
   //  Copyright (c) 2014 Etienne Toussaint. All rights reserved.
 */

#ifndef ProjetRC_heuristique_h
#define ProjetRC_heuristique_h
#include "grille.h"
#include "pion.h"
#include "partieHeuristique.h"

/*//int heuristiques (pion** grille,coup* coup,char joueur);*/
int calculHeuristiqueCoups(coup * pere, pion ** grille, char joueur,int type);
int calculHeuristiqueCoupsMultiples(coup * pere, pion ** grille, char joueur,int profondeur,int type);
void setReglageA(double armee,double perce, double def);
double* getReglageA();
void setReglageB(double armee,double perce, double def);
double* getReglageB();

#endif
