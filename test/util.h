//
//  util.h
//  test
//
//  Created by Maiquel Knechtel on 25/04/15.
//  Copyright (c) 2015 Maiquel knechtel. All rights reserved.
//

#ifndef test_util_h
#define test_util_h

static GLuint texid;
static GLubyte test;

//test maiquel

void doPaintImage(GLubyte * image){
    glGenTextures(1, &texid);
    glBindTexture(GL_TEXTURE_2D, texid);
    glTexEnvi(GL_TEXTURE_2D, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 640, 400, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);
    glTexCoord3f(0.0, 0.0,0.0); glVertex3f(-20.0, 20.0, 0.0);
    glTexCoord3f(1.0, 0.0,0.0); glVertex3f(20.0, 20.0,  0.0);
    glTexCoord3f(1.0, 1.0,0.0); glVertex3f(20.0, -20.0,  0.0);
    glTexCoord3f(0.0, 1.0,0.0); glVertex3f(-20.0, -20.0, 0.0);
    glEnd();
    glFlush();
}
void readCenario(char * fileName,GLubyte data[]){
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
            
        }else{
            int i = atoi(ler);
            dataAux[contCtl] = i;
            contCtl++;
        }
        
        
        
        
    }
    
    fclose(fp2);
    for(int i=0;i<640*400*3;i+=3){
        data[i]   = dataAux[i+2];
        data[i+1] = dataAux[i];
        data[i+2] = dataAux[i+1];
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

void readDataBarreira(char * fileName,GLubyte* dataBarreira1){
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
            dataBarreira1[contCtl2] = i;
            contCtl2++;
        }
        
        
        
        
    }
    
    fclose(fp2);
    
}

void paintImageGoleiro(char * fileName,GLubyte * data){
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
    
    for(int i=0;i<640*400*3;i+=3){
        
        if(dataAux[i] == 23 && dataAux[i+1]==23 & dataAux[i+2]==255 ){
        }else{
            data[i]   = dataAux[i+2];
            data[i+1] = dataAux[i];
            data[i+2] = dataAux[i+1];
        }
    }
    
    
    
    
    
}


#endif
