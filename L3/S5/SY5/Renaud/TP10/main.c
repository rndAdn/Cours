#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <dirent.h>
#include <dialog.h>
#include <termios.h>
#include <printf.h>
#include <limits.h>
#include <sys/wait.h>

char * arg[BUF_SIZE];

int parse(char* commande){
    int i = 0;
    *(commande+strlen(commande)-1)='\0';
    while((arg[i] = strsep(&commande, " ")) != NULL){
        i++;

    }
}

int execute(char* chaine){
    parse(chaine);
    if(fork() == 0){
        execv(arg[0],arg);
    }
    else{
        wait(NULL);
    }
}


int main(int argc, char*argv[]){
    char chaine[BUF_SIZE];
    while(1){
        printf("mpsh: ");
        fgets(chaine, BUF_SIZE, stdin);
        execute(chaine);
    }

    return 0;
}