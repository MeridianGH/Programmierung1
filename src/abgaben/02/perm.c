#include <stdio.h>

int main(void) {
    int count = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (j == i) { continue; }
            for (int k = 0; k < 4; ++k) {
                if (k == i || k == j) { continue; }
                for (int l = 0; l < 4; ++l) {
                    if (l == k || l == j || l == i) { continue; }
                    printf("{ %d, %d, %d, %d } | ", i, j, k, l);
                    count += 1;
                }
            }
        }
        printf("\n");
    }
    printf("Count: %d", count);
}
