#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <unistd.h>
#define BUFSIZE 128

void reverse(char * str){
    char tmp;
    int i;
    int taille = BUFSIZE;
    printf("%d\n",taille);
    for(i=0;i<taille/2;i++){
        tmp = str[i];
        str[i]=str[taille-1-i];
        str[taille-1-i]=tmp;
    }

}

void ypoc(int src,int des){

    int lus;
    char buf[BUFSIZE];
    //int tSrc = lseek(src,0,SEEK_END) - BUFSIZE;
    //lseek(src,0,SEEK_SET);
    while((lus=read(src,buf,BUFSIZE))!=0){
        //printf("%d\n",lus);
        reverse(buf);
        lseek(des,-lus,SEEK_CUR);
        write(des,buf,lus);

        //printf("%d\n",tSrc);
    }

}



int main (int argc, char const *argv[]){
    /*
    char * str = malloc(sizeof(char)*10);
    sprintf(str,"abcdefghij");
    reverse(str);
    printf("%s\n",str);
    */
    int src = open(argv[1],O_RDONLY);
    int des = open(argv[2],O_WRONLY|O_CREAT);
    ypoc(src,des);
    return 0;
}
