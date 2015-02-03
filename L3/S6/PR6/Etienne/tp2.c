#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define SIZE 128

void breakpoint(){

}

void readInput(){
  char buf[1024];
  int rc;
  int * tab = malloc(SIZE*sizeof(int));
  int i = 0;
  int size = SIZE;
  do{
    breakpoint();
    rc = read(0,&buf,1024);
    buf[rc] = 0;
    if(strncmp(buf,"quit\n",rc) == 0){
      free(tab);
      return;
    }
    *(tab+i) = atoi(buf);
    i++;
    if(i==size){
      size *= 2;
      tab = realloc(tab,size*sizeof(int));
    }

  }while(42);
}

void checkFile(int des){
  int rc = 0;
  char buf[1024];
  int i = 0;
  while((rc=read(des,buf,1024))!=0){
    for (i = 0;  i< rc; i++) {
      if(buf[i]<'0' || buf[i]>'9'){
        printf("Mauvais Fichier\n");
        return;
      }
    }
  }
  printf("Bon Fichier \n");
}

int main(int argc,char **args) {
  printf("Hello World!! \n");
  int A[] = {12,23,34,45,56,67,78,89,90};
  int *P;
  P=A;
  //++P;
  printf("P:  %p\n",P);
  printf("A:  %p\n",A);
  printf("&A:  %p\n",&A);
  printf("&P:  %p\n",&P);
  printf("*P+2:  %d\n",*P+2);
  printf("*(P+2):  %d\n",*(P+2));
  printf("*&P+1:  %p\n",&P+1);
  printf("P+1:  %p\n",P+1);
  printf("&A[4]-3:  %p\n",&A[4]-3);
  printf("A+3:  %p\n",A+3);
  printf("P+(*P-10):  %p\n",P+(*P-10));
  printf("*(P+*(P+8)-A[7]):  %d\n",*(P+*(P+8)-A[7]));

  return 0;

}
