#pragma once
#include "function.h"
#include <vector>
class PolynomialFunction : public Function { // 다항 함수 클래스
private:
    std::vector<double> coeffs;
public:
    PolynomialFunction(const std::vector<double>& c) : coeffs(c) {}

    double evaluate(double x) override;
};