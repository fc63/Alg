#include "h/functions.h"

void bruteForcePoly(int P[], int n, int x) {
    int result = 0;
    int power = 1;

    for (int i = 0; i <= n; i++) {
        result += P[i] * power;
        power *= x;
    }

    printf("Polynomial value at x = %d is %d\n", x, result);
}