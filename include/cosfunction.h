#pragma once
#include "function.h"
#include <array>
class CosFunction : public Function { // 코사인 함수 클래스
private:
    std::array<double, 3> coeffs;
public:
    CosFunction(const std::array<double, 3>& c) : coeffs(c) {}

    double evaluate(double x) override;
};
