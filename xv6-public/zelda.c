#include "types.h"
#include "user.h"
//#include "drawing.c"
//#include "rock_tile.c"
#include "redOctorok_tile.c"
#include "link_tile.c"
#include "character.c"
#define MO 2

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
int good_move_up(int x, int y){
    char color;
    int ret = 1;
    y = y - MO;
    for(int i = 0; i < WIDTH; ++i){
        color = (char)get_color(i+x,y);
        ret = ret && (color != 2 && color != 0);
    }
    return ret;
}
int good_move_down(int x, int y){
    char color;
    int ret = 1;
    y = y + MO + HEIGHT;
    for(int i = 0; i < WIDTH; ++i){
        color = (char)get_color(i+x,y);
        ret = ret && (color != 2 && color != 0);
    }
    return ret;
}

int good_move_left(int x, int y){
    char color;
    int ret = 1;
    x = x - MO; 
    for(int i = 0; i < WIDTH; ++i){
        color = (char)get_color(x,i+y);
        ret = ret && (color != 2 && color != 0);
    }
    return ret;
}

int good_move_right(int x, int y){
    char color;
    int ret = 1;
    x = x + MO + WIDTH;
    for(int i = 0; i < WIDTH; ++i){
        color = (char)get_color(x,i+y);
        ret = ret && (color != 2 && color != 0);
    }
    return ret;
}

int main(void){
    modeswitch(1);
    draw_map0(2);
    int x, y, counter;
    counter = 0;
    x = 120;
    y = 100;
    drawLinkD1(x,y);
    while(1){
    int key = getch();
    switch (key)
    {
    case 'w':
        /* move up */
        //rectangle
        plotrectangle(x,y, x+15, y+16, 14);
        
        if(good_move_up(x,y)){
            y = y - 2;
            if(counter % 6 < 3){ 
                drawLinkU1(x,y);
                counter++; 
            }else{
                drawLinkU2(x,y);
                counter++;
            }
        }
        else{
            drawLinkU2(x,y);  
        }        
        break;
    case 'a':
        plotrectangle(x,y, x+15, y+16, 14);
        /* move left */                
        if(good_move_left(x,y)){
            x = x - 2;
            if(counter % 6 < 3){ 
                drawLinkL1(x,y);
                counter++; 
            }else{
                drawLinkL2(x,y);
                counter++;
            }
        }
        else{
            drawLinkL1(x,y);
        } 
        break;
    case 's':
        //rectangle        
        plotrectangle(x,y, x+15, y+16, 14);        
        // move dwn
        if(good_move_down(x,y)){
            y = y + 2;
            if(counter % 6 < 3){ 
                drawLinkD1(x,y);
                counter++; 
            }else{
                drawLinkD2(x,y);
                counter++;
            }
        }
        else{
            drawLinkD2(x,y);            
        }         
        break;
    case 'd':
        plotrectangle(x,y, x+15, y+16, 14);
        /* move right */
        if(good_move_right(x,y)){
            x = x + 2;
            if(counter % 6 < 3){ 
                drawLinkR1(x,y);
                counter++; 
            }else{
                drawLinkR2(x,y);
                counter++;
            }
        }
        else{
            drawLinkR2(x,y);
        }   
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

