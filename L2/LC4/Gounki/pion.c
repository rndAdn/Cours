/*
   //  pion.c
   //  ProjetRC
   //
   //  Created by Etienne Toussaint on 13/04/2014.
   //  Copyright (c) 2014 Etienne Toussaint. All rights reserved.
 */

#include <stdio.h>
#include <math.h>
#include "pion.h"

int signeB(int test){
        if (test > 0)
                return 1;
        if (test < 0)
                return -1;
        return 0;
}


void calculTypeInterne(pion* pion){
        int joueur;
        joueur= 0;
        if(pion->joueur == 'B') joueur = -1;
        if(pion->joueur == 'A') joueur = 1;
        switch (pion->type) {
        case 0:
                pion->typeInterne =  0;
                break;
        case 1:
                pion->typeInterne =  11*joueur;
                break;
        case 2:
                pion->typeInterne =  101*joueur;
                break;
        case 3:
                pion->typeInterne =  21*joueur;
                break;
        case 4:
                pion->typeInterne =  201*joueur;
                break;
        case 5:
                pion->typeInterne =  31*joueur;
                break;
        case 6:
                pion->typeInterne =  301*joueur;
                break;
        case 7:
                pion->typeInterne =  111*joueur;
                break;
        case 8:
                pion->typeInterne =  121*joueur;
                break;
        case 9:
                pion->typeInterne =  211*joueur;
                break;
        }
}


int deplacement(pion pionDepart,pion pionArrive){
        int signeP;
        signeP= signeB(pionDepart.typeInterne);
        if (pionArrive.typeInterne == 9999||pionArrive.typeInterne == -9999)
                return 0;
        if(signeP*(pionDepart.typeInterne%100/10)+signeP*(pionDepart.typeInterne%1000/100)+signeP*(pionArrive.typeInterne%100/10)+signeP*(pionArrive.typeInterne%1000/100) < 4)
                return 1;
        if(pionDepart.typeInterne%10!=pionDepart.typeInterne%10)
                return 1;
        return 0;
}


int deployement(pion pionDepart,pion pionArrive){
        int signeA;
        signeA= signeB(pionArrive.typeInterne);
        if (pionArrive.typeInterne == 9999||pionArrive.typeInterne == -9999)
                return 0;
        if(signeA*(pionArrive.typeInterne%100/10)+signeA*(pionArrive.typeInterne%1000/100) < 3 && (pionArrive.joueur == 'V' || pionArrive.joueur == pionDepart.joueur ))
                return 1;
        return 0;
}

int deployement2(pion pionDepart,pion pionArrive){
        int signeA;
        signeA=signeB(pionArrive.typeInterne);
        if (pionArrive.typeInterne == 9999||pionArrive.typeInterne == -9999)
                return 0;
        if(signeA*(pionArrive.typeInterne%100/10)+signeA*(pionArrive.typeInterne%1000/100) < 2 && (pionArrive.joueur == 'V' || pionArrive.joueur == pionDepart.joueur ))
                return 1;
        return 0;
}

pion initPion(int x, int y){
        pion newPion;
        newPion.x = x;
        newPion.y=y;
        newPion.joueur='V';
        newPion.type=0;
        calculTypeInterne(&newPion);
        return newPion;
}

pion initRond(int x, int y,char joueur){
        pion newPion;
        newPion.x = x;
        newPion.y=y;
        newPion.joueur=joueur;
        newPion.type=2;
        calculTypeInterne(&newPion);
        return newPion;
}

pion initCarre(int x, int y,char joueur){
        pion newPion;
        newPion.x = x;
        newPion.y=y;
        newPion.joueur=joueur;
        newPion.type=1;
        calculTypeInterne(&newPion);
        return newPion;
}

void defPion(pion *p,char joueur){
        p->joueur = joueur;
        switch ((int)fabs(p->typeInterne)) {
        case 0:
                p->type = 0;
                break;
        case 11:
                p->type = 1;
                break;
        case 101:
                p->type = 2;
                break;
        case 21:
                p->type = 3;
                break;
        case 201:
                p->type = 4;
                break;
        case 31:
                p->type = 5;
                break;
        case 301:
                p->type = 6;
                break;
        case 111:
                p->type = 7;
                break;
        case 121:
                p->type = 8;
                break;
        case 211:
                p->type = 9;
                break;

        }
}
