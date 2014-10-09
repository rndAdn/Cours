#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int isRep(char * path){
  struct stat st;
  if(stat(path,&st)==-1){
    return 0; //Faux
  }
  if(S_ISDIR(st.st_mode)){
    return 1;
  }
  return 0;

}

int permOk(char * path){
  
}

int main(int argc,char** argv){

  if(!isRep(argv[1])){
    exit(0);
  }


}
