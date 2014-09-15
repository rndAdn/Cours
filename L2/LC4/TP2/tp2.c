#include <stdio.h>

int main() {
	int i = 0;
	int prison[100];
	for(i=0;i<100;i++)
	{
	prison[i] = 1;
	}
	
	int jour = 1;
	int k = 1;
	for(jour=1;jour<100;jour++){
	k=1;
		while(jour*k<100)
		{
		prison[jour*k] = !(prison[jour*k]);
		k++;
		}
	}
	for(i=0;i<100;i++)
	{
		if(!prison[i])
		{
		printf(" %d|",i);
		}
	}
	return 0;
}
