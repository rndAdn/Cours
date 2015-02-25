#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <dialog.h>


int main (int argc, char const *argv[]){
    if(argc != 2){
        printf("usage : wc <reference>\n");
        exit(0);
    }

    int ligne = 0, mot = 0, car = 0,lus=0;
    int fichier = open(argv[1],O_RDONLY);

    if(fichier ==-1){
        printf("Fichier introuvable\n");
        exit(0);
    }

    char * buf = malloc(sizeof(char)* BUF_SIZE);
    int i;
    int tmp = 1;
    while((lus=read(fichier,buf,BUF_SIZE))!= 0){
        car+=lus;
        for(i=0;i<lus;i++){
            if((buf[i]==' '|| buf[i]=='\t') && tmp){
                mot+=1;
                tmp=0;
            }else if((buf[i]=='\n') && tmp){
                mot+=1;
                ligne+=1;
                tmp=0;
            }
            else tmp=1;
        }
    }
    printf("%d %d %d %s\n",ligne,mot,car,argv[1]);
    close(fichier);
    free(buf);

    return 0;
}
