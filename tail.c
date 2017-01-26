#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

/* This function opens the file specified in the command line and refers to the specific lines inputted by the user to print out */ 
void PrintLines(char* argv[]) { 
	FILE *user_file; 
	//opens file to be read 
	user_file = fopen(argv[1], "r"); 
	char character_in_file;
	int lines = 0;
	int line_number = atoi(argv[2]);  
	//exits if the file is empty 
	//if (user_file == NULL) { 
	//	exit (0); 
	//}
	char last_character; 
	/* counts number of lines for every \n present in the text file */
	while ((character_in_file = fgetc(user_file)) != EOF) { 
		if (character_in_file == '\n') { 
			lines ++;
		} 
		last_character = character_in_file;
	}
	if(last_character != '\n') { 
		lines++;
	}
	//close file after figuring out number of lines
	fclose(user_file); 
	user_file = fopen(argv[1], "r"); 
	int printLine = 1;
	//use printLine to print out 
	while ((character_in_file = fgetc(user_file)) != EOF) { 
		//character_in_file stands for particular character in file that is printed
		if (line_number > lines || printLine > lines-line_number) { 
			printf("%c", character_in_file);
		}
		if (character_in_file == '\n') { 
			printLine++;
		} 
	}
	fclose(user_file); 
	//printf("%d\n", lines); 
}
/* This functions prints the last specific lines inputted by the user on the command line and calls out to the function PrintLines(char* argv[]) */ 
int main(int argc, char* argv[]) { 
	PrintLines(argv); 
	return 0; 
}
