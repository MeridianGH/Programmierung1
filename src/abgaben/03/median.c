#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double arithMW(int numbers[], const size_t n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) { sum += numbers[i]; }
    return (double)sum / (double)n;
}

double geoMW(int numbers[], const size_t n) {
    double result = 0;
    for (int i = 0; i < n; ++i) { result += pow(i, 1.0 / (double)n); }
    return result;
}

double harmMW(int numbers[], const size_t n) {
    double sum = 0;
    for (int i = 0; i < n; ++i) { sum += 1.0 / (double)numbers[i]; }
    return (double)n / sum;
}

int main(void) {
    const size_t n = 20;
    int numbers[n];
    for (size_t i = 0; i < n; i++) {
        numbers[i] = rand() % 20 + 1;
    }

    printf("%f\n", arithMW(numbers, n));
    printf("%f\n", geoMW(numbers, n));
    printf("%f\n", harmMW(numbers, n));
}