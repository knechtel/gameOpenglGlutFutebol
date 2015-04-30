//
//  doPaint.h
//  test
//
//  Created by Maiquel Knechtel on 25/04/15.
//  Copyright (c) 2015 Maiquel knechtel. All rights reserved.
//

#ifndef test_doPaint_h
#define test_doPaint_h

GLubyte * dataAuxBola = (unsigned char*) malloc( sizeof( unsigned char ) * 640 * 400 * 3 );
GLubyte * dataAuxBolaSwap = (unsigned char*) malloc( sizeof( unsigned char ) * 640 * 400 * 3 );


void paintImageBola1(char * fileName,GLubyte data[],int xx, int yy,int tam){
    FILE *fp2;
    
    
    fp2 = fopen(fileName,"r");   /* Arquivo ASCII, para leitura */
    char ler[10];
    int contCtl =0;
    while(fgets(ler, 10, fp2))  {
        if((strcmp(ler,"P3\n")) == 0){
            //
            //            char buf[10];
            //            fscanf(fp2,"%s",&buf);
            //
            
            int w,h;
            fscanf(fp2,"%d",&w);
            fscanf(fp2,"%d",&h);
            
            dataAuxBola = (unsigned char*) malloc( sizeof( unsigned char ) * w * h * 3 );
            
        }else{
            int i = atoi(ler);
            dataAuxBola[contCtl] = i;
            contCtl++;
        }
        
        
        
        
    }
    
    fclose(fp2);
    
    
    int flagYBall = 0;
    int flagXBall = 0;
    int contBall  = 0;
    
    
    for(int i=0;i<640*400*3;i+=3){
        
        
        int x = (i/3)%640;
        int y = (i/3)/640;
        
        if(x==xx){
            flagXBall = 1;
            
        }
        if(x==xx+tam){
            flagXBall = 0;
        }
        if(y==yy){
            flagYBall =1;
        }
        if(y==yy+tam){
            flagYBall=0;
        }
        
        
        
        if(flagXBall==1 && flagYBall==1){
            if(dataAuxBola[contBall]     ==0
               && dataAuxBola[contBall+1]==255
               && dataAuxBola[contBall+2]==0){}
            else{
                data[i]   = dataAuxBola[contBall+2];//R
                data[i+1] = dataAuxBola[contBall];//G
                data[i+2] = dataAuxBola[contBall+1];//B
            }
            
            contBall=contBall+3;
        }
        
    }
}

void paintImageBola(char * fileName,GLubyte data[]){
    FILE *fp2;
    
    
    fp2 = fopen(fileName,"r");   /* Arquivo ASCII, para leitura */
    char ler[10];
    int contCtl =0;
    while(fgets(ler, 10, fp2))  {
        if((strcmp(ler,"P3\n")) == 0){
           
            
            int w,h;
            fscanf(fp2,"%d",&w);
            fscanf(fp2,"%d",&h);
            
                dataAuxBola = (unsigned char*) malloc( sizeof( unsigned char ) * w * h * 3 );
            
        }else{
            int i = atoi(ler);
            dataAuxBola[contCtl] = i;
            contCtl++;
        }
        
        
        
        
    }
    
    fclose(fp2);
    
    
    int flagYBall = 0;
    int flagXBall = 0;
    int contBall  = 0;
    
    
    for(int i=0;i<640*400*3;i+=3){
        
      
        int x = (i/3)%640;
        int y = (i/3)/640;
        
        
        if(x==400){
            flagXBall = 1;
            
        }
        if(x==445){
            flagXBall = 0;
        }
        if(y==330){
            flagYBall =1;
        }
        if(y==375){
            flagYBall=0;
        }
        
        
        
        
        if(flagXBall==1 && flagYBall==1){
            
            
            if(dataAuxBola[contBall]     ==0
               && dataAuxBola[contBall+1]==255
               && dataAuxBola[contBall+2]==0){}
            else{
                data[i]   = dataAuxBola[contBall+2];//R
                data[i+1] = dataAuxBola[contBall];//G
                data[i+2] = dataAuxBola[contBall+1];//B
            }
            
            contBall=contBall+3;
        }
    
    }
    
}



void doPaintBarreira(GLubyte* data,GLubyte *dataBarreira1){
    
    int flagY = 0;
    int flagX = 0;
    int cont1  = 0;
    
    
    //primeiroHomem
    int flagYBarreira = 0;
    int flagXBarreira = 0;
    
    int flagYBarreira1 = 0;
    int flagXBarreira1 = 0;
    
    int flagYBarreira2 = 0;
    int flagXBarreira2 = 0;
    
    int flagYBarreira3 = 0;
    int flagXBarreira3 = 0;
    
    
    int contBarreira   = 0;
    int contBarreira1  = 0;
    int contBarreira2  = 0;
    int contBarreira3  = 0;
    
    for(int i=0;i<640*400*3;i+=3){
        
        
        int x = (i/3)%640;
        int y = (i/3)/640;
        
        
        
        
        if(x==340){
            flagXBarreira = 1;
        }if(x==371){
            flagXBarreira = 0;
        }
        if(y==150){
            flagYBarreira = 1;
        }if(y==255){
            flagYBarreira = 0;
        }
        
        //segundoHomem
        if(x==371){
            flagXBarreira1 =1;
        }if(x==402){
            flagXBarreira1 =0;
        }
        //segundoHomem
        if(y==150){
            flagYBarreira1 = 1;
        }if(y==255){
            flagYBarreira1 = 0;
        }
        //terceiroHomem
        if(x==402){
            flagXBarreira2 =1;
        }if(x==433){
            flagXBarreira2 =0;
        }
        
        //terceiroHomem
        if(y==150){
            flagYBarreira2 = 1;
        }if(y==255){
            flagYBarreira2 = 0;
        }
        
        //quartoHoem
        if(x==433){
            flagXBarreira3 =1;
        }if(x==464){
            flagXBarreira3 =0;
        }
        //quartoHomem
        if(y==150){
            flagYBarreira3 = 1;
        }if(y==255){
            flagYBarreira3 = 0;
        }
        
        
        //primeiroHomem barreira
        if(flagXBarreira==1&& flagYBarreira==1){
            //printf(" x  = %d && y = %d  \n",x,y);
            
            
            if(dataBarreira1[contBarreira]==255 && dataBarreira1[contBarreira+1]==255 && dataBarreira1[contBarreira+2]==255){}
            else{
                data[i]   = dataBarreira1[contBarreira+2];//R
                data[i+1] = dataBarreira1[contBarreira];//G
                data[i+2] = dataBarreira1[contBarreira+1];//B
            }
            
            contBarreira=contBarreira+3;
        }
        
        
        //segundo na barreira
        if(flagXBarreira1==1 && flagYBarreira1==1){
         
            if(dataBarreira1[contBarreira1]     ==255
               && dataBarreira1[contBarreira1+1]==255
               && dataBarreira1[contBarreira1+2]==255){}
            else{
                data[i]   = dataBarreira1[contBarreira1+2];//R
                data[i+1] = dataBarreira1[contBarreira1];//G
                data[i+2] = dataBarreira1[contBarreira1+1];//B
            }
            
            contBarreira1=contBarreira1+3;
        }
        
     
        //terceiroHoem
        
        if(flagXBarreira2==1 && flagYBarreira2==1){
            
            if(dataBarreira1[contBarreira2]     ==255
               && dataBarreira1[contBarreira2+1]==255
               && dataBarreira1[contBarreira2+1]==255){}
            else{
                data[i]   = dataBarreira1[contBarreira2+2];//R
                data[i+1] = dataBarreira1[contBarreira2];//G
                data[i+2] = dataBarreira1[contBarreira2+1];//B
            }
            
            contBarreira2=contBarreira2+3;
        }
        
        if(flagXBarreira3==1 && flagYBarreira3==1){
            
            if(dataBarreira1[contBarreira3]     ==255
               && dataBarreira1[contBarreira3+1]==255
               && dataBarreira1[contBarreira3+1]==255){}
            else{
                data[i]   = dataBarreira1[contBarreira3+2];//R
                data[i+1] = dataBarreira1[contBarreira3];//G
                data[i+2] = dataBarreira1[contBarreira3+1];//B
            }
            
            contBarreira3=contBarreira3+3;
        }
        
    }
    
}


void readProgressBar(char * fileName,GLubyte * data){
    FILE *fp2;
    
    GLubyte * dataAuxPro = (unsigned char*) malloc( sizeof( unsigned char ) * 170 * 70 * 3 );
    
    
    fp2 = fopen(fileName,"r");   /* Arquivo ASCII, para leitura */
    char ler[10];
    int contCtl =0;
    while(fgets(ler, 10, fp2))  {
        if((strcmp(ler,"P3\n")) == 0){
            //
            //            char buf[10];
            //            fscanf(fp2,"%s",&buf);
            //
            
            int w,h;
            fscanf(fp2,"%d",&w);
            fscanf(fp2,"%d",&h);
            
        }else{
            int i = atoi(ler);
            dataAuxPro[contCtl] = i;
            contCtl++;
        }
    }
    
    fclose(fp2);

    int flagYBall = 0;
    int flagXBall = 0;
    int contBall  = 0;
    
    
    for(int i=0;i<640*400*3;i+=3){
        
        
        int x = (i/3)%640;
        int y = (i/3)/640;
        
        if(x==70){
            flagXBall = 1;
            
        }
        if(x==240){
            flagXBall = 0;
        }
        if(y==300){
            flagYBall =1;
        }
        if(y==370){
            flagYBall=0;
        }
        
        
        if(flagXBall==1 && flagYBall==1){
            
            
            if(dataAuxPro[contBall]     ==0
               && dataAuxPro[contBall+1]==255
               && dataAuxPro[contBall+2]==0){}
            else{
                data[i]   = dataAuxPro[contBall+2];//R
                data[i+1] = dataAuxPro[contBall];//G
                data[i+2] = dataAuxPro[contBall+1];//B
            }
            
            contBall=contBall+3;
        }

      
        
    }
    
    
    
    
    
}


#endif
