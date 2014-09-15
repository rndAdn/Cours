#include "types_numeriques.h"

void affiche_fraction(fraction f){
	printf("%lld/%lld=%f\n",f.num,f.den,(float)((float)f.num/(float)f.den));
}

long long int pgcd(long long int a, long long int b){



return 1;
}

int main(){

fraction ex_fractions[8] = {
	[0] = {.num = 1, .den = 2}
	[
	};


ex_fractions[1].num = 1;
ex_fractions[1].den = 2;

ex_fractions[2].num = 2;
ex_fractions[2].den = 4;

ex_fractions[3].num = 15;
ex_fractions[3].den = 10;

ex_fractions[4].num = -9;
ex_fractions[4].den = 3;

ex_fractions[5].num = -8;
ex_fractions[5].den = 20;

ex_fractions[6].num = -5;
ex_fractions[6].den = 10;

ex_fractions[7].num = -1;
ex_fractions[7].den = 3;

int i=0;
for(i=0;i<8;i++){
affiche_fraction(ex_fractions[i]);

}

return 0;
}