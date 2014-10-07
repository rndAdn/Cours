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

void parc(char* rep, int a, int r, int l, char* tab){
    DIR *dir;
    dir = opendir(rep);
    struct dirent *entry;
    while((entry = readdir(dir)) != NULL){
        if(a == 0 && entry->d_name[0] == '.'){
            continue;
        }
        printf("%s%s\n",tab,entry->d_name);
        if(r == 1){
            struct stat tmp;
            lstat(entry->d_name, &tmp);
            if(S_ISDIR(tmp.st_mode)){
                char *chemin = malloc(sizeof(char)*(strlen(rep)+strlen(entry->d_name)+2));
                sprintf(chemin, "%s/%s",rep,entry->d_name);
                char *tab2 = malloc(sizeof(char)*(strlen(tab)+strlen("\t")+2));
                sprintf(tab2, "%s%s",tab,"\t");
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
