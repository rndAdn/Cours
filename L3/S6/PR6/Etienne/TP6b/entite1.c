#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>


int main(int argc, char const *argv[]) {
  //Variable pour les retour et erreur
  int retour = 0;
  //Socket Server IPV4
  int sockServer = socket(PF_INET,SOCK_STREAM,0);
  struct sockaddr_in address_sock;

  address_sock.sin_family=AF_INET;
  address_sock.sin_port=htons(4202);
  //Adresse quelqu'onque car localHost
  address_sock.sin_addr.s_addr=htonl(INADDR_ANY);

  //Fonction liant la socket a un port de la machine lui fournir un nom
  retour = bind(sockServer,(struct sockaddr *)&address_sock,sizeof(struct sockaddr_in));
  if(retour == -1){
    perror(strerror(errno));
    exit(1);
  }
  //fonction lancant l'écoute par default 0 nombre de client en attente
  retour = listen(sockServer,0);
  if(retour == -1){
    perror(strerror(errno));
    exit(1);
  }

  //Stocke l'addresse de l'appelant
  struct sockaddr_in caller;
  //Doit être init sinon bug
  socklen_t size=sizeof(caller);

  int descSock=accept(sockServer,(struct sockaddr *)&caller,&size);
  if(retour == -1){
    perror(strerror(errno));
    exit(1);
  }
  char buff[1024];
  int recu=recv(descSock,buff,1023*sizeof(char),0);
  buff[recu]='\0';
  printf("Message recu : %s\n",buff);
  int i = 0;
  char ip[1024];
  while(buff[i] != ' '){
    ip[i]=buff[i];
    i++;
  }
  ip[i]=0;
  close(descSock);
  close(sockServer);

  struct sockaddr_in adress_sock_client;

  //Si Ip connu:
  struct in_addr addrIPV4_client;
  retour = inet_aton(ip,&addrIPV4_client);
  if(retour == 0){
    printf("Adresse IP non valide\n");
    exit(1);
  }
  adress_sock_client.sin_family = AF_INET;
  //BigENDIAN
  adress_sock_client.sin_port = htons(atoi(buff+i));
  adress_sock_client.sin_addr = addrIPV4_client;

  int desc_sock_client = socket(PF_INET,SOCK_STREAM,0);
  retour = connect(desc_sock_client,(struct sockaddr *)&adress_sock_client,sizeof(struct sockaddr_in));
  if(retour == -1){
    perror(strerror(errno));
    exit(1);
  }
  char *mess="CONFIRM\n";
  retour = send(desc_sock_client,mess,strlen(mess),0);
  if(retour == -1){
    perror(strerror(errno));
    exit(1);
  }
  //char buff[1024];
  recu=recv(desc_sock_client,buff,1023*sizeof(char),0);
  buff[recu]='\0';
  printf("Message recu : %s\n",buff);
  close(desc_sock_client);

  
  return 0;
}

