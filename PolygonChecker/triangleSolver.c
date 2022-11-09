#define PI 3.1415926

#include "triangleSolver.h"

char* analyzeTriangle(int side1, int side2, int side3) {
	char* result = "";
	if (side1 <= 0 || side2 <= 0 || side3 <= 0) { 
		result = "Not a triangle";				
	}
	else if (side1 == side2 && side1 == side3) {
		result = "Equilateral triangle";	
	}
	else if ((side1 == side2 && side1 != side3) || 
		(side1 == side3 && side1 != side2))
	{
		result = "Isosceles triangle";
	}
	else {
		result = "Scalene triangle";
	}

	return result;
}

bool isTriangleValid(int side1, int side2, int side3) {
	bool status = false;
	if (side1 + side2 > side3 && side1 + side3 > side2 && side2 + side3 > side1)
	{
		status = true;
	}
	return status;
}
void getTriangleAngle(int side1, int side2, int side3) {
	double triangleAngles[MAXARRAYSIZE];

	triangleAngles[0] = acos((pow(side2, 2) + pow(side3, 2) - pow(side1, 2)) / (2 * side2 * side3)) * 180 / PI;
	
	triangleAngles[1] = acos((pow(side1, 2) + pow(side3, 2) - pow(side2, 2)) / (2 * side1 * side3)) * 180 / PI;

	triangleAngles[2] = acos((pow(side1, 2) + pow(side2, 2) - pow(side3, 2)) / (2 * side1 * side2)) * 180 / PI;

	printf("A: %lf B: %lf C: %lf\n", triangleAngles[0], triangleAngles[1], triangleAngles[2]);

}