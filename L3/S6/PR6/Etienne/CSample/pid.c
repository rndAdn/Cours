#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc,char ** argv){
  int pid = getpid();
  int f = fork();
  if(f == 0){
    int p = getpid();
    int m = getppid();
    printf("Hey pere %d file %d \n",m,p);
    exit(0);
  }
  else{
    printf("Hi am %d \n",pid);
    wait(NULL);
  }
  return 0;
}
