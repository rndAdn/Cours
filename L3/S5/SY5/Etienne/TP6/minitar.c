#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct entete{
  mode_t mode;
  size_t taille;
  size_t tailleNom;
}entete;

char * fileName(char * file){
  int i = 0;
  int j = 0;
  while(file[i]!=0){
    if (file[i]=='/') j = i+1;
  i++;
  }
  return (file+j);
}

int main(int argc, char * argv[])
{
        int t = 1024;
        int compresse = 0;
        if (argv[1][1] == 'c' && argv[1][2] == 'f')
          compresse = 1;
        else if (argv[1][1] == 'x' && argv[1][2] == 'f')
          compresse = 2;
        else {printf("argument impossible");return 1;}

        if (compresse == 1){
          //printf("HEY");
          int i = 3;
          while (i < argc){
            int tar;
            if ((tar =open(argv[2],O_WRONLY | O_CREAT | O_TRUNC,
                 S_IRWXU | S_IRWXG | S_IRWXO )) < 0) exit(1);
            //printf("HEY2");
            struct stat *tmp = malloc(sizeof(struct stat));
            lstat(argv[i], tmp);
            entete tmpEntete;
            tmpEntete.mode = tmp->st_mode;
            tmpEntete.taille = tmp->st_size;
            char * name = fileName(argv[i]);
            tmpEntete.tailleNom = strlen(name);
            write(tar,&tmpEntete,sizeof(entete));
            int fd = open(argv[i],O_RDONLY);
            char * tamp = malloc(t*sizeof(char));
            for( ;; ){
              //printf("HEY3");
              int rc = read(fd,tamp,t);
              if( rc < 0 ){
                exit(3);
              }
              if( rc == 0 )
                break;
              int wc=write(tar,tamp,rc);
              if( wc < 0 ){
                exit(4);
              }
            }
            i++;
            free(tmp);
            free(tamp);
            close(fd);
          }
        close(tar);
        }
        else if (compresse == 2){
          int tar = open(argv[i],O_RDONLY);
        }
        return 0;
}
