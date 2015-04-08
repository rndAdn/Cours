
#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>

int main(){
  //socket envoi UDP
  int sock=socket(PF_INET,SOCK_DGRAM,0);
  struct sockaddr_in address_sock;
  //IPV4
  address_sock.sin_family=AF_INET;
  address_sock.sin_port=htons(4243);
  //Any addr
  address_sock.sin_addr.s_addr=htonl(INADDR_ANY);
  //bind la socket pour ecouté
  int r=bind(sock,(struct sockaddr *)&address_sock,sizeof(struct sockaddr_in));

  //Get adress server
  struct addrinfo *first_info;
  struct addrinfo hints;
  memset(&hints, 0, sizeof(struct addrinfo));
  hints.ai_family = AF_INET;
  hints.ai_socktype=SOCK_DGRAM;
  r=getaddrinfo("0.0.0.0","4242",NULL,&first_info);
  if(r==0){
    if(first_info!=NULL){
      //Adresse du receveur
      struct sockaddr *saddr=first_info->ai_addr;

      char tampon[100];
      tampon[read(0,tampon,99)] = 0;      //envoi du paquet
      sendto(sock,tampon,strlen(tampon),0,saddr,(socklen_t)sizeof(struct sockaddr_in));
      tampon[recv(sock, tampon, 99, 0)] = 0;
      printf("%s\n",tampon);
    }
  }
  close(sock);
  return 0;
}
