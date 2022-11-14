#include <stdio.h>
#include <math.h>

void printArray(int * array, int arrayLength) {
    printf("[");
    for (int i = 0; i < arrayLength; i++) {
        printf("%d", array[i]);
        if (i != arrayLength - 1) { printf(", "); }
    }
    printf("]\n");

}

void popElement(int * array, int index, int arrayLength) {
    for (int i = index; i < arrayLength; i++) { array[i] = array[i + 1]; }
}

int main(void) {
    int n = 200 - 1;
    int numbers[n];
    for (int i = 0; i < n; i++) { numbers[i] = i + 2; }
    printArray(numbers, n);

    int lastPrime = 0;
    int p = numbers[0];
    int removed = 0;
    // As soon as p^2 is larger than n, there will be no more multiples in the list, so we're done sieving.
    while (pow(p, 2) <= n) {
        // Remove multiples
        for (int j = 2; j < n; j++) {
            for (int i = 0; i < n; i++) {
                if (j * p == numbers[i]) { numbers[i] = 0; }
            }
        }
        // Find next prime
        for (int i = 0; i < n; i++) {
            if (numbers[i] != 0 && i > lastPrime) {
                p = numbers[i];
                lastPrime = i;
                break;
            }
        }
        // Remove 0s
        removed = 0;
        for (int i = 0; i < n; i++) {
            if (numbers[i] == 0) {
                for (int j = i; j < n; j++) { numbers[j] = numbers[j + 1]; }
                removed++;
            }
        }
    }
    // Truncate array
    n -= removed - 1;
    printArray(numbers, n);
}
