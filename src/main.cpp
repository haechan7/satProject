#define SDL_MAIN_HANDLED
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <SDL.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

#include "mymath.h"
#include "renderer.h"

int main(int argc, char* argv[]) {
    myMath math;
    cout << "그래프를 그릴 함수의 번호를 입력하세요:" << endl
        << "1. 다항함수" << endl
        << "2. 절대값 함수" << endl
        // << 3. 삼각함수 << endl
        // << 4. 지수함수 << endl
        // << 5. 로그함수 << endl
        << "번호 :";
    int choice;
    int coeffs[100];
    cin >> choice;
    int i = 0;
    switch (choice) {
    case 1:
        cout << "다항함수를 선택하셨습니다." << endl
            << "항 순서대로 계수를 입력하세요." << endl
            << "입력이 끝나면 \"-9999\"를 입력하세요." << endl
            << "ex) x^2 + 2x + 1 => 1 2 1" << endl;
        while ((cin >> coeffs[i]) && (coeffs[i] != -9999)) {
            i++;
        }
        break;
    case 2:
        cout << "절대값 함수를 선택하셨습니다." << endl
            << "항 순서대로 계수를 입력하세요." << endl
            << "입력이 끝나면 \"-9999\"를 입력하세요." << endl
            << "ex) |x|^2 + 2|x| + 1 => 1 2 1" << endl;
        while ((cin >> coeffs[i]) && (coeffs[i] != -9999)) {
            i++;
        }
        break;
    }

    Renderer r;
    if (!r.init()) return -1;

    r.drawAxes();
    r.drawTicks();
    r.drawFunction(coeffs, i, choice, math);
    r.present();
    r.wait();
    r.cleanup();

    return 0;
}
