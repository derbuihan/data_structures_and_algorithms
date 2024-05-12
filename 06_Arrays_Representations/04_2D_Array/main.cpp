#include <cstdio>
#include <cstdlib>

void print_array(int (*A)[4], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int A[3][4] = {{1, 2, 3, 4},
                   {2, 4, 6, 8},
                   {1, 3, 5, 7}};
    print_array(A, 3, 4);

    int *B[3];
    B[0] = (int *) malloc(4 * sizeof(int));
    B[1] = (int *) malloc(4 * sizeof(int));
    B[2] = (int *) malloc(4 * sizeof(int));
    free(B[0]);
    free(B[1]);
    free(B[2]);

    int **C;
    C = (int **) malloc(3 * sizeof(int *));
    C[0] = (int *) malloc(4 * sizeof(int));
    C[1] = (int *) malloc(4 * sizeof(int));
    C[2] = (int *) malloc(4 * sizeof(int));
    free(C[0]);
    free(C[1]);
    free(C[2]);
    free(C);

    return 0;
}
