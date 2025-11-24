#pragma once
#include <SDL.h>
#include "mymath.h"

class Renderer {
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    int screenWidth;
    int screenHeight;
    double scale; // 확대/축소 값

public:
    Renderer(int width = 800, int height = 600, double scale = 50.0);
    bool init();
    void drawAxes();
    void drawTicks();
    void drawFunction(int* coeffs, int count, int choice, myMath& math);
    void present();
    void wait();
    void cleanup();
};
