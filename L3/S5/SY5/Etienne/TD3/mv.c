#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int recupNomFichier(char * path){
  int i = 0;
  int j = 0;
  while(path[i]!='\0'){
    if (path[i] == '/') j=i;
    i++;
  }
  return j;
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


int verifPerm(char *rep){
  struct stat repStat;
  stat(rep,&repStat);
  //printf("ok");
  if(repStat.st_mode & S_IRUSR)
    return 1;
  else
    return 0;
}

int main(int argc, char * argv[])
{
  if (strcmp(argv[0],"./mv")!=0)return 1;
  if (argv[1] == NULL || argv[2] == NULL) return 1;
  if(!verifPerm(argv[1]))return 1;
  if(verifFic2(argv[2]) == 1){
    if(!verifPerm(argv[2]))return 1;
    link(argv[1],strcat(argv[2],argv[1]+recupNomFichier(argv[1])));
    unlink(argv[1]);
  }
  else if(verifFic2(argv[2]) == -1){
    link(argv[1],argv[2]);
    unlink(argv[1]);
  }
  return 0;
}
