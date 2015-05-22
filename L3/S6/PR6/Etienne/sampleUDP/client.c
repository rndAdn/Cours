#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>

int main(){
  //socket envoi UDP
  int sock=socket(PF_INET,SOCK_DGRAM,0);
  //Get adress server
  struct addrinfo *first_info;
  struct addrinfo hints;
  memset(&hints, 0, sizeof(struct addrinfo));
  hints.ai_family = AF_INET;
  hints.ai_socktype=SOCK_DGRAM;
  int r=getaddrinfo("localhost","4242",NULL,&first_info);
  if(r==0){
    if(first_info!=NULL){
      //Adresse du receveur
      struct sockaddr *saddr=first_info->ai_addr;

      char tampon[100];
      int i=0;
      for(i=0;i<=10;i++){
        strcpy(tampon,"MESSAGE ");
        char entier[3];
        sprintf(entier,"%d",i);
        strcat(tampon,entier);
        //envoi du paquet
        sendto(sock,tampon,strlen(tampon),0,saddr,(socklen_t)sizeof(struct sockaddr_in));
      }
    }
  }
  close(sock);
  return 0;
}
//SERVER 
//
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
