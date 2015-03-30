#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>
#include <unistd.h>

typedef struct list_chainee{
    char* id;
    char* discipline;
    struct list_chainee *next;
} list_chainee;


list_chainee *liste;

char* get_id(char* id){
    list_chainee *tmp = liste;
    while(tmp != NULL){

        tmp = liste->next;
        if(strncmp(id, tmp->id, strlen(id)) == 0) return id;
    }
    return "-1";
}


char* get_discipline(char* dis){
    list_chainee *tmp = liste;
    while(tmp != NULL){
        tmp = liste->next;
        if(strncmp(dis, tmp->discipline, strlen(dis)) == 0) return tmp->id;
    }
    return "-1";
}


int num_of_list(){

    int i = 0;
    list_chainee *tmp = liste;
    while(tmp != NULL){
        tmp = liste->next;
        i++;
    }
    return i;
}

void send_liste_elem(int desc){
    char* mess;
    list_chainee *tmp = liste;
    while(tmp != NULL){
        mess = malloc(sizeof(char)*(strlen(tmp->id)+strlen(tmp->discipline)+3));
        sprintf(mess, "%s %s!", tmp->id, tmp->discipline);
        send(desc,mess,strlen(mess)*sizeof(char),0);
        tmp = liste->next;
    }
}

void *comm(void *arg){
    int sockcomm=*((int *)arg);
    while(1){
        char buff[1024];
        int recu=recv(sockcomm,buff,99*sizeof(char),0);
        buff[recu]='\0';
        if(strncmp(buff, "disp", 4) == 0){
            int nb = num_of_list();
            char* mess;
            mess = malloc(sizeof(char)*(255));
            sprintf(mess, "%d!", nb);
            send(sockcomm,mess,strlen(mess)*sizeof(char),0);
        }
        else if(strncmp(buff, "get ", 4)){

            char* id = get_id(strchr(buff, ' ')+1);
            send(sockcomm,id,strlen(id)*sizeof(char),0);
        }
        else if(strncmp(buff, "help ", 5)){
            char* discipline = get_discipline(strchr(buff, ' ')+1);
            send(sockcomm,discipline,strlen(discipline)*sizeof(char),0);
        }
        else if(strncmp(buff, "add ", 4)){
            
        }
        else if(strncmp(buff, "quit", 4)){
            close(sockcomm);
        }

    }

}

int main() {
    liste = malloc(sizeof(list_chainee));
    int sock=socket(PF_INET,SOCK_STREAM,0);
    struct sockaddr_in sockaddress;
    sockaddress.sin_family=AF_INET;
    sockaddress.sin_port=htons(4245);
    sockaddress.sin_addr.s_addr=htonl(INADDR_ANY);
    int r=bind(sock,(struct sockaddr *)&sockaddress,sizeof(struct sockaddr_in));
    if(r==0){r=listen(sock,0);
        if(r==0){struct sockaddr_in caller;
            socklen_t si=sizeof(caller);
            while(1){
                int *sock2=(int *)malloc(sizeof(int));
                *sock2=accept(sock,(struct sockaddr *)&caller,&si);
                if(*sock2>=0){
                    pthread_t th;
                    pthread_create(&th,NULL,comm,sock2);
                }
            }
        }
    }
    return 0;
}
