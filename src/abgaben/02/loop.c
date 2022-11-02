#include <stdio.h>

int main(void) {
    for (int i = 0; i < 100; ++i) {
        printf("%0.1f\n", 1 + (float)(int)(i * (1.0/3.0) * 100) / 100);
        // Below is a more reliable way that uses round from math.h
        // printf("%0.1f\n", 1 + round(i * (1.0/3.0) * 100) / 100);
    }
}