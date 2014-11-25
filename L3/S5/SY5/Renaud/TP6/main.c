#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>


#define BUFSIZE 1024

typedef struct {
    size_t taille;
    mode_t mode;
    size_t longueur_nom;
} Entete;


Entete getEntete(char * chemin){
    struct stat source;
    lstat(chemin, &source);

    Entete e;

    e.taille = source.st_size;
    e.mode = source.st_mode;
    e.longueur_nom = strlen(chemin);

    return e;

}

void tar(char* chemin, int des){
    int source = open(chemin, O_RDONLY);
    if(source == 0) exit(-1);

    Entete e = getEntete(chemin);
    write(des, &e,sizeof(Entete));
    char * buf = malloc(sizeof(char)* BUFSIZE);
    int lus;
    while((lus=read(source,buf, BUFSIZE))!=0) {
        write(des,buf,lus);
    }
    close(source);

}

void untar()


int main (int argc, char const *argv[]){
    int archive;
    if (argc > 3 && strcmp(argv[1], "-cf") == 0){
        if((archive = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0600) ) == -1){
            exit(-2);
        }
        int i;
        for(i=3; i < argc; i++){
            tar((char *)argv[i],archive);
        }
        close(archive);
    }
    return 0;
}


/**
Ex1 Q4
traiter les liens symboliques:
    S_ISLNK(mode) != 0

*) a l'archivage:
l'entete est le meme le contenu par contre est obtenu par readlink et non par open/read

*) au desarchivage:
on lit l'entete de la meme façcon dans tout les cs
si S_ISLNK(mode) detecte un lien:
- on utilise symlink() au lieu de open/write


int symlink(char* original, char* lien);
attention, si lien


*/
