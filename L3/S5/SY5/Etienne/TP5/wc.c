#define _POSIX_C_SOURCE 1
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#define TAILLE 500

int main(int argc, char *argv[]){
  int nbLignes = 0;
  int nbMots = 0;
  int nbCar = 0;
  int fd1, rc, t= TAILLE;
  int i = 0;
  char *tamp;

  if(argc != 2){
    fprintf(stderr,"usage:\n %s fichier_in",
      argv[0]);
    exit(1);
  }
  if( ( tamp = malloc(t) ) == NULL)
    exit(1);

  if ( ( fd1 = open(argv[1],O_RDONLY) ) < 0 )
    exit(1);
  for( ;; ){
    rc = read(fd1,tamp,t);
    nbCar += rc;
    if( rc < 0 ){
      exit(3);
    }
    if( rc == 0 )
      break;
    for (i = 0;i<rc;i++){
      if (tamp[i] == '\n')nbLignes ++;
      if ((tamp[i] == ' ' || tamp[i] == '\t' || tamp[i] == '\n') && ((i==0) || (tamp[i-1]!= ' ' && tamp[i-1] != '\t' && tamp[i-1] != '\n')))nbMots ++;
    }

  }
  close(fd1);
  free(tamp);
  printf("%d : nombreDeLignes \n%d : nombreDeMots \n%d : nombreDeCaracteres\n%s : nomDuFichier",nbLignes,nbMots,nbCar,argv[1]);
  return 0;
}
