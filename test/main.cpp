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
static GLuint texid;

#define DEG2RAD 3.14159/180.0

#define PI 3.1415926535898
int width  = 10;
int height = 10;
 GLubyte * data;
 struct square{
    
    int r;
    int g;
    int b;
    
    
     float p1;
     float p2;
     float P3;
     float p4;
     float yp1;
     float yp2;
     float yp3;
     float yp4;
     
     int index;
};

struct matrix{

    float x;
    float y;
};
int tam = 640*400*3;
GLubyte * dataAuxBola = (unsigned char*) malloc( sizeof( unsigned char ) * 640 * 400 * 3 );

GLubyte * dataAuxBolaSwap = (unsigned char*) malloc( sizeof( unsigned char ) * 640 * 400 * 3 );


GLubyte * dataRead = (unsigned char*) malloc( sizeof( unsigned char ) * 31 * 62 * 3 );


std::vector<square> vet(0);

void processMouse(int button, int state, int x, int y) {
    printf("press X = %d, y = %d ",x,y);
}

void doPaintImage(GLubyte * image){
    //    std::cout << "Read test.ppm, width = " << w << ", height = " << h << std::endl;
        glGenTextures(1, &texid);
        glBindTexture(GL_TEXTURE_2D, texid);
        glTexEnvi(GL_TEXTURE_2D, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 640, 400, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
        glEnable(GL_TEXTURE_2D);
    //
    //
    //
        glBegin(GL_QUADS);
        glTexCoord3f(0.0, 0.0,0.0); glVertex3f(-20.0, 20.0, 0.0);
        glTexCoord3f(1.0, 0.0,0.0); glVertex3f(20.0, 20.0,  0.0);
        glTexCoord3f(1.0, 1.0,0.0); glVertex3f(20.0, -20.0,  0.0);
        glTexCoord3f(0.0, 1.0,0.0); glVertex3f(-20.0, -20.0, 0.0);
    
    
        glEnd();
        glFlush();
}
void paintImage1(char * fileName){
    FILE *fp2;
    
    GLubyte * dataAux = (unsigned char*) malloc( sizeof( unsigned char ) * 640 * 400 * 3 );
    
    fp2 = fopen(fileName,"r");   /* Arquivo ASCII, para leitura */
    char ler[10];
    int contCtl = 0;
    
    while(fgets(ler, 10, fp2))  {
        if((strcmp(ler,"P3\n")) == 0){
            int w,h;
            fscanf(fp2,"%d",&w);
            fscanf(fp2,"%d",&h);
            data = (unsigned char*) malloc( sizeof( unsigned char ) * w * h * 3 );
        }else{
            int i = atoi(ler);
            dataAux[contCtl] = i;
            contCtl++;
        }
        
        
        
        
    }
    
    fclose(fp2);
    for(int i=0;i<tam;i+=3){
        data[i]   = dataAux[i+2];
        data[i+1] = dataAux[i];
        data[i+2] = dataAux[i+1];
    }
    
}




void readData(char * fileName){
    FILE *fp2;
    
    fp2 = fopen(fileName,"r");   /* Arquivo ASCII, para leitura */
    char ler[10];
    int contCtl2 = 0;
    
    while(fgets(ler, 10, fp2))  {
        if((strcmp(ler,"P3\n")) == 0){
            int w,h;
            fscanf(fp2,"%d",&w);
            fscanf(fp2,"%d",&h);
        }else{
            int i = atoi(ler);
            dataRead[contCtl2] = i;
            contCtl2++;
        }
        
      
        
        
    }
    
    fclose(fp2);
    
}

void paintImageGoleiro(char * fileName){
    FILE *fp2;
    
    GLubyte * dataAux = (unsigned char*) malloc( sizeof( unsigned char ) * 640 * 400 * 3 );
   
    
    fp2 = fopen(fileName,"r");   /* Arquivo ASCII, para leitura */
    char ler[10];
    int contCtl =0;
    while(fgets(ler, 10, fp2))  {
        if((strcmp(ler,"P3\n")) == 0){
            
            int w,h;
            fscanf(fp2,"%d",&w);
            fscanf(fp2,"%d",&h);
            
        //    data = (unsigned char*) malloc( sizeof( unsigned char ) * w * h * 3 );
            
        }else{
            int i = atoi(ler);
            dataAux[contCtl] = i;
            
            
            contCtl++;
        }
        
    }
    
    fclose(fp2);
    
    for(int i=0;i<tam;i+=3){
        
        if(dataAux[i] == 23 && dataAux[i+1]==23 & dataAux[i+2]==255 ){
        }else{
            data[i]   = dataAux[i+2];
            data[i+1] = dataAux[i];
            data[i+2] = dataAux[i+1];
        }
    }
    
    
    
    int flagY = 0;
    
    int flagX = 0;
    int cont1  = 0;
    for(int i=0;i<tam;i+=3){
        
        
        int x = (i/3)%640;
        int y = (i/3)/640;
        
//        printf(" x  = %d && y = %d  i = %d\n",x,y,i);
        
        if(x==250){
            flagX = 1;
        }if(x==281){
            flagX = 0;
        }
        if(y==250){
            flagY =1;
        }if(y==312){
            flagY = 0;
        }
        
        if(flagX==1&& flagY==1){
            printf(" x  = %d && y = %d  \n",x,y);
            
            
            if(dataRead[cont1]==255 && dataRead[cont1+1]==255 && dataRead[cont1+1]==255){}
            else{
            data[i]   = dataRead[cont1+2];//R
            data[i+1] = dataRead[cont1];//G
            data[i+2] = dataRead[cont1+1];//B
            }
            
            cont1=cont1+3;
        }
        
        
        
        
    }
    
    
}


void paintImageBola(char * fileName){
    FILE *fp2;
    
    
    fp2 = fopen(fileName,"r");   /* Arquivo ASCII, para leitura */
    char ler[10];
    int contCtl =0;
    while(fgets(ler, 10, fp2))  {
        if((strcmp(ler,"P3\n")) == 0){
            
            int w,h;
            fscanf(fp2,"%d",&w);
            fscanf(fp2,"%d",&h);
            
            //    data = (unsigned char*) malloc( sizeof( unsigned char ) * w * h * 3 );
            
        }else{
            int i = atoi(ler);
            dataAuxBola[contCtl] = i;
            contCtl++;
        }
        
        
        
        
    }
    
    fclose(fp2);
    for(int i=0;i<tam;i+=3){
        
        if(dataAuxBola[i] == 23 && dataAuxBola[i+1]==23 & dataAuxBola[i+2]==255 ){
            dataAuxBolaSwap[i]   = 23;
            dataAuxBolaSwap[i+1] = 23;
            dataAuxBolaSwap[i+2] = 255;
        
        }else{
            dataAuxBolaSwap[i+2]   = data[i];
            dataAuxBolaSwap[i] = data[i+1];
            dataAuxBolaSwap[i+1] = data[i+2];
            
            data[i]   = dataAuxBola[i+2];
            data[i+1] = dataAuxBola[i];
            data[i+2] = dataAuxBola[i+1];
        
           
        }
    }
    
}

void paintImageBola1(char * fileName){
    FILE *fp2;
    
    
    fp2 = fopen(fileName,"r");   /* Arquivo ASCII, para leitura */
    char ler[10];
    int contCtl =0;
    while(fgets(ler, 10, fp2))  {
        if((strcmp(ler,"P3\n")) == 0){
            
            int w,h;
            fscanf(fp2,"%d",&w);
            fscanf(fp2,"%d",&h);
            
            //    data = (unsigned char*) malloc( sizeof( unsigned char ) * w * h * 3 );
            
        }else{
            int i = atoi(ler);
            dataAuxBola[contCtl] = i;
            contCtl++;
        }
    }
    
    fclose(fp2);
    for(int i=0;i<tam;i+=3){
        
        if(dataAuxBola[i] == 23 && dataAuxBola[i+1]==23 & dataAuxBola[i+2]==255 ){
        }else{
            data[i]   = dataAuxBola[i+2];
            data[i+1] = dataAuxBola[i];
            data[i+2] = dataAuxBola[i+1];
        }
    }
    
    for(int i=0;i<tam;i+=3){
        
        if(dataAuxBolaSwap[i] == 23 && dataAuxBolaSwap[i+1]==23 & dataAuxBolaSwap[i+2]==255 ){
        }else{
            data[i]   = dataAuxBolaSwap[i+2];
            data[i+1] = dataAuxBolaSwap[i];
            data[i+2] = dataAuxBolaSwap[i+1];
            
        }
    }

    
}


void paintImageBola2(char * fileName){
    FILE *fp2;
    
    
    fp2 = fopen(fileName,"r");   /* Arquivo ASCII, para leitura */
    char ler[10];
    int contCtl =0;
    while(fgets(ler, 10, fp2))  {
        if((strcmp(ler,"P3\n")) == 0){
            
            int w,h;
            fscanf(fp2,"%d",&w);
            fscanf(fp2,"%d",&h);
            
            //    data = (unsigned char*) malloc( sizeof( unsigned char ) * w * h * 3 );
            
        }else{
            int i = atoi(ler);
            dataAuxBola[contCtl] = i;
            contCtl++;
        }
    }
    
    fclose(fp2);
    for(int i=0;i<tam;i+=3){
        
        if(dataAuxBola[i] == 23 && dataAuxBola[i+1]==23 & dataAuxBola[i+2]==255 ){
        }else{
            data[i]   = dataAuxBola[i+2];
            data[i+1] = dataAuxBola[i];
            data[i+2] = dataAuxBola[i+1];}
    }
    
    for(int i=0;i<tam;i+=3){
        
        if(dataAuxBolaSwap[i] == 23 && dataAuxBolaSwap[i+1]==23 & dataAuxBolaSwap[i+2]==255 ){
        }else{
            data[i]   = dataAuxBolaSwap[i+2];
            data[i+1] = dataAuxBolaSwap[i];
            data[i+2] = dataAuxBolaSwap[i+1];
            
        }
    }
    
    
}



GLubyte* glmReadPPM(char* filename, int* width, int* height) {
    FILE* fp;
    int i, w, h, d;
    unsigned char* image;
    char head[70]; /* max line <= 70 in PPM (per spec). */
    
   fp = fopen(filename, "rb");
    if (!fp) {
        perror(filename);
        return NULL;
    }
    
    /* grab first two chars of the file and make sure that it has the
     correct magic cookie for a raw PPM file. */
    fgets(head, 70, fp);
    if (strncmp(head, "P6", 2)) {
        fprintf(stderr, "%s: Not a raw PPM file\n", filename);
        return NULL;
    }
    
    /* grab the three elements in the header (width, height, maxval). */
    i = 0;
    while (i < 3) {
        fgets(head, 70, fp);
        if (head[0] == '#') /* skip comments. */
            continue;
        if (i == 0)
            i += sscanf(head, "%d %d %d", &w, &h, &d);
        else if (i == 1)
            i += sscanf(head, "%d %d", &h, &d);
        else if (i == 2)
            i += sscanf(head, "%d", &d);
    }
    
    /* grab all the image data in one fell swoop. */
    image = (unsigned char*)malloc(sizeof(unsigned char)*w*h*3);
    fread(image, sizeof(unsigned char), w*h*3, fp);
    fclose(fp);
    
    *width = w;
    *height = h;
    return image;
}

void display(void)
{
    width =1;
    height = 1;
   	int w, h;
    w=1;
    h=1;
    
//    data = glmReadPPM("/Users/maiquelknechtel/Desktop/outros/parallax/ceu.ppm", &w, &h );
//    std::cout << "Read test.ppm, width = " << w << ", height = " << h << std::endl;
//    glGenTextures(1, &texid);
//    glBindTexture(GL_TEXTURE_2D, texid);
//    glTexEnvi(GL_TEXTURE_2D, GL_TEXTURE_ENV_MODE, GL_MODULATE);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//    glEnable(GL_TEXTURE_2D);
//    glBegin(GL_QUADS);
//    glTexCoord3f(0.0, 0.0,10.0); glVertex3f(-20.0, 20.0, 0.0);
//    glTexCoord3f(1.0, 0.0,10.0); glVertex3f(20.0, 20.0,  0.0);
//    glTexCoord3f(1.0, 1.0,10.0); glVertex3f(20.0, -20.0,  0.0);
//    glTexCoord3f(0.0, 1.0,10.0); glVertex3f(-20.0, -20.0, 0.0);
//    glEnd();
//    glFlush();
 
    
    
    readData("/Users/maiquelknechtel/Desktop/outros/parallax/goleiroAt.ppm");
    
    paintImage1("/Users/maiquelknechtel/Desktop/outros/parallax/cenario4.ppm");
   doPaintImage(data);
    
    
    
    paintImageGoleiro("/Users/maiquelknechtel/Desktop/outros/parallax/goleiroV.ppm");
    doPaintImage(data);
    
    
    paintImageBola("/Users/maiquelknechtel/Desktop/outros/parallax/bolaAnima.ppm");
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

void init (void)
{
//    /*  select clearing (background) color       */
//      glClear (GL_COLOR_BUFFER_BIT);
//    glClearColor (0.0, 0.0, 0.0, 0.0);
//    
//    /*  initialize viewing values  */
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    width =10;
//    height = 10;
//    
//    glOrtho(0.0, width, 0.0, height, -10.0, 10.0);
    
      glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        // configuraÁ„o padr„o
     
}

void keyboard (unsigned char key, int x, int y){
    switch (key)
    {
        case '1':{
            
            paintImageGoleiro("/Users/maiquelknechtel/Desktop/outros/parallax/goleiroV.ppm");
            doPaintImage(data);
            
            paintImageBola1("/Users/maiquelknechtel/Desktop/outros/parallax/bolaAnima01.ppm");
            doPaintImage(data);
            break;
        }
            
            
        case '2':{
            paintImage1("/Users/maiquelknechtel/Desktop/outros/parallax/cenario4.ppm");
            doPaintImage(data);
            
            
            
            paintImageGoleiro("/Users/maiquelknechtel/Desktop/outros/parallax/goleiroV.ppm");
            doPaintImage(data);
            
            
            paintImageBola("/Users/maiquelknechtel/Desktop/outros/parallax/bolaAnima.ppm");
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
    glutCreateWindow ("Penalty Kick");
    glutMouseFunc(processMouse);
    glutReshapeFunc(ChangeSize);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    init ();
    glutMainLoop();
    
    return 0;
}
