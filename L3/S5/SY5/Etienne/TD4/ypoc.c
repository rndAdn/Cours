#define _POSIX_C_SOURCE 1
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define TAILLE 500

void inverseP(char * str, int size){
    int i = 0;
    char tmp;
    for(i=0;i<size/2+1;i++){
      tmp = str[size-(i+1)];
      str[size-(i+1)]=str[i];
      str[i]=tmp;
    }
}

char * inverse(char * str, int size){
  char * result = calloc(size,sizeof(char));
  int i = 0;
  for(i=0;i<size;i++){
    result[size-(i+1)]=str[i];
  }
  //free(str);
  return result;
}

int main(int argc, char *argv[]){

  int fd1, fd2, rc, wc, t;
  char *tamp;
  if( argc == 4 ){
    t=atoi(argv[3]);
  }
  else if( argc == 3 )
    t = TAILLE;
  else{
    fprintf(stderr,"usage:\n %s fichier_in"
          " fichier_out [taille_de_tampon]\n",
	    argv[0]);
    exit(1);
  }
  if( ( tamp = malloc(t) ) == NULL)
    exit(1);

  if ( ( fd1 = open(argv[1],O_RDONLY) ) < 0 )
    exit(1);

  if( ( fd2 = open(argv[2],O_WRONLY | O_CREAT | O_TRUNC,
		   S_IRWXU | S_IRWXG | S_IRWXO ) ) < 0 )
    exit(2);
  int i = 0;
  int tf = lseek(fd1,0,SEEK_END);
  lseek(fd1,0,SEEK_SET);
  for( ;; ){
    i++;
    rc = read(fd1,tamp,t);
    if( rc < 0 ){
      exit(3);
    }
    if( rc == 0 )
      break;
    if(tf-i*t>0) lseek(fd2,tf-(i*t),SEEK_SET);
    else lseek(fd2,2,SEEK_SET);
    inverseP(tamp,rc);
    wc=write(fd2,tamp,rc);
    //free(tmp);
    if( wc < 0 ){
      exit(4);
    }
  }
  close(fd1);
  close(fd2); free(tamp);
  return 0;
}
