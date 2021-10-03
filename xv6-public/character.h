#ifndef _CHARACTER_H
#define _CHARACTER_H
#include "user.h"

#define MAX_SPRITE 2000 //????

typedef struct position_s position_t;
struct position_s{
    int pos_x;
    int pos_y;
};

typedef struct character_s character;
struct character_s {
    int sprite[MAX_SPRITE];
    position_t position;
    //int health;
};

character set_sprite(int s[], int length);
void print_character(character c);
void set_position(int x, int y, character c);
int x_position(character c);
int y_position(character c);


#endif