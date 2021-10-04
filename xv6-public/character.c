#ifndef CHAR_C
#define CHAR_C

#include "character.h"

#define HEIGHT 16
#define WIDTH  15
#define MO 2


character create_character(){
  character c;
  /*Start at middle of the map*/
  c = set_position(120,100,c);
  for(unsigned int i = 0; i<4;++i)
    c.spriteCounter[i] = 0;

  return c;
}

static int 
good_move_up(int x, int y){
  char color;
  int ret = 1;
  y = y - MO;
  for(int i = 0; i < WIDTH; ++i){
    color = (char)get_color(i+x,y);
    ret = ret && (color != 2 && color != 0);
  }
  return ret;
}
static int 
good_move_down(int x, int y){
  char color;
  int ret = 1;
  y = y + MO + HEIGHT;
  for(int i = 0; i < WIDTH; ++i){
    color = (char)get_color(i+x,y);
    ret = ret && (color != 2 && color != 0);
  }
  return ret;
}

static int 
good_move_left(int x, int y){
    char color;
    int ret = 1;
    x = x - MO; 
    for(int i = 0; i < WIDTH; ++i){
        color = (char)get_color(x,i+y);
        ret = ret && (color != 2 && color != 0);
    }
    return ret;
}

static int 
good_move_right(int x, int y){
  char color;
  int ret = 1;
  x = x + MO + WIDTH;
  for(int i = 0; i < WIDTH; ++i){
    color = (char)get_color(x,i+y);
    ret = ret && (color != 2 && color != 0);
  }
  return ret;
}

character
move_up(character c){
  int x = c.pos_x; int y = c.pos_y;
  plotrectangle(x,y, x+15, y+16, 14);
        
  if(good_move_up(x,y)){
      y = y - 2;
      if(c.spriteCounter[0] % 6 < 3){ 
          drawLinkU1(x,y);
          c.spriteCounter[0]++; 
      }else{
          drawLinkU2(x,y);
          c.spriteCounter[0]++;
      }
  }
  else{
      drawLinkU2(x,y);  
  }
  c.pos_x = x;
  c.pos_y = y;
  return c;        
}

character
move_down(character c){
  int x = c.pos_x; int y = c.pos_y;
  plotrectangle(x,y, x+15, y+16, 14);
        
  if(good_move_down(x,y)){
      y = y + 2;
      if(c.spriteCounter[1] % 6 < 3){ 
          drawLinkD1(x,y);
          c.spriteCounter[1]++; 
      }else{
          drawLinkD2(x,y);
          c.spriteCounter[1]++;
      }
  }
  else{
      drawLinkD1(x,y);  
  }
  c.pos_x = x;
  c.pos_y = y;
  return c;    
}

character
move_left(character c){
int x = c.pos_x; int y = c.pos_y;
  plotrectangle(x,y, x+15, y+16, 14);
        
  if(good_move_left(x,y)){
      x = x - 2;
      if(c.spriteCounter[2] % 6 < 3){ 
          drawLinkL1(x,y);
          c.spriteCounter[2]++; 
      }else{
          drawLinkL2(x,y);
          c.spriteCounter[2]++;
      }
  }
  else{
      drawLinkL1(x,y);  
  }
  c.pos_x = x;
  c.pos_y = y;
  return c;
}  

character
move_right(character c){
int x = c.pos_x; int y = c.pos_y;
  plotrectangle(x,y, x+15, y+16, 14);
        
  if(good_move_right(x,y)){
      x = x + 2;
      if(c.spriteCounter[3] % 6 < 3){ 
          drawLinkR1(x,y);
          c.spriteCounter[3]++; 
      }else{
          drawLinkR2(x,y);
          c.spriteCounter[3]++;
      }
  }
  else{
      drawLinkR1(x,y);  
  }
  c.pos_x = x;
  c.pos_y = y;
  return c;
}  

character 
set_position(int x, int y, character c){
  c.pos_x = x;
  c.pos_y= y;
  return c;
}

int 
x_position(character c){
  return c.pos_x;
}
int
y_position(character c){
  return c.pos_y;
}
#endif