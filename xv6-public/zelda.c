#include "types.h"
#include "user.h"
//#include "drawing.c"
//#include "rock_tile.c"
#include "redOctorok_tile.c"
#include "link_tile.c"
#include "character.c"
#define MO 2

void 
draw_map0(int color){
  //Floor
  plotrectangle(0,0,320,200, 14);
  //Rock
  rock_tile_matrix(0,0,6,2,color);
  rock_tile_matrix(6,0,1,1,color);
  rock_tile_matrix(0,2,3,1,color);
  rock_tile_matrix(0,3,2,1,color);
  rock_tile_matrix(0,4,1,1,color);
  rock_tile_matrix(0,7,2,3,color);
  rock_tile_matrix(14,7,2,3,color);
  rock_tile_matrix(9,0,7,4,color);
  rock_tile_matrix(10,4,6,1,color);
  rock_tile_matrix(2,9,12,1,color);
  //Bottom rock
  rock_bottom_matrix(6,1,1,1,color);
  rock_bottom_matrix(3,2,1,1,color);
  rock_bottom_matrix(2,3,1,1,color);
  rock_bottom_matrix(1,4,1,1,color);
  //Trees
  tree_tile_matrix(0,6,2,1,color);
  tree_tile_matrix(2,8,12,1,color);
  tree_tile_matrix(14,6,2,1,color);
  //Cave
  plotrectangle(80,20,100,40,0);
}

int 
main(void){
  modeswitch(1);
  draw_map0(2);
  character link =  create_character();
  drawLinkD1(120,100);
  int key, play;
  play = 1;
  while(play){
    key = getch();
    switch (key)
    {
    case 'w':
        link = move_up(link);
        break;
    case 'a':
        link = move_left(link);
        break;
    case 's':
        link = move_down(link);
        break;
    case 'd':
        link = move_right(link);
        break;
    case 'p':
        play = 0;
        break;
    default:
        break;
    } 
  }
  plotrectangle(0,0,319,199,0);
  modeswitch(0);
  exit();
}

