//
//  main.cpp
//  test
//
//  Created by Maiquel knechtel on 2/24/15.
//  Copyright (c) 2015 Maiquel knechtel. All rights reserved.
//

#include <iostream>

#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#include <math.h>
#include <vector>
#include "Image.h"
#include <stdio.h>
#include "util.h"

#include "doPaint.h"
#include "moveBall.h"
#include <unistd.h>


int ctlKick = 0;

GLubyte * data = (unsigned char*) malloc( sizeof( unsigned char ) * 640 * 400 * 3 );
GLubyte * dataBarreira = (unsigned char*) malloc( sizeof( unsigned char ) * 31 * 105 * 3 );


void processMouse(int button, int state, int x, int y) {
    printf("press X = %d, y = %d ",x,y);
}


void display(void){

    
    
    readCenario("/Users/maiquelknechtel/Desktop/outros/parallax/cenario4.ppm",data);
    readDataBarreira("/Users/maiquelknechtel/Desktop/outros/parallax/barreira1.ppm",dataBarreira);
    doPaintBarreira(data,dataBarreira);
    paintImageGoleiro("/Users/maiquelknechtel/Desktop/outros/parallax/goleiroV.ppm",data);
    paintImageBola("/Users/maiquelknechtel/Desktop/outros/parallax/bola/bolaAniT0.ppm",data);
    doPaintImage(data);
    
    
    
}

void ChangeSize(int w, int h){
    // Prevent a divide by zero
    if(h == 0) h = 1;
    
    // Set Viewport to window dimensions
    
    glViewport(0, 0, 640, 400);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    gluOrtho2D(-20.0f, 20.0f, -20.0f, 20.0f);
    glutReshapeWindow( 640, 400);
    // Modelview matrix reset
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void init (void){
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void keyboard (unsigned char key, int x, int y){
    
    
    switch (key)
    {
            
        case'k':{
        
            
            break;
        }
            
        case 32:{
            
            if(ctlKick==0){
        
            readCenario("/Users/maiquelknechtel/Desktop/outros/parallax/cenario4.ppm",data);
            
            doPaintBarreira(data,dataBarreira);
            paintImageGoleiro("/Users/maiquelknechtel/Desktop/outros/parallax/goleiroV.ppm",data);
        
            paintImageBola("/Users/maiquelknechtel/Desktop/outros/parallax/bola/bolaAniT0.ppm",data);
            
            readProgressBar("/Users/maiquelknechtel/Desktop/outros/parallax/progressBar.ppm", data);
            doPaintImage(data);
            }else if(ctlKick==1){
                
                readCenario("/Users/maiquelknechtel/Desktop/outros/parallax/cenario4.ppm",data);
                
                doPaintBarreira(data,dataBarreira);
                paintImageGoleiro("/Users/maiquelknechtel/Desktop/outros/parallax/goleiroV.ppm",data);
                
                paintImageBola("/Users/maiquelknechtel/Desktop/outros/parallax/bola/bolaAniT0.ppm",data);
                
                readProgressBar("/Users/maiquelknechtel/Desktop/outros/parallax/progressBar2.1.ppm", data);
                doPaintImage(data);
                
            
            }if(ctlKick==2){
                
                readCenario("/Users/maiquelknechtel/Desktop/outros/parallax/cenario4.ppm",data);
                
                doPaintBarreira(data,dataBarreira);
                paintImageGoleiro("/Users/maiquelknechtel/Desktop/outros/parallax/goleiroV.ppm",data);
                
                paintImageBola("/Users/maiquelknechtel/Desktop/outros/parallax/bola/bolaAniT0.ppm",data);
                
                readProgressBar("/Users/maiquelknechtel/Desktop/outros/parallax/progressBar3.ppm", data);
                doPaintImage(data);
                
            }
            
            ctlKick++;
            break;
        }
         
            
            
        case 13:{
            
            if(ctlKick==1){
                readCenario("/Users/maiquelknechtel/Desktop/outros/parallax/cenario4.ppm",data);
                
                doPaintBarreira(data,dataBarreira);
                paintImageGoleiro("/Users/maiquelknechtel/Desktop/outros/parallax/goleiroV.ppm",data);
                
                paintImageBola("/Users/maiquelknechtel/Desktop/outros/parallax/bola/bolaAniT0.ppm",data);
                
                // readProgressBar("/Users/maiquelknechtel/Desktop/outros/parallax/progressBar.ppm", data);
                doPaintImage(data);
                
                kickBarrier(data, dataBarreira);
                
                usleep(3600000);
                
                //reset
                readCenario("/Users/maiquelknechtel/Desktop/outros/parallax/cenario4.ppm",data);
                
                doPaintBarreira(data,dataBarreira);
                paintImageGoleiro("/Users/maiquelknechtel/Desktop/outros/parallax/goleiroV.ppm",data);
                paintImageBola("/Users/maiquelknechtel/Desktop/outros/parallax/bola/bolaAniT0.ppm",data);
                doPaintImage(data);
                ctlKick=0;
            }
            
            if(ctlKick == 2){
                readCenario("/Users/maiquelknechtel/Desktop/outros/parallax/cenario4.ppm",data);
                
                doPaintBarreira(data,dataBarreira);
                paintImageGoleiro("/Users/maiquelknechtel/Desktop/outros/parallax/goleiroV.ppm",data);
                
                paintImageBola("/Users/maiquelknechtel/Desktop/outros/parallax/bola/bolaAniT0.ppm",data);
                
                doPaintImage(data);
               
                kickPerfect(data, dataBarreira);
                
                
                usleep(3600000);
                
                //reset
                readCenario("/Users/maiquelknechtel/Desktop/outros/parallax/cenario4.ppm",data);
                
                doPaintBarreira(data,dataBarreira);
                paintImageGoleiro("/Users/maiquelknechtel/Desktop/outros/parallax/goleiroV.ppm",data);
                paintImageBola("/Users/maiquelknechtel/Desktop/outros/parallax/bola/bolaAniT0.ppm",data);
                doPaintImage(data);
                ctlKick=0;
                
            }
            
            if (ctlKick==3) {
                kickOut(data, dataBarreira);
                
                usleep(3600000);
                
                //reset
                readCenario("/Users/maiquelknechtel/Desktop/outros/parallax/cenario4.ppm",data);
                
                doPaintBarreira(data,dataBarreira);
                paintImageGoleiro("/Users/maiquelknechtel/Desktop/outros/parallax/goleiroV.ppm",data);
                paintImageBola("/Users/maiquelknechtel/Desktop/outros/parallax/bola/bolaAniT0.ppm",data);
                doPaintImage(data);
                ctlKick=0;
                
                
            }
            
            
            break;
        }
            
        case'b':{
            
            readCenario("/Users/maiquelknechtel/Desktop/outros/parallax/cenario4.ppm",data);
            
            doPaintBarreira(data,dataBarreira);
            paintImageGoleiro("/Users/maiquelknechtel/Desktop/outros/parallax/goleiroV.ppm",data);
            
            paintImageBola("/Users/maiquelknechtel/Desktop/outros/parallax/bola/bolaAniT0.ppm",data);
            
            readProgressBar("/Users/maiquelknechtel/Desktop/outros/parallax/progressBar2.1.ppm", data);
            doPaintImage(data);
            
            break;
        }
            
            
            
        case '0':{
            //reset
            readCenario("/Users/maiquelknechtel/Desktop/outros/parallax/cenario4.ppm",data);
            
            doPaintBarreira(data,dataBarreira);
            paintImageGoleiro("/Users/maiquelknechtel/Desktop/outros/parallax/goleiroV.ppm",data);
            paintImageBola("/Users/maiquelknechtel/Desktop/outros/parallax/bola/bolaAniT0.ppm",data);
            doPaintImage(data);
            ctlKick=0;
            
            break;
        }
            
        case '1':{
            
            readCenario("/Users/maiquelknechtel/Desktop/outros/parallax/cenario4.ppm",data);
            
            doPaintBarreira(data,dataBarreira);
            paintImageGoleiro("/Users/maiquelknechtel/Desktop/outros/parallax/goleiroV.ppm",data);
            paintImageBola("/Users/maiquelknechtel/Desktop/outros/parallax/bola/bolaAniT0.ppm",data);
            doPaintImage(data);
            break;
        }
            
            
        case 'q':
            exit(0);			// exit
            
    }
    
   // glutPostRedisplay();
}
                                                                                                                                                                                   

int main(int argc,  char * argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (640, 400);
    glutInitWindowPosition (100, 100);
    glutCreateWindow (">	_ Tiro livre ");
    glutMouseFunc(processMouse);
    glutReshapeFunc(ChangeSize);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    init ();
    glutMainLoop();
    
    return 0;
}
