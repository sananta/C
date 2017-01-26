#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

/* The .h file lists all the function in mine_player.c */
void playGame(struct Board *b, char **gridMines, int **gridSurroundMines);
void revealNonMineTiles(struct Board *b, char **gridMines, int **gridSurroundMines, int row, int column, char **statusGrid);
