#include "print_result.h"


void display(int n){
    int i;
    for(i = 1; i<=n;i++){
        printf("C%d = %d\n", i, eval_catalan(i));
        display_par(i);
        printf("\n");
    }
}

int display_par(int n){

    if(n<0){
        printf("Nombre négatif");
        exit(1);
    }
    if(n==0) return 1;
    int nb_catalan = 0, k;
    for(k = 0; k <= n-1; k++){
        printf("(");
        display_par(k);
        display_par((n-1)-k);
        printf(")");
    }
    return nb_catalan;
}
