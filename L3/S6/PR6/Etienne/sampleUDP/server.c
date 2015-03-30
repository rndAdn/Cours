#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main() {
  //Socket UDP
  int sock=socket(PF_INET,SOCK_DGRAM,0);
  struct sockaddr_in address_sock;
  //IPV4
  address_sock.sin_family=AF_INET;
  address_sock.sin_port=htons(4242);
  //Any addr
  address_sock.sin_addr.s_addr=htonl(INADDR_ANY);
  //bind la socket pour ecouté
  int r=bind(sock,(struct sockaddr *)&address_sock,sizeof(struct sockaddr_in));
  if(r==0){
    char tampon[100];
    while(1){
      //rcv
      struct sockaddr_in caller;
      //Doit être init sinon bug
      socklen_t size=sizeof(caller);
      int rec = recvfrom(sock, tampon, 99, 0, (struct sockaddr *)&caller, &size);
      //int rec=recv(sock,tampon,99,0);
      tampon[rec]='\0';
      printf("Message recu : %s\n",tampon);
    }
  }
  close(sock);
  return 0;
}
