#include "sinfunction.h"
#include "mymath.h"
double SinFunction::evaluate(double x) {
	MyMath math;
	double sum;
	sum = coeffs.at(0) * math.mySin(x * coeffs.at(1)) + coeffs.at(2); // 사인 함수 계산

	return sum;
}