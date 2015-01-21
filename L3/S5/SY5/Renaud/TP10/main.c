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
#include <lber.h>

char * arg[BUF_SIZE];

int parse(char* commande){
    int i = 0;
    *(commande+strlen(commande)-1)='\0';
    while((arg[i] = strsep(&commande, " ")) != NULL){
        i++;

    }
    arg[i] = NULL;
}

int execute(char* chaine){
    parse(chaine);
    if(strcmp(arg[0], "cd") == 0){
        chdir(arg[1]);
    }
    else if(fork() == 0){
        execvp(arg[0],arg);
    }
    else{
        wait(NULL);
    }
}


int main(int argc, char*argv[]){
    char chaine[BUF_SIZE];
    char pwd [PATH_MAX];
    while(1){
        printf("\e[0;36m mpsh %s\e[0m $>> ", getcwd(pwd, PATH_MAX));
        fgets(chaine, BUF_SIZE, stdin);
        execute(chaine);
    }

    return 0;
}