#include "connectn.h"
#include "connectt.h"

/* argc is the number of command line arguments the user enters including the executable and is used in read_args to make sure that the user only inputted arguments of rows, columns and points next to or across each other to win along with the executable */
//argc is the number of arguments that are read in
void read_args(int argc) {
        if (argc < 4) {
              //there are four  arguments that follow the command line and they  represent the number of rows, columns, and pieces in a row needed to win.  If there is less than four arguments then the program will not run and it will instead print the text within the printf statement and exit.
	        printf("Not enough arguments entered\n");
                printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
                exit(0);
        }
	//if the user types more than four arguments then the program will not run and will instead print the text below  and exit
        if (argc > 4) {
                printf("Too many arguments entered\n");
                printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
                exit(0);
        }
	//if the user enters the correct number of arguments, then the program should run correctly
        if (argc == 4) {
                //exit (EXIT_SUCCESS);
        }
        return;
}

//The function create_board allocates memory for the board in which the game is played
char** create_board(int rows, int columns) { 
//int i is used to iterate the number of rows and int j is used to iterate the number of columns
	int i, j;
	//playgrid must be a double pointer because it points to the values within a two dimensional aray referred to as playgrid
	char **playgrid;
	//malloc is used to allocate memory for a two dimensional array
	playgrid = malloc(rows * sizeof(char *));
        //malloc is used to allocate memory for the number of individual elements (rows) within each column
	for (i = 0; i < rows; ++i) {
		playgrid[i] = malloc(columns * sizeof(char));
	}
        //creates blank spaces
	for (i = 0; i < rows; ++i) {
		for (j = 0; j < columns; ++j) {
			playgrid[i][j] = '*';
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
//this function allows a piece to fall into the space in which the user entered
int play_piece(int rows, int columns, int specific_column, char piece, char* playgrid[]) {
	//O and X are the pieces which will show up on the board for the two players
	if (playgrid[0][specific_column] == 'O' || playgrid[0][specific_column] == 'X')  {
		return 0; 
	}
	int i = rows - 1;
	char current = playgrid[i][specific_column]; 
	for (; ((current == 'O') || (current == 'X')) && (i> -1);) {
		i--;	
		current = playgrid[i][specific_column];
	}
	playgrid[i][specific_column] = piece; 
	return 1; 
}
//this function checks for all possible wins including horixzontal, vertical, and diagonal wins
int checkWin(int rows, int columns, int point, char* playgrid[]) { 
	int i, j, reaches_point;
	//RETURNS 1 IF SOMEONE WON, 0 IF NOT, 2 IF TIE
	//once all blank spaces are filled up without the number of pieces needed to win forming  a row, column, or diagonal there is a tie.
	int tie = 1;
	for(i = 0; i < columns; i++) { 
		if(playgrid[0][i] == '*')  tie = 0;
	}
		if(tie) return 2;
	for(i = 0; i < rows; i++) { 
		for(j = 0; j < columns; j++) { 
			char piece = playgrid[i][j];
			if(piece == '*') continue;
			
			//HORIZONTAL WIN
			int match = 1;
			if(j <= columns - point){
				//iterates the variabloe "reaches_point" until it reaches the the number of pieces in a row or the  point needed to win for the horizontal
				for(reaches_point = 1; reaches_point < point; reaches_point++) {
					//no more pieces can be played once there is a horizontal win within a row
					if(playgrid[i][j+reaches_point] != piece) {
					 	match = 0;
					}
				}
				if(match) {
					return 1;
				}
			}
			//VERTICAL WIN
			match = 1;
			if(i <= rows - point && j < columns){
				//iterates the variabloe reaches_point until it reaches the number of pieces in a column or the  point needed to win for the vertical win
				for(reaches_point = 1; reaches_point < point; reaches_point++) {
				//no more pieces can be played once their is a verticle win within a column	
				if(playgrid[i+reaches_point][j] != piece){
					 	match = 0;
					}
				}
				if(match){
					return 1;
				}
			}
			//DIAGONAL [/]
			match = 1;
			//iterates the variabloe reaches_point until it reaches the point needed to win for the right diagonal
			if(i >= point-1 && j <= columns - point) {
				for(reaches_point = 1; reaches_point < point; reaches_point++) {
					if(playgrid[i-reaches_point][j+reaches_point] != piece){
					 	match = 0;
					}
				}
				if(match) {
					return 1;
				}
			}
			//DIAGONAL [\]
			match = 1;
			//iterates the variabloe reaches_point until it reaches the point needed to win for the lef diagonal
			if(i <= rows - point && j <= columns - point){
				for(reaches_point = 1; reaches_point < point; reaches_point++) {
					 if(playgrid[i+reaches_point][j+reaches_point] != piece){
					 	match = 0;
					 }
				}
				if(match) {
					return 1;
				} 
			}


		}
	}
	return 0; 
}

/* Main function calls out to other functions which work together to create a connect4game with user inputted rows, columns and points horizontally, vertically or diagonall next to each other in order to win */	
int main(int argc, char* argv[]) {
	read_args(argc);
	//atoi converts the string command line arguments to integers to use in other functions called out in main
	int rows = atoi(argv[1]);
	int columns = atoi(argv[2]);
	int point = atoi(argv[3]);
	//declaration for playgrid makes it into a two dimensional array
	char **playgrid = create_board(rows, columns); /* playgrid is the grid the two players play connect4 on */
    	play_game(rows, columns, point, playgrid);
    	return 0;
}
