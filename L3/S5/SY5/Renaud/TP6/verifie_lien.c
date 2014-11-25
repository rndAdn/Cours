#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>

/**
* On verifie le lien on ne fait pas de suppression
*/
// ERREUR
int verifie_lien(char* path){
    struct stat st;
    char buf[PATH_MAX];

    return ( lstat(path, &st) != -1) //Le path existe
            && S_ISLNK(st.st_mode) // le path est un lien
            && (readlink(path, buf, PATH_MAX) != -1) // on suit le lien
            && (lstat(buf, &st) != -1); // si le lien existe
}


int main (int argc, char const *argv[]){
    if(argc != 2){
        printf("Arg !!");
        exit(-1);
    }

    struct stat st;
    char buf[PATH_MAX];

    if(lstat(argv[1], &st) == -1){
        printf("pour info %s invalide", argv[1]);
        exit(0);
    }

    if(S_ISLNK(st.st_mode)){
        printf("pour info %s pas lien symbolique", argv[1]);
        exit(0);
    }

    if(readlink(argv[1], buf, PATH_MAX) == -1){
        printf("readlink echoue sur %s", argv[1]);
        exit(-1);
    }

    if(stat(buf, &st) == -1){ // suit tout les liens
        /**inutile**/
        //if(errno == ELOOP){/* on a une boucle*/}
        //else {/* chaine qui fini par rien*/}


        printf("lien vers %s inexistant donc %s supprime",buf, argv[1]);
        char buf1[PATH_MAX], buf2[PATH_MAX];
        strcpy(buf1, argv[1]);
        while(1){
            if(readlink(buf1, buf2, PATH_MAX) == -1) break;
            unlink(buf1);
            strcpy(buf1, buf2);
        }
        if( unlink(argv[1]) == -1){
            printf("je n'arrive pas a supprimer %s", argv[1]);
        }
        exit(-1);
    }
    else{
        printf("pour info %s lien valide vers %s", argv[1], buf);
    }


    return 0;
}
