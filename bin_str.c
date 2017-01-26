#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <ctype.h>
#include <stdbool.h>

/* Converts all the characters within the user input known as string into the binary form of 0's and 1's, and keeps the 0's and 1's within the original argument string the same when printing the output(s) */
//points to the string that is the input
void printResult(char *string) {
	//declares the variable i in order to iterate through the string
	//length which represents the string length is used in the iteration
	int i, length = strlen(string);
	//strdup returns pointer to string2 and string3 which are duplicates of string
	char *string2 = strdup(string), *string3 = strdup(string);
	//iterates throughout the string and for every element within the string that is an x it prints either a 0 or a 1
	for(i = 0; i < length; i++){
		if(string[i] == 'x'){
			string2[i] = '0';
			//recursive call
			printResult(string2);
			string2[i] = '1';
			//recursive call
			printResult(string2);
			//break exits out of the loop
			break;
		}
		//if function below prints out the final binary result(s) of the string 
		if( i == length - 1) {
			printf("%s\n", string2);
		}
	}
	// printf("%s\n", string3);
 }
/* Calls to the functon of printResult */
int main(int argc, char *argv[]) {
	printResult(argv[1]); 
	return 0;
}

