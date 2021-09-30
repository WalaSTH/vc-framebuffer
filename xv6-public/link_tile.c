#include "types.h"
#include "user.h"
//#include "drawing.c"


//Primer movimiento hacia abajo
void drawLink1(int xV,int yV){
    int img[] = {
    		-1,-1,-1,-1,-1,2,2,2,2,2,2,-1,-1,-1,-1,
    		-1,-1,-1,-1,2,2,2,2,2,2,2,2,-1,-1,-1,
			-1,-1,6,-1,2,8,8,8,8,8,8,2,-1,6,-1,
			-1,-1,6,-1,8,8,8,8,8,8,8,8,-1,6,-1,
			-1,-1,6,6,8,6,2,6,6,2,6,8,6,6,-1,
			-1,-1,6,6,8,6,8,6,6,8,6,8,6,6,-1,
			-1,-1,-1,6,6,6,6,6,6,6,6,6,6,8,-1,
			-1,-1,-1,2,2,6,6,8,8,6,6,2,2,8,-1,
			-1,8,8,8,8,8,6,6,6,6,2,2,8,8,8,
			8,8,6,8,8,8,8,2,2,2,2,2,6,8,8,
			8,6,6,6,8,8,6,8,8,2,2,6,6,6,8,
			8,8,6,8,8,8,6,2,8,8,8,8,6,6,6,
			8,8,6,8,8,8,6,8,8,2,2,2,2,6,-1,
			8,8,8,8,8,8,6,2,2,2,2,2,-1,-1,-1,
			-1,6,6,6,6,6,8,-1,-1,8,8,8,-1,-1,-1,
			-1,-1,-1,-1,8,8,8,-1,-1,-1,-1,-1,-1,-1,-1};            

    int x = xV,y = yV;
    for(unsigned int i=0; i<239; i++){
        if(i==0){
        	plotPixel(x,y,img[i]);
        }
        else{
			if(i%15 == 0){
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

//Segundo movimiento hacia abajo
void drawLink2(int xV,int yV){
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

    int x = xV,y = yV;
    for(unsigned int i=0; i<239; i++){
        if(i==0){
        	plotPixel(x,y,img[i]);
        }
        else{
			if(i%15 == 0){
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
