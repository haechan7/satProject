#include "renderer.h"
#include <iostream>

Renderer::Renderer(int width, int height, double scale)
    : window(nullptr), renderer(nullptr), screenWidth(width), screenHeight(height), scale(scale) {
}

bool Renderer::init() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) return false;

    window = SDL_CreateWindow("Function Grapher",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        screenWidth, screenHeight, SDL_WINDOW_SHOWN);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    return (window && renderer);
}

void Renderer::drawAxes() {
    SDL_SetRenderDrawColor(renderer, 150, 150, 150, 255);

    // XÃà
    SDL_RenderDrawLine(renderer, 0, screenHeight / 2, screenWidth, screenHeight / 2);
    // YÃà
    SDL_RenderDrawLine(renderer, screenWidth / 2, 0, screenWidth / 2, screenHeight);
}

void Renderer::drawTicks() {
    SDL_SetRenderDrawColor(renderer, 180, 180, 180, 255);

    int centerX = screenWidth / 2;
    int centerY = screenHeight / 2;

    // XÃà ´«±Ý
    for (int x = centerX; x < screenWidth; x += (int)scale) {
        SDL_RenderDrawLine(renderer, x, centerY - 5, x, centerY + 5);
    }
    for (int x = centerX; x > 0; x -= (int)scale) {
        SDL_RenderDrawLine(renderer, x, centerY - 5, x, centerY + 5);
    }

    // YÃà ´«±Ý
    for (int y = centerY; y < screenHeight; y += (int)scale) {
        SDL_RenderDrawLine(renderer, centerX - 5, y, centerX + 5, y);
    }
    for (int y = centerY; y > 0; y -= (int)scale) {
        SDL_RenderDrawLine(renderer, centerX - 5, y, centerX + 5, y);
    }
}

void Renderer::drawFunction(int* coeffs, int count, int choice, myMath& math) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    for (int px = 0; px < screenWidth; px++) {
        double x = (px - screenWidth / 2.0) / scale;
        double sum = 0;

        for (int j = count - 1; j >= 0; j--) {
            double value = (choice == 2) ? math.myFabs(x) : x;
            sum += coeffs[-j + count - 1] * math.myPow(value, j);
        }

        int py = screenHeight / 2 - (int)(sum * scale);

        if (py >= 0 && py < screenHeight)
            SDL_RenderDrawPoint(renderer, px, py);
    }
}

void Renderer::present() {
    SDL_RenderPresent(renderer);
}

void Renderer::wait() {
    SDL_Event e;
    bool quit = false;

    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) quit = true;
        }
    }
}

void Renderer::cleanup() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}