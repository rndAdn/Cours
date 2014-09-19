//
//  alloc.c
//  TP7
//
//  Created by Etienne Toussaint on 12/03/2014.
//  Copyright (c) 2014 Etienne Toussaint. All rights reserved.
//

#include <stdio.h>
#import "alloc.h"

static char memoire[N];

typedef struct memblock {
    int free;
    int size;
}memblock;

void* search_free_blocks(int x){
    char *curr = memoire;
    while(curr+2*sizeof(int) < memoire+N){
        memblock * tmp = (memblock *)curr;
        if(tmp->size >=x && !tmp->free){
            return tmp;
        }
        else{
            curr += 2*sizeof(int) + tmp->size;
        }
        
    }
    return NULL;
}

void *my_alloc(int x){
    static int i = 0;
    if(i == 0){
        i =1;
        memblock * init = (memblock *)memoire;
        init->free = 1;
        init->size = x;
        memblock * next = (memblock *)(memoire +2*sizeof(int)+x);
        next->free = 0;
        next->size = N-2*sizeof(int)-init->size;
        return init +1;
    }
    memblock * curr = search_free_blocks(x);
    if(curr == NULL) return NULL;
    curr->free = 1;
    if(curr->size - x >= 2*sizeof(int)){
        int tmp = curr->size;
        curr->size = x;
        char * new = (char *)curr;
        memblock *newBlock = (memblock *)(new +2*sizeof(int)+x);
        newBlock->free = 0;
        newBlock->size = tmp - curr->size - 2*sizeof(int);
    }
    return curr+1;
}

void my_free(void * mem){
    char * tmp = (char *) mem;
    memblock * toFree = (memblock *)(tmp -2*sizeof(int));
    toFree->free = 0;
    memblock *check =(memblock*)(tmp+toFree->size);
    if(check->free == 0){
        toFree ->size += check->size +2*sizeof(int);
    }
    char *curr = memoire;
    while(curr < (char *)mem -2*sizeof(int)){
        memblock * tmp = (memblock *)curr;
        curr += 2*sizeof(int) + tmp->size;
        check = tmp;
    }
    if(check->free == 0){
        check ->size += toFree->size +2*sizeof(int);
    }
}
void toPrint(){
    char *curr = memoire;
    while(curr < memoire+N){
        memblock * tmp = (memblock *)curr;
        curr += 2*sizeof(int) + tmp->size;
        printf("%p||",tmp);
        printf("%d||",tmp->free);
        printf("%d\n",tmp->size);
    }
    printf("---------------------------\n");
}

void* search_best_free_blocks(int x){
    char *curr = memoire;
    memblock *res;
    int min = N;
    while(curr+2*sizeof(int) < memoire+N){
        memblock * tmp = (memblock *)curr;
        if(tmp->size >=x && !tmp->free && min>tmp->size){
            min = tmp->size;
            res = tmp;
        }
        else{
            curr += 2*sizeof(int) + tmp->size;
        }
        
    }
    if (min != 1024)return res;
    return NULL;
}


