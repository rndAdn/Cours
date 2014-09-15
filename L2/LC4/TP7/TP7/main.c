//
//  main.c
//  TP7
//
//  Created by Etienne Toussaint on 12/03/2014.
//  Copyright (c) 2014 Etienne Toussaint. All rights reserved.
//

#include <stdio.h>
#import "alloc.h"

int main(int argc, const char * argv[])
{

    void * test = my_alloc(14);
    void * test2 = my_alloc(20);
    void * test3 = my_alloc(32);
    void * test4 = my_alloc(40);
    void * test5 = my_alloc(50);
    toPrint();
    my_free(test2);
    toPrint();
    my_free(test4);
    toPrint();
    my_free(test3);
    toPrint();
    return 0;
}

