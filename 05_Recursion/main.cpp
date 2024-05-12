#include <stdio.h>


void func1(int n) {
    if (n > 0) {
        printf("%d ", n);
        func1(n - 1);
        func1(n - 1);
    }
}
void func2(int n) {
    if (n > 0) {
        func2(n - 1);
        printf("%d ", n);
        func2(n - 1);
    }
}

void func3(int n) {
    if (n > 0) {
        func3(n - 1);
        func3(n - 1);
        printf("%d ", n);
    }
}

int func(int n) {
    if (n > 100) {
        return n - 10;
    }
    return func(func(n + 11));
}

float e(float x, float n) {
    static float p = 1, f = 1;
    float r;

    if (n == 0) {
        return 1;
    }

    r = e(x, n - 1);
    p *= x;
    f *= n;
    return r + p / f;
}


float e_(float x, float n, float p = 1, float f = 1) {
    if (n == 0) {
        return 1;
    }

    float r = e_(x, n - 1, p * x, f * n);
    return r + p / f;
}

int main() {
    float x = e(1, 100);
    printf("x = %f\n", x);
    float y = e_(1, 100);
    printf("x = %f\n", y);

    return 0;
}
