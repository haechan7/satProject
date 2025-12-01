#pragma once
#include "function.h"
#include <array>
class SinFunction : public Function { // 사인 함수 클래스
private:
    std::array<double, 3> coeffs;
public:
    SinFunction(const std::array<double, 3>& c) : coeffs(c) {}

    double evaluate(double x) override;
};