#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char const *argv[]) {
  //Variable pour les retour et erreur
 int retour = 0;
  //Socket Server IPV4
 int sockServer = socket(PF_INET6,SOCK_STREAM,0);
 struct  sockaddr_in6 address_sock;

 address_sock.sin6_family=AF_INET6;
 address_sock.sin6_port=htons(4202);
 //Adresse quelqu'onque car localHost
 address_sock.sin6_addr = in6addr_any;

 //Fonction liant la socket a un port de la machine lui fournir un nom
 retour = bind(sockServer,(struct sockaddr *)&address_sock,sizeof(struct  sockaddr_in6));
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

 int pid = fork();
 if(pid == 0){
   struct  sockaddr_in6 caller;
   socklen_t size=sizeof(caller);

   int descSock=accept(sockServer,(struct sockaddr *)&caller,&size);
   if(retour == -1){
     perror(strerror(errno));
     exit(1);
   }
   char *mess="Confirmation!\n";
   send(descSock,mess,strlen(mess)*sizeof(char),0);
   close(descSock);
   close(sockServer);
   exit(0);
  }

  close(sockServer);
  //Client :
  int retourClient = 0;
  //Socket IPV4
  struct sockaddr_in adress_sock_client;

  //SI IP INCONNUE
  struct addrinfo *first_info;
  struct addrinfo hints;
  //Init 0
  bzero(&hints,sizeof(struct addrinfo));
  //Set Filter IPV4 / TCP
  hints.ai_family = AF_INET;
  hints.ai_socktype=SOCK_STREAM;

  //On oubliera pas le free
  retourClient = getaddrinfo("lucien","4201",&hints,&first_info);
  if(retourClient !=0){
    printf("%s\n",gai_strerror(retourClient));
    exit(1);
  }
  if(first_info!=NULL){
    adress_sock_client = *(struct sockaddr_in *)first_info->ai_addr;
  }

  int desc_sock = socket(PF_INET,SOCK_STREAM,0);
  retourClient = connect(desc_sock,(struct sockaddr *)&adress_sock_client,sizeof(struct sockaddr_in));
  if(retour == -1){
    perror(strerror(errno));
    exit(1);
  }

  /*
  USAGE SAMPLE

  char addr[INET6_ADDRSTRLEN];
  //inet_ntop(AF_INET6,,)
  inet_ntop(AF_INET6,&address_sock.sin6_addr,addr,sizeof(address_sock));
  printf("%s\n",addr);
  */





  //struct sockaddr_in adress_sock_client;

  //SI IP INCONNUE
  struct addrinfo *first_info2;
  struct addrinfo hints2;
  //Init 0
  bzero(&hints2,sizeof(struct addrinfo));
  //Set Filter IPV4 / TCP
  hints2.ai_family = AF_INET6;
  hints2.ai_socktype=SOCK_STREAM;

  //On oubliera pas le free
  retourClient = getaddrinfo("lucien","daytime",&hints2,&first_info2);
  if(retourClient !=0){
    printf("%s\n",gai_strerror(retourClient));
    exit(1);
  }
  if(first_info2!=NULL){
    char test[ INET6_ADDRSTRLEN];
    inet_ntop(AF_INET6,first_info2->ai_addr,test,sizeof(first_info2->ai_addr));
    printf("%s\n",test);
    //adress_sock_client = *(struct sockaddr_in *)first_info->ai_addr;
  }
  freeaddrinfo(first_info2);



  char * mess = "2001:660:3301:8070:215:c5ff:fee6:1f9a\n";
  send(desc_sock,mess,strlen(mess),0);

  //Les free
  close(desc_sock);
  freeaddrinfo(first_info);



 return 0;
}
