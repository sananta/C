#include <stdio.h> 
// Program used to calculate the sum of two fractions inputted by user 
int main(void) {
	int numeratorfraction1; 
	int denominatorfraction1;
	int numeratorfraction2; 
	int denominatorfraction2;
	int numeratorfinal; 
	int denominatorfinal;    
	printf("Please enter the first fraction to be added: ");
	scanf("%d / %d", &numeratorfraction1, &denominatorfraction1); 
	printf("Please enter the second fraction to be added: "); 
	scanf("%d / %d", &numeratorfraction2, &denominatorfraction2);
	/* The final numerator and denominator are calculated in a similar 
	way to multiplying both the numerator and denominator of a fraction
	by the same number, in this case the denominator of the other 
	fraction added to it */ 
	numeratorfinal = (numeratorfraction1 * denominatorfraction2) +				(denominatorfraction1 * numeratorfraction2); 
	denominatorfinal = denominatorfraction1 * denominatorfraction2;
	printf("%d/%d + %d/%d = %d/%d\n", numeratorfraction1, 					denominatorfraction1, numeratorfraction2, denominatorfraction2, 			numeratorfinal, denominatorfinal);
	return 0; 
} 
