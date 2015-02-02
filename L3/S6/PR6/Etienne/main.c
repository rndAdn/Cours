#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>


int checkFile(int des){
  int rc = 0;
  char buf[1024];
  int i = 0;
  while((rc=read(des,buf,1024))!=0){
    for (i = 0;  i< rc; i++) {
      if(buf[i]<'0' || buf[i]>'9'){
        printf("Mauvais Fichier\n");
        return 1;
      }
    }
  }
  printf("Bon Fichier \n");
  return 0;
}


int main(int argc,char **argv) {
  if(argc<4)return 1;
  char * fic = argv[1];
  int alire = atoi(argv[2]);
  int pivot = atoi(argv[3]);

  int des = open(fic,O_RDONLY);
  if(checkFile(des)) return 1;



  return 0;
}
