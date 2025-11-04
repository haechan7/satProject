#include "mymath.h"
double myMath::myPow(double base, int exp) {
    double result = 1.0;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}
double myMath::myFabs(double x) {
    if (x < 0) {
        return -x;
    }
    return x;
}
double myMath::mySqrt(double x) {
	// ´ºÅÏ-·¦½¼ ¹æ¹ýÀ» »ç¿ëÇÑ Á¦°ö±Ù °è»ê
    double num = x / 2;
    for(int i = 0; i < 100; i++) {
        num = 0.5 * (num + x / num);
	}
    return num;
}