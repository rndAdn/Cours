/*
   //  pion.h
   //  ProjetRC
   //
   //  Created by Etienne Toussaint on 13/04/2014.
   //  Copyright (c) 2014 Etienne Toussaint. All rights reserved.
 */

#ifndef ProjetRC_pion_h
#define ProjetRC_pion_h

typedef struct pion {
        int x;
        int y;
        char joueur;
        int type;
        int typeInterne;
}pion;

pion initPion(int x,int y);
pion initRond(int x,int y,char joueur);
pion initCarre(int x,int y,char joueur);
void defPion(pion *p,char joueur);

int deplacement(pion pionDepart,pion pionArrive);
int deployement(pion pionDepart,pion pionArrive);
int deployement2(pion pionDepart,pion pionArrive);

void calculTypeInterne(pion* pionjoueur);


#endif
