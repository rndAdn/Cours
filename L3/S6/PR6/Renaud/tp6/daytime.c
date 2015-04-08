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


int main(int argc, char const *argv[]) {
    //struct hostent* host;
    //host = gethostbyname("lucien.informatique.univ-paris-diderot.fr");
    /*
    if(host == NULL){
        printf("erreur host\n");
        exit(-1);
    }
    struct in_addr **adresses = (struct in_addr**)host->h_addr_list;
    while(*adresses != NULL){
        printf("Adresse : %s\n", inet_ntoa(**adresses));
        adresses++;
    }*/
    int sock=socket(PF_INET,SOCK_STREAM,0);
    struct addrinfo *info;
    /*struct addrinfo filtre;
    bzero(&filtre,sizeof(struct addrinfo));
    filtre.ai_family = AF_INET;
    filtre.ai_socktype=SOCK_STREAM;*/
    int res = getaddrinfo("lucien","13", NULL, &info);
    if(res != 0 ){
        printf("erreur host\n");
        exit(-2);
    }

    if(info != NULL){
        struct sockaddr_in *addressin;
        addressin=(struct sockaddr_in *)info->ai_addr;
        int ret=connect(sock,(struct sockaddr *)addressin,(socklen_t)sizeof(struct sockaddr_in));
        if(ret==0){
            char buff[100];
            int recu=recv(sock,buff,99*sizeof(char),0);buff[recu]='\0';
            printf("Message recu : %s\n",buff);
        }
        else{
            printf("Probleme de connexion!\n");
        }
        close(sock);
    }

    return 0;
}
