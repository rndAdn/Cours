#include "catalan.h"

int eval_catalan(int n){

    if(n<0){
        printf("Nombre négatif");
        exit(1);
    }
    if(n==0) return 1;
    int nb_catalan = 0, k;
    for(k = 0; k <= n-1; k++){
        nb_catalan += eval_catalan(k)*eval_catalan((n-1)-k);
    }
    return nb_catalan;
}
