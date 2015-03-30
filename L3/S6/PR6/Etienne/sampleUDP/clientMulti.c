
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
  //BroadCast 
  int ok =1;
  int r = setsockopt(sock,SOL_SOCKET,SO_BROADCAST,&ok,sizeof(ok));
  if(r!=0){
    exit(1);
  }
  //Get adress server
  struct addrinfo *first_info;
  struct addrinfo hints;
  memset(&hints, 0, sizeof(struct addrinfo));
  hints.ai_family = AF_INET;
  hints.ai_socktype=SOCK_DGRAM;
  r=getaddrinfo("localhost","4242",NULL,&first_info);
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
