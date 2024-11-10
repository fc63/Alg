#include "h/functions.h"

void bruteForcePoly(int P[], int n, int x) {
    int result = 0;

    for (int i = 0; i <= n; i++) {
        int power = 1;

        for (int j = 0; j < i; j++)
            power *= x;


        result += P[i] * power;
    }

    printf("Polynomial value at x = %d is %d\n", x, result);
}