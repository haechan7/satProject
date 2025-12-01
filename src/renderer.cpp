#include "renderer.h"
#include <iostream>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
Renderer::Renderer(double scale)
    : window(nullptr), renderer(nullptr), scale(scale) {
}

bool Renderer::init() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) return false;

    window = SDL_CreateWindow("Function Grapher",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    return (window && renderer);
}

void Renderer::drawAxes() {
    SDL_SetRenderDrawColor(renderer, 150, 150, 150, 255);

    // XÃà
    SDL_RenderDrawLine(renderer, 0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2);
    // YÃà
    SDL_RenderDrawLine(renderer, SCREEN_WIDTH / 2, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT);
}

void Renderer::drawTicks() {
    SDL_SetRenderDrawColor(renderer, 180, 180, 180, 255);

    int centerX = SCREEN_WIDTH / 2;
    int centerY = SCREEN_HEIGHT / 2;

    // XÃà ´«±Ý
    for (int x = centerX; x < SCREEN_WIDTH; x += (int)scale) {
        SDL_RenderDrawLine(renderer, x, centerY - 5, x, centerY + 5);
    }
    for (int x = centerX; x > 0; x -= scale) {
        SDL_RenderDrawLine(renderer, x, centerY - 5, x, centerY + 5);
    }

    // YÃà ´«±Ý
    for (int y = centerY; y < SCREEN_HEIGHT; y += (int)scale) {
        SDL_RenderDrawLine(renderer, centerX - 5, y, centerX + 5, y);
    }
    for (int y = centerY; y > 0; y -= scale) {
        SDL_RenderDrawLine(renderer, centerX - 5, y, centerX + 5, y);
    }
}

void Renderer::plot(Function *func) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    for (int px = 0; px < SCREEN_WIDTH; px++) {
        double x = (px - SCREEN_WIDTH / 2.0) / scale;
		double y = func->evaluate(x);
        int py = SCREEN_HEIGHT / 2 - (int)(y * (scale));

        if (py >= 0 && py < SCREEN_HEIGHT)
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