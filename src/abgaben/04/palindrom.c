#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool isPalindrome(const char * string) {
    for (int i = 0; i < (int)strlen(string); i++) {
        char char1 = (char)tolower(string[i]);
        char char2 = (char)tolower(string[strlen(string) - 1 - i]);
        int j = 1;
        int k = 1;
        while (!isalpha(char1)) { char1 = (char)tolower(string[i + j]); j++; }
        while (!isalpha(char2)) { char2 = (char)tolower(string[strlen(string) - 1 - i - k]); k++; }
        printf("%c, %c\n", char1, char2);
        if (char1 != char2) { return false; }
    }
    return true;
}

int main(void) {
    printf(isPalindrome("Trug Tim eine so helle Hose nie mit Gurt?") ? "true" : "false");
}
