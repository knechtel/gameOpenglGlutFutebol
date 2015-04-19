//
//  Image.cpp
//  test
//
//  Created by Maiquel knechtel on 3/16/15.
//  Copyright (c) 2015 Maiquel knechtel. All rights reserved.
//

#include "Image.h"
#include <stdlib.h>

Image::Image(){}
Image::Image(int w, int h){
    width = w; height = h;
    pixels = (unsigned char*) malloc( sizeof( unsigned char ) * width * height * 3 );
    channels = 3;
    }
void Image::setPixel(char* rgb, int x, int y){
    for(int i=0; i<channels-1; i++)
        pixels[i+x*channels + y*width*channels] = rgb[i];


    }
int Image::getPixel(int x, int y){
        return pixels[x+y*width];
    }
int Image::getWidth(){ return width; }
int Image::getHeight(){ return height; }
