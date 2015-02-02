#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main(int argc,char **argv) {
  if(argc<2)return 1;
  int test = atoi(argv[1]);
  printf("arg = %x\n",test);
  printf("netlong = %x\n",htonl(test));
  printf("hostlong = %x\n",ntohl(htonl(test)));
}
