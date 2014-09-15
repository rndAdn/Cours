#include <stdio.h>
#include <math.h>

void triTableau(int tab[], int n);
void rempliTableau(int n, int tab[4]);
int exporteTableau(int tab[] , int n);
int exporteTableaub(int tab[] , int n);


int main() {
	int nombre = 0;
	//int i =0;
	printf("Entrez un entier de 4 chiffres TOUS différents\n");
	scanf("%d",&nombre);
	int tab[4]={0};
	while(nombre != 6174){
	rempliTableau(nombre, tab);
	//for(i=0;i<4;i++)printf(":%d:",tab[i]);
	//printf("\n");
	triTableau(tab,4);
	//for(i=0;i<4;i++)printf(":%d:",tab[i]);
	int big = exporteTableau(tab,4);
	printf("%d\n",big);
	int small = exporteTableaub(tab,4);
	printf("%d\n",small);
	nombre = big - small;
	printf("%d\n",nombre);
	printf("______________________\n");
	}
	return 0;
}

void triTableau(int tab[], int n){
    int i = 0,j = 0,temp=0;
    for(i=0;i<n;i++){
    j=1;
    	while ((i+j)<n) {
        if(tab[i] > tab[i+j]){
            j++;
        }
        else{
        	temp = tab[i];
        	tab[i]=tab[i+j];
        	tab[i+j] = tab[i+1];
        	tab[i+1] = temp;
            j++;
        }
    }
    }
}

void rempliTableau(int n, int tab[4]){
tab[0]=(n/1000);
n=n-(n/1000)*1000;
tab[1]=(n/100);
n=n-(n/100)*100;
tab[2]=(n/10);
n=n-(n/10)*10;
tab[3]=n;
}

int exporteTableau(int tab[] , int n){
int resultat = 0;
int i = 0;
for(i=0;i<n;i++){
	resultat += tab[i]*pow(10,n-1-i);
}
return resultat;
}

int exporteTableaub(int tab[] , int n){
int resultat = 0;
int i = n-1;
for(i=n-1;i>=0;i--){
	resultat += tab[i]*pow(10,i);
}
return resultat;
}
