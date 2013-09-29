#include <stdio.h>
#include <stdlib.h>
#include "types_numeriques.h"


int main(){
	struct fration ex_fractions[8];
	ex_fractios[0].numerateur = 1;
	ex_fractions[0].denominateur = 1

	ex_fractios[1].numerateur = 1;
	ex_fractions[1].denominateur = 2

	ex_fractios[2].numerateur = 2;
	ex_fractions[2].denominateur = 4

	ex_fractios[3].numerateur = 15;
	ex_fractions[3].denominateur = 10

	ex_fractios[4].numerateur = -9;
	ex_fractions[4].denominateur = 3

	ex_fractios[5].numerateur = 8;
	ex_fractions[5].denominateur = -20

	ex_fractios[6].numerateur = -5;
	ex_fractions[6].denominateur = -10

	ex_fractios[7].numerateur = 1;
	ex_fractions[7].denominateur = -3;

	int i;

	for (i = 0; i < 8; ++i)
{
		affiche_fraction(ex_fractions[i]);
	}
	return 0;
}

void affiche_fraction(struct fraction f){
	double resultat = f.numerateur/f.denominateur;
	printf("%d / %d = %f\n",f.numerateur,f.denominateur, resultat);
}

long long pgcd(long long a, long long b){
	

}

struct fraction reduit(struct fraction f){

}