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
    
    str_s *result = str_init("test");
    str_s *copy = str_cpy(result);
    str_print(copy);
    printf("%p",copy);
    printf("%p",result);
    
    
    return 0;
}

