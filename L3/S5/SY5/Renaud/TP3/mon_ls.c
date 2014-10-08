#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

void argument(const char* str, int *a, int *r, int *l){
    char c;
    int i=1;
    while((c= str[i]) != '\0'){
        switch(c){

            case 'a':
                *a = 1;
                break;
            case 'l':
                *l = 1;
                break;
            case 'R':
                *r = 1;
                break;
            default:
                printf("Bad args");
                exit(0);
        }
        i++;
    }
}

void parc(const char* rep, int a, int r, int l, char* tab){
    DIR *dir;
    dir = opendir(rep);
    struct dirent *entry;
    while((entry = readdir(dir)) != NULL){
        if(a == 0 && entry->d_name[0] == '.'){
            continue;
        }
        struct stat tmp;
        char *chemin = malloc(sizeof(char)*(strlen(rep)+strlen(entry->d_name)+2));
        sprintf(chemin, "%s/%s",rep,entry->d_name);
        lstat(chemin, &tmp);
        if(S_ISDIR(tmp.st_mode)){
            printf("\e[0;34m%s%s\e[0m\n",tab,entry->d_name);// ajouter couleur si dossier/link/exe
        }
        else{
            printf("%s%s\n",tab,entry->d_name);// ajouter couleur si dossier/link/exe
        }

        if(l == 1){
            // INFORMATION fic/dir
            //printf("%s%s",tab,entry->d_name);
        }
        if(r == 1){ //corriger dossier . et .. pour la rec
            if(strcmp(entry->d_name,".") == 0 || strcmp(entry->d_name,"..") == 0){

                continue;
            }
            if(S_ISDIR(tmp.st_mode)){

                char *tab2 = malloc(sizeof(char)*(strlen(tab)+strlen(" ")+2));
                sprintf(tab2, "%s%s",tab," ");
                parc(chemin,a,r,l,tab2);
            }
        }

    }
}

int main (int argc, char const *argv[]){
    int a=0, r=0, l=0;

    struct stat tmp;
    switch(argc){
        case 2:
            if(lstat(argv[1], &tmp) == -1){
                printf("Erreur fichier");
                exit(0);
            }

            parc(argv[1], a,r,l,"");
            break;

        case 3:
            argument(argv[1], &a,&r,&l);
            if(lstat(argv[2], &tmp) == -1){
                printf("Erreur fichier");
                exit(0);
            }
            parc(argv[2], a,r,l,"");
            break;
        default:
        printf("NB Args");
        exit(0);
    }




    return 0;
}
