/*
   //  grille.c
   //  ProjetRC
   //
   //  Created by Etienne Toussaint on 13/04/2014.
   //  Copyright (c) 2014 Etienne Toussaint. All rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grille.h"
#include "heuristique.h"
#include "Jouer.h"

int heuristique_ok = 1;


pion ** copieGrille(pion ** grille){
        pion** grilleCpy = malloc(sizeof(pion *)*8);
        int x,y;
        x=0,y=0;
        for (x=0; x<8; x++) {
                *(grilleCpy+x) = malloc(sizeof(pion)*8);
                for (y=0; y<8; y++) {
                        *(*(grilleCpy+x)+y) = grille[x][y];
                }
        }
        return grilleCpy;
}

pion ** initGrille(){
        pion** grille;
        int x,y;
        grille = malloc(sizeof(pion *)*8);
        x=0,y=0;
        for (x=0; x<8; x++) {
                *(grille+x) = malloc(sizeof(pion)*8);
                for (y=0; y<8; y++) {
                        if(y<2 && (x+y)%2==0) *(*(grille+x)+y) = initCarre(x,y,'A');
                        else if (y<2 && (x+y)%2==1) *(*(grille+x)+y) = initRond(x,y,'A');
                        else if(y>5 && (x+y)%2==0) *(*(grille+x)+y) = initCarre(x,y,'B');
                        else if (y>5 && (x+y)%2==1) *(*(grille+x)+y) = initRond(x,y,'B');
                        else *(*(grille+x)+y) = initPion(x,y);
                }
        }

        return grille;
}

pion ** grilleString(pion ** grille,char * chargement){
        int i;
        i= 0;
        for (i=0; i<64; i++) {
                grille[i%8][i/8].type = charToInt(chargement[3*i+1]);
                grille[i%8][i/8].joueur =(chargement[3*i] == 'B') ? 'A' : (chargement[3*i] == 'N') ? 'B' : 'V';
                calculTypeInterne(&grille[i/8][i%8]);
                calculTypeInterne(&grille[i/8][i%8]);
        }
        return grille;
}


void initChar(char * string, int stringLen){
        int i;
        i= 0;
        for (i=0; i<stringLen; i++) {
                string[0]=0;
        }
}

void freeGrille(pion ** grille){
        int x;
        x= 0;
        for (x=0; x<8; x++) {
                free(grille[x]);
                grille[x]=NULL;
        }
        free(grille);
        grille=NULL;
}

void freeCoup(coup * pere,int i){
        if (pere->coupSuivant != NULL) {
                freeCoup(pere->coupSuivant,i);
        }
        if(i) free(pere->proto),pere->proto = NULL;
        pere->coupSuivant = NULL;
        pere->heuristique = 0;
        free(pere);
        pere = NULL;
}

pion grillePion(pion** grille,int x,int y){
        if(x>7||x<0||y>7||y<0) {
                pion test;
                test.joueur= 'N';
                test.typeInterne = 9999;
                return test;
        }
        return grille[x][y];
}

char * caract(int turn, int type){
        if(turn == 1) return "-";
        if(type == 1) return "+";
        return "*";
}

int signe(int test){
        if (test > 0)
                return 1;
        if (test < 0)
                return -1;
        return 0;
}

char * concat(char * string1,char * string2){
        char * result;
        result= calloc((strlen(string1)+strlen(string2)),sizeof(char));
        /*//initChar(result, strlen(string1)+strlen(string2));*/
        strcat(strcpy(result,string1), string2);
        /*//printf("%s\n",result);*/
        return result;
}

char * convertit(int x,int y){
        char * result;
        result= calloc(2,sizeof(char));
        /*//initChar(result, 2);*/
        result[0]=(char)(x+97);
        result[1]=(char)(y+49);
        return result;
}

int recupX(char x){
        return (int)(x-97);
}
int recupY(char y){
        return (int)(y-49);
}

coup * victoirePossibles(pion p, pion** grille,coup* coupActuelle,char *begin){
        int x,y,j;
        x=p.x; y=p.y; j=signe(p.typeInterne);
        switch (j*(p.typeInterne%100)/10) {
        case 3:
                if (((y == 5&&p.typeInterne>0) || (y == 2&&p.typeInterne<0))&& deployement(p, grillePion(grille,x,y+1*j))&&deployement(p, grillePion(grille,x,y+2*j)))
                {
                        coup * coupSuivant = calloc(1,sizeof(coup)); coupSuivant->proto = NULL; coupSuivant->coupSuivant= NULL;
                        coupActuelle->proto=(concat(begin,"#"));
                        coupActuelle->coupSuivant = coupSuivant;
                        coupActuelle = coupSuivant;
                }
        case 2:
                if (((y == 6&&p.typeInterne>0) || (y == 1&&p.typeInterne<0))&& deployement(p, grillePion(grille,x,y+1*j)))
                {
                        coup * coupSuivant = calloc(1,sizeof(coup)); coupSuivant->proto = NULL; coupSuivant->coupSuivant= NULL;
                        coupActuelle->proto=(concat(begin,"#"));
                        coupActuelle->coupSuivant = coupSuivant;
                        coupActuelle = coupSuivant;
                }
        case 1:
                if((y==0&&p.typeInterne<0) || (y==7&&p.typeInterne>0))
                {
                        coup * coupSuivant = calloc(1,sizeof(coup)); coupSuivant->proto = NULL; coupSuivant->coupSuivant= NULL;
                        coupActuelle->proto=(concat(begin,"#"));
                        coupActuelle->coupSuivant = coupSuivant;
                        coupActuelle = coupSuivant;
                }
                break;
        }
        switch (j*(p.typeInterne%1000)/100) {
        case 3:
                if (((y == 5&&p.typeInterne>0) || (y == 2&&p.typeInterne<0))&& ((deployement(p, grillePion(grille,x+1,y+1*j))&&deployement(p, grillePion(grille,x+2,y+2*j))) || (deployement(p, grillePion(grille,x-1,y+1*j))&&deployement(p, grillePion(grille,x-2,y+2*j))))) {
                        coup * coupSuivant = calloc(1,sizeof(coup)); coupSuivant->proto = NULL; coupSuivant->coupSuivant= NULL;
                        coupActuelle->proto=(concat(begin,"#"));
                        coupActuelle->coupSuivant = coupSuivant;
                        coupActuelle = coupSuivant;
                }
        case 2:
                if (((y == 6&&p.typeInterne>0) || (y == 1&&p.typeInterne<0))&& (deployement(p, grillePion(grille,x+1,y+1*j))|| deployement(p, grillePion(grille,x-1,y+1*j))))
                {
                        coup * coupSuivant = calloc(1,sizeof(coup)); coupSuivant->proto = NULL; coupSuivant->coupSuivant= NULL;
                        coupActuelle->proto=(concat(begin,"#"));
                        coupActuelle->coupSuivant = coupSuivant;
                        coupActuelle = coupSuivant;
                }

        case 1:
                if ((y==0&&p.typeInterne<0) || (y==7&&p.typeInterne>0))
                {
                        coup * coupSuivant = calloc(1,sizeof(coup)); coupSuivant->proto = NULL; coupSuivant->coupSuivant= NULL;
                        coupActuelle->proto=(concat(begin,"#"));
                        coupActuelle->coupSuivant = coupSuivant;
                        coupActuelle = coupSuivant;
                }
                break;

        }

        return coupActuelle;
}


coup * deplacementPossibles(pion pionDepart,pion** grille,coup*coupActuelle,char * begin){
        int x, y, signePion;
        char * freeA;
        char * freeB;
        x = pionDepart.x, y = pionDepart.y, signePion = signe(pionDepart.typeInterne);
        switch (signePion*(pionDepart.typeInterne%100)/10) {
        case 3:
                if(y < 5|| y>2) {
                        if(grillePion(grille,x,y+(1*signePion)).joueur == 'V'&&grillePion(grille,x,y+(2*signePion)).joueur == 'V'&&deplacement(pionDepart,grillePion(grille,x,y+(3*signePion)))) {
                                coup * coupSuivant = calloc(1,sizeof(coup)); coupSuivant->proto = NULL; coupSuivant->coupSuivant= NULL;
                                freeA = concat(begin,"-");
                                freeB = convertit(x,y+(3*signePion));
                                coupActuelle->proto=concat(freeA,freeB);
                                free(freeA); freeA = NULL;
                                free(freeB); freeB = NULL;
                                coupActuelle->coupSuivant = coupSuivant;
                                coupActuelle = coupSuivant;
                        }
                }
                if(x < 5) {
                        if(grillePion(grille,x+1,y).joueur == 'V'&&grillePion(grille,x+2,y).joueur == 'V'&&deplacement(pionDepart,grillePion(grille,x+3,y))) {
                                coup * coupSuivant = calloc(1,sizeof(coup)); coupSuivant->proto = NULL; coupSuivant->coupSuivant= NULL;
                                freeA = concat(begin,"-");
                                freeB = convertit(x+3,y);
                                coupActuelle->proto=concat(freeA,freeB);
                                free(freeA); freeA = NULL;
                                free(freeB); freeB = NULL;
                                coupActuelle->coupSuivant = coupSuivant;
                                coupActuelle = coupSuivant;
                        }
                }

                if(x > 2) {
                        if(grillePion(grille,x-1,y).joueur == 'V'&&grillePion(grille,x-2,y).joueur == 'V'&&deplacement(pionDepart,grillePion(grille,x-3,y))) {
                                coup * coupSuivant = calloc(1,sizeof(coup)); coupSuivant->proto = NULL; coupSuivant->coupSuivant= NULL;
                                freeA = concat(begin,"-");
                                freeB = convertit(x-3,y);
                                coupActuelle->proto=concat(freeA,freeB);
                                free(freeA); freeA = NULL;
                                free(freeB); freeB = NULL;
                                coupActuelle->coupSuivant = coupSuivant;
                                coupActuelle = coupSuivant;
                        }
                }

        case 2:
                if(y < 6 || y>1) {
                        if(grillePion(grille,x,y+(1*signePion)).joueur == 'V'&&deplacement(pionDepart,grillePion(grille,x,y+(2*signePion)))) {
                                coup * coupSuivant = calloc(1,sizeof(coup)); coupSuivant->proto = NULL; coupSuivant->coupSuivant= NULL;
                                freeA = concat(begin,"-");
                                freeB = convertit(x,y+(2*signePion));
                                coupActuelle->proto=concat(freeA,freeB);
                                free(freeA); freeA = NULL;
                                free(freeB); freeB = NULL;
                                coupActuelle->coupSuivant = coupSuivant;
                                coupActuelle = coupSuivant;
                        }
                }
                if(x < 6) {
                        if(grillePion(grille,x+1,y).joueur == 'V'&&deplacement(pionDepart,grillePion(grille,x+2,y))) {
                                coup * coupSuivant = calloc(1,sizeof(coup)); coupSuivant->proto = NULL; coupSuivant->coupSuivant= NULL;
                                freeA = concat(begin,"-");
                                freeB = convertit(x+2,y);
                                coupActuelle->proto=concat(freeA,freeB);
                                free(freeA); freeA = NULL;
                                free(freeB); freeB = NULL;
                                coupActuelle->coupSuivant = coupSuivant;
                                coupActuelle = coupSuivant;
                        }
                }
                if(x > 1) {
                        if(grillePion(grille,x-1,y).joueur == 'V'&&deplacement(pionDepart,grillePion(grille,x-2,y))) {
                                coup * coupSuivant = calloc(1,sizeof(coup)); coupSuivant->proto = NULL; coupSuivant->coupSuivant= NULL;
                                freeA = concat(begin,"-");
                                freeB = convertit(x-2,y);
                                coupActuelle->proto=concat(freeA,freeB);
                                free(freeA); freeA = NULL;
                                free(freeB); freeB = NULL;
                                coupActuelle->coupSuivant = coupSuivant;
                                coupActuelle = coupSuivant;
                        }
                }
        case 1:
                if(y < 7 || y>0) {
                        if(deplacement(pionDepart,grillePion(grille,x,y+(1*signePion)))) {
                                coup * coupSuivant = calloc(1,sizeof(coup)); coupSuivant->proto = NULL; coupSuivant->coupSuivant= NULL;
                                freeA = concat(begin,"-");
                                freeB = convertit(x,y+(1*signePion));
                                coupActuelle->proto=concat(freeA,freeB);
                                free(freeA); freeA = NULL;
                                free(freeB); freeB = NULL;
                                coupActuelle->coupSuivant = coupSuivant;
                                coupActuelle = coupSuivant;
                        }
                }
                if(x < 7) {
                        if(deplacement(pionDepart,grillePion(grille,x+1,y))) {
                                coup * coupSuivant = calloc(1,sizeof(coup)); coupSuivant->proto = NULL; coupSuivant->coupSuivant= NULL;
                                freeA = concat(begin,"-");
                                freeB = convertit(x+1,y);
                                coupActuelle->proto=concat(freeA,freeB);
                                free(freeA); freeA = NULL;
                                free(freeB); freeB = NULL;
                                coupActuelle->coupSuivant = coupSuivant;
                                coupActuelle = coupSuivant;
                        }
                }
                if(x > 0) {
                        if(deplacement(pionDepart,grillePion(grille,x-1,y))) {
                                coup * coupSuivant = calloc(1,sizeof(coup)); coupSuivant->proto = NULL; coupSuivant->coupSuivant= NULL;
                                freeA = concat(begin,"-");
                                freeB = convertit(x-1,y);
                                coupActuelle->proto=concat(freeA,freeB);
                                free(freeA); freeA = NULL;
                                free(freeB); freeB = NULL;
                                coupActuelle->coupSuivant = coupSuivant;
                                coupActuelle = coupSuivant;
                        }
                }
                break;
        }

        switch (signePion*(pionDepart.typeInterne%1000)/100) {
        case 3:

                if(x < 5 && (y < 5 || y > 2)) {
                        if(grillePion(grille,x+1,y+(1*signePion)).joueur == 'V'&&grillePion(grille,x+2,y+(2*signePion)).joueur == 'V'&&deplacement(pionDepart,grillePion(grille,x+3,y+(3*signePion)))) {
                                coup * coupSuivant = calloc(1,sizeof(coup)); coupSuivant->proto = NULL; coupSuivant->coupSuivant= NULL;
                                freeA = concat(begin,"-");
                                freeB = convertit(x+3,y+(3*signePion));
                                coupActuelle->proto=concat(freeA,freeB);
                                free(freeA); freeA = NULL;
                                free(freeB); freeB = NULL;
                                coupActuelle->coupSuivant = coupSuivant;
                                coupActuelle = coupSuivant;
                        }
                }

                if(x == 6 && (y < 4|| y > 3)) {
                        if(grillePion(grille,x+1,y+(1*signePion)).joueur == 'V'&&grillePion(grille,x,y+(2*signePion)).joueur == 'V'&&deplacement(pionDepart,grillePion(grille,x-1,y+(3*signePion)))) {
                                coup * coupSuivant = calloc(1,sizeof(coup)); coupSuivant->proto = NULL; coupSuivant->coupSuivant= NULL;
                                freeA = concat(begin,"-");
                                freeB = convertit(x-1,y+(3*signePion));
                                coupActuelle->proto=concat(freeA,freeB);
                                free(freeA); freeA = NULL;
                                free(freeB); freeB = NULL;
                                coupActuelle->coupSuivant = coupSuivant;
                                coupActuelle = coupSuivant;
                        }
                }

                if(x == 5 && (y < 4|| y > 3)) {
                        if(grillePion(grille,x+1,y+(1*signePion)).joueur == 'V'&&grillePion(grille,x+2,y+(2*signePion)).joueur == 'V'&&deplacement(pionDepart,grillePion(grille,x+1,y+(3*signePion)))) {
                                coup * coupSuivant = calloc(1,sizeof(coup)); coupSuivant->proto = NULL; coupSuivant->coupSuivant= NULL;
                                freeA = concat(begin,"-");
                                freeB = convertit(x+1,y+(3*signePion));
                                coupActuelle->proto=concat(freeA,freeB);
                                free(freeA); freeA = NULL;
                                free(freeB); freeB = NULL;
                                coupActuelle->coupSuivant = coupSuivant;
                                coupActuelle = coupSuivant;
                        }
                }


                if((y < 5 || y > 2) && x > 2) {
                        if(grillePion(grille,x-1,y+(1*signePion)).joueur == 'V'&&grillePion(grille,x-2,y+(2*signePion)).joueur == 'V'&&deplacement(pionDepart,grillePion(grille,x-3,y+(3*signePion)))) {
                                coup * coupSuivant = calloc(1,sizeof(coup)); coupSuivant->proto = NULL; coupSuivant->coupSuivant= NULL;
                                freeA = concat(begin,"-");
                                freeB = convertit(x-3,y+(3*signePion));
                                coupActuelle->proto=concat(freeA,freeB);
                                free(freeA); freeA = NULL;
                                free(freeB); freeB = NULL;
                                coupActuelle->coupSuivant = coupSuivant;
                                coupActuelle = coupSuivant;
                        }
                }

                if((y < 4|| y > 3) && x == 2) {
                        if(grillePion(grille,x-1,y+(1*signePion)).joueur == 'V'&&grillePion(grille,x-2,y+(2*signePion)).joueur == 'V'&&deplacement(pionDepart,grillePion(grille,x-1,y+(3*signePion)))) {
                                coup * coupSuivant = calloc(1,sizeof(coup)); coupSuivant->proto = NULL; coupSuivant->coupSuivant= NULL;
                                freeA = concat(begin,"-");
                                freeB = convertit(x-1,y+(3*signePion));
                                coupActuelle->proto=concat(freeA,freeB);
                                free(freeA); freeA = NULL;
                                free(freeB); freeB = NULL;
                                coupActuelle->coupSuivant = coupSuivant;
                                coupActuelle = coupSuivant;
                        }
                }


                if((y < 4|| y > 3) && x == 1) {
                        if(grillePion(grille,x-1,y+(1*signePion)).joueur == 'V'&&grillePion(grille,x,y+(2*signePion)).joueur == 'V'&&deplacement(pionDepart,grillePion(grille,x+1,y+(3*signePion)))) {
                                coup * coupSuivant = calloc(1,sizeof(coup)); coupSuivant->proto = NULL; coupSuivant->coupSuivant= NULL;
                                freeA = concat(begin,"-");
                                freeB = convertit(x+1,y+(3*signePion));
                                coupActuelle->proto=concat(freeA,freeB);
                                free(freeA); freeA = NULL;
                                free(freeB); freeB = NULL;
                                coupActuelle->coupSuivant = coupSuivant;
                                coupActuelle->coupSuivant = coupSuivant;
                                coupActuelle = coupSuivant;
                        }
                }

        case 2:
                if(x < 6 && (y < 6|| y > 1)) {
                        if(grillePion(grille,x+1,y+(1*signePion)).joueur == 'V'&&deplacement(pionDepart,grillePion(grille,x+2,y+(2*signePion)))) {
                                coup * coupSuivant = calloc(1,sizeof(coup)); coupSuivant->proto = NULL; coupSuivant->coupSuivant= NULL;
                                freeA = concat(begin,"-");
                                freeB = convertit(x+2,y+(2*signePion));
                                coupActuelle->proto=concat(freeA,freeB);
                                free(freeA); freeA = NULL;
                                free(freeB); freeB = NULL;
                                coupActuelle->coupSuivant = coupSuivant;
                                coupActuelle = coupSuivant;
                        }
                }

                if(x == 6 && (y < 5|| y > 2)) {
                        if(grillePion(grille,x+1,y+(1*signePion)).joueur == 'V'&&deplacement(pionDepart,grillePion(grille,x,y+(2*signePion)))) {
                                coup * coupSuivant = calloc(1,sizeof(coup)); coupSuivant->proto = NULL; coupSuivant->coupSuivant= NULL;
                                freeA = concat(begin,"-");
                                freeB = convertit(x,y+(2*signePion));
                                coupActuelle->proto=concat(freeA,freeB);
                                free(freeA); freeA = NULL;
                                free(freeB); freeB = NULL;
                                coupActuelle->coupSuivant = coupSuivant;
                                coupActuelle = coupSuivant;
                        }
                }

                if((y < 6|| y > 1) && x > 1) {
                        if(grillePion(grille,x-1,y+(1*signePion)).joueur == 'V'&&deplacement(pionDepart,grillePion(grille,x-2,y+(2*signePion)))) {
                                coup * coupSuivant = calloc(1,sizeof(coup)); coupSuivant->proto = NULL; coupSuivant->coupSuivant= NULL;
                                freeA = concat(begin,"-");
                                freeB = convertit(x-2,y+(2*signePion));
                                coupActuelle->proto=concat(freeA,freeB);
                                free(freeA); freeA = NULL;
                                free(freeB); freeB = NULL;
                                coupActuelle->coupSuivant = coupSuivant;
                                coupActuelle = coupSuivant;
                        }
                }

                if((y < 5|| y > 2) && x == 1) {
                        if(grillePion(grille,x-1,y+(1*signePion)).joueur == 'V'&&deplacement(pionDepart,grillePion(grille,x,y+(2*signePion)))) {
                                coup * coupSuivant = calloc(1,sizeof(coup)); coupSuivant->proto = NULL; coupSuivant->coupSuivant= NULL;
                                freeA = concat(begin,"-");
                                freeB = convertit(x,y+(2*signePion));
                                coupActuelle->proto=concat(freeA,freeB);
                                free(freeA); freeA = NULL;
                                free(freeB); freeB = NULL;
                                coupActuelle->coupSuivant = coupSuivant;
                                coupActuelle = coupSuivant;
                        }
                }

        case 1:
                if(x < 7 && (y < 7||y>0)) {
                        if(deplacement(pionDepart,grillePion(grille,x+1,y+(1*signePion)))) {
                                coup * coupSuivant = calloc(1,sizeof(coup)); coupSuivant->proto = NULL; coupSuivant->coupSuivant= NULL;
                                freeA = concat(begin,"-");
                                freeB = convertit(x+1,y+(1*signePion));
                                coupActuelle->proto=concat(freeA,freeB);
                                free(freeA); freeA = NULL;
                                free(freeB); freeB = NULL;
                                coupActuelle->coupSuivant = coupSuivant;
                                coupActuelle = coupSuivant;
                        }
                }
                if((y < 7||y>0) && x > 0 ) {
                        if(deplacement(pionDepart,grillePion(grille,x-1,y+(1*signePion)))) {
                                coup * coupSuivant = calloc(1,sizeof(coup)); coupSuivant->proto = NULL; coupSuivant->coupSuivant= NULL;
                                freeA = concat(begin,"-");
                                freeB = convertit(x-1,y+(1*signePion));
                                coupActuelle->proto=concat(freeA,freeB);
                                free(freeA); freeA = NULL;
                                free(freeB); freeB = NULL;
                                coupActuelle->coupSuivant = coupSuivant;
                                coupActuelle = coupSuivant;
                        }
                }

                break;
        }

        return coupActuelle;
}


coup * deployPossibles(pion pionDepart,pion** grille,int turn,int newType,coup *coupActuelle,char* begin,int signePion){
        int x, y;
        char * freeA;
        char * freeB;
        char * proto;
        coup * coupSuivant;
        x = pionDepart.x, y = pionDepart.y;
        switch (signePion*(newType%1000)/100) {
        case 1:
                if(x < 7 && (y < 7||y>0) ) {
                        if(deployement(pionDepart,grillePion(grille,x+1,y+(1*signePion)))) {
                                freeA = concat(begin,caract(turn,2));
                                freeB = convertit(x+1,y+(1*signePion));
                                proto = concat(freeA, freeB);
                                free(freeA); freeA = NULL;
                                free(freeB); freeB = NULL;
                                if((newType%100)/10==0) {
                                        coupSuivant = calloc(1,sizeof(coup)); coupSuivant->proto = NULL;
                                        coupSuivant->coupSuivant= NULL;
                                        coupActuelle->proto=proto;
                                        coupActuelle->coupSuivant = coupSuivant;
                                        coupActuelle = coupSuivant;
                                }
                                else {
                                        coupActuelle = deployPossibles(grillePion(grille,x+1,y+(1*signePion)), grille, 1, newType-(newType%1000/100)*100, coupActuelle, proto,signePion);
                                        free(proto); proto = NULL;
                                }
                        }
                }

                if(x > 0 && (y < 7||y>0) ) {
                        if(deployement(pionDepart,grillePion(grille,x-1,y+(1*signePion)))) {
                                freeA = concat(begin,caract(turn,2));
                                freeB = convertit(x-1,y+(1*signePion));
                                proto = concat(freeA, freeB);
                                free(freeA); freeA = NULL;
                                free(freeB); freeB = NULL;
                                if((newType%100)/10==0) {
                                        coupSuivant = calloc(1,sizeof(coup)); coupSuivant->proto = NULL; coupSuivant->coupSuivant= NULL;
                                        coupActuelle->proto=proto;
                                        coupActuelle->coupSuivant = coupSuivant;
                                        coupActuelle = coupSuivant;
                                }
                                else{
                                        coupActuelle = deployPossibles(grillePion(grille,x-1,y+(1*signePion)), grille, 1, newType-(newType%1000/100)*100, coupActuelle, proto,signePion);
                                        free(proto); proto = NULL;
                                }
                        }
                }
                break;
        case 2:
                if(x < 6 && (y < 6|| y > 1) ) {
                        if(deployement(pionDepart, grillePion(grille,x+1,y+(1*signePion)))&&deployement(pionDepart,grillePion(grille,x+2,y+(2*signePion)))) {
                                freeA = concat(begin,caract(turn,2));
                                freeB = convertit(x+2,y+(2*signePion));
                                proto = concat(freeA, freeB);
                                free(freeA); freeA = NULL;
                                free(freeB); freeB = NULL;
                                if ((newType%100)/10==0) {
                                        coupSuivant = calloc(1,sizeof(coup)); coupSuivant->proto = NULL; coupSuivant->coupSuivant= NULL;
                                        coupActuelle->proto=proto;
                                        coupActuelle->coupSuivant = coupSuivant;
                                        coupActuelle = coupSuivant;
                                }
                                else {
                                        coupActuelle = deployPossibles(grillePion(grille,x+2,y+(2*signePion)), grille, 1, newType-(newType%1000/100)*100, coupActuelle, proto,signePion);
                                        free(proto); proto = NULL;
                                }
                        }

                }

                if(x == 6 && (y < 6|| y > 1) ) {
                        if(deployement(pionDepart, grillePion(grille,x+1,y+(1*signePion)))&&deployement(pionDepart,grillePion(grille,x,y+(2*signePion)))) {
                                freeA = concat(begin,caract(turn,2));
                                freeB = convertit(x,y+(2*signePion));
                                proto = concat(freeA, freeB);
                                free(freeA); freeA = NULL;
                                free(freeB); freeB = NULL;
                                if ((newType%100)/10==0) {
                                        coupSuivant = calloc(1,sizeof(coup)); coupSuivant->proto = NULL; coupSuivant->coupSuivant= NULL;
                                        coupActuelle->proto=proto;
                                        coupActuelle->coupSuivant = coupSuivant;
                                        coupActuelle = coupSuivant;
                                }
                                else{
                                        coupActuelle = deployPossibles(grillePion(grille,x,y+(2*signePion)), grille, 1, newType-(newType%1000/100)*100, coupActuelle, proto,signePion);
                                        free(proto); proto = NULL;
                                }
                        }

                }

                if(x > 1 && (y < 6|| y > 1) ) {
                        if(deployement(pionDepart, grillePion(grille,x-1,y+(1*signePion)))&&deployement(pionDepart,grillePion(grille,x-2,y+(2*signePion)))) {
                                freeA = concat(begin,caract(turn,2));
                                freeB = convertit(x-2,y+(2*signePion));
                                proto = concat(freeA, freeB);
                                free(freeA); freeA = NULL;
                                free(freeB); freeB = NULL;
                                if ((newType%100)/10==0) {
                                        coupSuivant = calloc(1,sizeof(coup)); coupSuivant->proto = NULL; coupSuivant->coupSuivant= NULL;
                                        coupActuelle->proto=proto;
                                        coupActuelle->coupSuivant = coupSuivant;
                                        coupActuelle = coupSuivant;
                                }
                                else{
                                        coupActuelle = deployPossibles(grillePion(grille,x-2,y+(2*signePion)), grille, 1, newType-(newType%1000/100)*100, coupActuelle, proto,signePion);
                                        free(proto); proto = NULL;
                                }
                        }

                }

                if(x == 1 && (y < 6|| y > 1) ) {
                        if(deployement(pionDepart, grillePion(grille,x-1,y+(1*signePion)))&&deployement(pionDepart,grillePion(grille,x,y+(2*signePion)))) {
                                freeA = concat(begin,caract(turn,2));
                                freeB = convertit(x,y+(2*signePion));
                                proto = concat(freeA, freeB);
                                free(freeA); freeA = NULL;
                                free(freeB); freeB = NULL;
                                if ((newType%100)/10==0) {
                                        coupSuivant = calloc(1,sizeof(coup)); coupSuivant->proto = NULL; coupSuivant->coupSuivant= NULL;
                                        coupActuelle->proto=proto;
                                        coupActuelle->coupSuivant = coupSuivant;
                                        coupActuelle = coupSuivant;
                                }
                                else{
                                        coupActuelle = deployPossibles(grillePion(grille,x,y+(2*signePion)), grille, 1, newType-(newType%1000/100)*100, coupActuelle, proto,signePion);
                                        free(proto); proto = NULL;
                                }
                        }

                }
                break;
        case 3:
                if(x < 5 && (y < 5||y>2)) {
                        if(deployement(pionDepart, grillePion(grille,x+1,y+(1*signePion)))&&deployement(pionDepart, grillePion(grille,x+2,y+(2*signePion)))&&deployement(pionDepart, grillePion(grille,x+3,y+(3*signePion)))) {
                                coup * coupSuivant = calloc(1,sizeof(coup)); coupSuivant->proto = NULL; coupSuivant->coupSuivant= NULL;
                                freeA = concat(begin,caract(turn,2));
                                freeB =convertit(x+3,y+(3*signePion));
                                proto = concat(freeA, freeB);
                                free(freeA); freeA = NULL;
                                free(freeB); freeB = NULL;
                                coupActuelle->proto=proto;
                                coupActuelle->coupSuivant = coupSuivant;
                                coupActuelle = coupSuivant;
                        }
                }

                if(x == 5 && (y < 5||y>2)) {
                        if(deployement(pionDepart, grillePion(grille,x+1,y+(1*signePion)))&&deployement(pionDepart, grillePion(grille,x+2,y+(2*signePion)))&&deployement(pionDepart, grillePion(grille,x+1,y+(3*signePion)))) {
                                coupSuivant = calloc(1,sizeof(coup)); coupSuivant->proto = NULL; coupSuivant->coupSuivant= NULL;
                                freeA = concat(begin,caract(turn,2));
                                freeB =convertit(x+1,y+(3*signePion));
                                proto = concat(freeA, freeB);
                                free(freeA); freeA = NULL;
                                free(freeB); freeB = NULL;
                                coupActuelle->proto=proto;
                                coupActuelle->coupSuivant = coupSuivant;
                                coupActuelle = coupSuivant;
                        }
                }

                if(x == 6 && (y < 5||y>2)) {
                        if(deployement(pionDepart, grillePion(grille,x+1,y+(1*signePion)))&&deployement(pionDepart, grillePion(grille,x,y+(2*signePion)))&&deployement(pionDepart, grillePion(grille,x-1,y+(3*signePion)))) {
                                coup * coupSuivant = calloc(1,sizeof(coup)); coupSuivant->proto = NULL; coupSuivant->coupSuivant= NULL;
                                freeA = concat(begin,caract(turn,2));
                                freeB =convertit(x-1,y+(3*signePion));
                                proto = concat(freeA, freeB);
                                free(freeA); freeA = NULL;
                                free(freeB); freeB = NULL;
                                coupActuelle->proto=proto;
                                coupActuelle->coupSuivant = coupSuivant;
                                coupActuelle = coupSuivant;
                        }
                }


                if(x > 2 && (y < 5||y>2)) {
                        if(deployement(pionDepart, grillePion(grille,x-1,y+(1*signePion)))&&deployement(pionDepart, grillePion(grille,x-2,y+(2*signePion)))&&deployement(pionDepart, grillePion(grille,x-3,y+(3*signePion)))) {
                                coupSuivant = calloc(1,sizeof(coup)); coupSuivant->proto = NULL; coupSuivant->coupSuivant= NULL;
                                freeA = concat(begin,caract(turn,2));
                                freeB = convertit(x-3,y+(3*signePion));
                                proto = concat(freeA, freeB);
                                free(freeA); freeA = NULL;
                                free(freeB); freeB = NULL;
                                coupActuelle->proto=proto;
                                coupActuelle->coupSuivant = coupSuivant;
                                coupActuelle = coupSuivant;
                        }
                }

                if(x == 2 && (y < 5||y>2)) {
                        if(deployement(pionDepart, grillePion(grille,x-1,y+(1*signePion)))&&deployement(pionDepart, grillePion(grille,x-2,y+(2*signePion)))&&deployement(pionDepart, grillePion(grille,x-1,y+(3*signePion)))) {
                                coupSuivant = calloc(1,sizeof(coup)); coupSuivant->proto = NULL; coupSuivant->coupSuivant= NULL;
                                freeA = concat(begin,caract(turn,2));
                                freeB = convertit(x-1,y+(3*signePion));
                                proto = concat(freeA, freeB);
                                free(freeA); freeA = NULL;
                                free(freeB); freeB = NULL;
                                coupActuelle->proto=proto;
                                coupActuelle->coupSuivant = coupSuivant;
                                coupActuelle = coupSuivant;
                        }
                }

                if(x == 1 && (y < 5||y>2)) {
                        if(deployement(pionDepart, grillePion(grille,x-1,y+(1*signePion)))&&deployement(pionDepart, grillePion(grille,x,y+(2*signePion)))&&deployement(pionDepart, grillePion(grille,x+1,y+(3*signePion)))) {
                                coupSuivant = calloc(1,sizeof(coup)); coupSuivant->proto = NULL; coupSuivant->coupSuivant= NULL;
                                freeA = concat(begin,caract(turn,2));
                                freeB = convertit(x+1,y+(3*signePion));
                                proto = concat(freeA, freeB);
                                free(freeA); freeA = NULL;
                                free(freeB); freeB = NULL;
                                coupActuelle->proto=proto;
                                coupActuelle->coupSuivant = coupSuivant;
                                coupActuelle = coupSuivant;
                        }
                }
                break;
        }

        switch (signePion*(newType%100)/10) {
        case 1:

                if((y < 7||y>0) ) {
                        if(deployement(pionDepart,grillePion(grille,x,y+(1*signePion)))) {
                                freeA = concat(begin,caract(turn,1));
                                freeB = convertit(x,y+(1*signePion));
                                proto = concat(freeA, freeB);
                                free(freeA); freeA = NULL;
                                free(freeB); freeB = NULL;
                                if((newType%1000)/100==0) {
                                        coupSuivant = calloc(1,sizeof(coup)); coupSuivant->proto = NULL; coupSuivant->coupSuivant= NULL;
                                        coupActuelle->proto=proto;
                                        coupActuelle->coupSuivant = coupSuivant;
                                        coupActuelle = coupSuivant;
                                }
                                else{
                                        coupActuelle = deployPossibles(grillePion(grille,x,y+(1*signePion)), grille, 1, newType-(newType%100/10)*10, coupActuelle, proto,signePion);
                                        free(proto); proto = NULL;
                                }
                        }
                }

                if( x < 7 ) {
                        if(deployement(pionDepart,grillePion(grille,x+1,y))) {
                                freeA = concat(begin,caract(turn,1));
                                freeB = convertit(x+1,y);
                                proto = concat(freeA, freeB);
                                free(freeA); freeA = NULL;
                                free(freeB); freeB = NULL;
                                if((newType%1000)/100==0) {
                                        coupSuivant = calloc(1,sizeof(coup)); coupSuivant->proto = NULL; coupSuivant->coupSuivant= NULL;
                                        coupActuelle->proto=proto;
                                        coupActuelle->coupSuivant = coupSuivant;
                                        coupActuelle = coupSuivant;
                                }
                                else{
                                        coupActuelle = deployPossibles(grillePion(grille,x+1,y), grille, 1, newType-(newType%100/10)*10, coupActuelle, proto,signePion);
                                        free(proto); proto = NULL;
                                }
                        }
                }

                if( x > 0 ) {
                        if(deployement(pionDepart,grillePion(grille,x-1,y))) {
                                freeA = concat(begin,caract(turn,1));
                                freeB = convertit(x-1,y);
                                proto = concat(freeA, freeB);
                                free(freeA); freeA = NULL;
                                free(freeB); freeB = NULL;
                                if((newType%1000)/100==0) {
                                        coupSuivant = calloc(1,sizeof(coup)); coupSuivant->proto = NULL; coupSuivant->coupSuivant= NULL;
                                        coupActuelle->proto=proto;
                                        coupActuelle->coupSuivant = coupSuivant;
                                        coupActuelle = coupSuivant;
                                }
                                else{
                                        coupActuelle = deployPossibles(grillePion(grille,x-1,y), grille, 1, newType-(newType%100/10)*10, coupActuelle, proto,signePion);
                                        free(proto); proto = NULL;
                                }
                        }
                }
                break;
        case 2:

                if((y < 6||y>1) ) {
                        if(deployement(pionDepart,grillePion(grille,x,y+(1*signePion)))&&deployement(pionDepart,grillePion(grille,x,y+(2*signePion)))) {
                                freeA = concat(begin,caract(turn,1));
                                freeB = convertit(x,y+(2*signePion));
                                proto = concat(freeA, freeB);
                                free(freeA); freeA = NULL;
                                free(freeB); freeB = NULL;
                                if((newType%1000)/100==0) {
                                        coupSuivant = calloc(1,sizeof(coup)); coupSuivant->proto = NULL; coupSuivant->coupSuivant= NULL;
                                        coupActuelle->proto=proto;
                                        coupActuelle->coupSuivant = coupSuivant;
                                        coupActuelle = coupSuivant;
                                }
                                else{
                                        coupActuelle = deployPossibles(grillePion(grille,x,y+(2*signePion)), grille, 1, newType-(newType%100/10)*10, coupActuelle, proto,signePion);
                                        free(proto); proto = NULL;
                                }
                        }
                }

                if(x<6 ) {
                        if(deployement(pionDepart,grillePion(grille,x+1,y))&&deployement(pionDepart,grillePion(grille,x+2,y))) {
                                freeA = concat(begin,caract(turn,1));
                                freeB = convertit(x+2,y);
                                proto = concat(freeA, freeB);
                                free(freeA); freeA = NULL;
                                free(freeB); freeB = NULL;
                                if((newType%1000)/100==0) {
                                        coupSuivant = calloc(1,sizeof(coup)); coupSuivant->proto = NULL; coupSuivant->coupSuivant= NULL;
                                        coupActuelle->proto=proto;
                                        coupActuelle->coupSuivant = coupSuivant;
                                        coupActuelle = coupSuivant;
                                }
                                else{
                                        coupActuelle = deployPossibles(grillePion(grille,x+2,y), grille, 1, newType-(newType%100/10)*10, coupActuelle, proto,signePion);
                                        free(proto); proto = NULL;
                                }
                        }
                }

                if(x>1 ) {
                        if(deployement(pionDepart,grillePion(grille,x-1,y))&&deployement(pionDepart,grillePion(grille,x-2,y))) {
                                freeA = concat(begin,caract(turn,1));
                                freeB = convertit(x-2,y);
                                proto = concat(freeA, freeB);
                                free(freeA); freeA = NULL;
                                free(freeB); freeB = NULL;
                                if((newType%1000)/100==0) {
                                        coupSuivant = calloc(1,sizeof(coup)); coupSuivant->proto = NULL; coupSuivant->coupSuivant= NULL;
                                        coupActuelle->proto=proto;
                                        coupActuelle->coupSuivant = coupSuivant;
                                        coupActuelle = coupSuivant;
                                }
                                else{
                                        coupActuelle = deployPossibles(grillePion(grille,x-2,y), grille, 1, newType-(newType%100/10)*10, coupActuelle, proto,signePion);
                                        free(proto); proto = NULL;
                                }
                        }
                }

                break;
        case 3:

                if((y < 5||y>2) ) {
                        if(deployement(pionDepart,grillePion(grille,x,y+(1*signePion)))&&deployement(pionDepart,grillePion(grille,x,y+(2*signePion)))&&deployement(pionDepart,grillePion(grille,x,y+(3*signePion)))) {
                                freeA = concat(begin,caract(turn,1));
                                freeB = convertit(x,y+(3*signePion));
                                proto = concat(freeA, freeB);
                                free(freeA); freeA = NULL;
                                free(freeB); freeB = NULL;
                                coupSuivant = calloc(1,sizeof(coup)); coupSuivant->proto = NULL; coupSuivant->coupSuivant= NULL;
                                coupActuelle->proto=proto;
                                coupActuelle->coupSuivant = coupSuivant;
                                coupActuelle = coupSuivant;
                        }
                }
                if((x < 5) ) {
                        if(deployement(pionDepart,grillePion(grille,x+1,y))&&deployement(pionDepart,grillePion(grille,x+2,y))&&deployement(pionDepart,grillePion(grille,x+3,y))) {
                                freeA = concat(begin,caract(turn,1));
                                freeB = convertit(x+3,y);
                                proto = concat(freeA, freeB);
                                free(freeA); freeA = NULL;
                                free(freeB); freeB = NULL;
                                coupSuivant = calloc(1,sizeof(coup)); coupSuivant->proto = NULL; coupSuivant->coupSuivant= NULL;
                                coupActuelle->proto=proto;
                                coupActuelle->coupSuivant = coupSuivant;
                                coupActuelle = coupSuivant;
                        }
                }

                if(x == 5) {
                        if(deployement(pionDepart,grillePion(grille,x+1,y))&&deployement2(pionDepart,grillePion(grille,x+2,y))) {
                                freeA = concat(begin,caract(turn,1));
                                freeB = convertit(x+2,y);
                                proto = concat(freeA, freeB);
                                free(freeA); freeA = NULL;
                                free(freeB); freeB = NULL;
                                coupSuivant = calloc(1,sizeof(coup)); coupSuivant->proto = NULL; coupSuivant->coupSuivant= NULL;
                                coupActuelle->proto=proto;
                                coupActuelle->coupSuivant = coupSuivant;
                                coupActuelle = coupSuivant;
                        }
                }

                if((x > 2) ) {
                        if(deployement(pionDepart,grillePion(grille,x-1,y))&&deployement(pionDepart,grillePion(grille,x-2,y))&&deployement(pionDepart,grillePion(grille,x-3,y))) {
                                freeA = concat(begin,caract(turn,1));
                                freeB = convertit(x-3,y);
                                proto = concat(freeA, freeB);
                                free(freeA); freeA = NULL;
                                free(freeB); freeB = NULL;
                                coupSuivant = calloc(1,sizeof(coup)); coupSuivant->proto = NULL; coupSuivant->coupSuivant= NULL;
                                coupActuelle->proto=proto;
                                coupActuelle->coupSuivant = coupSuivant;
                                coupActuelle = coupSuivant;
                        }
                }

                if(x == 2) {
                        if(deployement(pionDepart,grillePion(grille,x-1,y))&&deployement2(pionDepart,grillePion(grille,x-2,y))) {
                                freeA = concat(begin,caract(turn,1));
                                freeB = convertit(x-2,y);
                                proto = concat(freeA, freeB);
                                free(freeA); freeA = NULL;
                                free(freeB); freeB = NULL;
                                coupSuivant = calloc(1,sizeof(coup)); coupSuivant->proto = NULL; coupSuivant->coupSuivant= NULL;
                                coupActuelle->proto=proto;
                                coupActuelle->coupSuivant = coupSuivant;
                                coupActuelle = coupSuivant;
                        }
                }

                break;
        }
        return coupActuelle;
}

coup* coupsPossibles(pion** grille,char joueur,coup * coupPere){
        /*//coup* coupPere = calloc(1,sizeof(coup));*/
        coup* coupActuelle;
        int x;
        int y;
        int signePion;
        char * begin;
        coupActuelle= coupPere;
        x=0; y=0;
        for (x=0; x<8; x++) {
                for (y=0; y<8; y++) {
                        if(grille[x][y].joueur == joueur) {
                                signePion= signe(grille[x][y].typeInterne);
                                begin= convertit(x,y);
                                coupActuelle = deplacementPossibles(grille[x][y],grille,coupActuelle,begin);
                                if(signePion*(grille[x][y].typeInterne%1000/100)+signePion*(grille[x][y].typeInterne%100/10)>1)
                                        coupActuelle = deployPossibles(grille[x][y],grille,0,grille[x][y].typeInterne,coupActuelle,begin,signePion);
                                coupActuelle = victoirePossibles(grille[x][y],grille,coupActuelle,begin);
                                free(begin); begin=NULL;
                        }
                }
        }
        /*coupActuelle = coupPere;
           while (coupActuelle != NULL) {
            printf("%s\n",coupActuelle->proto);
            coupActuelle = coupActuelle->coupSuivant;
           }*/
        /*//freeCoup(coupActuelle,0);
           //coupActuelle = NULL;*/
        return coupPere;
}

void actionDeplacer(char * proto, pion ** grille){
        pion pionDepart = grille[recupX(proto[0])][recupY(proto[1])];
        pion pionArrive = grille[recupX(proto[3])][recupY(proto[4])];
        grille[pionDepart.x][pionDepart.y]=initPion(pionDepart.x, pionDepart.y);
        grille[pionArrive.x][pionArrive.y].x=pionArrive.x;
        grille[pionArrive.x][pionArrive.y].y=pionArrive.y;
        if(signe(pionArrive.typeInterne) == signe(pionDepart.typeInterne))
                grille[pionArrive.x][pionArrive.y].typeInterne = pionArrive.typeInterne + pionDepart.typeInterne-pionDepart.typeInterne%10;
        else grille[pionArrive.x][pionArrive.y].typeInterne = pionDepart.typeInterne;
        defPion(&grille[pionArrive.x][pionArrive.y],pionDepart.joueur);
}



void actionDeployRecursif(pion** grille,char *proto,int typeInterne,int n){
        int x0,y0,type,signePion,x1,y1,pasY,pasX;
        char joueur;
        char * protoB;
        char * freeA;
        x0= recupX(proto[0]);
        y0= recupY(proto[1]);
        type= n==0 ? grille[x0][y0].typeInterne : typeInterne;
        signePion= signe(grille[x0][y0].typeInterne);
        joueur= grille[x0][y0].joueur;
        x1= recupX(proto[3]);
        y1= recupY(proto[4]);
        pasY= signe(y1-y0);
        pasX= signe(x1-x0);
        if (proto[2] == '*') {
                if(fabs(x1-x0)==fabs(y1-y0)) {
                        pasX=signe(x1-x0);
                }
                else if(x0==7||x0==0) {
                        pasY*=2;
                        pasX=0;
                }
                else if(x0>4) {
                        pasX = 1;
                }
                else{
                        pasX = -1;
                }
                grille[x0+pasX][y0+pasY].typeInterne+=grille[x0+pasX][y0+pasY].joueur=='V' ? signePion*101 : signePion*100;
                type -= signePion*100;
        }
        else if(proto[2]=='+') {
                if(fabs(x1-x0)+fabs(y1-y0) != signePion*type%100/10) {
                        if(x0==0||x0==7) {
                                pasX = 0;
                        }
                        else if(x0>4) {
                                pasX = 1;
                        }
                        else{
                                pasX= -1;
                        }
                }
                grille[x0+pasX][y0+pasY].typeInterne+=grille[x0+pasX][y0+pasY].joueur=='V' ? signePion*11 : signePion*10;
                type -= signePion*10;
        }
        else if(proto[2]==0) {
                pasX=0;
                pasY=0;
                grille[x0+pasX][y0+pasY].typeInterne+=grille[x0+pasX][y0+pasY].joueur=='V' ? signePion*11 : signePion*10;
                type -= signePion*10;
        }
        defPion(&grille[x0+pasX][y0+pasY],joueur);
        if(n==0) {
                grille[x0][y0]=initPion(x0, y0);
        }
        if(fabs(type)>1) {
                if (x0+pasX == x1 && y0+pasY == y1) {
                        protoB = proto+3;
                        /*//printf("\n%d,%d,%d,%d,n=%d\n",x0+pasX,x1,y0+pasY,y1,n);
                           //printf("\n[%s]\n",protoB);*/
                        actionDeployRecursif(grille, protoB, type, ++n);
                        /*//free(protoB);protoB=NULL;*/
                }
                else{
                        freeA =convertit(x0+pasX, y0+pasY);
                        protoB = concat(freeA, proto+2);
                        free(freeA); freeA = NULL;
                        /*//printf("\n%d,%d,%d,%d,n=%d\n",x0+pasX,x1,y0+pasY,y1,n);
                           //printf("\n[%s]\n",protoB);*/
                        actionDeployRecursif(grille, protoB, type, ++n);
                        free(protoB); protoB=NULL;
                }
        }
}


int action(pion ** grille,char * proto,coup* coupPere,int fake){
        coup* coupSuivant = coupPere;
        char * protoB;
        int i;
        while (coupSuivant->coupSuivant != NULL) {

                if(strcmp(coupSuivant->proto, proto)==0) {
                        /*//if(fake)setGrilleCancel(copieGrille(grille));*/
                        if (strlen(proto)==3) {
                                /*//printf("\n Victoire ");*/
                                if(fake) setVictoire(1);
                                return 1;
                        }
                        else if (strlen(proto)==5&&proto[2]=='-') {
                                actionDeplacer(proto,grille);
                        }
                        else if(strlen(proto)==5&&proto[2]!='-') {
                                actionDeployRecursif(grille, proto, 0, 0);
                        }
                        else{
                                protoB = malloc(sizeof(char)*8);
                                initChar(protoB, 8);
                                for (i = 0; i<8; i++) {
                                        protoB[i] = proto[i];
                                }
                                if(proto[2]=='*') {
                                        protoB[5] = '+';
                                }
                                else{
                                        protoB[5] = '*';
                                }
                                actionDeployRecursif(grille, protoB, 0, 0);
                                free(protoB); protoB=NULL;
                        }
                        return 0;
                }
                coupSuivant = coupSuivant->coupSuivant;
        }
        return -1;
}
