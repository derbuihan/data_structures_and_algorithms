#include <stdio.h>

int main() {
    int A[5];

    int B[5] = {2, 4, 6, 8, 10};

    int C[10] = {2, 4, 6};// {2, 4, 6, 0, 0, 0, 0, 0, 0, 0}

    int D[5] = {0};// {0, 0, 0, 0, 0}

    int E[] = {2, 4, 6, 8, 10};// E[5]


    for (int i = 0; i < 5; i++)
        printf("%u ", &A[i]);

    return 0;
}
