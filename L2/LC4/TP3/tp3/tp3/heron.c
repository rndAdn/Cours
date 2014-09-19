//
//  heron.c
//  tp3
//
//  Created by Etienne Toussaint on 12/02/2014.
//  Copyright (c) 2014 Etienne Toussaint. All rights reserved.
//

#include "fractions.h"

fraction heron(int a,int n){
    fraction result = {.num = 0, .den = 1};
    if (n != 0){
        fraction unFrac = heron(a,(n-1));
        fraction aFrac ={.num = a, .den = 1};
        fraction deuxFrac ={.num = 2, .den = 1};
        result = div_frac(add_frac(unFrac, div_frac(aFrac, unFrac)), deuxFrac);
        affiche_fraction(result);
        return result;
    }
    else{
        result.num =1;
        result.den = 1;
        return result;
        affiche_fraction(result);
    }
}

int main(){
    
    int a = 0;
    int n = 0;
    scanf("%d",&a);
    scanf("%d",&n);
    heron(a, n);
    
    return 0;
}
