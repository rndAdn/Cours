//
//  carnet.h
//  TP8
//
//  Created by Etienne Toussaint on 26/03/2014.
//  Copyright (c) 2014 Etienne Toussaint. All rights reserved.
//

#ifndef TP8_carnet_h
#include <stdlib.h>
#include <stdio.h>
#define TP8_carnet_h

typedef struct personne {
    int id; /* On prendra l'indice du tableau , par exemple */
    char *nom;
    char age;
    char telephone [10];
    char *notes;
}personne;

#endif
