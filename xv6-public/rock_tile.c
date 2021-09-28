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

    //0 a la derecha, 5 abajo, pinto 4
    vertdown(pos_x + 1 *scale, pos_y + 5*scale, 4, scale, 0);
    //1 a la derecha, 1 abajo, pinto 6
    vertdown(pos_x + 2 *scale, pos_y + 1 *scale, 6, scale,0);
    //me muevo 3 cuadr *scaleadito al a  *scalederecscale,ha 0 abajo pinto 3
    vertdown(pos_x + 3 *scale, pos_y + 0 *scale, 3, scale,0);
    //me muevo 4 cuadr *scaleadito al a  *scalederecscale,ha 0 abajo pinto 1
    vertdown(pos_x + 4 *scale, pos_y + 0 *scale, 1, scale,0);
    //me muevo 4 cuadr *scaleadito al a  *scalederecscale,ha 8 abajo pinto 1
    vertdown(pos_x + 4 *scale, pos_y + 8 *scale , 1,scale, 0);
    //5 derecha 7 abaj *scaleo pinto 2 *scalescale,
    vertdown(pos_x + 5 *scale, pos_y + 7 *scale, 2, scale,0);
    //6 9 1 *scale *scalescale,
    vertdown(pos_x + 6 *scale, pos_y + 9 *scale , 1,scale, 0);
    //8 0 3 *scale *scalescale,
    vertdown(pos_x + 8 *scale, pos_y + 0 *scale , 3,scale, 0);
    //8 6 4  *scale *scalescale,
    vertdown(pos_x + 8 *scale, pos_y + 6 *scale , 4,scale, 0);
    //9 2 2 *scale *scalescale,
    vertdown(pos_x + 9 *scale, pos_y + 2 *scale , 2,scale, 0);
    // *scale *scalescale,
    vertdown(pos_x + 9 *scale, pos_y + 5 *scale , 1,scale, 0);

    //----------Details white---------- color 7 or 14
    //0 1 1
    vertdown(pos_x + 0 *scale, pos_y + 1 *scale , 1,scale, 14);
    //0 7 2
    vertdown(pos_x + 0 *scale, pos_y + 7 *scale , 3,scale, 14);
    //2 9 1
    vertdown(pos_x + 2 *scale, pos_y + 9 *scale , 1,scale, 14);
    //3 3 4
    vertdown(pos_x + 3 *scale, pos_y + 3 *scale , 4,scale, 14);
    //4 1 2
    vertdown(pos_x + 4 *scale, pos_y + 1 *scale , 2,scale, 14);
    //4 9 1
    vertdown(pos_x + 4 *scale, pos_y + 9 *scale , 1,scale, 14);
    //6 3 6
    vertdown(pos_x + 6 *scale, pos_y + 3 *scale , 6,scale, 14);
    //7 3 1 
    vertdown(pos_x + 7 *scale, pos_y + 3 *scale , 1,scale, 14);
    //9 0 2
    vertdown(pos_x + 9 *scale, pos_y + 0 *scale , 2,scale, 14);
    //9 6 4
    vertdown(pos_x + 9 *scale, pos_y + 6 *scale , 4,scale, 14);
}

void print_tile_matrix(int pos_x, int pos_y, int wide, int height, int color){
    pos_x = pos_x * N;
    pos_y = pos_y * N;
    int prev_y = pos_y;
    for(int i = 0; i < wide; ++i){
        for (int j = 0; j < height; ++j){
            print_rock_tile(pos_x, pos_y, color);
            pos_y = pos_y + N;
        }
        pos_y = prev_y;
        pos_x = pos_x + N;
    }
}