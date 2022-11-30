#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    // Demonstrate with small example array.
    int smallArray[] = {5, 3, 1,2, 4};
    printArray(smallArray, 5);
    sort(smallArray, 5);
    printArray(smallArray, 5);

    // Allocate large array.
    const size_t length = 1000000;
    int *array = (int*)malloc(length * sizeof(int));
    for (size_t i = 0; i < length; i++) { array[i] = rand(); }

    clock_t start = clock();
    sort(array, length);
    printf("%dms", (int)(clock() - start));
}
