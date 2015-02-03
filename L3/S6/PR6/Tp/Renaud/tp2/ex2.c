# include <stdio.h>
#include <stdlib.h>


int main(void){
    int taille = 1, nb = 0;
    int *tab;
    tab = malloc(sizeof(int)*taille);
    char buff[1024];

    fgets(buff, 1024, stdin);
    while(strcmp(buff, "quit\n")){
        if(nb == taille){
            taille * 2;
            tab = realloc(tab, sizeof(taille));
        }
        tab[nb] = atoi(buff);
        nb++;
        fgets(buff, 1024, stdin);
    }


}
