#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* Struct function used to organize data in the file provided as input */
struct point_of_polygon {
	int x_value;
	int y_value;
};

/* Get the distance between two points of the polygon */
double getDistance(struct point_of_polygon point1, struct point_of_polygon point2) {
	return sqrt(pow((double)point1.x_value-point2.x_value, 2) + pow((double)point1.y_value-point2.y_value, 2));
}

/* The arguments function uses argc and argv to make sure the file the user inputted has enough arguments and then reads the file to see how many points are needed to construct the polygon and the x and y values of these points are associated with the variables points[i].x_value and points[i].y_value which are plugged into the getDistance function to find the distance between all points and then calculate perimeter */ 
void arguments(int argc, char *argv[]){
	int number_of_points, point;
    	struct point_of_polygon specific_point;
    	FILE *user_file;
    	if (argc < 2) {
        	printf("No file name supplied\n");
        	exit(-1);
    	}
    	user_file = fopen(argv[1], "r");
    	if (user_file == NULL) {   
        	printf("Error opening file\n");
        	exit(-1);
    	}
    	int test_points = fread(&number_of_points, sizeof(int), 1, user_file);
	struct point_of_polygon points[number_of_points];
	int i;
	for ( i = 0; i < number_of_points; i++ ) {
     		int temporary_x_value, temporary_y_value;
     		fread(&temporary_x_value, sizeof(int), 1, user_file);
     		fread(&temporary_y_value, sizeof(int), 1, user_file);
     		points[i].x_value = temporary_x_value;
     		points[i].y_value = temporary_y_value;
    	}
    	double perimeter = 0;
    	for ( i = 0; i < number_of_points; i++ ) {
     		perimeter += getDistance(points[i], points[(i+1)%number_of_points]);
    	}
    	printf("The perimeter is %.2f", perimeter);
}

/* Main function calls to the arguments function and takes the name of the file containing the points of the polygon as an argument */
int main(int argc, char *argv[]) {
	arguments(argc, argv);
    	return 0;
}
