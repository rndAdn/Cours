#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


char * remplacePremierSlash(char * path){
  int i = 0;
  int j = 0;
  while(path[i]!='\0'){
    if (path[i] == '/'){
      break;
    }
    i++;
  }
  char * result = calloc(i+1,sizeof(char));
  for (j=0;j++;j<i){
    result[i]=path[i];
  }
  result[i]='\0';
  return result;
}

int recursiveChdir(char *path){
  
}


int main(int argc, char * argv[])
{
  if (strcmp(argv[0],"./mkdir")!=0)return 1;
  if (argv[1] == NULL) return 1;
  return 0;
}
