#include "fractions.h"

void affiche_fraction(fraction f){
	printf("%lld/%lld=%f\n",f.num,f.den,(float)((float)f.num/(float)f.den));
}

long long int pgcd(long long int a, long long int b){
    long long int q ,r =0;
    if(a>b){
        q = a/b;
        r = a-b*q;
        if(r != 0){
            pgcd(b,r);
        }
        else
        {
            return b;
        }
    }
    else if(a<b){
        q = b/a;
        r = b-a*q;
        if(r != 0){
            pgcd(a,r);
        }
        else
        {
            return a;
        }
    }
    return a;
}

fraction reduit(fraction f){
    long long int p = pgcd(f.den,f.num);
    fraction reduite = {.num = f.num/p, .den = f.den/p};
    return reduite;
}

fraction add_frac(fraction f1,fraction f2){
    fraction result = {.num = f1.num*f2.den+f2.num*f1.den, .den = f1.den*f2.den};
    return reduit(result);
}

fraction sub_frac(fraction f1,fraction f2){
    fraction result = {.num = f1.num*f2.den-f2.num*f1.den, .den = f1.den*f2.den};
    return reduit(result);
}

fraction mult_frac(fraction f1,fraction f2){
    fraction result = {.num = f1.num*f2.num, .den = f1.den*f2.den};
    return reduit(result);
}

fraction div_frac(fraction f1,fraction f2){
    fraction result = {.num = f1.num*f2.den, .den = f1.den*f2.num};
    return reduit(result);
}

int eq_frac(fraction f1,fraction f2){
    fraction r1 = reduit(f1);
    fraction r2 = reduit(f2);
    return (r1.num == r2.num && r1.den == r2.num);
}

/*int main(){
    
    fraction ex_fractions[8] = {
        [0] = {.num = 1, .den = 1},
        [1] = {.num = 1, .den = 2},
        [2] = {.num = 2, .den = 4},
        [3] = {.num = 15, .den = 10},
        [4] = {.num = -9, .den = 3},
        [5] = {.num = -8, .den = 20},
        [6] = {.num = -5, .den = 10},
        [7] = {.num = -1, .den = 3}
	};
    
    int i=0;
    for(i=0;i<8;i++){
        affiche_fraction(ex_fractions[i]);
    }
    
    printf("%lld",pgcd(773*45, 773));
    
    return 0;
}*/