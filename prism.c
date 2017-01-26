#include <stdio.h> 
#include <math.h> 
/* User inputs the vertices of the 8 points around the prism in (x y z) format and is returned its surface area and volume as outputs */ 

//calculates distance between two points with (x y z) notation
double get_dist(double point1x, double point1y, double point1z, double point2x, double point2y, double point2z) { 
	double distance; 
	distance = sqrt(pow(point1x-point2x,2)+pow(point1y-point2y,2)+pow(point1z-point2z,	2)); 
	return distance; 
} 
//calculates area of one side of rectangular prism
double get_rect_area(double point1x, double point1y, double point1z, double point2x, double point2y, double point2z, double point3x, double point3y, double point3z, double point4x, double point4y, double point4z) {
	double distance1; 
	double distance2; 
	double area; 
	distance1 = get_dist(point1x, point1y, point1z, point2x, point2y, point2z); 
	distance2 = get_dist(point3x, point3y, point3z, point4x, point4y, point4z); 
	area = distance1 * distance2; 
	return area; 
} 
//calculates surface area of rectangular prism 
double get_surface_area(double point1x, double point1y, double point1z, double point2x, double point2y, double point2z, double point3x, double point3y, double point3z, double point4x, double point4y, double point4z, double point5x, double point5y, double point5z) { 
	double area1; 
	double area2; 
	double area3; 
	double totalarea; 
	area1 = get_rect_area(point1x, point1y, point1z, point2x, point2y, point2z, 		point2x, point2y, point2z, point3x, point3y, point3z); 
	area2 = get_rect_area(point1x, point1y, point1z, point2x, point2y, point2z, 		point4x, point4y, point4z, point5x, point5y, point5z); 
	area3 = get_rect_area(point2x, point2y, point2z, point3x, point3y, point3z, 		point4x, point4y, point4z, point5x, point5y, point5z); 
	totalarea = (2*area1)+(2*area2)+(2*area3); 
	return totalarea; 
} 
//calculates volume of rectangular prism 
double get_volume(double point1x, double point1y, double point1z, double point2x, double point2y, double point2z, double point3x, double point3y, double point3z, double point4x,
double point4y, double point4z, double point5x, double point5y, double point5z) { 
	double length; 
	double width; 
	double height;
	double volume; 
	length = get_dist(point1x, point1y, point1z, point2x, point2y, point2z);
	width = get_dist(point2x, point2y, point2z, point3x, point3y, point3z); 
	height = get_dist(point4x, point4y, point4z, point5x, point5y, point5z); 
	volume = length * width * height; 
	return volume; 
} 
//main program calls out to the get_surface_area and get_volume functions previously defined 	
int main(void) {
	double point1x;
	double point1y;
	double point1z; 
	double point2x;
        double point2y;
        double point2z;
        double point3x;
        double point3y;
        double point3z;
        double point4x;
        double point4y;
        double point4z;
        double point5x;
        double point5y;
        double point5z;
        double point6x;
        double point6y;
        double point6z;
        double point7x;
        double point7y;
        double point7z;
        double point8x;
        double point8y;
        double point8z;
	double surfacearea;
	double volumefinal;
	printf("Enter the first coordinate in the form x y z: ");
	scanf("%lf %lf %lf", &point1x, &point1y, &point1z);
        printf("Enter the second coordinate in the form x y z: ");
        scanf("%lf %lf %lf", &point2x, &point2y, &point2z);
        printf("Enter the third coordinate in the form x y z: ");
        scanf("%lf %lf %lf", &point3x, &point3y, &point3z);
        printf("Enter the fourth coordinate in the form x y z: ");
        scanf("%lf %lf %lf", &point4x, &point4y, &point4z);
        printf("Enter the fifth coordinate in the form x y z: ");
        scanf("%lf %lf %lf", &point5x, &point5y, &point5z);
        printf("Enter the sixth coordinate in the form x y z: ");
        scanf("%lf %lf %lf", &point6x, &point6y, &point6z);
        printf("Enter the seventh coordinate in the form x y z: ");
        scanf("%lf %lf %lf", &point7x, &point7y, &point7z);
        printf("Enter the eighth coordinate in the form x y z: ");
        scanf("%lf %lf %lf", &point8x, &point8y, &point8z);
	surfacearea = get_surface_area(point1x, point1y, point1z, point2x, point2y, 		point2z, point3x, point3y, point3z, point4x, point4y, point4z, point5x, point5y, 	point5z);
	printf("The surface area of the prism is %0.2lf\n", surfacearea);
	volumefinal = get_volume(point1x, point1y, point1z, point2x, point2y, point2z, 		point3x, point3y, point3z, point4x, point4y, point4z, point5x, point5y, point5z);
	printf("The volume of the prism is %0.2lf\n", volumefinal);
	return 0; 
}  

