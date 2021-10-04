#include "types.h"
#include "user.h"
#include "drawing.c"
#define N 20
//--------Rock Background Tile---------//

void
print_rock_tile(int pos_x, int pos_y, int color){
  int scale = N/10;
  //Saving initial position
  int prev_y = pos_y;
  int prev_x = pos_x;
  //Color Square - Color 2 or 10 work for green
  //plotrectangle(pos_x, pos_y, pos_x + N, pos_y + N, 2);

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      plotpixel(pos_x, pos_y, color);
      pos_y = pos_y + 1;
    }
    pos_y = prev_y;
    pos_x = pos_x + 1;
  }
  //Restoring position
  pos_x = prev_x; pos_y = prev_y;
  //----------Details black----------
    
//  0 5 1
  vertdown(pos_x + 0 *scale, pos_y + 5*scale, 1, scale, 0);
// 0 8 1
  vertdown(pos_x + 0 *scale, pos_y + 8*scale, 1, scale, 0);
//0 9 1
  vertdown(pos_x + 0 *scale, pos_y + 9*scale, 1, scale, 0);
//3 0 1
  vertdown(pos_x + 3 *scale, pos_y + 0*scale, 1, scale, 0);
//3 4 1
  vertdown(pos_x + 3 *scale, pos_y + 4*scale, 1, scale, 0);
//4 1 4
  vertdown(pos_x + 4 *scale, pos_y + 1*scale, 4, scale, 0);
//4 7 2
  vertdown(pos_x + 4 *scale, pos_y + 7*scale, 2, scale, 0);
//5 3 1
  vertdown(pos_x + 5 *scale, pos_y + 3*scale, 1, scale, 0);
//6 8 2
  vertdown(pos_x + 6 *scale, pos_y + 8*scale, 2, scale, 0);
//8 1 2
  vertdown(pos_x + 8 *scale, pos_y + 1*scale, 2, scale, 0);
//8 6 1
  vertdown(pos_x + 8 *scale, pos_y + 6*scale, 1, scale, 0);
//9 3 2
  vertdown(pos_x + 9 *scale, pos_y + 3*scale, 2, scale, 0);
//9 7 3
  vertdown(pos_x + 9 *scale, pos_y + 7*scale, 3, scale, 0);

  //--Details White--/

// 0 0 4
  vertdown(pos_x + 0 *scale, pos_y + 0 *scale , 4,scale, 14);
//1 0 1
  vertdown(pos_x + 1 *scale, pos_y + 0 *scale , 1,scale, 14);
//4 0 1
  vertdown(pos_x + 4 *scale, pos_y + 0 *scale , 1,scale, 14);
//4 5 2
  vertdown(pos_x + 4 *scale, pos_y + 5 *scale , 2,scale, 14);
//4 9 4
  vertdown(pos_x + 4 *scale, pos_y + 9 *scale , 4,scale, 14);
//5 0 2
  vertdown(pos_x + 5 *scale, pos_y + 0 *scale , 2,scale, 14);
//5 3 2
  vertdown(pos_x + 5 *scale, pos_y + 3 *scale , 2,scale, 14);
//5 6 3
  vertdown(pos_x + 5 *scale, pos_y + 6 *scale , 3,scale, 14);
//6 0 2
  vertdown(pos_x + 6 *scale, pos_y + 0 *scale , 2,scale, 14);
//7 0 1
  vertdown(pos_x + 7 *scale, pos_y + 0 *scale , 1,scale, 14);
//8 0 1
  vertdown(pos_x + 8 *scale, pos_y + 0 *scale , 1,scale, 14);
//9 0 3
  vertdown(pos_x + 9 *scale, pos_y + 0 *scale , 3,scale, 14);
//9 6 2
  vertdown(pos_x + 9 *scale, pos_y + 6 *scale , 2,scale, 14);
}