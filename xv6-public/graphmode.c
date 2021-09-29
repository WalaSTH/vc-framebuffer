#include "types.h"
#include "user.h"
//#include "drawing.c"
#include "rock_tile.c"
#include "redOctorok_tile.c"
#include "link.c"

int main(void){
    modeswitch(1);
    plotrectangle(0,0,320,200, 14);
    //print_rock_tile(0,0,2);
    print_tile_matrix(0,0,6,2,2);
    print_tile_matrix(9,0,7,4,2);
    drawRedO(100,100);
    drawLink(120,100);
    exit();
}
