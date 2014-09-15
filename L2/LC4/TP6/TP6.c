#include <stdlib.h>

struct traduction {
    char*lang1;
    char*lang2;
};

char *traduit12(const struct traduction *dico, int taille_dico, const char *mot){
    int bool = 0;
    int i = 0;
    int j = 0;
    for(i=0;i<taille_dico;i++){
        j = 0;
        while(*(mot+j)){
            if(*(mot+j)==*(((*(dico+i)).lang1)+j)){
                bool = 1;
                j++;
            }
            else{
                bool = 0;
                break;
            }
        if(bool){
            return (*(dico+i)).lang2
        }
        
        }
    }
    return NULL;
}