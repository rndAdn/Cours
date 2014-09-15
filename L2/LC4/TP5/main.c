//
//  main.c
//  TP5
//
//  Created by Etienne Toussaint on 26/02/2014.
//  Copyright (c) 2014 Etienne Toussaint. All rights reserved.
//

#include <stdio.h>
#import "chaine.h"

int main(int argc, const char * argv[])
{
    
    str_s*result = str_scan();
    str_print(result);
    str_free(result);
    
    
    return 0;
}

