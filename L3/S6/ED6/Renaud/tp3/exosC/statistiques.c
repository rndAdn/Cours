#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 200

void skel(char *buff){
    char *p = buff;
    while(1){
        printf("%d\n", atoi(p));
        if((p = index(p, ' ')) == NULL){
            break;
        }
        else p++;
    }
}

int* eval_string(char *buf){
    int taille = 50;
    int *tab = malloc(sizeof(int)*taille);
    int i = 1;
    char *p = buf;
    while(1){
        int tmp = atoi(p);
        if(i<taille){
            tab[i] = tmp;
            i++;
        }
        else{
            taille *=2;
            tab = realloc(tab, sizeof(int)*taille);
        }
        if((p = index(p, ' ')) == NULL){
            break;
        }
        else p++;
    }

    tab = realloc(tab, sizeof(int)*i);
    tab[0] = i-1;

    return tab;
}

int moyenne(int* tab){
    int acc = 0;
    int i;
    int j=0;
    for(j=1; j<=tab[0]; j++){
        acc += tab[j];
    }
    return acc/tab[0];
}


int main(int argc, char* argv[]){
    //skel("1 2 3 4 5 6 7 8 9 10");
    fputs("entiers + espace\n", stdout);
    if(getopt(argc, argv, "-1") != -1){
        char chr[MAX_LINE_LENGTH];
        fgets(chr, MAX_LINE_LENGTH, stdin);
        int* tab = eval_string(chr);

        printf("%d\n", moyenne(tab));
    }
    else {
        while(1){
            char chr[MAX_LINE_LENGTH];
            fgets(chr, MAX_LINE_LENGTH, stdin);
            int* tab = eval_string(chr);
            printf("%d\n", moyenne(tab));
        }

    }



    exit(0);
}
