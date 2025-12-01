#define SDL_MAIN_HANDLED
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "renderer.h"
#include "functionfactory.h"

int main() {

	Function* func = FunctionFactory::createFunction(); // 함수 생성
	if (!func) return -1; // 함수 생성 실패 시 종료

	Renderer r; // 렌더러 객체 생성
	if (!r.init()) return -1; // 렌더러 초기화 실패 시 종료

    // 그래프 그리기
    r.drawAxes();
    r.drawTicks();
    r.plot(func);
    r.present();

    // 이벤트 대기 (그래프 유지)
    r.wait();

    // 종료 정리
    r.cleanup();
    delete func;

    return 0;
}