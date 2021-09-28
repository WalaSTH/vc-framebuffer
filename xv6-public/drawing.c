#include "types.h"
#include "user.h"
//DRAWING UTILITES

//--Prints n 4x4 squares verticaly downwards


void vertdown(int pos_x,int pos_y, int n, int size, int color){
    int initial_y = pos_y;
    for(int i = 0; i < size ; i++){
        for(int j = 0; j < n * size; j++){
            plotpixel(pos_x, pos_y, color);
            pos_y = pos_y + 1; 
        }
        pos_y = initial_y;
        pos_x = pos_x + 1;
    }
}