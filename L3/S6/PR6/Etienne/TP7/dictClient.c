#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>

#include <string.h>
//bzero
#include <netinet/in.h>
// struct in_addr / struct sockaddr_in
#include <arpa/inet.h>
//Manipulation struct in_addr
#include <sys/socket.h>
//struct sockaddr
#include <netdb.h>
#include <fcntl.h>
//getaddrinfo
//
//

void breakpoint(){
}

int main(int argc, char const *argv[]) {
  //Variable pour les retour et erreur
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
  retour = getaddrinfo("lucien","4202",&hints,&first_info);
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
  /*
     USAGE SAMPLE
     */
  char * mess = malloc(sizeof(char)*1024);
  strcat(mess,"DEFINE ! ");
  strcat(mess,argv[1]);
  strcat(mess,"\n");
  printf("%s",mess);
  breakpoint();
  retour = send(desc_sock,mess,strlen(mess),0);
  if(retour == -1){
    perror(strerror(errno));
    exit(1);
  }


  char buff[1024];

  int size_rec =0;
  
  //BLOCK to Synchronize
  size_rec = recv(desc_sock,buff,1023*sizeof(char),0);
  buff[size_rec]='\0';
  printf("%s",buff);
  fflush(stdout);

  //NON BLOCK TO READ
  if(fcntl(desc_sock,F_SETFL,O_NONBLOCK) == -1){
    perror(strerror(errno));
    exit(1);
  }

  while((size_rec = recv(desc_sock,buff,1023*sizeof(char),0)) != -1){
    buff[size_rec]='\0';
    printf("%s",buff);
    fflush(stdout);
  }
  //Les free
  free(mess);
  close(desc_sock);
  freeaddrinfo(first_info);


  return 0;
}

/*Historiquement / Obsolete:
  struct hostent * host = gethostbyname("lucien.informatique.univ-paris-diderot.fr");
  if(host==NULL){
  printf("Hostname inconnue\n");
  exit(1);
  }
  struct in_addr **addresses=(struct in_addr**)host->h_addr_list;
  if(*addresses!=NULL)addrIPV4 = **addresses;
  else{
  printf("adresse IP non trouvé\n");
  exit(1);
  }
  */

