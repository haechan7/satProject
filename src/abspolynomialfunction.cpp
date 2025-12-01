#include "abspolynomialfunction.h"
double AbsPolynomialFunction::evaluate(double x){ 
    MyMath math;
    double absX = math.myFabs(x);
    double sum = 0;
    int power = coeffs.size() - 1;
    for (double c : coeffs) {
		sum += c * math.myPow(absX, power--); // 절대값 다항식 계산
    }
    return sum;
}