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

		TEST_METHOD(isTriangleValidFunctionality) {
			bool status = isTriangleValid(9, 2, 8);
			Assert::AreEqual(true, status);
		}

		TEST_METHOD(getTriangleAngleFunctionality) {
			double* angles = getTriangleAngle(9, 2, 8);
			int expectedAngles[3] = {113, 11, 54};
			Assert::AreEqual((int)angles[0], expectedAngles[0]);
			Assert::AreEqual((int)angles[1], expectedAngles[1]);
			Assert::AreEqual((int)angles[2], expectedAngles[2]);
		}

		TEST_METHOD(overallTriangleFunctionality) {
			char* result = analyzeTriangle(9, 2, 8);
			char* expected = {"Scalene triangle"};

			Assert::AreEqual(result, expected);
		}

		//Rectangle Test Cases

		TEST_METHOD(findRectangleCornersFunctionality) {
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

		TEST_METHOD(findRectangleAreaFunctionality) {
			double length = 3;
			double height = 4;

			double result = findRectangleArea(length, height);
			double expected = 12;

			Assert::AreEqual(result, expected);
		}

		TEST_METHOD(findRectanglePerimeterFunctionality) {
			double length = 3;
			double height = 4;

			double result = findRectanglePerimeter(length, height);
			double expected = 14;

			Assert::AreEqual(result, expected);
		}

	};
}
