#include <stdio.h> 
/* This program calculates when two trains, at specific speeds as well as
positions, are heading towards each other and at what time and 
location they will crash */
int main(void) { 
	double train1position = 0; 
	double train1speed = 0;
	double train2position = 0; 
	double train2speed = 0;
	double velocity = 0;
	double distance = 0; 
	double time = 0;
	double crashpoint = 0;  
	printf("Please enter the starting position of train 1: "); 
	scanf("%lf", &train1position);
	printf("Please enter the speed of train 1: "); 
	scanf("%lf", &train1speed); 
	printf("Please enter the starting position of train 2: ");
	scanf("%lf", &train2position);
	printf("Please enter the speed of train 2: "); 
	scanf("%lf", &train2speed);
	/* distance represents the difference in the positions of train 1 and
	train 2 */
	distance = train2position - train1position;
	// time of crash calculated by dividing distance by sum of train speeds 
	time = distance/(train1speed + train2speed);
	/* crashpoint calculated by finding distance traveled by train 1
	during time and adding that to initial position of train 1 */
	crashpoint = (time * train1speed) + train1position;  
	printf("The two trains will collide in %.02lf hours %.02lf miles down"
	" the track.\n", time, crashpoint); 
	return 0; 
}   
	
