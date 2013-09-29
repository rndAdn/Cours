#include <stdio.h>
#include <string.h>

int main(){
	int i;
	char s[64];
	
	fgets(s,64,stdin);
	for (i = 0; i < strlen(s); i++){
		
		if(s[i] >= 97 && s[i] <= 122){
			s[i] = (((s[i] - 97)+13)% 26)+97;
		}else if(s[i] >= 65 && s[i] <= 90){ // ajout pour les majuscules
			s[i] = (((s[i] - 65)+13)% 26)+65;
		}
	}
	fputs(s,stdout);
	return 0;
}