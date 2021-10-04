#ifndef _CHARACTER_H
#define _CHARACTER_H
#include "user.h"
#include "link_tile.c"



typedef struct character_s character;
struct character_s {
    int spriteCounter[4]; //Counter for [UP,DOWN,LEFT,RIGTH] 
    int pos_x;int pos_y;
    int counter;
    //int health;
};

character create_character();
character set_position(int x, int y, character c);
int x_position(character c);
int y_position(character c);

character move_up(character c);
character move_down(character c);
character move_left(character c);
character move_right(character c);

#endif