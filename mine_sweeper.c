#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "tile.h"
#include "board.h"

void read_args(int argc) {
        if (argc < 5) {
		printf("Not enough arguments. Usage:\n");
                printf("./mine_sweeper.out num_rows num_cols num_mines [seed])\n");
		exit(0); 
	}
	if (argc > 5) { 
		printf("Too many arguments. Usage:\n"); 
		printf("./mine_sweeper.out num_rows num_cols num_mines [seed])\n"); 
		exit(0); 
	}
	if (argc == 4) { 
		//exit (EXIT_SUCCESS); 
	} 

	if (argc == 5) { 
		//exit (EXIT_SUCCESS); 
	}
	return; 
}

char** create_board(struct Board* b) { 
//int i is used to iterate the number of rows and int j is used to iterate the number of columns
	int i, j;
	//playgrid must be a double pointer because it points to the values within a two dimensional aray referred to as playgrid
	char **playgrid;
	//malloc is used to allocate memory for a two dimensional array
	playgrid = malloc(b->num_rows * sizeof(char *));
        //malloc is used to allocate memory for the number of individual elements (rows) within each column
	for (i = 0; i < b->num_rows; ++i) {
		playgrid[i] = malloc(b->num_columns * sizeof(char));
	}
        //creates blank spaces
	for (i = 0; i < b->num_rows; ++i) {
		for (j = 0; j < b->num_columns; ++j) {
			playgrid[i][j] = '#';
		}

	}
	return playgrid; 
}

//this function prints the game board
void print_board(int rows, int columns, char* playgrid[]) {
	int i, j;
	//starts the row from 0 and iterates until the last row.  
	for (i = 0; i < rows; ++i) {
	//prints the rows
		printf("%d ", rows-1-i);
	for (j = 0; j < columns; ++j) {
	//prints the columns
		printf("%c ", playgrid[i][j]);
	}
	printf("\n");
	}
	printf(" ");
	for(i = 0; i < columns; ++i) {
		printf(" %d", i);
	}
	printf("\n");
	return;
}

struct Board* initBoard(int argc, char* argv[] ) {

	int rows = atoi(argv[1]); 
	int columns = atoi(argv[2]); 
	int mines = atoi(argv[3]);
	int seed_number = atoi(argv[4]); 	
	if (!seed_number) {
		seed_number = (int)time(NULL);
	}

	//using struct for board initialization
	struct Board* b = malloc(sizeof(struct Board));
        b->num_rows 	= rows;
        b->num_columns 	= columns;
        b->num_mines 	= mines;
        b->seed 	= seed_number;

        return b;
}

void find_mines(struct Board* b) {
	int i; 
	int l; 
	int j;
	int k; 
	int m;
	srand(b->seed); 
	for (m = 0; m < b->num_mines; ++m) {
		l = rand()%(b->num_rows);	
		k = rand()%(b->num_columns); 
		printf("%d %d\n", l, k); 		
	}
}		
	
int main(int argc, char* argv[]) {
	read_args(argc);
        struct Board* b = initBoard(argc, argv);
	char** playgrid = create_board(b);
	find_mines(b); 
	print_board(b->num_rows, b->num_columns, playgrid); 
	return 0; 
}
