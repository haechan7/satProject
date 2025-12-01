#include "tanfunction.h"
#include "mymath.h"
double TanFunction::evaluate(double x) {
	MyMath math;
	double sum;
	sum = coeffs.at(0) * math.myTan(x * coeffs.at(1)) + coeffs.at(2); // ÅºÁ¨Æ® ÇÔ¼ö °è»ê

	return sum;
}