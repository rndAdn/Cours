#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char * argv[]){

        const char * rep1 = argv[1];
        const char * rep2 = argv[2];
        //printf("%s",rep1);

        //printf("%s \n",rep1);
        //printf("%s",rep2);
        int p = 0;
        int i = 0;
        while(rep1[p]!=0 && rep2[p]!=0) {
                if (rep1[p] == '/') i=p;
                if (rep1[p]!=rep2[p]) break;
                p++;
        }
        int j = 0;
        int count = 0;
        while(rep1[i+j]!=0) {
                if (rep1[i+j] == '/' ) count++;
                j++;
        }

        //printf("%d \n",count);
        char * retour = malloc(sizeof(rep1)+sizeof(rep2));
        for (j=0; j<count; j++) {
                retour[3*j] = '.';
                retour[3*j+1] = '.';
                retour[3*j+2] = '/';
        }
        //printf("%s \n",retour);
        int t = 1;
        i++;
        //printf("%c \n",rep2[i]);
        while(rep2[i]!=0) {
                retour[3*(j-1)+2+t] = rep2[i];
                i++;
                t++;
        }
        printf("%s \n",retour);

        return 0;
}
