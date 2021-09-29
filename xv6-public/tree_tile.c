#include "types.h"
#include "user.h"
#include "drawing.c"
#define N 20
//--------Rock Background Tile---------//

void print_rock_tile(int pos_x, int pos_y, int color){
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
    
}