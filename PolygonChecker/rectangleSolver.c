#include "rectangleSolver.h"

bool analyzeRectangle(double length, double height) {
	bool result;
	if (length < 0 || height < 0) {
		printf("\nNot a rectangle. Please enter anew set of points:");
		result = false;
	}
	else if ( length == height) {
		printf("\nA square was successfully formed.");
		result = true;
	}
	else {
		printf("\nA rectangle was successfully formed.");
		result = true;
	}
	return result;
}

int* findRectangleCorners(int points[]) {
	int corners[8];			// Spots 0 and 1 ae the top left corner, 2 and 3 are the top right corner,
							// 4 and 5 are the bottom left corner, 6 and 7 are the bottom right corner.
	double rectangleMidPoint[2];
	rectangleMidPoint[0] = ((points[0] + points[2] + points[4] + points[6]) / 4);
	rectangleMidPoint[1] = ((points[1] + points[3] + points[5] + points[7]) / 4);

	for (int i = 0; i < 8; i++) {
		points[i] = points[i] * 1;
	}

	for (int i = 0; i <= 6; i+=2) {
		if (points[i] < rectangleMidPoint[0] && points[i+1] > rectangleMidPoint[1]) {
			corners[0] = points[i];
			corners[1] = points[i + 1];
		} else if (points[i] > rectangleMidPoint[0] && points[i+1] > rectangleMidPoint[1]) {
			corners[2] = points[i];
			corners[3] = points[i + 1];
		} else if (points[i] < rectangleMidPoint[0] && points[i+1] < rectangleMidPoint[1]) {
			corners[4] = points[i];
			corners[5] = points[i + 1];
		} else {
			corners[6] = points[i];
			corners[7] = points[i + 1];
		}
	}
	return corners;
}

double findRectanglePerimeter(double length, double height) {
	double perimeter = 2 * (length + height);
	printf("\nThe perimeter of the rectangle is: %lf", perimeter);
	return perimeter;
}

double findRectangleArea(double length, double height) {
	double area = length * height;
	printf("\nThe area of the rectangle is: %lf", area);
	return area;
}