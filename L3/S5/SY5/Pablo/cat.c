#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<sys/time.h>
#include	<unistd.h>

#define BUFSIZE 128

void cat (int des){
    int lus;
    char buf[BUFSIZE];
    while((lus=read(des,buf,BUFSIZE))){
        write(STDOUT_FILENO,buf,lus);
    }
}


int main (int argc, char const *argv[]){

    int op = open(argv[1],O_RDONLY);
    cat(op);
    return 0;
}
