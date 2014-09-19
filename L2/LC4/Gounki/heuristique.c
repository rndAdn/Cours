/*
   //  heuristique.c
   //  ProjetRC
   //
   //  Created by Etienne Toussaint on 15/04/2014.
   //  Copyright (c) 2014 Etienne Toussaint. All rights reserved.
 */

#include <stdio.h>
#include "heuristique.h"
#include <string.h>

#define HEURISTIQUE_ARMEE 3.351562;
#define HEURISTIQUE_PERCEE 1.466797;
#define HEURISTIQUE_DEFENSE 1.201172;
#define min(a, b)       ((a) < (b) ? (a) : (b))
#define max(a, b)       ((a) < (b) ? (b) : (a))


double heuristique_armeeA;
double heuristique_perceeA;
double heuristique_defenseA;

double heuristique_armeeB;
double heuristique_perceeB;
double heuristique_defenseB;

void setReglageA(double arme, double perce,double def){
        heuristique_armeeA = arme;
        heuristique_perceeA = perce;
        heuristique_defenseA = def;
}

double* getReglageA(){
        double * result;
        result= calloc(3,sizeof(double));;
        result[0]=heuristique_armeeA;
        result[1]=heuristique_perceeA;
        result[2]=heuristique_defenseA;
        return result;
}

void setReglageB(double arme, double perce,double def){
        heuristique_armeeB = arme;
        heuristique_perceeB = perce;
        heuristique_defenseB = def;
}

double* getReglageB(){
        double * result;
        result= calloc(3,sizeof(int));;
        result[0]=heuristique_armeeB;
        result[1]=heuristique_perceeB;
        result[2]=heuristique_defenseB;
        return result;
}


void setNormal(){
        heuristique_armeeA = HEURISTIQUE_ARMEE;
        heuristique_perceeA = HEURISTIQUE_PERCEE;
        heuristique_defenseA = HEURISTIQUE_DEFENSE;
        heuristique_armeeB = HEURISTIQUE_ARMEE;
        heuristique_perceeB = HEURISTIQUE_PERCEE;
        heuristique_defenseB = HEURISTIQUE_DEFENSE;
}

void setRush(){
        heuristique_armeeA = HEURISTIQUE_ARMEE;
        heuristique_perceeA = 2*HEURISTIQUE_PERCEE;
        heuristique_defenseA = HEURISTIQUE_DEFENSE;
        heuristique_armeeB = HEURISTIQUE_ARMEE;
        heuristique_perceeB = 2*HEURISTIQUE_PERCEE;
        heuristique_defenseB = HEURISTIQUE_DEFENSE;
}

void setBlock(){
        heuristique_armeeA = HEURISTIQUE_ARMEE;
        heuristique_perceeA = HEURISTIQUE_PERCEE;
        heuristique_defenseA = 2*HEURISTIQUE_DEFENSE;
        heuristique_armeeB = HEURISTIQUE_ARMEE;
        heuristique_perceeB = HEURISTIQUE_PERCEE;
        heuristique_defenseB = 2*HEURISTIQUE_DEFENSE;
}

void setLoose(){
        heuristique_armeeA = 2*HEURISTIQUE_ARMEE;
        heuristique_perceeA = HEURISTIQUE_PERCEE;
        heuristique_defenseA = HEURISTIQUE_DEFENSE;
        heuristique_armeeB = 2*HEURISTIQUE_ARMEE;
        heuristique_perceeB = HEURISTIQUE_PERCEE;
        heuristique_defenseB = HEURISTIQUE_DEFENSE;
}

int heuristiques (pion** grille,coup* coup,char joueur,int type){
        int maxY, minY;
        double resultat;
        pion** grilleCpy;
        int x;
        int y;
        switch (type) {
        case -1:
                break;
        case 0:
                setNormal();
                break;
        case 1:
                setRush();
                break;
        case 2:
                setBlock();
                break;
        case 3:
                setLoose();
                break;
        default:
                setNormal();
                break;
        }
        maxY=0;
        minY=7;
        resultat= 0;
        grilleCpy= copieGrille(grille);
        if (coup->proto == NULL) {
                freeGrille(grilleCpy);
                return -9999;
        }
        if ( coup->proto!=  NULL && coup->proto[2]=='#') {
                freeGrille(grilleCpy);
                return 9999;
        }
        else if (coup->proto != NULL && coup->proto != 0 ) action(grilleCpy, coup->proto,coup,0);
        x=0;
        y=0;
        for (x=0; x<8; x++) {
                for (y=0; y<8; y++) {
                        if(grilleCpy[x][y].joueur == 'A') maxY= max(maxY,y);
                        else if(grilleCpy[x][y].joueur == 'B') minY=min(minY,y);
                        if(joueur == 'A') resultat += (grilleCpy[x][y].joueur == joueur ? grilleCpy[x][y].type : -grilleCpy[x][y].type)*heuristique_armeeA;
                        if(joueur == 'B') resultat += (grilleCpy[x][y].joueur == joueur ? grilleCpy[x][y].type : -grilleCpy[x][y].type)*heuristique_armeeB;

                }
        }
        if(joueur == 'A') resultat+=maxY*heuristique_perceeA;
        if(joueur == 'B') resultat+=(7-minY)*heuristique_perceeB;
        if(joueur == 'A') resultat-=(7-minY)*heuristique_defenseA;
        if(joueur == 'B') resultat-=(maxY)*heuristique_defenseB;

        freeGrille(grilleCpy);
        return (int)resultat;
}

int heuristiquesMultiple (pion** grille,coup* coup,char joueur,int profondeur,int type){
        int max;
        char joueurTemp;
        struct coup * pere;
        pion** grilleCpy;
        profondeur--;
        grilleCpy= copieGrille(grille);
        if (coup->proto == NULL) {
                freeGrille(grilleCpy);
                return -9999;
        }
        if ( coup->proto!=  NULL && coup->proto[2]=='#') {
                freeGrille(grilleCpy);
                return 9999;
        }
        else if (coup->proto != NULL && coup->proto != 0 ) action(grilleCpy, coup->proto,coup,0);

        joueurTemp= joueur;
        if(joueurTemp == 'A') joueurTemp = 'B';
        else joueurTemp = 'A';

        if(jouerCoupIA(grilleCpy, joueurTemp,0,1,0,0)) {
                freeGrille(grilleCpy);
                return -9998;
        }
        if(joueurTemp == 'A') joueurTemp = 'B';
        else joueurTemp = 'A';
        pere = calloc(1,sizeof(struct coup));
        pere->proto = NULL;
        pere->coupSuivant = NULL;
        pere = coupsPossibles(grilleCpy, joueurTemp,pere);
        max= -9999;
        if(profondeur>0) max = calculHeuristiqueCoupsMultiples(pere, grilleCpy,joueurTemp,profondeur,type);
        else max = calculHeuristiqueCoups(pere, grilleCpy,joueurTemp,type);
        freeCoup(pere,1);
        freeGrille(grilleCpy);
        return max;
}

int calculHeuristiqueCoups(coup * pere, pion ** grille, char joueur,int type){
        int max;
        coup * coupPossible;
        max = -1000000;
        coupPossible = pere;
        while (coupPossible != NULL) {
                coupPossible->heuristique = heuristiques(grille, coupPossible, joueur,type);
                if(coupPossible->heuristique > max) max = coupPossible->heuristique;
                /*printf("%s|%d\n",coupPossible->proto,coupPossible->heuristique);*/
                coupPossible = coupPossible->coupSuivant;
        }
        return max;
}
int calculHeuristiqueCoupsMultiples(coup * pere, pion ** grille, char joueur,int prodondeur,int type){
        int max;
        coup * coupPossible;
        max=-1000000;
        coupPossible = pere;
        while (coupPossible != NULL) {
                coupPossible->heuristique = heuristiquesMultiple(grille, coupPossible, joueur,prodondeur,type);
                if(coupPossible->heuristique > max) max = coupPossible->heuristique;
                /*printf("%s|%d\n",coupPossible->proto,coupPossible->heuristique);*/
                coupPossible = coupPossible->coupSuivant;
        }
        return max;
}
