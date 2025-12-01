#include "cosfunction.h"
#include "mymath.h"
double CosFunction::evaluate(double x) {
	MyMath math;
	double sum;
	sum = coeffs.at(0) * math.myCos(x * coeffs.at(1)) + coeffs.at(2); // 코사인 함수 계산

	return sum;
}