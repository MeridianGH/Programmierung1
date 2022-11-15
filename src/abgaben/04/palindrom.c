#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

bool isPalindrome(const char * string) {
    // Remove non-alphanumeric characters.
    if (strlen(string) <= 1) { return true; }
    int j = 0;
    char alphaString[strlen(string)];
    for (int i = 0; i < (int) strlen(string); i++) { if (isalpha(string[i])) { alphaString[j++] = (char)tolower(string[i]); } }
    alphaString[j] = '\0';

    // Compare first half of string to second half.
    for (int i = 0; i < (int)strlen(alphaString) / 2; i++) {
        char char1 = (char)tolower(alphaString[i]);
        char char2 = (char)tolower(alphaString[strlen(alphaString) - 1 - i]);
        // Return false if any character doesn't match its equivalent in the second half.
        if (char1 != char2) { return false; }
    }
    return true;
}

bool isPalindromeRec(const char * string) {
    int stringLength = (int)strlen(string);

    // Ignore non-alphanumeric characters.
    int i = 0;
    int j = stringLength - 1;
    while (!isalpha(string[i])) { i++; }
    while (!isalpha(string[j])) { j--; }

    // Return false if any character doesn't match its equivalent in the second half.
    if (tolower(string[i]) != tolower(string[j])) { return false; }

    // Create substring that is missing the first and last character.
    char substring[stringLength];
    strncpy(substring, &string[i + 1], j - i - 1);
    substring[j - i - 1] = '\0';

    // Count alphanumeric characters and return if we have one or zero.
    int alphaCount = 0;
    for (int k = 0; k < (int)strlen(substring); k++) { if (isalpha(substring[k])) { alphaCount++; } }
    if (alphaCount <= 1) { return true; }

    return isPalindromeRec(substring);
}

int main(void) {
    // I had to use a very large palindrom to be able to see any difference in computation speed between the two functions.
    char string[] = "Dennis, Nell, Edna, Leon, Nedra, Anita, Rolf, Nora, Alice, Carol, Leo, Jane, Reed, Dena, Dale, Basil, Rae, Penny, Lana, Dave, Denny, Lena, Ida, Bernadette, Ben, Ray, Lila, Nina, Jo, Ira, Mara, Sara, Mario, Jan, Ina, Lily, Arne, Bette, Dan, Reba, Diane, Lynn, Ed, Eva, Dana, Lynne, Pearl, Isabel, Ada, Ned, Dee, Rena, Joel, Lora, Cecil, Aaron, Flora, Tina, Arden, Noel, and Ellen sinned.";
    clock_t beginIt = clock();
    printf(isPalindrome(string) ? "true\n" : "false\n");
    clock_t endIt = clock();

    clock_t beginRec = clock();
    printf(isPalindromeRec(string) ? "true\n" : "false\n");
    clock_t endRec = clock();

    double timeIterative = (double)(endIt - beginIt);
    double timeRecursive = (double)(endRec - beginRec);
    printf("Iterative: %f\nRecursive: %f\n", timeIterative, timeRecursive);
}
