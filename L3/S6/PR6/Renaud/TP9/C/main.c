#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <string.h>

int main() {
    int desc_sock = socket(PF_INET,SOCK_DGRAM, 0);
    struct sockaddr_in adresse;
    adresse.sin_family = AF_INET;
    adresse.sin_port = htons(7552);
    adresse.sin_addr.s_addr = htonl(INADDR_ANY);

    int retour  = bind(desc_sock, (struct sockaddr *)&adresse, sizeof(struct sockaddr_in));

    if(retour == 0){
        char buff[1024];
        while(1){
            socklen_t size = sizeof(struct sockaddr_in);
            int lu = recvfrom(desc_sock, buff, 1024, 0, (struct sockaddr *)&adresse, &size);
            buff[lu] = '\0';
            printf("%s:%d %s", inet_ntoa(adresse.sin_addr),adresse.sin_port ,buff );
            sendto(desc_sock,buff, strlen(buff),0,(struct sockaddr *)&adresse, (socklen_t)sizeof(struct sockaddr_in));
        }
    }

    return 0;
}