#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main(int argc,char **argv) {
  int test = 97;
  char * cool = (char *)&test;
  printf("0 : %c ,",cool[0]);
  printf("1 : %c ,",cool[1]);
  printf("2 : %c ,",cool[2]);
  printf("3 : %c ,",cool[3]);
  return 0;
}
