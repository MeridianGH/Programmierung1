#include <stdio.h>
#include <math.h>

int roundF(double x) {
    return (int)round(x);
}

// Enter any function here or uncomment one of the presets.
double function(double x) {
//  return x;                         // Linear
//  return 4;                         // Constant
    return pow(0.5 * x, 2) + 1; // Quadratic
//  return pow(-0.4 * x, 3);          // Cubic
//  return pow(2.7, x);               // Exponential
//  return sin(x);                    // Trigonometric
//  return sinh(x);                   // Hyperbolic
//  return log(x);                    // Logarithmic
}

// Set to 1 to enable additional dots that can improve readability.
int extraDots = 0;

int main(void) {
    for (int y = 10; y >= -10; --y) {
        for (int x = -10; x <= 10; ++x) {
            if (roundF(function(x)) == y || (extraDots && (roundF(function(x - 0.25)) == y || roundF(function(x + 0.25)) == y))) {
                printf(" * ");
            } else if (x == 0 || y == 0) {
                if ((y == 0 && (abs(x) % 5 == 0 || x == 0)) || (x == 0 && abs(y) % 5 == 0)) {
                    printf("-|-");
                } else {
                    printf(y == 0 ? "---" : " | ");
                }
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }
}