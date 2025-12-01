#pragma once
#include "function.h"
#include <vector>
#include "mymath.h"
class AbsPolynomialFunction : public Function { // 절대값 다항 함수 클래스
private:
    std::vector<double> coeffs;
public:
    AbsPolynomialFunction(const std::vector<double>& c) : coeffs(c) {}

    double evaluate(double x) override; 
};