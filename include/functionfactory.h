#pragma once
#include "function.h"
#include "polynomialfunction.h"
#include "abspolynomialfunction.h"
#include "sinfunction.h"
#include "cosfunction.h"
#include "tanfunction.h"
#include <vector>
#include <array>
#include <iostream>

class FunctionFactory { // 함수 생성 팩토리 클래스
public:
	static Function* createFunction(); 
private:
	static std::vector<double> inputCoefficients(); 
    static std::array<double, 3> inputTrigCoefficients();
};