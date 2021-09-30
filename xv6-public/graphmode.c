#include "types.h"
#include "user.h"
//#include "drawing.c"
//#include "rock_tile.c"
#include "redOctorok_tile.c"
#include "link_tile.c"

int main(void){
	modeswitch(1);
	plotrectangle(0,0,320,200, 14);
    //print_rock_tile(0,0,2);
    rock_tile_matrix(0,6,2,4,2);
    rock_tile_matrix(14,6,2,4,2);
    rock_tile_matrix(2,8,12,2,2);
    rock_tile_matrix(0,0,6,2,2);
    rock_tile_matrix(0,2,2,2,2);
    rock_tile_matrix(2,2,1,1,2);
    rock_tile_matrix(9,0,7,4,2);
    plotrectangle(60,20,80,40,0);
    drawRedO1(80,100);
    drawRedO2(100,100);
    drawLink1(120,100);
    drawLink2(140,100);
    exit();
}

