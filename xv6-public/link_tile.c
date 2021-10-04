#ifndef LINK_TILE
#define LINK_TILE
#include "types.h"
#include "user.h"
#define HEIGHT 16
#define WIDTH  15
//#include "drawing.c"


void 
plotImg(int xV,int yV,int img[]){
  int x = xV,y = yV;
    for(unsigned int i=0; i<WIDTH*HEIGHT; i++){
      if(i==0){
        plotPixel(x,y,img[i]);
      }
    else{
	    if(i%WIDTH == 0){
	      y = y + 1;
		    x = xV;
		    plotPixel(x,y,img[i]);
	    }
	  else{
			  x = x + 1;
			  plotPixel(x,y,img[i]);
	    }
    }
  }  
}

//Primer movimiento hacia abajo
void 
drawLinkD1(int xV,int yV){
  int img[] = {
                -1,-1,-1,-1,-1, 2, 2, 2, 2, 2, 2,-1,-1,-1,-1,
                -1,-1,-1,-1, 2, 2, 2, 2, 2, 2, 2, 2,-1,-1,-1,
                -1,-1, 6,-1, 2, 8, 8, 8, 8, 8, 8, 2,-1, 6,-1,
                -1,-1, 6,-1, 8, 8, 8, 8, 8, 8, 8, 8,-1, 6,-1,
                -1,-1, 6, 6, 8, 6, 2, 6, 6, 2, 6, 8, 6, 6,-1,
                -1,-1, 6, 6, 8, 6, 8, 6, 6, 8, 6, 8, 6, 6,-1,
                -1,-1,-1, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 8,-1,
                -1,-1,-1, 2, 2, 6, 6, 8, 8, 6, 6, 2, 2, 8,-1,
                -1, 8, 8, 8, 8, 8, 6, 6, 6, 6, 2, 2, 8, 8, 8,
                 8, 8, 6, 8, 8, 8, 8, 2, 2, 2, 2, 2, 6, 8, 8,
                 8, 6, 6, 6, 8, 8, 6, 8, 8, 2, 2, 6, 6, 6, 8,
                 8, 8, 6, 8, 8, 8, 6, 2, 8, 8, 8, 8, 6, 6, 6,
                 8, 8, 6, 8, 8, 8, 6, 8, 8, 2, 2, 2, 2, 6,-1,
                 8, 8, 8, 8, 8, 8, 6, 2, 2, 2, 2, 2,-1,-1,-1,
                -1, 6, 6, 6, 6, 6, 8,-1,-1, 8, 8, 8,-1,-1,-1,
                -1,-1,-1,-1, 8, 8, 8,-1,-1,-1,-1,-1,-1,-1,-1};    

  plotImg(xV,yV,img);                        
}

//Segundo movimiento hacia abajo
void 
drawLinkD2(int xV,int yV){
  int img[] = {
				-1,-1,-1,-1,-1,2,2,2,2,2,2,-1,-1,-1,-1,
				-1,-1,-1,-1,2,2,2,2,2,2,2,2,-1,-1,-1,
				-1,-1,6,-1,2,8,8,8,8,8,8,2,-1,6,-1,
				-1,-1,6,-1,8,8,8,8,8,8,8,8,-1,6,-1,
				-1,-1,6,6,8,6,2,6,6,2,6,8,6,6,-1,
				-1,-1,6,6,8,6,8,6,6,8,6,8,6,6,-1,
				-1,-1,-1,6,6,6,6,6,6,6,6,6,6,8,-1,
				-1,-1,-1,2,2,6,6,8,8,6,6,2,8,8,-1,
				-1,-1,8,8,8,8,8,6,6,6,6,2,2,6,6,
				-1,8,8,6,8,8,8,8,2,2,2,2,2,6,6,
				-1,8,6,6,6,8,8,6,8,8,2,2,2,8,-1,
				-1,8,8,6,8,8,8,6,2,8,8,8,8,6,-1,
				-1,8,8,6,8,8,8,6,8,8,2,2,2,2,6,-1,
				8,8,8,8,8,8,6,2,2,2,2,8,-1,-1,-1,
				-1,-1,6,6,6,6,6,-1,-1,8,8,8,-1,-1,-1,
				-1,-1,-1,-1,-1,-1,-1,-1,-1,8,8,8,-1,-1,-1};

  plotImg(xV,yV,img);  
}

void 
drawLinkR1(int xV,int yV){
  int img[] = {
-1,-1,-1,-1,-1, 2, 2, 2, 2,-1,-1,-1,-1,-1,-1,
-1,-1,-1, 2, 2, 2, 2, 2, 8, 8, 8, 8,-1,-1,-1,
-1, 2, 2, 2, 6, 2, 2, 8, 8, 8, 8, 8, 8,-1,-1,
 2, 2, 2, 2, 6, 6, 8, 8, 8, 8, 8, 8,-1,-1,-1,
 2,-1, 2, 2, 6, 6, 6, 8, 6, 6, 2, 6,-1,-1, 8,
-1,-1, 2, 8, 8, 6, 6, 8, 6, 6, 8, 6, 6, 6, 8,
-1,-1,-1, 8, 8, 8, 6, 6, 6, 6, 6, 6,-1,-1, 8,
-1,-1,-1,-1, 2, 2, 2, 2, 6, 6, 6, 6,-1,-1, 8,
-1,-1, 8, 2, 2, 2, 2, 2, 2, 2, 8, 8, 8, 6, 8,
-1, 8, 8, 8, 2, 6, 6, 6, 2, 2, 2, 8, 8, 6, 8,
-1, 8, 8, 8, 8, 6, 6, 6, 2, 2, 2, 8, 8,-1, 8,
-1, 8, 8, 8, 8, 6, 6, 2, 2, 2, 8,-1,-1,-1, 8,
-1,-1, 2, 8, 8, 2, 2, 8, 8, 8, 8,-1,-1,-1, 8,
-1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,-1,-1,-1,-1,
-1,-1,-1,-1, 8, 8, 8, 8, 8,-1,-1,-1,-1,-1,-1,
-1,-1,-1,-1, 8, 8, 8, 8, 8, 8,-1,-1,-1,-1,-1};

  plotImg(xV,yV,img);                        
}

void 
drawLinkR2(int xV,int yV){
  int img[] = {
				-1,-1,-1,-1,-1, 2, 2, 2, 2,-1,-1,-1,-1,-1,-1,
				-1,-1,-1, 2, 2, 2, 2, 2, 8, 8, 8, 8,-1,-1,-1,
				-1, 2, 2, 2, 6, 2, 2, 8, 8, 8, 8, 8, 8,-1,-1,
				 2, 2, 2, 2, 6, 6, 8, 8, 8, 8, 8, 8,-1,-1,-1,
				 2,-1, 2, 2, 6, 6, 6, 8, 6, 6, 2, 6,-1,-1,-1,
				-1,-1, 2, 8, 8, 6, 6, 8, 6, 6, 8, 6, 6, 6, 8,
				-1,-1,-1, 8, 8, 8, 6, 6, 6, 6, 6, 6,-1,-1, 8,
				-1,-1,-1,-1, 2, 2, 2, 2, 6, 6, 6, 6,-1,-1, 8,
				-1, 2, 8, 8, 2, 2, 2, 6, 6, 8, 8, 8, 6, 6, 8,
				-1, 2, 8, 8, 2, 2, 2, 6, 6, 6, 2, 8,-6, 6, 8, //Debo empezar desde aca (incluyendolar)
				-1, 2, 8, 8, 8, 8, 6, 2, 2, 2, 8, 8,-1,-1, 8,
				-1, 2, 2, 8, 8, 8, 2, 2, 2, 8, 8,-1,-1,-1, 8,
				-1, 2, 2, 2, 2, 2, 8, 8, 8, 8, 8, 2,-1,-1, 8,
				 8, 8, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,-1,-1, 8,
				 8, 8, 8, 8, 2, 2, 2, 2, 2, 2, 2, 8, 8, 8,-1,
				 -1, 8, 8, 8, 8,-1,-1,-1,-1, 8, 8, 8, 8,-1,-1};

  plotImg(xV,yV,img);                        
}

//Primer movimiento hacia la izquierda
void
drawLinkL1(int xV,int yV){
  int img[] = {
				-1,-1,-1,-1,-1,-1, 2, 2, 2, 2,-1,-1,-1,-1,-1,
				-1,-1,-1, 8, 8, 8, 8, 2, 2, 2, 2, 2,-1,-1,-1,
				-1,-1, 8, 8, 8, 8, 8, 8, 2, 2, 6, 2, 2, 2,-1,
				-1,-1,-1, 8, 8, 8, 8, 8, 8, 6, 6, 2, 2, 2, 2,
				 8,-1,-1, 6, 2, 6, 6, 8, 6, 6, 6, 2, 2,-1, 2,
				 8, 6, 6, 6, 8, 6, 6, 8, 6, 6, 8, 8, 2,-1,-1,
				 8,-1,-1, 6, 6, 6, 6, 6, 6, 8, 8, 8,-1,-1,-1,
				 8,-1,-1, 6, 6, 6, 6, 2, 2, 2, 2,-1,-1,-1,-1,
				 8, 6, 8, 8, 8, 2, 2, 2, 2, 2, 2, 2, 8,-1,-1,
				 8, 6, 8, 8, 2, 2, 2, 6, 6, 6, 2, 8, 8, 8,-1,
				 8,-1, 8, 8, 2, 2, 2, 6, 6, 6, 8, 8, 8, 8,-1,
				 8,-1,-1,-1, 8, 2, 2, 2, 6, 6, 8, 8, 8, 8,-1,
				 8,-1,-1,-1, 8, 8, 8, 8, 2, 2, 8, 8, 2,-1,-1,
				-1,-1,-1,-1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,-1,
				-1,-1,-1,-1,-1,-1, 8, 8, 8, 8, 8,-1,-1,-1,-1,
				-1,-1,-1,-1, 8, 8, 8, 8, 8, 8,-1,-1,-1,-1,-1};

  plotImg(xV,yV,img);
}

//Segundo movimiento hacia la derecha
void
drawLinkL2(int xV,int yV){
  int img[] = {
				-1,-1,-1,-1,-1,-1, 2, 2, 2, 2,-1,-1,-1,-1,-1,
				-1,-1,-1, 8, 8, 8, 8, 2, 2, 2, 2, 2,-1,-1,-1,
				-1,-1, 8, 8, 8, 8, 8, 8, 2, 2, 6, 2, 2, 2,-1,
				-1,-1,-1, 8, 8, 8, 8, 8, 8, 6, 6, 2, 2, 2, 2,
				-1,-1,-1, 6, 2, 6, 6, 8, 6, 6, 6, 2, 2,-1, 2,
				 8, 6, 6, 6, 8, 6, 6, 8, 6, 6, 8, 8, 2,-1,-1,
				 8,-1,-1, 6, 6, 6, 6, 6, 6, 8, 8, 8,-1,-1,-1,
				 8,-1,-1, 6, 6, 6, 6, 2, 2, 2, 2,-1,-1,-1,-1,
				 8, 6, 6, 8, 8, 8, 6, 6, 2, 2, 2, 8, 8, 2,-1,
				 8, 6,-6, 8, 2, 6, 6, 6, 2, 2, 2, 8, 8, 2,-1,
				 8,-1,-1, 8, 8, 2, 2, 2, 6, 8, 8, 8, 8, 2,-1,
				 8,-1,-1,-1, 8, 8, 2, 2, 2, 8, 8, 8, 2, 2,-1,
				 8,-1,-1, 2, 8, 8, 8, 8, 8, 2, 2, 2, 2, 2,-1,
				 8,-1,-1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 8, 8,
				-1, 8, 8, 8, 2, 2, 2, 2, 2, 2, 2, 8, 8, 8, 8,
				-1, 8, 8, 8, 8,-1,-1,-1,-1, 8, 8, 8, 8,-1,-1};

  plotImg(xV,yV,img);
}

//Primer movimiento hacia arriba
void
drawLinkU1(int xV,int yV){
    int img[] = {
				-1,-1,-1,-1,-1,2,2,2,2,2,2,-1,-1,-1,-1,
				-1,-1,-1,-1,2,2,2,2,2,2,2,2,-1,-1,-1,
				-1,-1,6,-1,2,2,2,2,2,2,2,2,-1,6,-1,
				-1,-1,6,2,2,2,2,2,2,2,2,2,2,6,-1,
				-1,-1,6,8,2,2,2,2,2,2,2,2,8,6,-1,
				-1,-1,6,6,8,8,2,2,2,2,8,8,6,6,-1,
				-1,-1,-1,6,8,8,8,2,2,8,8,8,6,-1,-1,
				-1,-1,-1,8,2,8,8,8,8,8,8,2,8,-1,-1,
				-1,-1,-1,8,8,2,2,2,2,2,2,2,8,8,-1,
				-1,-1,6,8,8,2,2,2,2,2,2,8,8,-1,-1,
				-1,-1,6,6,2,8,8,8,8,8,8,2,2,-1,-1,
				-1,-1,-1,2,2,2,2,2,2,2,2,2,2,-1,-1,
				-1,-1,-1,-1,8,2,2,2,2,2,8,8,8,-1,-1,
				-1,-1,-1,-1,-1,8,8,-1,-1,8,8,8,8,-1,-1,
				-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,8,8,-1,-1,-1,
				-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

    plotImg(xV,yV,img);
}

//Segundo movimiento hacia arriba
void
drawLinkU2(int xV,int yV){
  int img[] = {
				-1,-1,-1,-1,2,2,2,2,2,2,-1,-1,-1,-1,-1,
				-1,-1,-1,2,2,2,2,2,2,2,2,-1,-1,-1,-1,
				-1,6,-1,2,2,2,2,2,2,2,2,-1,6,-1,-1,
				-1,6,2,2,2,2,2,2,2,2,2,2,6,-1,-1,
				-1,6,8,2,2,2,2,2,2,2,2,8,6,-1,-1,
				-1,6,6,8,8,2,2,2,2,8,8,6,6,-1,-1,
				-1,-1,6,8,8,8,2,2,8,8,8,6,-1,-1,-1,
				-1,-1,8,2,8,8,8,8,8,8,2,8,-1,-1,-1,
				-1,8,8,2,2,2,2,2,2,2,8,8,-1,-1,-1,
				-1,-1,8,8,2,2,2,2,2,2,8,8,6,-1,-1,
				-1,-1,2,2,8,8,8,8,8,8,2,6,6,-1,-1,
				-1,-1,2,2,2,2,2,2,2,2,2,2,-1,-1,-1,
				-1,-1,8,8,8,2,2,2,2,2,8,-1,-1,-1,-1,
				-1,-1,8,8,8,8,-1,-1,8,8,-1,-1,-1,-1,-1,
				-1,-1,-1,8,8,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
				-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

  plotImg(xV,yV,img);
}
#endif