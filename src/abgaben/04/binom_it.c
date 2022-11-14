#include <stdio.h>

typedef unsigned long long ull;

ull binomCoef(ull n, ull k) {
    if (k > n) { return 0; }
    if (k == 0 || k == n) { return 1; }
    return binomCoef(n - 1, k - 1) + binomCoef(n - 1, k);
}

int main(void) {
    printf("%d", (int)binomCoef(756, 25));
}
