#include <stdio.h>
#include <stdlib.h>
#include "catalan.h"
#include "print_result.h"

int main(int argc, char const *argv[]) {
    int n = atoi(argv[1]);
    display(n);
    return 0;
}
