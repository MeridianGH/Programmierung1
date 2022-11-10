#include <stdio.h>
#include <limits.h>

unsigned long long fib(int n) {
    unsigned long long prev1 = 1; // n - 1
    unsigned long long prev2 = 0; // n - 2
    unsigned long long fib = 1;
    for (int i = 0; i < n; ++i) {
        if (prev1 > ULONG_LONG_MAX - prev2) { return -1; } // Addition would result in overflow.
        fib = prev1 + prev2;
        prev2 = prev1;
        prev1 = fib;
    }
    return fib;
}

int main(void) {
    printf("%llu\n", fib(7)); // 7th Fibonacci number

    // Calculate maximum possible Fibonacci number.
    printf("Calculating increasing Fibonacci numbers:\n");
    int i = 0;
    unsigned long long result = 0;
    while (result != -1) {
        result = fib(i);
        i++;
        printf("%llu\n", result);
    }

    // For calculating incredibly large Fibonacci numbers I would probably look into storing the numbers
    // per-digit in an array and perform addition by summing up the two values corresponding to the same
    // place in the decimal system and carrying over any overflow into the next addition.
    // This is comparable to column addition taught in schools.
    // In order to optimize calculation of larger Fibonacci numbers, I would probably set up caching
    // to reduce required calculations by getting them from the cache.

    return 0;
}