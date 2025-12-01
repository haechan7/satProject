#define SDL_MAIN_HANDLED
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "SDL.h"

#include "mymath.h"
#include "renderer.h"
#include "function.h"
#include "polynomialfunction.h"
#include "abspolynomialfunction.h"
#include "sinfunction.h"
#include "cosfunction.h"
#include "tanfunction.h"
#include <vector>
#include <array>


int main(int argc, char* argv[]) {
    cout << "그래프를 그릴 함수의 번호를 입력하세요:" << endl
        << "1. 다항함수" << endl
        << "2. 절대값 함수" << endl
        << "3. 삼각함수" << endl
        // << 4. 지수함수 << endl
        // << 5. 로그함수 << endl
        << "번호 :";
    int choice;
    cin >> choice;
	int i = 0;
    vector<double> coeffs; // 계수를 저장할 벡터
    Function* func = nullptr;
    switch (choice) {
    case 1:
        cout << "다항함수를 선택하셨습니다." << endl
            << "항 순서대로 계수를 입력하세요." << endl
            << "입력이 끝나면 \"-9999\"를 입력하세요." << endl
            << "ex) x^2 + 2x + 1 => 1 2 1" << endl;

        while ((cin >> i) && (i != -9999)) {
			coeffs.push_back(i);
        }

        func = new PolynomialFunction(coeffs);

        break;
    case 2:
        cout << "절대값 함수를 선택하셨습니다." << endl
            << "항 순서대로 계수를 입력하세요." << endl
            << "입력이 끝나면 \"-9999\"를 입력하세요." << endl
            << "ex) |x|^2 + 2|x| + 1 => 1 2 1" << endl;

        while ((cin >> i) && (i != -9999)) {
            coeffs.push_back(i);
        }

        func = new AbsPolynomialFunction(coeffs);

        break;
    case 3:
        cout << "삼각 함수를 선택하셨습니다." << endl
            << "sin, cos, tan를 선택해 주세요 (sin = 1, cos = 2 tan = 3)" << endl
            << "번호: " << endl;
        array<double, 3> triCoeffs;
		int tri;
        cin >> tri;
        switch (tri) {
        case 1:
            cout << "sin을 선택하셨습니다." << endl
                << "(a)sin(b)x + (c) a b c를 입력해 주세요" << endl;
            for (int j = 0; j < 3; ++j) {
                cin >> triCoeffs[j];
            }
			func = new SinFunction(triCoeffs);
            break;
        case 2:
            cout << "cos을 선택하셨습니다." << endl
                << "(a)cos(b)x + (c) a b c를 입력해 주세요" << endl;
            for (int j = 0; j < 3; ++j) {
                cin >> triCoeffs[j];
            }
            func = new CosFunction(triCoeffs);
            break;
        case 3:
            cout << "tan을 선택하셨습니다." << endl
                << "(a)tan(b)x + (c) a b c를 입력해 주세요" << endl;
            for (int j = 0; j < 3; ++j) {
                cin >> triCoeffs[j];
            }
            func = new TanFunction(triCoeffs);
            break;
        default:
            cout << "잘못된 선택입니다." << endl;
            return -1;
        }
        
		break;
	default:
        cout << "잘못된 선택입니다." << endl;
		return -1;
    }

    Renderer r;
    if (!r.init()) return -1;

    r.drawAxes();
    r.drawTicks();
    r.plot(func);
    r.present();
    r.wait();
    r.cleanup();

	delete func;
    return 0;
}
