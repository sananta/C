#include "connectt.h"
#include "connectn.h"

/*This function gets the value of the last column within the board from the value that the user inputed
 within the command line, and uses this "UserInput" to tell the user to enter a value between 0 and the last column for where they wish
 to play their piece.*/
int get_play(int rows, int columns) {
	int userInput;
	printf("Enter a column between 0 and %d to play in: ", columns-1);
	scanf("%d", &userInput);
	while ((userInput < 0) || (userInput > columns-1)) {
		printf("Enter a column between 0 and %d to play in: ", columns-1);
		scanf("%d", &userInput);
	}
	return userInput;
}
//This function says to print X if it is the first player's turn, and O if it is the second player's turn
void play_game(int rows, int columns, int point, char* playgrid[]) {
	int game_over;
	game_over = 0;
	int player_turn = 0;
	char piece;
	//This loop allows the pieces X and O to be played until the game comes to an end.
	while (game_over == 0) {
        // calls to the function in which the board was printed
		print_board(rows, columns, playgrid);
		if(player_turn == 0) {
			piece = 'X';
		}
		else {
			piece = 'O';
		}
		//The function returns 1  if someone won, 0 if not, and 2 if tied. Prints out if player 2 won, player 1 won, or if there is a tie.
		while (play_piece(rows, columns, get_play(rows, columns), piece, playgrid) == 0);
		player_turn ^= 1;
		int result;
		if((result = checkWin(rows, columns, point, playgrid))){
			print_board(rows, columns, playgrid);
			if(result == 2){
				printf("Tie game!");
			}
			else if (player_turn == 0) {
				printf("Player 2  Won!\n");
			}
			else {
				printf("Player 1 Won!\n");
			}
			game_over = 1;
		}
	 }
	return;
}
