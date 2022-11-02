#include "stdio.h"
#include <stdbool.h>

int main(void) {
    for (int i = 0; i < 100; ++i) {
        bool fizz = i % 3 == 0;
        bool buzz = i % 5 == 0;
        printf("%s%s", fizz ? "fizz" : "", buzz ? "buzz" : "");
        if (!(fizz || buzz)) { printf("%d\n", i); } else { printf("\n"); }
    }
}