#ifndef CHAR_C
#define CHAR_C
#include "character.h"
#define HEIGHT 16
#define WIDTH  15

void 
plotImg2(int xV,int yV,int img[]){
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
character set_sprite(int s[], int length){
    character new;
    for (int i = 0; i < length; i++){
        new.sprite[i] = s[i];
    }
    return new;
}
void set_position(int x, int y, character c){
    c.position.pos_x = x;
    c.position.pos_y = y;
}
void print_character(character c){
    int img4[10] = {1,2,3,4};
    plotImg2(0,0,img4); 
}
int x_position(character c){
    return c.position.pos_x;
}
int y_position(character c){
    return c.position.pos_y;
}
#endif