#include <stdio.h>
#include <stdlib.h>

void swap(int* i1,int* i2){
        int temp = *i1;
        *i1 = *i2;
        *i2 = temp;
}

int** allocTab(int n,int m){
        int ** tab =  malloc(n*sizeof(int *));
        *tab = malloc(m*sizeof(int));
        int i = 0, j = 0;
        for (i=0; i<n; i++) {
                *(tab + i) = malloc(m*sizeof(int *));
                for (j=0; j<m; j++) {
                        *(*(tab+i)+j) = 0;
                }
        }
        return tab;
}

void afficheLigne(int ** tab,int n,int m,int t){
        int i = 0;
        for (i=0; i<m; i++) {
                printf("%d ",*(*(tab+t)+i));
        }
}
void afficheColone(int ** tab,int n,int m,int t){
        int i = 0;
        for (i=0; i<n; i++) {
                printf("%d \n",*(*(tab+i)+t));
        }
}


//void retourner_mots(char * texte){
//}

void retourner(char * texte){
        int i = 0;
        while(texte[i] != 0 || texte[i] != ' ') i++;
        i--;
        int j = 0;
        for (j=0; j<i/2; j++) {
                char temp = texte[j];
                texte[j] = texte[i-j];
                texte[i-j] = temp;
        }
}

int main(){
        /*int i = 2;
           int j = 3;
           swap(&i,&j);
           printf("%d \n",i);
           printf("%d \n",j);
           int** tab = allocTab(10,20);
           afficheLigne(tab,10,20,8);
           afficheColone(tab,10,20,17);
         */
        char * test = "coucou ";
        printf("%s",test);
        retourner(test);
        //printf("%s",test);
        return 0;
}
