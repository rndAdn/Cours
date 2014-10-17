#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>


void sauv_rec(const char *src, const char *dest){
    struct stat source;
    lstat(src, &source);
    struct stat destination;
    lstat(dest, &destination);

    if(!S_ISDIR(source.st_mode)){
        exit(-1);
    }
    if(!S_ISDIR(destination.st_mode)){
        mkdir(dest, source.st_mode);
    }

    DIR *dir;
    dir = opendir(src);
    struct dirent *entry;

    while((entry = readdir(dir)) != NULL){
        printf("%s",src);
        if(strcmp(entry->d_name,".") == 0 || strcmp(entry->d_name,"..") == 0){
            continue;
        }
        char *chSrc =malloc(sizeof(char)*(strlen(src)+strlen(entry->d_name)+2));
        sprintf(chSrc, "%s/%s",src,entry->d_name);
        struct stat tmp;
        lstat(chSrc, &tmp);

        if(S_ISDIR(tmp.st_mode)){
            printf("%s\n",src);
            char *chDest =malloc(sizeof(char)*(strlen(dest)+strlen(entry->d_name)+2));
            sprintf(chDest, "%s/%s",dest,entry->d_name);
            sauv_rec(chSrc, chDest);
        }

    }


}


int main (int argc, char const *argv[]){
    sauv_rec(argv[1], argv[2]);


    return 0;
}
