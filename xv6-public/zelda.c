#include "types.h"
#include "user.h"
//#include "drawing.c"
//#include "rock_tile.c"
#include "redOctorok_tile.c"
#include "link_tile.c"
#include "character.c"

void draw_map0(int color){
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


int main(void){
    
    modeswitch(1);
    draw_map0(2);
    int x, y;
    x = 120;
    y = 100;
    drawLinkD1(x,y);
    while(1){
    int key = getch();
    switch (key)
    {
    case 'w':
        /* move up */
        //pintar mapa
        plotrectangle(x,y, x+15, y+16, 14);
        //mover abajo
        y = y - 2;

        drawLinkU1(x,y);
        
        break;
    case 'a':
        plotrectangle(x,y, x+15, y+16, 14);
        /* move left */
        x = x - 2;
        drawLinkL1(x,y);
        
        break;
    case 's':        
        plotrectangle(x,y, x+15, y+16, 14);
        y = y + 2;
        /* move dwn */
        drawLinkD1(x,y);        
        break;
    case 'd':
        plotrectangle(x,y, x+15, y+16, 14);
        /* move right */
        x = x + 2;
        drawLinkR1(x,y);
        
        break;
    default:
        break;
    }
    //print_rock_tile(0,0,2);       
/*     drawRedO1(80,100);
    drawRedO2(100,100);
    drawLinkD1(120,100);
    drawLinkD2(140,100);
    drawLinkR1(160,100);
    drawLinkR2(180,100);
    drawLinkU1(120,120);
    drawLinkU2(140,120);
    drawLinkL1(160,120);
    drawLinkL2(180,120);  */   
    }
    exit();
}

