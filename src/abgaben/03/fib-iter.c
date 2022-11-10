#include <stdio.h>
#include <limits.h>

unsigned long long fib(int n) {
    if (n <= 1) { return n; }
    unsigned long long prev1 = 1; // n - 1
    unsigned long long prev2 = 0; // n - 2
    unsigned long long fib;
    for (int i = 1; i < n; ++i) {
        if (prev1 > ULONG_LONG_MAX - prev2) { return 4; } // Addition would result in overflow.
        fib = prev1 + prev2;
        prev2 = prev1;
        prev1 = fib;
    }
    return fib;
}

int main(void) {
    // I'm having difficulties getting this to compile properly on Windows.
    // If this doesn't compile, try with %d and cast to int.
    // Same goes for the print statement below.
    // If you cast to int, make sure to change the limit above to INT_MAX.
    printf("%llu\n", fib(7)); // 7th Fibonacci number

    // Calculate maximum possible Fibonacci number.
    printf("Calculating increasing Fibonacci numbers:\n");
    int i = 0;
    while (1) {
        unsigned long long result = fib(i);
        if (result == 4) { break; } // 4 is the first number not in the sequence, so I use it as the code for an overflow.
        ++i;
        printf("%d: %llu\n", i, result);
    }

    // For calculating incredibly large Fibonacci numbers I would probably look into storing the numbers
    // per-digit in an array and perform addition by summing up the two values corresponding to the same
    // place in the decimal system and carrying over any overflow into the next addition.
    // This is comparable to column addition taught in schools.
    // In order to optimize calculation of larger Fibonacci numbers, I would probably set up caching
    // to reduce required calculations by getting them from the cache.

    return 0;
}
