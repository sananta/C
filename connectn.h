/*This file names all of the function names within the connectn.c file and is used to connect and compile the two files named, connectn.c and connectt.c*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void read_args(int argc);
char** create_board(int rows, int columns);
void print_board(int rows, int columns, char* playgrid[columns]);
int play_piece(int rows, int columns, int specific_column, char piece, char* playgrid[columns]);
int checkWin(int rows, int columns, int point, char* playgrid[columns]); 
