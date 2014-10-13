#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

void argument(const char* str, int arg[4]){
    char c;
    int i=1;
    arg[0] = 0;
    arg[1] = 0;
    arg[2] = 0;
    arg[3] = 0;
    while((c= str[i]) != '\0'){
        switch(c){

            case 'a':
                arg[0] = 1;
                break;
            case 'R':
                arg[1] = 1;
                break;
            case 'l':
                arg[2] = 1;
                break;
            case 'd':
                arg[3] = 1;
                break;
            default:
                printf("Bad args");
                exit(0);
        }
        i++;
    }
}

char* recup(int i){
  char * buffer = calloc(10,sizeof(char));
  char * result = calloc(10,sizeof(char));
  int j = 10;
  int c = 0;
  while(i!=0){
    buffer[c] = (i%j)+'0';
    i /= 10;
    c++;
  }
  for(j=0;j<c;j++){
    result[j]=buffer[(c-1)-j];
  }
  return result;
}
char* info(const char* rep){
    struct stat tmp;
    char type = '-';
    char* rwx = malloc(sizeof(char)*9);
    int i;
    lstat(rep, &tmp);
    int nb_lien = tmp.st_nlink;
    int taille = tmp.st_size;


    if(S_ISDIR(tmp.st_mode)){
        type = 'd';
    }
    else if(S_ISLNK(tmp.st_mode)){
        type = 'l';
    }
    else if(S_ISFIFO(tmp.st_mode)){
        type = 'f';
    }
    else if(S_ISBLK(tmp.st_mode)){
        type = 'b';
    }
    else if(S_ISCHR(tmp.st_mode)){
        type = 'c';
    }

    for(i = 0; i<9;i++){
        rwx[i] = '-';
    }

    if(tmp.st_mode & S_IRUSR){
        rwx[0] = 'r';
    }

    if(tmp.st_mode & S_IWUSR){
        rwx[1] = 'w';
    }
    if(tmp.st_mode & S_IXUSR){
        rwx[2] = 'x';
    }
    if(tmp.st_mode & S_IRGRP){
        rwx[3] = 'r';
    }
    if(tmp.st_mode & S_IWGRP){
        rwx[4] = 'w';
    }
    if(tmp.st_mode & S_IXGRP){
        rwx[5] = 'x';
    }
    if(tmp.st_mode & S_IROTH){
        rwx[6] = 'r';
    }
    if(tmp.st_mode & S_IWOTH){
        rwx[7] = 'w';
    }
    if(tmp.st_mode & S_IXOTH){
        rwx[8] = 'x';
    }
    char *n =recup(nb_lien);
    char *t =recup(taille);
    char* final = malloc(sizeof(char)*(sizeof(char)+strlen(rwx)+strlen(t)+strlen(n)+strlen("   ")+2));
    sprintf(final, "%c%s %s %s",type,rwx,n,t);

    //printf("%s\n", final);
    return final;
}

void parc(const char* rep, int arg[4], char* tab){
    DIR *dir;
    dir = opendir(rep);
    struct dirent *entry;
    if(arg[3] == 1){
        if(arg[2] == 1){
            printf("%s ",info(rep));
        }
        printf("%s\n",rep);// ajouter couleur si dossier/link/exe

        exit(0);
    }
    while((entry = readdir(dir)) != NULL){
        if(arg[0] == 0 && entry->d_name[0] == '.'){
            continue;
        }
        struct stat tmp;
        char *chemin = malloc(sizeof(char)*(strlen(rep)+strlen(entry->d_name)+2));
        sprintf(chemin, "%s/%s",rep,entry->d_name);
        lstat(chemin, &tmp);
        if(arg[2] == 1){
            printf("%s ",info(chemin));
        }
        if(S_ISDIR(tmp.st_mode)){
            printf("\e[0;34m%s%s\e[0m\n",tab,entry->d_name);// ajouter couleur si dossier/link/exe
        }
        else{
            printf("%s%s\n",tab,entry->d_name);// ajouter couleur si dossier/link/exe
        }

        if(arg[1] == 1){ //corriger dossier . et .. pour la rec
            if(strcmp(entry->d_name,".") == 0 || strcmp(entry->d_name,"..") == 0){
                continue;
            }
            if(S_ISDIR(tmp.st_mode)){
                char *tab2 = malloc(sizeof(char)*(strlen(tab)+strlen(" ")+2));
                sprintf(tab2, "%s%s",tab," ");
                parc(chemin,arg,tab2);
            }
        }

    }
}

int main (int argc, char const *argv[]){
    int arg[4];
    //printf("0");
    struct stat tmp;
    switch(argc){
        case 2:
            if(lstat(argv[1], &tmp) == -1){
                printf("Erreur fichier");
                exit(0);
            }

            parc(argv[1], arg,"");
            break;

        case 3:
            argument(argv[1], arg);
            if(lstat(argv[2], &tmp) == -1){
                printf("Erreur fichier");
                exit(0);
            }
            parc(argv[2], arg,"");
            break;
        default:
        printf("NB Args");
        exit(0);
    }




    return 0;
}
