#include <stdio.h>

char* find(const char* string, const char* substring) {
    int i = 0;
    char c = ' ';
    // Iterate over string.
    while (c != '\0') {
        // Set current characters.
        c = *(string + i);
        char subc = *substring;

        // Iterate as long as substring matches original string.
        int j = 0;
        while (c == subc) {
            c = *(string + i + j);
            subc = *(substring + j);
            // If we can iterate over the entire substring without breaking, we have an exact match.
            // Return pointer to start of match.
            if (subc == '\0') { return (char*)string + i; }
            j++;
        }
        i++;
    }
    return NULL;
}

int main(void) {
    printf("%s", find("Anna", "nn"));
}
