/*
   //  persistance.h
   //  ProjetRC
   //
   //  Created by Etienne Toussaint on 08/05/2014.
   //  Copyright (c) 2014 Etienne Toussaint. All rights reserved.
 */

#ifndef ProjetRC_persistance_h
#include "grille.h"
#include "pion.h"
#include <time.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#define ProjetRC_persistance_h

void save(pion ** grille, char joueur, int mode);
char * charger();
int charToInt(char c);

#endif
