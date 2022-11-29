#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "triangleSolver.h"
#include "rectangleSolver.h"
#include "math.h"

int side = 0;

int main() {
	bool continueProgram = true;
	int* corners;
	double* sides;
	while (continueProgram) {
		printWelcome();

		int shapeChoice = printShapeMenu();

		switch (shapeChoice)
		{
		case 1:
			printf_s("Triangle selected.\n");
			int triangleSides[3] = { 0, 0, 0 };
			int* triangleSidesPtr = getTriangleSides(triangleSides);
			bool triangleStatus = isTriangleValid(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			while (triangleStatus != true) {
				printf("\nTriangle was not valid.\n");
				triangleSidesPtr = getTriangleSides(triangleSides);
				triangleStatus = isTriangleValid(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			}
			printf("A triangle was succesfully formed\n");
			getTriangleAngle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			char* triangleResult = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			printf_s("%s\n", triangleResult);
			break;
		case 2:
			printf("Rectangle selected.\n");
			int rectanglePoints[8];
			int* rectanglePointsPtr = getRectanglePoints(rectanglePoints);

			corners = findRectangleCorners(rectanglePointsPtr);

			double sides[2];
			sides[0] = sqrt(pow((corners[6] - corners[4]), 2) + pow((corners[7] - corners[5]), 2));
			printf("\nLength: %lf", sides[0]);
			sides[1] = sqrt((pow((corners[0] - corners[4]), 2)) + (pow((corners[1] - corners[5]), 2)));
			printf("\nHeight: %lf", sides[1]);

			bool rectangleStatus = analyzeRectangle(sides[0], sides[1]);
			while (rectangleStatus != true) {
				rectanglePointsPtr = getRectanglePoints(rectanglePoints);
				corners = findRectangleCorners(rectanglePointsPtr);;
				sides[0] = sqrt(pow((corners[6] - corners[4]), 2) + pow((corners[7] - corners[5]), 2));
				printf("\nLength: %lf", sides[0]);
				sides[1] = sqrt((pow((corners[2] - corners[0]), 2)) + (pow((corners[3] - corners[1]), 2)));
				printf("\nHeight: %lf", sides[1]);
				rectangleStatus = analyzeRectangle(sides[0], sides[1]);
			}
			findRectanglePerimeter(sides[0], sides[1]);
			findRectangleArea(sides[0], sides[1]);
			break;
		case 0:
			continueProgram = false;
			break;
		case '\n':
			break;
		default:
			printf_s("Invalid value entered.\n");
			break;
		}
	}
	return 0;
}

void printWelcome() {
	printf_s("\n");
	printf_s(" **********************\n");
	printf_s("**     Welcome to     **\n");
	printf_s("**   Polygon Checker  **\n");
	printf_s(" **********************\n");
}

int printShapeMenu() {
	printf_s("1. Triangle\n");
	printf_s("2. Rectangle\n");
	printf_s("0. Exit\n");

	int shapeChoice;

	printf_s("Enter number: ");
	scanf_s("%d", &shapeChoice);

	return shapeChoice;
}

int* getTriangleSides(int* triangleSides) {
	printf_s("Enter the three sides of the triangle: ");
	for (int i = 0; i < 3; i++)
	{
		scanf_s("%d", &triangleSides[i]);
	}
	return triangleSides;
}

int* getRectanglePoints(int* rectanglePoints) {
	printf("Enter the coordinates of the corners of the rectangle (x value followed by y value)");
	fseek(stdin, 0, SEEK_END);
	for (int i = 0; i < 8; i++)
	{
		printf("\nenter: ");
		scanf_s("%d", &rectanglePoints[i]);
	}
	return rectanglePoints;
}

