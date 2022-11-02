#include <limits.h>
#include "stdio.h"

int integer = 42;
long long llong = LLONG_MAX;


int main(void) {
    printf("%d\n", integer);
    printf("%c\n", integer);

    printf("\n");
    printf("%lld\n", llong);
    printf("%ld\n", llong);
    printf("%d\n", llong);

    printf("\n");
    printf("%llu, %llu, %llu", sizeof(int), sizeof(long), sizeof(long long));

    return 0;
}