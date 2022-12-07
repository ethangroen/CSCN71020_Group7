#include "pch.h"
#include "CppUnitTest.h"
#include <stdbool.h>

extern "C" int* findRectangleCorners(int[]);
extern "C" double findRectanglePerimeter(double, double);
extern "C" double  findRectangleArea(double, double);

extern "C" bool isTriangleValid(int, int, int);
extern "C" double* getTriangleAngle(int, int, int);
extern "C" char* analyzeTriangle(int, int, int);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestCases
{
	TEST_CLASS(TestCases)
	{
	public:
		
		//Triangle Test Cases

		TEST_METHOD(isTriangleValidFunctionality_01) {
			bool status = isTriangleValid(9, 2, 8);
			Assert::AreEqual(true, status);
		}

		TEST_METHOD(isTriangleValidFunctionality_02) {
			bool status = isTriangleValid(7, 7, 7);
			Assert::AreEqual(true, status);
		}

		TEST_METHOD(isTriangleValidFunctionality_03) {
			bool status = isTriangleValid(10, 5, 1);
			Assert::AreEqual(false, status);
		}

		TEST_METHOD(isTriangleValidFunctionality_04) {
			bool status = isTriangleValid(34, 123, 8);
			Assert::AreEqual(false, status);
		}



		TEST_METHOD(getTriangleAngleFunctionality_01) {
			double* angles = getTriangleAngle(9, 2, 8);
			int expectedAngles[3] = {113, 11, 54};
			Assert::AreEqual((int)angles[0], expectedAngles[0]);
			Assert::AreEqual((int)angles[1], expectedAngles[1]);
			Assert::AreEqual((int)angles[2], expectedAngles[2]);
		}

		TEST_METHOD(getTriangleAngleFunctionality_02) {
			double* angles = getTriangleAngle(7, 7, 7);
			int expectedAngles[3] = { 60, 60, 60 };
			Assert::AreEqual((int)angles[0], expectedAngles[0]);
			Assert::AreEqual((int)angles[1], expectedAngles[1]);
			Assert::AreEqual((int)angles[2], expectedAngles[2]);
		}

		TEST_METHOD(getTriangleAngleFunctionality_03) {
			double* angles = getTriangleAngle(100, 51, 50);
			int expectedAngles[3] = { 163, 8, 7 };
			Assert::AreEqual((int)angles[0], expectedAngles[0]);
			Assert::AreEqual((int)angles[1], expectedAngles[1]);
			Assert::AreEqual((int)angles[2], expectedAngles[2]);
		}

		TEST_METHOD(getTriangleAngleFunctionality_04) {
			double* angles = getTriangleAngle(15, 7, 9);
			int expectedAngles[3] = { 138, 17, 23 };
			Assert::AreEqual((int)angles[0], expectedAngles[0]);
			Assert::AreEqual((int)angles[1], expectedAngles[1]);
			Assert::AreEqual((int)angles[2], expectedAngles[2]);
		}



		TEST_METHOD(analyzeTriangleFunctionality_01) {
			char* result = analyzeTriangle(9, 2, 8);
			char* expected = {"Scalene triangle"};

			Assert::AreEqual(result, expected);
		}

		TEST_METHOD(analyzeTriangleFunctionality_02) {
			char* result = analyzeTriangle(7, 7, 7);
			char* expected = { "Equilateral triangle" };

			Assert::AreEqual(result, expected);
		}

		TEST_METHOD(analyzeTriangleFunctionality_03) {
			char* result = analyzeTriangle(10, 10, 8);
			char* expected = { "Isosceles triangle" };

			Assert::AreEqual(result, expected);
		}

		TEST_METHOD(analyzeTriangleFunctionality_04) {
			char* result = analyzeTriangle(12, 27, 0);
			char* expected = { "Not a triangle" };

			Assert::AreEqual(result, expected);
		}



		//Rectangle Test Cases

		TEST_METHOD(findRectangleCornersFunctionality_01) {
			int points[8] = {1, 4, 4, 4, 1, 8, 4, 8};
			int* result = findRectangleCorners(points);
			int expected[8] = {1, 8, 4, 8, 1, 4, 4, 4};

			Assert::AreEqual(result[0], expected[0]);
			Assert::AreEqual(result[1], expected[1]);
			Assert::AreEqual(result[2], expected[2]);
			Assert::AreEqual(result[3], expected[3]);
			Assert::AreEqual(result[4], expected[4]);
			Assert::AreEqual(result[5], expected[5]);
			Assert::AreEqual(result[6], expected[6]);
			Assert::AreEqual(result[7], expected[7]);
		}

		TEST_METHOD(findRectangleCornersFunctionality_02) {
			int points[8] = { 0, 0, 0, 5, 5, 5, 5, 0 };
			int* result = findRectangleCorners(points);
			int expected[8] = { 0, 5, 5, 5, 0, 0, 5, 0 };

			Assert::AreEqual(result[0], expected[0]);
			Assert::AreEqual(result[1], expected[1]);
			Assert::AreEqual(result[2], expected[2]);
			Assert::AreEqual(result[3], expected[3]);
			Assert::AreEqual(result[4], expected[4]);
			Assert::AreEqual(result[5], expected[5]);
			Assert::AreEqual(result[6], expected[6]);
			Assert::AreEqual(result[7], expected[7]);
		}

		TEST_METHOD(findRectangleCornersFunctionality_03) {
			int points[8] = { 1, 6, 1, 12, 10, 12, 10, 6 };
			int* result = findRectangleCorners(points);
			int expected[8] = { 1, 12, 10, 12, 1, 6, 10, 6 };

			Assert::AreEqual(result[0], expected[0]);
			Assert::AreEqual(result[1], expected[1]);
			Assert::AreEqual(result[2], expected[2]);
			Assert::AreEqual(result[3], expected[3]);
			Assert::AreEqual(result[4], expected[4]);
			Assert::AreEqual(result[5], expected[5]);
			Assert::AreEqual(result[6], expected[6]);
			Assert::AreEqual(result[7], expected[7]);
		}

		TEST_METHOD(findRectangleCornersFunctionality_04) {
			int points[8] = { 1, 1, 1, 6, 6, 6, 6, 1 };
			int* result = findRectangleCorners(points);
			int expected[8] = { 1, 6, 6, 6, 1, 1, 6, 1 };

			Assert::AreEqual(result[0], expected[0]);
			Assert::AreEqual(result[1], expected[1]);
			Assert::AreEqual(result[2], expected[2]);
			Assert::AreEqual(result[3], expected[3]);
			Assert::AreEqual(result[4], expected[4]);
			Assert::AreEqual(result[5], expected[5]);
			Assert::AreEqual(result[6], expected[6]);
			Assert::AreEqual(result[7], expected[7]);
		}



		TEST_METHOD(findRectangleAreaFunctionality_01) {
			double length = 3;
			double height = 4;

			double result = findRectangleArea(length, height);
			double expected = 12;

			Assert::AreEqual(result, expected);
		}

		TEST_METHOD(findRectangleAreaFunctionality_02) {
			double length = 12;
			double height = 12;

			double result = findRectangleArea(length, height);
			double expected = 144;

			Assert::AreEqual(result, expected);
		}

		TEST_METHOD(findRectangleAreaFunctionality_03) {
			double length = 1;
			double height = 32;

			double result = findRectangleArea(length, height);
			double expected = 32;

			Assert::AreEqual(result, expected);
		}

		TEST_METHOD(findRectangleAreaFunctionality_04) {
			double length = 1000;
			double height = 2;

			double result = findRectangleArea(length, height);
			double expected = 2000;

			Assert::AreEqual(result, expected);
		}



		TEST_METHOD(findRectanglePerimeterFunctionality_01) {
			double length = 3;
			double height = 4;

			double result = findRectanglePerimeter(length, height);
			double expected = 14;

			Assert::AreEqual(result, expected);
		}

		TEST_METHOD(findRectanglePerimeterFunctionality_02) {
			double length = 13;
			double height = 42;

			double result = findRectanglePerimeter(length, height);
			double expected = 110;

			Assert::AreEqual(result, expected);
		}

		TEST_METHOD(findRectanglePerimeterFunctionality_03) {
			double length = 10;
			double height = 4;

			double result = findRectanglePerimeter(length, height);
			double expected = 28;

			Assert::AreEqual(result, expected);
		}

		TEST_METHOD(findRectanglePerimeterFunctionality_04) {
			double length = 7.5;
			double height = 5.7;

			double result = findRectanglePerimeter(length, height);
			double expected = 26.4;

			Assert::AreEqual(result, expected);
		}
	};
}
