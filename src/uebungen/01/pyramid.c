#include "stdio.h"

const int height = 5;
const int width = height * 2;

int main(void) {
    for (int i = 0; i < height; ++i) {
        if (i == height - 1) {
            for (int j = 0; j < width; ++j) { printf("."); }
            printf(" %d.\n", i);
            break;
        }
        for (int s1 = 0; s1 < (width / 2) - 1 - i; ++s1) { printf(" "); }; // First spaces
        printf(".");
        for (int s2 = 0; s2 < i * 2; ++s2) { printf(" "); } // Middle spaces
        printf(".");
        for (int s3 = 0; s3 < (width / 2) - 1 - i; ++s3) { printf(" "); } // End spaces
        printf(" %d.\n", i + 1);
    }

    return 0;
}