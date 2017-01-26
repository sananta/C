#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h>

/* ReadWords opens the file named user_file and using isspace() determines the number of words in the file */
void ReadWords(char* argv[]) { 
	FILE *user_file; 
	user_file = fopen(argv[1], "r");
	char specific_character;
	//specific_character stands for character in user_file
	int i = 1;
	if (user_file == NULL) {
		exit( -1); 
	}
	else { 
	specific_character = fgetc(user_file);
	while (specific_character != EOF) {
		if (isspace(specific_character)) {
			i++;
			specific_character = fgetc(user_file);
			while (isspace(specific_character)) {
				specific_character = fgetc(user_file);			
			}
		}
		specific_character = fgetc(user_file);
	}	
	printf("There are %d word(s).\n", i-1); 	
	fclose(user_file); 
	//getchar(); 
	}
}

/* Main function takes command line argument of file name and then calls out to the function ReadWords which determines the number of words in the file */
int main(int argc, char* argv[]) { 
	ReadWords(argv); 
	return 0; 
}
