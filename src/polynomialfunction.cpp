#include "polynomialfunction.h"
#include "mymath.h"
double PolynomialFunction::evaluate(double x) {
    MyMath math;
    double sum = 0;
    int power = coeffs.size() - 1;
    for (double c : coeffs) {
		sum += c * math.myPow(x, power--); // 다항식 계산
    }
    return sum;
}