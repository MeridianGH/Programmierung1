#include <stdio.h>

int main(void) {
    char txt[] = "abcedfghij";
    char *zeiger = &txt[1];
    printf("%p\n", (void*)txt); // 0xABCDEF90 | "txt" is cast as a typeless pointer that references the location of "txt".
    printf("%p\n", (void*)zeiger); // 0xABCDEF98 | "zeiger" is pointing to the second array element.
    printf("%c\n", *zeiger); // b | The dereferenced pointer returns the character stored at its location.
    printf("%p\n", (void*)(zeiger+3)); // 0xABCDEFB0 | zeiger+3 references the location three bytes higher. It is still cast as a pointer.
    printf("%p\n", (void*)(++zeiger)); // 0xABCDEFA0 | The previous operation hasn't been saved, which means that this returns a pointer to the next location (i.e. 1 byte higher)
    printf("%c\n", *++zeiger); // e | The pointer explained one line earlier is dereferenced and returns the element after the first array element.
    printf("%p\n", (void*)zeiger); // 0xABCDEF90 | "zeiger" still hasn't changed and is still pointing to the second array element.
    printf("%c\n", *zeiger++); //
    printf("%c\n", --(*zeiger));
    printf("%c\n", *zeiger);
    printf("%c\n", *(zeiger-3));
    printf("%c\n", zeiger[-1]);
    printf("%ld\n", zeiger-txt);
    printf("%s\n", txt);
}