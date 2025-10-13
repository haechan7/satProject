#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <math.h>
double myfabs(double x) {
    if (x <= 0) {
        return -x;
    }
    else {
        return x;
    }
}

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

double func(double x) {
    return myfabs(x - 1);  // y = x^2
}

int main(int argc, char* argv[]) {
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
        double y = func(x);                          // y = x^2
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
