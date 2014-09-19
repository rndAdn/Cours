//
//  dico.c
//  TP5
//
//  Created by Etienne Toussaint on 05/03/2014.
//  Copyright (c) 2014 Etienne Toussaint. All rights reserved.
//

#include <stdio.h>


struct traduction {
    char*lang1;
    char*lang2;
};

char *traduit12(const struct traduction *dico, int taille_dico, const char *mot){
    int bool = 0;
    int i = 0;
    int j = 0;
    for(i=0;i<taille_dico;i++){
        j = 0;
        if(strcmp((*(dico+i)).lang1),mot){
            return (*(dico+i)).lang2
        }
    }
    return NULL;
}

int nombre_mots(const char *texte){
    int i = 0;
    int result = 0;
    while (*(texte+i)!=0)
    {
        if(*(texte+i) == ' ')result ++;
        i++;
    }
    return result;
}

char **decoupe(char *texte){
    int nombreMots=nombre_mots(texte);
    int i = 0;
    int j = 1;
    char **result = malloc(sizeof(char*)*nombreMots);
    *result = *texte;
    while (*(texte+i)!=0)
    {
        if(*(texte+i) == ' '){
            *(texte+i) = 0;
            *result +j = texte+i+1;
            j++;
        }
        i++;
    }
    return result;
    
}