#include <stdlib.h>
#include <stdio.h>

int myStrcmp(char* a, char* b){
    int i = 0;
    while(a[i] != '\0' && b[i] != '\0'){
        if(a[i] != b[i]) return 1;
        i++;
    }
    return 0;
}


int myAtoi(char* s){


    /*
        TODO:
                Ne faire q'une boucle while
    */

    int i = 0;
    int res = 0;
    char c = s[i];
    int signe = 1;
    while (c != '\0'){
        i++;
        c = s[i];
    }
    i--;
    int u = 1;
    while(i>= 0){
        int tmp = s[i] - '0';
        if ((tmp < 0 || tmp > 9) && tmp != -3) printf("connard: \"%c\"\n",s[i]);
        if (i == 0 && s[i] == '-'){
            signe = -1;
            break;
        }
        res += (tmp*u);
        u *=10;
        i--;
    }
    return signe*res;
}


int arg_to_int(char* s, char* nom){
    int a = myAtoi(s);
    if (!a){
        printf("usage : %s <liste d'entiers>\n", nom);
        exit(0);
    }
    return a;
}

int addition(int* tab, int taille){
    int sum = 0, i;
    for(i = 0; i<taille; i++){
        sum += tab[i];
    }
    return sum;
}

int multiplication(int* tab, int taille) {
    int mul = 1, i;
    for (i = 0; i < taille; i++) {
        mul *= tab[i];
    }
    return mul;

}

int main(int argc, char *argv[]){
    int* tab;
    int i;
    int res = 0;
    if (argc == 1){
        printf("usage : %s <liste d'entiers>\n", argv[0]);
        exit(0);
    }
    tab = malloc((argc-1)*sizeof(int));
    for(i = 0; i<argc-1; i++){
        tab[i] = arg_to_int(argv[i+1], argv[0]);
    }

    int op = 0;
    if(myStrcmp("./addition", argv[0]) == 0){
        res = addition(tab, (argc-1));
    }
    else if (myStrcmp("./multiplication", argv[0]) == 0){
        res = multiplication(tab, (argc-1));
    }
    else{
        printf("%s: opération non autorisée\n", argv[0]);
        exit(0);
    }
    printf("%d\n", res);

    return 0;
}
