//
//  main.c
//  TP11
//
//  Created by Etienne Toussaint on 09/04/2014.
//  Copyright (c) 2014 Etienne Toussaint. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int x, y;
} pixel;
typedef struct {
    int R, G, B;
} color;
typedef struct {
    int width , height;
    color map [1];
} image;

image * make_canvas(int width, int height, color c){
    image * result = malloc(sizeof(image)+(height*width)*sizeof(color));
    result->width = width;
    result->height = height;
    result->map[0]=c;
    return result;
}

void put_pixel(image * image, pixel pixel, color c){
    *((image->map)+pixel.y*image->width+pixel.x)=c;
}


int main(int argc, const char * argv[])
{

    // insert code here...
    printf("Hello, World!\n");
    return 0;
}

