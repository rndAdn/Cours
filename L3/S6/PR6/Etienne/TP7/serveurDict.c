#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <pthread.h>
#include <fcntl.h>


void * fonctionThread(void * descSockP){
  //sleep(1);??
  int retour = 0;
  //Socket IPV4
  struct sockaddr_in adress_sock;

  //SI IP INCONNUE
  struct addrinfo *first_info;
  struct addrinfo hints;
  //Init 0
  bzero(&hints,sizeof(struct addrinfo));
  //Set Filter IPV4 / TCP
  hints.ai_family = AF_INET;
  hints.ai_socktype=SOCK_STREAM;

  //On oubliera pas le free
  retour = getaddrinfo("lucien","2628",&hints,&first_info);
  if(retour !=0){
    printf("%s\n",gai_strerror(retour));
    exit(1);
  }
  if(first_info!=NULL){
    adress_sock = *(struct sockaddr_in *)first_info->ai_addr;
  }
  //fin sans ip

  int desc_sock = socket(PF_INET,SOCK_STREAM,0);
  retour = connect(desc_sock,(struct sockaddr *)&adress_sock,sizeof(struct sockaddr_in));
  if(retour == -1){
    perror(strerror(errno));
    exit(1);
  }

  if(fcntl(desc_sock,F_SETFL,O_NONBLOCK) == -1){
    perror(strerror(errno));
    exit(1);
  }

  /*
     USAGE SAMPLE
     */
  int descSock = *(int *)descSockP;
  char buf2[1024];
  int recu=recv(descSock,buf2,1023*sizeof(char),0);
  buf2[recu]='\0';


  retour = send(desc_sock,buf2,strlen(buf2),0);
  if(retour == -1){
    perror(strerror(errno));
    exit(1);
  }

  sleep(1);

  char buff[1024];

  int size_rec =0;
  while((size_rec = recv(desc_sock,buff,1023*sizeof(char),0)) != -1){
    buff[size_rec]='\0';
    retour = send(descSock,buff,strlen(buff),0);
    if(retour == -1){
      perror(strerror(errno));
      exit(1);
    }
  }
  //Les free
  close(desc_sock);
  freeaddrinfo(first_info);

  return NULL;
}

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

  while(42){
    //Stocke l'addresse de l'appelant
    struct sockaddr_in caller;
    //Doit être init sinon bug
    socklen_t size=sizeof(caller);
    int * descSock = malloc(sizeof(int));

    if(descSock == NULL){
      exit(1);
    }

    *descSock = accept(sockServer,(struct sockaddr *)&caller,&size);
    if(retour == -1){
      perror(strerror(errno));
      continue;
    }

    /*
     *Creation de thread 
     *via pthread
     *Memoire partagé
     *
     */
    pthread_t th;
    retour = pthread_create(&th,NULL,fonctionThread,descSock);
    if(retour != 0){
      perror(strerror(errno));
      close(*descSock);
      free(descSock);
      continue;
    }
    //pthread_join(th,NULL);

  }
  close(sockServer);
  return 0;
}

