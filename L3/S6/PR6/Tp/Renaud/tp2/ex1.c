#include <stdio.h>


int main(void){
    int A [] = {12, 23, 34, 45, 56, 67, 78, 89, 90};
    int *P;
    P = A;

    printf("P  = %p\n", P);
    printf("A  = %p\n", A);
    printf("&A  = %p\n", &A);
    printf("&P  = %p\n", &P);
    printf("*P+2  = %p\n", *P+2);
    printf("*(P+2)  = %p\n", *(P+2));
    printf("&P+1  = %p\n", &P+1);
    printf("&A[4]-3  = %p\n",&A[4]-3);
    printf("A+3  = %p\n", A+3);
    printf("P + (*P-10)  = %p\n", P + (*P-10));
    printf("*(P+*(P+8)-A[7])  = %p\n", *(P+*(P+8)-A[7]));
}
