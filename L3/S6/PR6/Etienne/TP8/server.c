
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <pthread.h>

pthread_mutex_t verrou= PTHREAD_MUTEX_INITIALIZER;


typedef struct Lc{
  int id;
  char disc[1024];
  struct Lc * next;
}Lc;

Lc* listeDebut;
Lc* listeFin;
int nbElement = 0;

void createElementLc(int id,char * disc, Lc * l){
  l->id = id;
  int i = 0;
  for(i=0;i<strlen(disc);i++){
    l->disc[i] = disc[i];
  }
  l->next = NULL;
}

void addLc(Lc * l){
  pthread_mutex_lock(&verrou);
  if(nbElement == 0){
    listeDebut = l;
    listeFin = l;
  }
  else{
    listeFin->next = l;
    listeFin = l;
  }
  nbElement++;
  pthread_mutex_unlock(&verrou);
}

Lc * popLc(){
  //breakpoint();
  pthread_mutex_lock(&verrou);
  Lc * tmp;
  tmp = listeDebut;
  listeDebut = listeDebut->next;
  pthread_mutex_unlock(&verrou);
  return tmp;
}

int isEmptyLc(){
  return listeDebut == NULL || listeDebut == 0;
}

void deleteLcId(int id){
  Lc * tmp = listeDebut;
  Lc * prev = listeDebut;
  while(!(tmp == NULL || tmp == 0)){
    if(tmp->id == id){
      if(tmp == listeDebut)
        listeDebut = listeDebut->next;
      else 
        prev->next = tmp->next;
      free(tmp);
      nbElement --;
      break;
    }
    prev = tmp;
    tmp = tmp->next;
  }
}

void * fonctionThread(void * descSockP){
  //sleep(1);??
  int descSock = *(int *)descSockP;
  int retour;

  while(42){
    /*
       char *mess="Yeah!\n";
       send(descSock,mess,strlen(mess)*sizeof(char),0);
       char buff[1024];
       int recu=recv(descSock,buff,1023*sizeof(char),0);
       buff[recu]='\0';
       printf("Message recu : %s\n",buff);
       */
    char buff[1024];
    int recu=recv(descSock,buff,1023*sizeof(char),0);
    buff[recu]='\0';
    printf("Message recu : %s|||\n",buff);

    if(strncmp(buff,"disp",4)==0){
      char mess[1024];
      sprintf(mess,"%d!",nbElement);
      retour = send(descSock,mess,strlen(mess)*sizeof(char),0);
      if(retour == -1){
        perror(strerror(errno));
        exit(1);
      }
      pthread_mutex_lock(&verrou);
      Lc * tmp = listeDebut;
      while(!(tmp == NULL || tmp == 0)){
        char  mess[1024];
        sprintf(mess,"%d %s!",tmp->id,tmp->disc);
        retour = send(descSock,mess,strlen(mess)*sizeof(char),0);
        if(retour == -1){
          perror(strerror(errno));
          exit(1);
        }
        tmp = tmp->next;
      }
      pthread_mutex_unlock(&verrou);
    }
    else if(strncmp(buff,"get",3)==0){
      char * idChar = strchr(buff,' ');
      idChar++;
      int id = atoi(idChar);
      int fail = 1;
      pthread_mutex_lock(&verrou);
      Lc * tmp = listeDebut;
      while(!(tmp == NULL || tmp == 0)){
        if(tmp->id == id){
          retour = send(descSock,idChar,strlen(idChar)*sizeof(char),0);
          if(retour == -1){
            perror(strerror(errno));
            exit(1);
          }
          fail = 0;
          deleteLcId(id);
          break;
        }
        tmp = tmp->next;
      }
      pthread_mutex_unlock(&verrou);
      if(fail){
        retour = send(descSock,"erreur",strlen("erreur")*sizeof(char),0);
        if(retour == -1){
          perror(strerror(errno));
          exit(1);
        }
      }

      //get listElement
    }
    else if(strncmp(buff,"help",4)==0){
      char * disc = strchr(buff,' ');
      disc++;
      int fail = 1;
      pthread_mutex_lock(&verrou);
      Lc * tmp = listeDebut;
      while(!(tmp == NULL || tmp == 0)){
        if(strcmp(tmp->disc,disc)==0){
          char mess[1024];
          sprintf(mess,"%d",tmp->id);
          retour = send(descSock,mess,strlen(mess)*sizeof(char),0);
          if(retour == -1){
            perror(strerror(errno));
            exit(1);
          }
          fail = 0;
          deleteLcId(tmp->id);
          break;
        }
        tmp = tmp->next;
      }
      pthread_mutex_unlock(&verrou);
      if(fail){
        retour = send(descSock,"erreur",strlen("erreur")*sizeof(char),0);
        if(retour == -1){
          perror(strerror(errno));
          exit(1);
        }
      }

      //get listElement
    }
    else if(strncmp(buff,"add",3)==0){
      char * idChar = strchr(buff,' ');
      idChar++;
      char * disc = strchr(idChar,' ');
      disc[0]=0;
      //disc[strlen(disc)-2]=0;
      disc++;
      struct Lc *l = malloc(sizeof(Lc));
      createElementLc(atoi(idChar),disc,l);
      addLc(l);
      retour = send(descSock,"Merci!",strlen("Merci!")*sizeof(char),0);
        if(retour == -1){
          perror(strerror(errno));
          exit(1);
        }

    }
    else if(strncmp(buff,"quit",4)==0){
      close(descSock);
      free(descSockP);
      return NULL;
    }
    else{
      retour = send(descSock,"erreur",strlen("erreur")*sizeof(char),0);
      if(retour == -1){
        perror(strerror(errno));
        exit(1);
      }
    } 
  }
}

int main(int argc, char const *argv[]) {
  //Variable pour les retour et erreur
  int retour = 0;
  //Socket Server IPV4
  int sockServer = socket(PF_INET,SOCK_STREAM,0);
  struct sockaddr_in address_sock;

  address_sock.sin_family=AF_INET;
  address_sock.sin_port=htons(atoi(argv[1]));
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
