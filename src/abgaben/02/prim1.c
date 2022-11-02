#include <stdio.h>

const int n = 150;

int main(void) {
    for (int i = 1; i < n; ++i) {
        for (int j = 2; j < i; ++j) {
            if (i % j == 0) { break; }
            if (j == i - 1) { printf("%d\n", i); }
        }
    }
}