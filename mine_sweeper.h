#include <stdio.h> 
#include <stdlib.h> 

struct Board { 
	int num_rows; 
	int num_columns;
	int num_mines;
	int seed;
};

void playGrid(struct Board *b);
void printGrid(struct Board *b, char **gridMines, int **gridSurroundMines);
void printInitGrid(struct Board *b, char **gridMines, int **gridSurroundMines);
void createMines(struct Board *b, char **gridMines, int **gridSurroundMines);
void updateGridSurroundMineCount(int **gridSurroundMines, int row, int col, struct Board *b);
char ** initGridStatus(struct Board *b);
char ** initGridMines(struct Board *b);
int ** initGridSurroundMines(struct Board *b);
struct Board* initBoard(int argc, char* argv[] );
void read_args(int argc);
