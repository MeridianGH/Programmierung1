#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int result = 0;
    for (int i = 0; i < 10; ++i) { result += rand() % 6 + 1; }
    printf("%d", result);
}