#pragma once
#include "SDL.h"
#include "mymath.h"
#include "function.h"
class Renderer {
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    double scale; // 확대/축소 값

public:
    Renderer(double scale = 50.0);
    bool init();
    void drawAxes();
    void drawTicks();
    void plot(Function *func);
    void present();
    void wait();
    void cleanup();
};