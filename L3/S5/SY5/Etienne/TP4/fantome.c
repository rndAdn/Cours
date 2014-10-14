#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>

void copy(char * source_file, char * target_file){
        char ch;
        FILE *source, *target;

        printf("Enter name of file to copy\n");

        source = fopen(source_file, "r");

        if( source == NULL )
        {
                printf("Press any key to exit...\n");
                exit(EXIT_FAILURE);
        }

        printf("Enter name of target file\n");

        target = fopen(target_file, "w");

        if( target == NULL )
        {
                fclose(source);
                printf("Press any key to exit...\n");
                exit(EXIT_FAILURE);
        }

        while( ( ch = fgetc(source) ) != EOF )
                fputc(ch, target);

        printf("File copied successfully.\n");

        fclose(source);
        fclose(target);
}

int verifFic2(char * rep){
        struct stat repStat;
        if(stat(rep,&repStat) == -1)
                return -1;
        if(S_ISDIR(repStat.st_mode))
                return 1;
        else
                return 0;
}



void sauv_rec(char *src, char *dest){
        struct stat srcStat;
        struct stat destStat;
        if (stat(src,&srcStat)==-1) {
                printf("%s n'est pas une source valide.\n",src);
                exit(0);
        }
        else if( !(S_ISDIR(srcStat.st_mode))) {
                //printf("%s n'est pas un répertoire.\n",src);
                //exit(0);
                if (stat(dest,&destStat)==-1) {
                        printf("Creation du lien vers le fichier\n");
                        copy(src,dest);
                }
                else{
                        printf("Il exite déja un fichier/dossier de ce nom");
                        exit(0);
                }
        }
        else{
                if (stat(dest,&destStat)==-1) {
                        printf("Creation dossier dest\n");
                        mkdir(dest, srcStat.st_mode);
                }
                else if (!(S_ISDIR(destStat.st_mode))) {
                        printf("Dest est un fichier.\n");
                        exit(0);
                }

                DIR *dirSrc = opendir(src);
                struct dirent *entry;
                while((entry = readdir(dirSrc)) != NULL) {
                        if(entry->d_name[0] == '.') {
                                continue;
                        }
                        struct stat tmpSrc;
                        char *cheminSrc = malloc(sizeof(char)*(strlen(src)+strlen(entry->d_name)+2));
                        sprintf(cheminSrc, "%s/%s",src,entry->d_name);
                        lstat(cheminSrc, &tmpSrc);
                        char *cheminDest = malloc(sizeof(char)*(strlen(dest)+strlen(entry->d_name)+2));
                        sprintf(cheminDest, "%s/%s",dest,entry->d_name);
                        sauv_rec(cheminSrc,cheminDest);
                }
        }

}



int main(int argc, char * argv[])
{
        printf("%s\n",argv[1]);
        sauv_rec(argv[1],argv[2]);
        return 0;
}
