/*
   //  partieHeuristique.h
   //  ProjetRC
   //
   //  Created by Etienne Toussaint on 15/04/2014.
   //  Copyright (c) 2014 Etienne Toussaint. All rights reserved.
 */

#ifndef ProjetRC_partieHeuristique_h
#define ProjetRC_partieHeuristique_h

#include <stdio.h>
#include <stdlib.h>
#include "Grille.h"
#include "pion.h"
#include "test.h"
#include <time.h>
#include "heuristique.h"
#include "Jouer.h"

int partiH();
int jouerCoupIA(pion ** grille, char joueur,int difficulter,int testIA, int ad,int type);



#endif
