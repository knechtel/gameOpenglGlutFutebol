//
//  Image.h
//  test
//
//  Created by Maiquel knechtel on 3/16/15.
//  Copyright (c) 2015 Maiquel knechtel. All rights reserved.
//

#ifndef __test__Image__
#define __test__Image__
#include <GLUT/glut.h>
#include <stdio.h>

class Image {
public:
    Image();
    Image(int w, int h);
        
    void setPixel(char* rgb, int x, int y);
    int getPixel(int x, int y);
    int getWidth();
    int getHeight();
private:
    GLubyte *pixels; // alternativamente char *pixels – 1 byte por canal
    // neste caso, pixels = new char[w*h*3];
    int width, height, channels;
};

#endif /* defined(__test__Image__) */
