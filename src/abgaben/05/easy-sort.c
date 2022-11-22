#include <stdio.h>
#include <stdlib.h>

void sort(int array[], size_t length) {
    // Insertion sort.
    for (size_t i = 1; i < length; i++) {
        int element = array[i];
        size_t j = i;
        while (j > 0 && array[j - 1] > element) {
            array[j] = array[j - 1];
            j--;
        }
        array[j] = element;
    }
}

void printArray(int array[], size_t length) {
    printf("[");
    for (size_t i = 0; i < length; i++) {
        printf("%d", array[i]);
        if (i != length - 1) { printf(", "); }
    }
    printf("]\n");
}

int main(void) {
    const size_t length = 100;
    int array[length];
    for (size_t i = 0; i < length; i++) { array[i] = rand(); }

    printArray(array, length);

    sort(array, length);

    printArray(array, length);
}
