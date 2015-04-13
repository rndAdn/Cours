#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>


int main()
{
  //Socket UDP
  int sock = socket(PF_INET, SOCK_DGRAM, 0);
  struct sockaddr_in address_sock;
  //IPV4
  address_sock.sin_family = AF_INET;
  address_sock.sin_port = htons(12321);
  //Any addr
  address_sock.sin_addr.s_addr = htonl(INADDR_ANY);
  
  int sock_b=socket(PF_INET,SOCK_DGRAM,0);
  //BroadCast 
  int ok =1;
  int r = setsockopt(sock_b,SOL_SOCKET,SO_BROADCAST,&ok,sizeof(ok));
  if(r!=0){
    exit(1);
  }
  //Get adress server
  struct addrinfo *first_info;
  struct addrinfo hints;
  memset(&hints, 0, sizeof(struct addrinfo));
  hints.ai_family = AF_INET;
  hints.ai_socktype=SOCK_DGRAM;
  r=getaddrinfo("255.255.255.255","10101",NULL,&first_info);

  //bind la socket pour ecouté
  r = bind(sock, (struct sockaddr *)&address_sock, sizeof(struct sockaddr_in));
  if (r != 0 || first_info == NULL)
    exit(1);
  struct sockaddr *saddr = first_info->ai_addr;
  char tampon[100];
  while (1)
  {
    //rcv
    struct sockaddr_in caller;
    //Doit être init sinon bug
    socklen_t size = sizeof(caller);
    int rec = recvfrom(sock, tampon, 99, 0, (struct sockaddr *)&caller, &size);
    //int rec=recv(sock,tampon,99,0);
    tampon[rec] = '\0';
    printf("Message recu : %s\n", tampon);
    sendto(sock_b, tampon, strlen(tampon), 0, saddr, (socklen_t)sizeof(struct sockaddr_in));
  }

  close(sock);
  return 0;
}

