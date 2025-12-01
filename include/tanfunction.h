#pragma once
#include "function.h"
#include <array>
class TanFunction : public Function { // ÅºÁ¨Æ® ÇÔ¼ö Å¬·¡½º
private:
    std::array<double, 3> coeffs;
public:
    TanFunction(const std::array<double, 3>& c) : coeffs(c) {}

    double evaluate(double x) override;
};
