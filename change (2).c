#include <stdio.h> 
/* In this program the user enters a whole number of the money they wish to
withdraw and are given it back in change of 100,50,20,10 and 1 dollar bills */
int main(void) {
	int amount_money = 0;
	int amount_bills = 0; 
	printf("Please enter the amount of money you wish to withdraw: "); 
	scanf("%d",&amount_money);
	/* if and else statements used to check amount of money and whether 
	or not user will receive change back in a specific bill amount */ 
	if (amount_money >= 100) { 
		amount_bills = amount_money/100;
		printf("You received %d hundred(s)\n", amount_bills); 
	} 
	else { 
		amount_bills = 0; 
		printf("You received %d hundred(s)\n", amount_bills); 
	}
	amount_money = amount_money - (amount_bills * 100);
	if (amount_money >= 50) { 
		amount_bills = amount_money/50; 
		printf("You received %d fifty(s)\n", amount_bills);
	}
	else { 
		amount_bills = 0; 
		printf("You received %d fifty(s)\n", amount_bills); 
	}
	amount_money = amount_money - (amount_bills * 50); 
	if (amount_money >= 20) { 
		amount_bills = amount_money/20; 
		printf("You received %d twenty(s)\n", amount_bills); 
	} 
	else { 
		amount_bills = 0;
		printf("You received %d twenty(s)\n", amount_bills); 
	} 
	amount_money = amount_money - (amount_bills * 20); 
	if (amount_money >= 10) { 
		amount_bills = amount_money/10; 
		printf("You received %d ten(s)\n", amount_bills); 
	} 
	else { 
		amount_bills = 0; 
		printf("You received %d ten(s)\n", amount_bills); 
	} 
	amount_money = amount_money - (amount_bills * 10); 
	if (amount_money >= 5) { 
		amount_bills = amount_money/5; 
		printf("You received %d five(s)\n", amount_bills); 
	} 
	else { 
		amount_bills = 0; 
		printf("You received %d five(s)\n", amount_bills); 
	} 
	amount_money = amount_money - (amount_bills * 5); 
	if (amount_money >= 1) { 
		amount_bills = amount_money/1; 
		printf("You received %d one(s)\n", amount_bills); 
	} 
	else { 
		amount_bills = 0; 
		printf("You received %d one(s)\n", amount_bills); 
	}  	
	return 0; 
}

