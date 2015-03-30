#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#define BUFFSIZE 1024

lectPartagee(int a){
    struct flock verrou;
    verrou.l_type = F_RDLCK;
    verrou.l_whence = SEEK_SET;
    verrou.l_start = 0;
    verrou.l_len = 0;
    if(fcntl(a, F_SETLK, &verrou) != 0) printf("error");

    int lu;
    char buff[BUFFSIZE];

    while ((lu = read(a,buff, BUFFSIZE)) != 0){
        write(1, buff, lu);
    }
    sleep(5);

}

lectExclu(int a){
    struct flock verrou;
    verrou.l_type = F_WRLCK;
    verrou.l_whence = SEEK_SET;
    verrou.l_start = 0;
    verrou.l_len = 0;
    if(fcntl(a, F_SETLK, &verrou) != 0) printf("error");

    int lu;
    char buff[BUFFSIZE];

    while ((lu = read(a,buff, BUFFSIZE)) != 0){
        write(1, buff, lu);
    }
    //sleep(5);
}

int main(int argc, char*argv[]){

    int fichier = open("/media/data/git/Cours/L3/S5/SY5/Renaud/TP7/test.txt", O_RDWR);

    lectExclu(fichier);
    //lectPartagee(fichier);

    //perror("choco");
}