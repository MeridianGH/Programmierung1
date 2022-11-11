#include <stdlib.h>
#include <stdio.h>

void printMatrix(int matrix[4][4]) {
    for (int i = 0; i < 4; ++i) {
        printf("| ");
        for (int j = 0; j < 4; ++j) {
            printf(matrix[i][j] < 0 ? "" : " ");
            for (int k = 10; k <= 100; k *= 10) { printf(abs(matrix[i][j]) < k ? " " : ""); }
            printf("%d ", matrix[i][j]);
        }
        printf(" |\n");
    }
    printf("\n");
}

void multiplyMatrices(int a[4][4], int b[4][4]) {
    int result[4][4];
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            int sum = 0;
            for (int k = 0; k < 4; ++k) { sum += a[i][k] * b[k][j]; }
            result[i][j] = sum;
        }
    }
    printMatrix(result);
}

int main(void) {
    int a[4][4];
    int b[4][4];

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            a[i][j] = rand() % 21 - 10;
            b[i][j] = rand() % 21 - 10;
        }
    }

    printMatrix(a);
    printf("            *\n\n");
    printMatrix(b);
    printf("            =\n\n");
    multiplyMatrices(a, b);
}
