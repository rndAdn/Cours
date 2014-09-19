/*
   //  persistance.c
   //  ProjetRC
   //
   //  Created by Etienne Toussaint on 08/05/2014.
   //  Copyright (c) 2014 Etienne Toussaint. All rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>
#include "persistance.h"

void viderBufferb()
{
        int c;
        c= 0;
        while (c != '\n' && c != EOF)
        {
                c = getchar();
        }
}

char inToChar(int i){
        char result;
        result= 48+i;
        return result;
}

int charToInt(char c){
        int result;
        result= (int)c-48;
        return result;
}

void save(pion ** grille, char joueur, int mode){
        char * date, * name,* sauvegarde;
        FILE * fichier;
        int i;
        time_t result;
        result= time(NULL);
        date= asctime(localtime(&result));
        date[strlen(date)-1]=0;
        name= calloc(60,sizeof(char));
        strcat(name,"./Sauvegarde/");
        strcat(name,date);
        fichier= fopen((const char *)name, "w");
        sauvegarde= calloc(196,sizeof(char));
        sauvegarde[0]='#';
        sauvegarde[1]=inToChar(mode);
        sauvegarde[2]=joueur;
        sauvegarde[3]='\n';

        i= 2;
        for (i=0; i<64; i++) {
                sauvegarde[3*i+4]=(grille[i%8][i/8].joueur == 'A') ? 'B' : (grille[i%8][i/8].joueur == 'B') ? 'N' : 'V';
                sauvegarde[3*i+5]=inToChar(grille[i%8][i/8].type);
                sauvegarde[3*i+6]='\n';
        }
        fprintf(fichier,"%s",sauvegarde);
        /*free(result);
           //free(date);*/
        free(name);
        free(sauvegarde);
        fclose(fichier);
}
char * charger(){
        struct dirent *lecture;
        DIR *rep;
        char * lec, * chargement,* name;
        int i,choix;
        FILE * fichier;
        rep = opendir("./Sauvegarde/" );
        i= 0;
        while ((lecture = readdir(rep))) {
                lec = lecture->d_name;
                if(lec[0]!='.') printf("Pour ouvrir : %s taper %d \n",lec,i+1);
                i++;
        }
        choix = 0;
        while (choix==0) {
                scanf("%d", &choix);
                viderBufferb();
        }
        closedir(rep);
        rep = opendir("./Sauvegarde/" );
        for (i = 0; i<choix; i++) {
                lecture = readdir(rep);
        }
        name = calloc(60,sizeof(char));
        strcat(name,"./Sauvegarde/");
        strcat(name,lecture->d_name);
        closedir(rep);
        fichier= fopen(name, "r");
        free(name);

        chargement= calloc(196,sizeof(char));
        fread( chargement, 196*sizeof(char), 1, fichier );
        fclose(fichier);

        return chargement;
}
