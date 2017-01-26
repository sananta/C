#include <stdio.h>
#include <stdlib.h> 

//user inputs two matrices and is given back their sum  
void get_matrix(int number_rows, int number_columns) { 
	int** first_matrix; 
	int** second_matrix; 
	int** final_matrix;
	int i; 
	int j;
// malloc is used to allocate memory for the matrix, which is a two dimensional array  
        printf("Please enter the number of rows: ");
        scanf("%d", &number_rows);
        printf("Please enter the number of columns: ");
        scanf("%d", &number_columns);
	//this allocates memory for the entire 2d array
	first_matrix = (int**)malloc(number_rows * sizeof(int *));
	//This for loop iterates within the rows. It individually allocates memory for each element within the row.  The number of elements within the row is the number of columns. 
	for (i = 0; i <number_rows; ++i) { 
		first_matrix[i] = (int*)malloc(number_columns * sizeof(int ));  
	}
	//creates the first matrix by iterating individually through every row and column based on the number of rows and columns the user inputs.
	printf("Enter Matrix A\n"); 
	for(i = 0; i < number_rows; ++i) { 
		for(j = 0; j <number_columns; ++j) { 
			scanf("%d", &first_matrix[i][j]); 
		}
	} 
	//Allocates memory for the second two dimensional array.
	second_matrix = (int**)malloc(number_rows * sizeof(int *));
	// //This for loop iterates within the rows. It individually allocates memory for each element within the row.  The number of elements within the row is the number of columns. 
	for (i = 0; i <number_rows; ++i) {
		second_matrix[i] = (int*)malloc(number_columns * sizeof(int )); 
	}
       //creates the second  matrix by iterating individually through every row and column based on the number of rows  and columns the user inputs.
	printf("Enter Matrix B\n"); 
	for(i = 0; i < number_rows; ++i) { 
                for(j = 0; j <number_columns; ++j) { 
                        scanf("%d", &second_matrix[i][j]); 
                }
        }
	//allocates memory for the final two dimensional array
	final_matrix = (int**)malloc(number_rows * sizeof(int *)); 
	for (i = 0; i<number_rows; ++i) { 
		final_matrix[i] = (int*)malloc(number_columns * sizeof(int )); 
 	}
	//Adds matrix A and B to create the final matrix.
	for(i = 0; i < number_rows; ++i) {
                for(j = 0; j <number_columns; ++j) {
                        final_matrix[i][j] = first_matrix[i][j] + second_matrix[i][j]; 
                }
        }
//The sum of the two matrices is shown here  
 	printf("A + B =\n"); 
	for(i = 0; i < number_rows; ++i) {
                for(j = 0; j <number_columns; ++j) {
                        printf("%d ", final_matrix[i][j]);  
                }
		printf("\n");
        }
}
//declares the number of rows and columns and calls to get_matrix function in order to create the matrices and add them
int main() {
//number_rows stands for the rows in the matrices and number_columns stands for the columns 
	int number_rows, number_columns;
	get_matrix(number_rows, number_columns);
	return 0;
}
	
