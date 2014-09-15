//
//  main.c
//  TP8
//
//  Created by Etienne Toussaint on 26/03/2014.
//  Copyright (c) 2014 Etienne Toussaint. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct personne {
    int id; /* On prendra l'indice du tableau , par exemple */
    char *nom;
    char age;
    char telephone [10];
    char *notes;
}personne;

static struct personne *carnet_lu;
static int taille_carnet_lu;
static personne carnet[3] = {
     {1,"coucou",13,"0437363747","test"},
     {2,"coucou",14,"0437363747","test"},
     {3,"coucou",15,"0437363747","test"}
};
static int nombreDEntrees =  3;

int put_16(FILE *stream, short s){
    fputc((s>>8)&0xFF, stream);
    fputc(s&0xFF, stream);
    return 0;
}
int get_16(FILE *stream, short *s){
    *s = fgetc(stream)<<8;
    *s += fgetc(stream);
    return 0;
}

int jette(FILE *stream, int noctets){
    int i = 0;
    for (i=0; i<noctets; i++) {
        fgetc(stream);
    }
    return 0;
}

int get_32(FILE *stream, int *i){
    *i = fgetc(stream)<<24;
    *i += fgetc(stream)<<16;
    *i += fgetc(stream)<<8;
    *i += fgetc(stream);
    return 0;
}

int put_32(FILE *stream, int i){
    fputc((i>>24)&0xFF, stream);
    fputc((i>>16)&0xFF, stream);
    fputc((i>>8)&0xFF, stream);
    fputc(i&0xFF, stream);
    return 0;
}

int serialize(void){
    FILE* fichier = NULL;
    fichier = fopen("/Users/Toussaint/Documents/sauvegarde.dat", "w");
    if (fichier == NULL)
    {
        return -1;   // On peut lire et écrire dans le fichier
    }
    //TLV Meta
    fputc(1, fichier);
    put_16(fichier, 9);
    fputc(0, fichier);
    put_32(fichier, (int)"Nombre de personnes");
    put_32(fichier, (int)" Nombre de groupes");
    //TLV carnet
    
    int i = 0;
    for (i=0; i<nombreDEntrees; i++) {
        fputc(2, fichier);
        put_16(fichier, sizeof(personne));
        fputc(carnet[i].age, fichier);
        put_32(fichier, (int)carnet[i].id);
        int j = 0;
        for (j=0; j<10; j++) {
            fputc(carnet[i].telephone[j], fichier);
        }
        char *  courant = carnet[i].nom;
        while (*courant != 0) {
            fputc(*courant, fichier);
            courant++;
        }
        fputc(0, fichier);
    }
    
    
    fclose(fichier); // On ferme le fichier qui a été ouvert
    return 0;
    
}

int deserialize(void) {
    char buffer[4096];
    FILE* fichier = NULL;
    fichier = fopen("/Users/Toussaint/Documents/sauvegarde.dat", "r");
    if (fichier == NULL)
    {
        return -1;
    }
    jette(fichier, 4);
    get_32(fichier, &taille_carnet_lu);
    carnet_lu = malloc(sizeof(personne)*taille_carnet_lu);
    jette(fichier, 4);
    int i = 0;
    for (i=0; i<taille_carnet_lu; i++) {
        jette(fichier, 3);
        carnet_lu[i].age = fgetc(fichier);
        get_32(fichier,&carnet_lu[i].id);
        int j = 0;
        for (j=0; j<10; j++) {
            carnet_lu[i].telephone[j] = fgetc(fichier);
        }
        char courant;
        j = 0;
        do{
            courant = fgetc(fichier);
            buffer[j] = courant;
        }while (courant != 0);
    }
    
    fclose(fichier);
    return 0;
}

int main(int argc, const char * argv[])
{
    serialize();
    deserialize();
    return 0;
}
