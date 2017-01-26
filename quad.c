#include <stdio.h>
#include <math.h> 
/* user inputs values for the variables a,b,c in the quadratic equation a*x^2 + b * x + c and is returned with the solutions to equation as output */ 
int main(void) { 
	double a; 
	double b; 
	double c; 
	/* discriminant (b^2-4ac) or what's underneath the square root in quadratic 		formula determines number of solutions */
	double discriminant;  
	double solution1; 
	double solution2; 
	printf("Given a quadratic equation of the form a*x^2 + b * x + c\n"); 
	printf("Please enter a: ");
	scanf("%lf", &a);
	printf("Please enter b: "); 
	scanf("%lf", &b); 
	printf("Please enter c: "); 
	scanf("%lf", &c);  
	discriminant = (b*b)-(4*a*c);
	//positive number under radical indicates 2 possible solutions
	if (discriminant > 0) { 
		solution1 = (-b + sqrt(discriminant))/(2*a);      
       		solution2 = (-b - sqrt(discriminant))/(2*a);
		printf("There are 2 real solutions\n"); 
		printf("Solution 1: %0.2lf\n", solution1); 
		printf("Solution 2: %0.2lf\n", solution2); 
	} 
	//0 under radical indicates only 1 possible solution
	if (discriminant == 0) { 
		solution1 = solution2 = -b/(2*a); 
		printf("There is one real solution: %0.02lf\n", solution2); 
	}
	//negative under radical indicates no real solutions, only imaginary  
	if (discriminant < 0) { 
		printf("There are no real solutions\n"); 
	} 
	return 0; 
} 
