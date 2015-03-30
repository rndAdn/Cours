

#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>


typedef struct story
{
    struct sockaddr ip;
    struct story * next;
} Story;

Story* story_debut;
Story* story_fin;

void createElementLcS(struct sockaddr * ip ,Story * s)
{
    memcpy(&(s->ip),ip,sizeof(struct sockaddr));
    s->next = NULL;
}

void addLcS(Story * s)
{
    if(story_debut == 0)
        {
            story_debut = s;
            story_fin = s;
            return;
        }
    story_fin->next = s;
    story_fin = s;
}

int in_list(struct sockaddr n){
  Story * tmp = story_debut;
  while(tmp != 0 && tmp != NULL)
    if(memcmp(&(tmp->ip),&n,sizeof(struct sockaddr))==0) return 0;
  return 1;
}

  
void * read_udp(void * sock_p){
  int sock = *(int*)sock_p;
  char tampon_recv[100];
   struct sockaddr caller;
   //Doit être init sinon bug
   socklen_t size=sizeof(caller);

  while(1){
    tampon_recv[recvfrom(sock, tampon_recv, 99, 0,&caller,&size)] = 0;
    if(in_list(caller)){
      Story *s = malloc(sizeof(Story));
      createElementLcS(&caller,s);
      addLcS(s);
    }
    write(1,tampon_recv,strlen(tampon_recv));
  }
  return NULL;
}

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

   pthread_t th_client;
   r = pthread_create(&th_client,NULL,read_udp,&sock);
   if(r != 0)
        {
          exit(0);
        }   
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
      while(42){
        tampon[read(0,tampon,99)] = 0;      //envoi du paquet
        sendto(sock,tampon,strlen(tampon),0,saddr,(socklen_t)sizeof(struct sockaddr_in));
        Story * tmp = story_debut;
        while(tmp != 0 && tmp != NULL)
           sendto(sock,tampon,strlen(tampon),0,&(tmp->ip),(socklen_t)sizeof(struct sockaddr_in));
      }
    }
  }
  close(sock);
  return 0;
}
