#include <stdio.h>
#include <time.h>

int height = 28; // Use height smaller than 19 in order to print changes.
int stacks[3][28];
int operations = 0;

void printStacks(void) {
    if (height > 18) { printf("Unable to print properly for large sizes. Skipping.\n"); return; }
    // Inversely iterate over stacks in order to print stacks vertically.
    for (int j = height - 1; j >= 0; j--) {
        for (int i = 0; i < 3; i++) {
            // Format empty slot.
            if (stacks[i][j] == 0) {
                for (int space = 0; space < height; space++) { printf(" "); }
                printf("||");
                for (int space = 0; space < height; space++) { printf(" "); }
                continue;
            }
            // Format ring with given radius.
            for (int space = 0; space < stacks[i][j]; space++) { printf(" "); }
            for (int equals = 0; equals < (height * 2) - (2 * stacks[i][j]) + 2; equals++) { printf("="); }
            for (int space = 0; space < stacks[i][j]; space++) { printf(" "); }
        }
        printf("\n");
    }
    printf("\n");
}

void move(size_t n, char fromStack, char toStack, char tempStack) { // NOLINT(misc-no-recursion) Disable recursion warning.
    // Return if no moves should be made. This is also the termination condition for the recursive function.
    if (n <= 0) { return; }

    // Move n - 1 elements to temporary stack first.
    move(n - 1, fromStack, tempStack, toStack);

    // Iterate over stacks to find the highest element and lowest target position.
    for (int i = height - 1; i >= 0; i--) {
        if (stacks[fromStack - 1][i] == 0) { continue; }
        for (int j = 0; j < height; j++) {
            if (stacks[toStack - 1][j] != 0) { continue; }

            // Copy element and set original position to 0.
            stacks[toStack - 1][j] = stacks[fromStack - 1][i];
            stacks[fromStack - 1][i] = 0;
            break;
        }
        break;
    }

//    printf("From %d to %d:\n", fromStack, toStack); // Uncomment to print steps.
//    printStacks(); // Uncomment to print steps.
    operations++;

    // Move n - 1 elements from temporary stack to target stack.
    move(n - 1, tempStack, toStack, fromStack);
}

int main(void) {
    // Fill first stack with rings of increasing size.
    for (int i = 0; i < height; i++) { stacks[0][i] = i + 1; }

    // Print moving two elements from stack 1 to stack 2.
    printStacks();
    move(2, 1, 3, 2);
    printStacks();
    printf("Operations: %d\n", operations);

    // Calculate runtimes for n = {4, ..., 28}.
    printf("\nRuntimes:\n");
    for (int i = 4; i <= height; i++) {
        // Reset stacks to default.
        for (int j = 0; j < height; j++) { stacks[0][j] = j + 1; }
        for (int j = 0; j < 2; j++) { for (int k = 0; k < height; k++) { stacks[j + 1][k] = 0; } }

        // Measure runtime.
        // Observation: Runtime usually doubles when increasing n by 1. O(n) = 2^n.
        clock_t start = clock();
        move(i, 1, 3, 2);
        double runtime = (double)(clock() - start);
        printf("n = %d: %.1fs\n", i, runtime / 1000);
    }
}
