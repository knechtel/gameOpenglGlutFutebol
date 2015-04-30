//
//  moveBall.h
//  test
//
//  Created by Maiquel Knechtel on 25/04/15.
//  Copyright (c) 2015 Maiquel knechtel. All rights reserved.
//

#ifndef test_moveBall_h
#define test_moveBall_h

#include <OpenGL/OpenGL.h>
#include <unistd.h>
#include "doPaint.h"
#include <GLUT/glut.h>


void kickPerfect(GLubyte* data,GLubyte* dataBarreira1){
    usleep(100000);
    
    readCenario("/Users/maiquelknechtel/Desktop/outros/parallax/cenario4.ppm",data);
    
    doPaintBarreira(data,dataBarreira1);
    paintImageGoleiro("/Users/maiquelknechtel/Desktop/outros/parallax/goleiroV.ppm",data);
    paintImageBola1("/Users/maiquelknechtel/Desktop/outros/parallax/bola/bolaAniT0.ppm",data,400,250,45);
    doPaintImage(data);
    usleep(100000);
    
    
    readCenario("/Users/maiquelknechtel/Desktop/outros/parallax/cenario4.ppm",data);
    
    doPaintBarreira(data,dataBarreira1);
    paintImageGoleiro("/Users/maiquelknechtel/Desktop/outros/parallax/goleiroV.ppm",data);
    paintImageBola1("/Users/maiquelknechtel/Desktop/outros/parallax/bola/bolaAniT0.ppm",data,400,200,45);
    doPaintImage(data);
    usleep(100000);
    
    
    readCenario("/Users/maiquelknechtel/Desktop/outros/parallax/cenario4.ppm",data);
    doPaintBarreira(data,dataBarreira1);
    paintImageGoleiro("/Users/maiquelknechtel/Desktop/outros/parallax/goleiroV.ppm",data);
    paintImageBola1("/Users/maiquelknechtel/Desktop/outros/parallax/bola/bolaAniT0.ppm",data,400,200,45);
    doPaintImage(data);
    
    usleep(100000);
    readCenario("/Users/maiquelknechtel/Desktop/outros/parallax/cenario4.ppm",data);
    
    doPaintBarreira(data,dataBarreira1);
    paintImageGoleiro("/Users/maiquelknechtel/Desktop/outros/parallax/goleiroV.ppm",data);
    paintImageBola1("/Users/maiquelknechtel/Desktop/outros/parallax/bola/bolaAniT1.ppm",data,400,150,30);
    doPaintImage(data);
    usleep(100000);
    
    readCenario("/Users/maiquelknechtel/Desktop/outros/parallax/cenario4.ppm",data);
    
    doPaintBarreira(data,dataBarreira1);
    paintImageGoleiro("/Users/maiquelknechtel/Desktop/outros/parallax/goleiroV.ppm",data);
    paintImageBola1("/Users/maiquelknechtel/Desktop/outros/parallax/bola/bolaAniT1.ppm",data,400,130,30);
    doPaintImage(data);
    
    usleep(100000);
    
    readCenario("/Users/maiquelknechtel/Desktop/outros/parallax/cenario4.ppm",data);
    
    doPaintBarreira(data,dataBarreira1);
    paintImageGoleiro("/Users/maiquelknechtel/Desktop/outros/parallax/goleiroV.ppm",data);
    paintImageBola1("/Users/maiquelknechtel/Desktop/outros/parallax/bola/bolaAniT2.ppm",data,400,120,20);
    doPaintImage(data);
    
    usleep(100000);
    
    readCenario("/Users/maiquelknechtel/Desktop/outros/parallax/cenario4.ppm",data);
    
    doPaintBarreira(data,dataBarreira1);
    paintImageGoleiro("/Users/maiquelknechtel/Desktop/outros/parallax/goleiroV.ppm",data);
    paintImageBola1("/Users/maiquelknechtel/Desktop/outros/parallax/bola/bolaAniT3.ppm",data,400,110,15);
    doPaintImage(data);
    
    usleep(10000);
    readCenario("/Users/maiquelknechtel/Desktop/outros/parallax/cenario4.ppm",data);
    
    doPaintBarreira(data,dataBarreira1);
    paintImageGoleiro("/Users/maiquelknechtel/Desktop/outros/parallax/goleiroV.ppm",data);
    paintImageBola1("/Users/maiquelknechtel/Desktop/outros/parallax/bola/bolaAniT3.ppm",data,400,90,15);
    doPaintImage(data);
    
    
    
    usleep(10000);
    readCenario("/Users/maiquelknechtel/Desktop/outros/parallax/cenario4.ppm",data);
    
    doPaintBarreira(data,dataBarreira1);
    paintImageGoleiro("/Users/maiquelknechtel/Desktop/outros/parallax/goleiroV.ppm",data);
    paintImageBola1("/Users/maiquelknechtel/Desktop/outros/parallax/bola/bolaAniT3.ppm",data,400,110,15);
    doPaintImage(data);
    
    
    
    usleep(10000);
    readCenario("/Users/maiquelknechtel/Desktop/outros/parallax/cenario4.ppm",data);
    
    doPaintBarreira(data,dataBarreira1);
    paintImageGoleiro("/Users/maiquelknechtel/Desktop/outros/parallax/goleiroV.ppm",data);
    paintImageBola1("/Users/maiquelknechtel/Desktop/outros/parallax/bola/bolaAniT3.ppm",data,400,130,15);
    doPaintImage(data);
    
    
}

void kickBarrier(GLubyte* data,GLubyte* dataBarreira1){

    
    
    readCenario("/Users/maiquelknechtel/Desktop/outros/parallax/cenario4.ppm",data);
    
    doPaintBarreira(data,dataBarreira1);
    paintImageGoleiro("/Users/maiquelknechtel/Desktop/outros/parallax/goleiroV.ppm",data);
    paintImageBola1("/Users/maiquelknechtel/Desktop/outros/parallax/bola/bolaAniT0.ppm",data,400,250,45);
    doPaintImage(data);
    usleep(100000);
    
    
    readCenario("/Users/maiquelknechtel/Desktop/outros/parallax/cenario4.ppm",data);
    
    doPaintBarreira(data,dataBarreira1);
    paintImageGoleiro("/Users/maiquelknechtel/Desktop/outros/parallax/goleiroV.ppm",data);
    paintImageBola1("/Users/maiquelknechtel/Desktop/outros/parallax/bola/bolaAniT1.ppm",data,400,200,30);
    doPaintImage(data);
    usleep(100000);
  
    readCenario("/Users/maiquelknechtel/Desktop/outros/parallax/cenario4.ppm",data);
    
    doPaintBarreira(data,dataBarreira1);
    paintImageGoleiro("/Users/maiquelknechtel/Desktop/outros/parallax/goleiroV.ppm",data);
    paintImageBola1("/Users/maiquelknechtel/Desktop/outros/parallax/bola/bolaAniT2.ppm",data,400,200,20);
    doPaintImage(data);
  
    usleep(100000);
    readCenario("/Users/maiquelknechtel/Desktop/outros/parallax/cenario4.ppm",data);
    doPaintBarreira(data,dataBarreira1);
    paintImageGoleiro("/Users/maiquelknechtel/Desktop/outros/parallax/goleiroV.ppm",data);
    paintImageBola1("/Users/maiquelknechtel/Desktop/outros/parallax/bola/bolaAniT2.ppm",data,400,250,20);
    doPaintImage(data);
    
    
}
void kickOut(GLubyte* data,GLubyte* dataBarreira1){
    usleep(100000);
    
    readCenario("/Users/maiquelknechtel/Desktop/outros/parallax/cenario4.ppm",data);
    
    doPaintBarreira(data,dataBarreira1);
    paintImageGoleiro("/Users/maiquelknechtel/Desktop/outros/parallax/goleiroV.ppm",data);
    paintImageBola1("/Users/maiquelknechtel/Desktop/outros/parallax/bola/bolaAniT0.ppm",data,400,250,45);
    doPaintImage(data);
    usleep(100000);
    
    
    readCenario("/Users/maiquelknechtel/Desktop/outros/parallax/cenario4.ppm",data);
    
    doPaintBarreira(data,dataBarreira1);
    paintImageGoleiro("/Users/maiquelknechtel/Desktop/outros/parallax/goleiroV.ppm",data);
    paintImageBola1("/Users/maiquelknechtel/Desktop/outros/parallax/bola/bolaAniT0.ppm",data,400,200,45);
    doPaintImage(data);
    usleep(100000);
    
    
    readCenario("/Users/maiquelknechtel/Desktop/outros/parallax/cenario4.ppm",data);
    doPaintBarreira(data,dataBarreira1);
    paintImageGoleiro("/Users/maiquelknechtel/Desktop/outros/parallax/goleiroV.ppm",data);
    paintImageBola1("/Users/maiquelknechtel/Desktop/outros/parallax/bola/bolaAniT0.ppm",data,400,200,45);
    doPaintImage(data);
    
    usleep(100000);
    readCenario("/Users/maiquelknechtel/Desktop/outros/parallax/cenario4.ppm",data);
    
    doPaintBarreira(data,dataBarreira1);
    paintImageGoleiro("/Users/maiquelknechtel/Desktop/outros/parallax/goleiroV.ppm",data);
    paintImageBola1("/Users/maiquelknechtel/Desktop/outros/parallax/bola/bolaAniT1.ppm",data,400,150,30);
    doPaintImage(data);
    usleep(100000);
    
    
    readCenario("/Users/maiquelknechtel/Desktop/outros/parallax/cenario4.ppm",data);
    
    doPaintBarreira(data,dataBarreira1);
    paintImageGoleiro("/Users/maiquelknechtel/Desktop/outros/parallax/goleiroV.ppm",data);
    paintImageBola1("/Users/maiquelknechtel/Desktop/outros/parallax/bola/bolaAniT2.ppm",data,400,120,20);
    doPaintImage(data);
    
    
    usleep(100000);
    
    
    readCenario("/Users/maiquelknechtel/Desktop/outros/parallax/cenario4.ppm",data);
    
    doPaintBarreira(data,dataBarreira1);
    paintImageGoleiro("/Users/maiquelknechtel/Desktop/outros/parallax/goleiroV.ppm",data);
    paintImageBola1("/Users/maiquelknechtel/Desktop/outros/parallax/bola/bolaAniT2.ppm",data,400,100,20);
    doPaintImage(data);
    
    usleep(100000);
    
    
    readCenario("/Users/maiquelknechtel/Desktop/outros/parallax/cenario4.ppm",data);
    
    doPaintBarreira(data,dataBarreira1);
    paintImageGoleiro("/Users/maiquelknechtel/Desktop/outros/parallax/goleiroV.ppm",data);
    paintImageBola1("/Users/maiquelknechtel/Desktop/outros/parallax/bola/bolaAniT2.ppm",data,400,80,20);
    doPaintImage(data);
    
    
    usleep(100000);
    
    readCenario("/Users/maiquelknechtel/Desktop/outros/parallax/cenario4.ppm",data);
    
    doPaintBarreira(data,dataBarreira1);
    paintImageGoleiro("/Users/maiquelknechtel/Desktop/outros/parallax/goleiroV.ppm",data);
    paintImageBola1("/Users/maiquelknechtel/Desktop/outros/parallax/bola/bolaAniT2.ppm",data,400,60,20);
    doPaintImage(data);
    
    
    usleep(100000);
    
    readCenario("/Users/maiquelknechtel/Desktop/outros/parallax/cenario4.ppm",data);
    
    doPaintBarreira(data,dataBarreira1);
    paintImageGoleiro("/Users/maiquelknechtel/Desktop/outros/parallax/goleiroV.ppm",data);
    paintImageBola1("/Users/maiquelknechtel/Desktop/outros/parallax/bola/bolaAniT3.ppm",data,400,40,15);
    doPaintImage(data);
    
    usleep(10000);
    
    
    readCenario("/Users/maiquelknechtel/Desktop/outros/parallax/cenario4.ppm",data);
    
    doPaintBarreira(data,dataBarreira1);
    paintImageGoleiro("/Users/maiquelknechtel/Desktop/outros/parallax/goleiroV.ppm",data);
    paintImageBola1("/Users/maiquelknechtel/Desktop/outros/parallax/bola/bolaAniT3.ppm",data,400,20,15);
    doPaintImage(data);
    
    usleep(10000);
    
    
    readCenario("/Users/maiquelknechtel/Desktop/outros/parallax/cenario4.ppm",data);
    
    doPaintBarreira(data,dataBarreira1);
    paintImageGoleiro("/Users/maiquelknechtel/Desktop/outros/parallax/goleiroV.ppm",data);
    paintImageBola1("/Users/maiquelknechtel/Desktop/outros/parallax/bola/bolaAniT3.ppm",data,400,00,15);
    doPaintImage(data);
    
    usleep(10000);
    
    
    readCenario("/Users/maiquelknechtel/Desktop/outros/parallax/cenario4.ppm",data);
    
    doPaintBarreira(data,dataBarreira1);
    paintImageGoleiro("/Users/maiquelknechtel/Desktop/outros/parallax/goleiroV.ppm",data);
    doPaintImage(data);
    
    usleep(10000);
}

#endif
