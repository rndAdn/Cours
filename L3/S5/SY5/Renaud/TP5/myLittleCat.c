#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <tclDecls.h>

#define BUFSIZE 1024

void cat(int des, int n){
    char * buf = malloc(sizeof(char)* BUFSIZE);
    int lus=0;
    if(n){
        int ligne = 1;
        int i;
        while((lus=read(0,buf, BUFSIZE))!=0) {
            int last = 0;
            for(i=0;i<lus;i++){
                if(buf[i]=='\n'){
                    char *c = calloc(sizeof(char), 15);
                    sprintf(c,"%d ",ligne);
                    write(1,c,15);
                    write(1,buf+last, i - (last-1));
                    last = i+1;
                    ligne++;
                }
            }

        }
    }else{
        while((lus=read(0,buf, BUFSIZE))!=0) {
            write(1, buf, lus);
        }
    }
    free(buf);
}

int main(int argc, char const *argv[]){

    int n=0;
    int size = argc-1;
    int *fics;
    if(argc>1){
        if(strcmp(argv[1],"-n")==0){
            n=1;
            size--;
        }
        fics = malloc(sizeof(int)* size);




    }


    return 0;
}