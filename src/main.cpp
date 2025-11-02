#define SDL_MAIN_HANDLED
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <SDL.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

double myPow(double base, int exp) {
    double result = 1.0;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

double myFabs(double x) {
    if(x < 0) {
        return -x;
	}
	return x;
}
int main(int argc, char* argv[]) {
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
    

    // SDL 초기화
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Graph", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // 배경을 흰색으로
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    // 검은색으로 선 그리기
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    // 배경색
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    // 축 색상 (회색)
    SDL_SetRenderDrawColor(renderer, 150, 150, 150, 255);
    SDL_RenderDrawLine(renderer, 0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2); // x축
    SDL_RenderDrawLine(renderer, SCREEN_WIDTH / 2, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT);   // y축

    // 그래프 색상 (검정)
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    // 그래프 루프 시작

    // 그래프 그리기
    for (int px = 0; px < SCREEN_WIDTH; px++) {
        double x = (px - SCREEN_WIDTH / 2.0) / 80.0; // x: -5 ~ 5
        double sum = 0;
        switch(choice){
		    case 1: // 다항함수
                for (int j = i - 1; j >= 0; j--) {
                    sum += coeffs[-j + i - 1] * myPow(x, j);
                }
                break;
			case 2: // 절대값 함수
                for (int j = i - 1; j >= 0; j--) {
                    sum += coeffs[-j + i - 1] * myPow(myFabs(x), j);
				}
        }
        double y = sum;                               // y = x^2
        int py = SCREEN_HEIGHT / 2 - (int)(y * 20);  // y축 변환

        if (py >= 0 && py < SCREEN_HEIGHT) {
            SDL_RenderDrawPoint(renderer, px, py);
        }
    }

    SDL_RenderPresent(renderer);  // 그린 걸 화면에 보여주기

    // 이벤트 루프
    SDL_Event e;
    int quit = 0;
    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) quit = 1;
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
