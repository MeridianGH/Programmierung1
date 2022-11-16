#include <stdio.h>
#include <limits.h>

// DISCLAIMER: %llu doesn't compile under Windows when using "-Werror". This program works and compiles without errors if I omit the flag.
// Should this not compile under Linux, please replace all occurrences of "%llu" with "%d" and cast the values to "(int)".
// This will however obviously print wrong values.

// Define commonly used type.
typedef unsigned long long ull;

ull binomCoef(int n, int k) {
    // Return trivial case.
    if (n < k) { return 0; }
    // Create empty Pascal's triangle.
    ull c[n + 1][k + 1];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            c[i][j] = 0;
        }
    }
    // Fill triangle using addition.
    for (int i = 0; i <= n; i++) {
        // Fill to smaller of i or k, so we don't calculate unnecessary values.
//        printf("%*s", 4 * (n - i),  ""); // Uncomment to print Pascal's triangle.
        for(int j = 0; j <= (i < k ? i : k); j++) {
            if(j == 0 || j == i) {
                // Set edges to 1.
                c[i][j] = 1;
            } else {
                // Calculate value using two values of previous line.
                ull prev1 = c[i-1][j-1];
                ull prev2 = c[i-1][j];
                if (prev1 > ULONG_LONG_MAX - prev2) { return 0; }
                c[i][j] = prev1 + prev2;
            }
//            printf(" %6llu ", c[i][j]); // Uncomment to print Pascal's triangle.
        }
//        printf("\n"); // Uncomment to print Pascal's triangle.
    }
    return c[n][k];
}

int main(void) {
    printf("%llu\n", binomCoef(18, 8));

    int n = 0;
    ull result = 1;
    while (result != 0) {
        // The binomial coefficient will be the largest, when we use (n, ⌊n/2⌋).
        // C implicitly rounds down when we divide two integers.
        // If we can compute this value successfully, all other values for this n will be computable as well, as they are guaranteed to be lower.
        n++;
        result = binomCoef(n, (n / 2));
    }
    printf("Largest possible a: %d\n", n - 1); // Subtract 1 as we add one too many with the last loop.
}
