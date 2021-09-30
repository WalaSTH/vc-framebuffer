

#define N 20

//----------rock_tile.c----------
/*  Print rock tile matrix  
    USAGE:  Prints a matrix of wide x height dimensions of rock tiles
            Args: pos_x and pos_y are the positions when seeing
                  the screen as a set of 20x20 squares
                  color stores the desired color
*/
void rock_tile_matrix(int pos_x, int pos_y, int wide, int height, int color);

//----------rock_bottom_tile.c----------

/*  Print tile bottom matrix  
    USAGE:  Same as tile_matrix, except it prints a bottom rock tile
*/
void rock_bottom_matrix(int pos_x, int pos_y, int wide, int height, int color);

//----------Tree tile ----------
void tree_tile_matrix(int pos_x, int pos_y, int wide, int height, int color);

/* #endif
 */