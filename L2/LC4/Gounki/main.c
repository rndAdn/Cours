#include <stdio.h>
#include <string.h>
#include "partieHeuristique.h"
#include "jouer.h"
#include "modeTest.h"

int main(int argc, const char * argv[])
{
        if(argv[1]==NULL) jouer();
        else if(strcmp(argv[1],"heuri")==0)
                partiH();
        else if(strcmp(argv[1],"-t")==0) modeTest(argv[2]);
        return 0;
}
