#include <stdio.h>

int main(void) {
    char txt[] = "abcedfghij";
    char *zeiger = &txt[1];
    printf("%p\n", (void*)txt);
    // 0xABCDEF90 | "txt" is cast as a typeless pointer that references the location of "txt".
    printf("%p\n", (void*)zeiger);
    // 0xABCDEF98 | "zeiger" is pointing to the second array element.
    printf("%c\n", *zeiger);
    // b | The dereferenced pointer returns the character stored at its location, which is "b".
    printf("%p\n", (void*)(zeiger+3));
    // 0xABCDEFB0 | zeiger+3 references the location three locations higher. It is still cast as a pointer. The operation is not saved.
    printf("%p\n", (void*)(++zeiger));
    // 0xABCDEFA0 | "zeiger" is incremented by 1, which means it is now referencing the next element.
    printf("%c\n", *++zeiger);
    // e | "zeiger" is incremented again and is now pointing to the fourth array element.
    printf("%p\n", (void*)zeiger);
    // 0xABCDEFA8 | "zeiger" has been incremented twice and is now pointing to the location two bytes higher than it started.
    printf("%c\n", *zeiger++);
    // e | Due to operator precedence "zeiger" is incremented first and then dereferenced, but as the "++" is after "zeiger", this prints the old value but still increments the pointer.
    printf("%c\n", --(*zeiger));
    // c | "zeiger" is first dereferenced (which returns d) and then decremented by one. This results in setting the value of the location to "c" and printing the character.
    printf("%c\n", *zeiger);
    // c | "zeiger" is simply dereferenced. As it has been set to "c" in the previous step, it is now returning "c", but is still pointing to the fifth array element.
    printf("%c\n", *(zeiger-3));
    // b | "zeiger" is decremented by three and is now pointing to the second element again. The operation is not saved.
    printf("%c\n", zeiger[-1]);
    // e | "zeiger" is still pointing to an array after all, so this returns the element prior to the one "zeiger" is currently pointing to, which is the second "c" that has been set earlier.
    printf("%ld\n", zeiger-txt);
    // 4 | When subtracting two pointers that point to the same array, the result is the distance between the elements they point to. As zeiger is pointing to the fifth element and txt to the first, the result is 4.
    printf("%s\n", txt);
    // abcecfghij | The fifth element has been set to "c" five steps prior while the rest of the array remains unchanged.
}
