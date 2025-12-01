#include "functionfactory.h"
using namespace std;

vector<double> FunctionFactory::inputCoefficients() { // 다항함수 계수 입력
    vector<double> coeffs;
    cout << "항 순서대로 계수를 입력하세요." << endl
        << "입력이 끝나면 -9999를 입력하세요." << endl
        << "예: x^2 + 2x + 1 => 1 2 1" << endl;

    int num;
    while ((cin >> num) && num != -9999)
        coeffs.push_back(num);

    return coeffs;
}

array<double, 3> FunctionFactory::inputTrigCoefficients() { // 삼각함수 계수 입력
    array<double, 3> values;
    cout << "(a)f(bx) + c 형태로 a, b, c를 입력하세요:" << endl;
    for (int i = 0; i < 3; i++) {
        cin >> values[i];
    }
    return values;
}

Function* FunctionFactory::createFunction() { // 함수 생성
    cout << "그래프를 그릴 함수의 번호를 입력하세요:" << endl
        << "1. 다항함수" << endl
        << "2. 절대값 함수" << endl
        << "3. 삼각함수" << endl
        << "번호 :";
    int choice;
    cin >> choice;

    switch (choice) {

    case 1: {
        cout << "다항함수를 선택하셨습니다.";
        auto coeffs = inputCoefficients();
        return new PolynomialFunction(coeffs);
    }

    case 2: {
        cout << "절대값 함수를 선택하셨습니다.";
        auto coeffs = inputCoefficients();
        return new AbsPolynomialFunction(coeffs);
    }

    case 3: {
        cout << "삼각 함수를 선택하셨습니다."
            << "1. sin" << endl
            << "2. cos" << endl
            << "3. tan" << endl
            << "번호를 입력하세요: ";

        int triSelect;
        cin >> triSelect;

        // 잘못된 선택 처리
        if ((triSelect < 1) || (triSelect > 3)) {
            cout << "잘못된 번호입니다." << endl;
            return nullptr;
        }
        auto params = inputTrigCoefficients();

        switch (triSelect) {
        case 1: return new SinFunction(params);
        case 2: return new CosFunction(params);
        case 3: return new TanFunction(params);
        }
    }

    default:
        cout << "잘못된 선택입니다." << endl;
        return nullptr;
    }
}
