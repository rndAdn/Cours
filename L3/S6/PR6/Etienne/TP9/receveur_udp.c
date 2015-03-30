#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

void get_address_from_caller(struct sockaddr * caller,socklen_t size)
{
    if(size == sizeof(struct sockaddr_in))
        {
          printf("%s:%u " ,inet_ntoa(((struct sockaddr_in *)caller)->sin_addr),ntohs(((struct sockaddr_in *)caller)->sin_port));
        }
}

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
    int sock2=socket(PF_INET,SOCK_DGRAM,0);
    while(1){
      struct sockaddr caller;
      //Doit être init sinon bug
      socklen_t size=sizeof(caller);
      int rec = recvfrom(sock, tampon, 99, 0, &caller, &size);
      /* get_address_from_caller(&caller,size); */
      tampon[rec]='\0';
      /* fflush(stdout); */
      sendto(sock2,tampon,strlen(tampon),0,&caller,(socklen_t)sizeof(struct sockaddr_in));
    }
  }
  close(sock);
  return 0;
}
