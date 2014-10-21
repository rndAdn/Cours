#define _POSIX_C_SOURCE 1
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define TAILLE 1024

int main(int argc, char *argv[]){
        int lastLigne=0;
        int nbLignes = 0;
        int n = 0;
        int rc,wc,fd1, t= TAILLE;
        int i = 0;
        char *tamp;
        char *tampLigne;
        int j = 1;

        if(argc == 1 || (argc > 1 && argv[1][0] == '-' && (argv[1][1] != 'n' || argv[1][2] != 0))) {
                fprintf(stderr,"usage:\n %s (-n) fichier_in",
                        argv[0]);
                exit(1);
        }
        else if(argc == 2 && argv[1][0] == '-' && argv[1][1] == 'n' && argv[1][2] == 0) {
                //nbFichier = argc;
                n = 1;
                //j=1;
        }
        else if(argc > 2 && argv[1][0] == '-' && argv[1][1] == 'n' && argv[1][2] == 0) {
                //nbFichier = argc;
                n=1;
                j=2;
        }
        else if(argc > 2 ) {
                //nbFichier = argc
                j=1;
        }
        if( ( tamp = malloc(t) ) == NULL)
                exit(1);
        if( n && ( tampLigne = calloc(15,1) ) == NULL)
                exit(1);
        do {
                nbLignes = 0;
                if(n) {
                        sprintf(tampLigne,"\n%d ",++nbLignes);
                        wc=write(1,tampLigne,15);
                      }
                if(j == 1)
                        rc = read(0,tamp,t);
                else{
                        if ( ( fd1 = open(argv[j],O_RDONLY) ) < 0 )
                                exit(1);
                    }
                for(;; ) {
                        rc = read(fd1,tamp,t);
                                //printf("HI");
                        if( rc < 0 ) {
                                exit(3);
                        }
                        if( rc == 0 )
                                break;
                        if(n) {
                                lastLigne = 0;
                                for (i = 0; i<rc; i++) {
                                        if (tamp[i] == '\n') {
                                                wc = write(1,tamp+lastLigne,i+1 - lastLigne);
                                                sprintf(tampLigne,"%d ",++nbLignes);
                                                wc = write(1,tampLigne,15);
                                                lastLigne = i+1;
                                        }
                                }
                                wc = write(1,tamp+(lastLigne),i+1 - lastLigne);
                        }
                        else wc=write(1,tamp,rc);
                }
                j++;
                //printf("%d",j);
        } while(j<argc);
        //printf("%d" ,argc);
        free(tamp);
        if(n) free(tampLigne);
        return 0;
}
