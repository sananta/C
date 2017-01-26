#include <stdio.h>
/* In this program the user inputs a year and is given an output that confirms whether that year is a leap year or not */ 
int main(void) {
	int year; 
	printf("Please enter a year: "); 
	scanf("%d", &year);
	//if the year is a multiple of 4 it can be evaluated
	if (year%4 == 0) { 
		//if year multiple of 400 it is a leap year
		if (year%400 == 0) { 
			printf("%d is a leap year.\n", year); 
		} 
		//if year just a multiple of 100 it is not a leap year
		else if (year%100 == 0) { 
			printf("%d is not leap year.\n", year);
		}
		//if year is just a multiple of 4 it is a leap year 
		else if (year%4 ==0) { 
			printf("%d is a leap year.\n", year);  
		} 
		}
	//if year is not multiple of 4 it can't be evaluated and is not a leap year 
	else { 
		printf("%d is not leap year.\n", year); 
	} 
	return 0; 
}  
