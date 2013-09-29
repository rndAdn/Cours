#include <stdio.h>

int main(){
	/*int i;
	int t[128];
	for (i = 0; i < 128; ++i){
		t[i] = 1;
	}
	for (i = -5; i < 9999999999; ++i){
		printf("Valeur %d: %d\n",i,t[i] );
	}
	*/

	/*if(7+(5>3)){
			printf("c'est Vrai\n");
	}
		else {
			printf("c'est Faux\n");
	}*/
	int i;
	for (i = -50; i < 50; i++){
		if(i){
			printf("Pour i = %d c'est Vrai\n",i);
		}
		else {
			printf("Pour i = %d c'est Faux\n",i);
		}
	}
	
	return 0;
}