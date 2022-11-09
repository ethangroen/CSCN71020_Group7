#pragma once

#define MAXARRAYSIZE 3

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

char* analyzeTriangle(int side1, int side2, int side3);

bool isTriangleValid(int side1, int side2, int side3);

void getTriangleAngle(int side1, int side2, int side3);