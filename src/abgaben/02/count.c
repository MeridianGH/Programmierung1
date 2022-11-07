#include <stdio.h>

int integer = 15; // Use any integer.

int countOnes(int bits) {
    int ones = 0;
    while(bits > 0) {     // While there's still ones in the integer.
        ones += bits & 1; // Compare LSB to 1 and add to counter.
        bits >>= 1;       // Shift bits to the right.
    }
    return ones;
}

int main(void) {
    int zeroes;
    int ones;
    if (integer < 0) {
        // Invert and count 1s to get 0s of negative integer.
        zeroes = countOnes(~integer);
        // Subtract 0s from integer bit count to get 1s.
        ones = (int)(sizeof(int) * 8) - zeroes;
    } else {
        // Count 1s of integer.
        ones = countOnes(integer);
        // Subtract 1s from integer bit count to get 0s.
        zeroes = (int)(sizeof(int) * 8) - ones;
    }
    printf("%d\n", integer);
    printf("1s: %d | 0s: %d\n", ones, zeroes);
}

