#include "mine_sweeper.h"
#include "mine_player.h"

void revealNonMineTiles(struct Board *b, char **gridMines, int **gridSurroundMines, int row, int column, char **statusGrid) {

	if(row < 0 || row > b->num_rows-1 ) return;
	if(column < 0 || column > b->num_columns-1) return;
	printf ("row: %d , column: %d\n", row, column);

	int tile = gridSurroundMines[row][column];
	char mine = gridMines[row][column];
	printf ("tile: %d , m: %c\n", tile, mine);
	if(tile == 0 && mine != '*') {
		printf("inside zero and non-mine\n");
		statusGrid[row][column] = (char)(gridSurroundMines[row][column]+'0');
		revealNonMineTiles(b, gridMines, gridSurroundMines, row-1, column-1, statusGrid);
		revealNonMineTiles(b, gridMines, gridSurroundMines, row-1, column, statusGrid);
		revealNonMineTiles(b, gridMines, gridSurroundMines, row-1, column+1, statusGrid);
		revealNonMineTiles(b, gridMines, gridSurroundMines, row, column-1, statusGrid);
		revealNonMineTiles(b, gridMines, gridSurroundMines, row, column+1, statusGrid);
		revealNonMineTiles(b, gridMines, gridSurroundMines, row+1, column-1, statusGrid);
		revealNonMineTiles(b, gridMines, gridSurroundMines, row+1, column, statusGrid);
		revealNonMineTiles(b, gridMines, gridSurroundMines, row+1, column+1, statusGrid);
	} 

	if( tile != 0) {

		statusGrid[row][column] = (char)(gridSurroundMines[row][column]+'0');
		printf("inside non-zero: %d\n", statusGrid[row][column]);
		return;
	}
	

}

void printGridStatus(struct Board *b, char **gridStatus) {
        int i, j;

        for(i = b->num_rows-1; i>=0; --i) {
                printf("%d", i);
                for(j = 0; j<b->num_columns; j++) {
                        printf(" %c", gridStatus[i][j]);
                }
                printf("\n");
        }

        printf(" ");
        for(j= 0; j < b->num_columns; j++) {
                printf(" %d", j);
        }
        printf("\n");
}

void playGame(struct Board *b, char **gridMines, int **gridSurroundMines) {

	int revealed = 0;
	int row, column, action;
	char **statusGrid = initGridStatus(b);

	do {
		
		printf("Enter row a row between 0-%d and a column between 0-%d: ", b->num_rows-1, b->num_columns-1);
		scanf("%d", &row);
		scanf("%d", &column);
		printf("Enter Action\n");
		printf("0. Reveal\n");
		printf("1. Question\n");
		printf("2. Mark\n");
		printf("3. Cancel\n");
		printf("Action: ");
		scanf("%d", &action);

		switch( action )  {
			case 0: 
				if(gridMines[row][column] != '*') {
					printf("There are %d mines left\n", b->num_mines);
					revealNonMineTiles(b, gridMines, gridSurroundMines, row, column, statusGrid);
					printGridStatus(b,statusGrid);
				}
				break;
			case 1:
				statusGrid[row][column] = '?';
				if(gridMines[row][column] == '*') {
					b->num_mines -= 1;
					printf("There are %d mines left\n", b->num_mines);
				}
				printGridStatus(b,statusGrid);
				break;
			case 2:
				statusGrid[row][column] = '!';
				if(gridMines[row][column] == '*') {
					b->num_mines -= 1;
					printf("There are %d mines left\n", b->num_mines);
				}
				printGridStatus(b,statusGrid);
				break;
			case 3:
				
				break;
			default:
				break;
		} 

		if(gridMines[row][column] == '*')  {
			statusGrid[row][column] = gridMines[row][column];
			printGridStatus(b, statusGrid);
			printf("You Lost : \(\n");
	  		revealed = 1;
		}
	} while(!revealed);
}
