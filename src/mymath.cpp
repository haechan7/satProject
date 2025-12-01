#include "mymath.h"
double MyMath::myPow(double base, int exp) {
    double result = 1.0;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}
double MyMath::myFabs(double x) {
    if (x < 0) {
        return -x;
    }
    return x;
}
double MyMath::mySqrt(double x) {
	// 뉴턴-랩슨 방법을 사용한 제곱근 계산
    double num = x / 2;
    for(int i = 0; i < 100; i++) {
        num = 0.5 * (num + x / num);
	}
    return num;
}
double MyMath::mySin(double x) {
    // 테일러 급수를 사용한 사인 계산
    double term = x; // 첫 번째 항
    double sum = term;
    for (int n = 1; n < 1000; n++) {
        term *= -x * x / ((2 * n) * (2 * n + 1));
        sum += term;
    }
    return sum;
}
double MyMath::myCos(double x) {
    // 테일러 급수를 사용한 코사인 계산
    double term = 1; // 첫 번째 항
    double sum = term;
    for (int n = 1; n < 1000; n++) {
        term *= -x * x / ((2 * n - 1) * (2 * n));
        sum += term;
    }
    return sum;
}
double MyMath::myTan(double x) {
    // 사인과 코사인을 사용한 탄젠트 계산
    double sinx = mySin(x);
    double cosx = myCos(x);
    if (cosx == 0) {
        // 코사인이 0일 때는 정의되지 않음
        return 0; // 또는 적절한 오류 처리
    }
    return sinx / cosx;
}