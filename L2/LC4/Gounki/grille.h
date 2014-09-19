/*
   //  grille.h
   //  ProjetRC
   //
   //  Created by Etienne Toussaint on 13/04/2014.
   //  Copyright (c) 2014 Etienne Toussaint. All rights reserved.
 */

#ifndef ProjetRC_grille_h
#define ProjetRC_grille_h
#include "pion.h"
#include <stdlib.h>
#include <math.h>
#include "persistance.h"


typedef struct coup {
        char * proto;
        int heuristique;
        struct coup* coupSuivant;
}coup;

pion ** initGrille();
void freeGrille(pion ** grille);
void freeCoup(coup * pere,int i);
coup* coupsPossibles(pion** grilleActuelle,char joueur,coup * pere);
int action(pion ** grille,char * proto,coup* coupPere,int fake);
pion ** grilleString(pion ** grille,char * string);
pion ** copieGrille(pion ** grille);

#endif
