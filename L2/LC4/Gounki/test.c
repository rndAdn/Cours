#include <stdio.h>
#include <stdlib.h>
#include "Pion.h"
#define clear()     printf("\033[H\033[2J")
#define fond1()     printf("\033[40m"); /*fond noir*/
#define fond2()     printf("\033[47m"); /*fond gris.*/
#define BLUE()      printf("\033[1;34m")
#define RED()       printf("\033[1;31m")
#define BLACK       "\033[0;30m"

char ** map;
void initMap(){
        int i,j;
        char a;
        map=malloc(sizeof(char *)*17);
        for (i=0; i<17; i++) {
                map[i]=malloc(sizeof(char)*17);
        }
        for (i=0; i<17; i++) {
                for (j=0; j<17; j++) {
                        map[i][j]=' ';
                }
        }
        a=49;
        for (i=1; i<16; i+=2) {
                map[0][i]=a;
                a++;
        }
        a=65;
        for (i=1; i<16; i+=2) {
                map[i][16]=a;
                a++;
        }
}

void freeMap(){
        int i;
        for (i=0; i<17; i++) {
                free(map[i]);
        }
        free(map);
}

int joueurs(){
        return 0;
}

void affiche(){
        int i;
        int j;
        int a;
        int b;
        int c;
        a=0; b=0; c=1;
        for (j=16; j>=0; j--) {
                for (i=0; i<17; i++) {
                        if (i>0 && j<16) {
                                if(b%2==0) {
                                        fond1();
                                }
                                else{
                                        fond2();
                                }
                                a++;
                                if(a==2) {
                                        b++;
                                        a=0;
                                }
                        }
                        if(i==0 && c==2) {
                                b++;
                                c=0;
                        }
                        if (i==0 || j==16) {
                                printf ("\033[0m");
                        }
                        if((map[i][j]=='B'&& j != 16)||(map[i][j-1]=='B'&& j != 17)) BLUE();
                        if((map[i][j]=='A'&& j != 16)||(map[i][j-1]=='A'&& j != 17)) RED();
                        printf("%c ",map[i][j]);
                }
                c++;
                printf ("\033[0m \n");
        }
}
void updateMap(pion ** grille){
        int x,y;
        x=0; y=0;
        for (x=0; x<8; x++) {
                for (y=0; y<8; y++) {
                        switch (grille[x][y].type) {
                        case 1:
                                map[x*2+1][y*2]=grille[x][y].joueur;
                                map[x*2+2][y*2]='C';
                                break;
                        case 2:
                                map[x*2+1][y*2]=grille[x][y].joueur;
                                map[x*2+2][y*2]='R';
                                break;
                        case 3:
                                map[x*2+1][y*2]=grille[x][y].joueur;
                                map[x*2+2][y*2]='C';
                                map[x*2+1][y*2+1]='C';
                                break;
                        case 4:
                                map[x*2+1][y*2]=grille[x][y].joueur;
                                map[x*2+2][y*2]='R';
                                map[x*2+1][y*2+1]='R';
                                break;
                        case 5:
                                map[x*2+1][y*2]=grille[x][y].joueur;
                                map[x*2+2][y*2]='C';
                                map[x*2+1][y*2+1]='C';
                                map[x*2+2][y*2+1]='C';
                                break;
                        case 6:
                                map[x*2+1][y*2]=grille[x][y].joueur;
                                map[x*2+2][y*2]='R';
                                map[x*2+1][y*2+1]='R';
                                map[x*2+2][y*2+1]='R';
                                break;
                        case 7:
                                map[x*2+1][y*2]=grille[x][y].joueur;
                                map[x*2+2][y*2]='C';
                                map[x*2+1][y*2+1]='R';
                                break;
                        case 8:
                                map[x*2+1][y*2]=grille[x][y].joueur;
                                map[x*2+2][y*2]='C';
                                map[x*2+1][y*2+1]='C';
                                map[x*2+2][y*2+1]='R';
                                break;
                        case 9:
                                map[x*2+1][y*2]=grille[x][y].joueur;
                                map[x*2+2][y*2]='C';
                                map[x*2+1][y*2+1]='R';
                                map[x*2+2][y*2+1]='R';
                                break;
                        case 0:
                                map[x*2+1][y*2]=' ';
                                map[x*2+2][y*2]=' ';
                                map[x*2+1][y*2+1]=' ';
                                map[x*2+2][y*2+1]=' ';
                                break;

                        }

                }
        }

}
