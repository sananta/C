#include <stdio.h>
#include <stdlib.h>

/* determine_fibanocci functions finds the value of the nth fibanocci term and prints out 0 and 1 for the 0th and 1st fibanocci term respectively and uses recursion to find the most of the other terms */
int determine_fibanocci(int nth_term, int number_1, int number_2) {
	//0th term
	if (nth_term == -2) {
        	return 0;
    	}
	//1st term
    	if (nth_term == -1) { 
		return 1;
    	}
	//3rd term 
    	if (nth_term == 1) {
        	return number_1 + number_2;
    	}
	//recursive call to determine other fibanocci terms 
    	return determine_fibanocci(nth_term - 1, number_2, number_1 + number_2);
}

/* printResult function takes nth_term as an argument and calls out to determine_fibanocci function to find the nth fibanocci term */ 
void printResult(int nth_term) {
	//number_1 and number_2 are variables used to in the determine_fibonacci function to find the nth_fibanocci term using recursion
	int number_1 = 1;
        int number_2 = 1; 
	int nth_fibanocci_term;
	//nth_fibanocci_term is defined as call to determine_fibanocci function
        nth_fibanocci_term = determine_fibanocci(nth_term - 2, number_1, number_2);
	//prints fibanocci term
        printf("The %dth fibanocci number is %d.\n", nth_term, nth_fibanocci_term);
}

/* Main function converts the argv[1] argument into an integer which represents the nth term for the fibanocci sequence and calls to the printResult function to print out the term */
int main(int argc, char *argv[]) {
	//atoi converts argv[1] into an integer and this value assigned to variable nth_term 
    	int nth_term = atoi(argv[1]);
	printResult(nth_term); 
    	return 0;
}
