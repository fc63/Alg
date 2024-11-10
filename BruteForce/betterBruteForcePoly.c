#include "h/functions.h"

int betterBruteForcePoly(int P[], int n, int x) {
    int result = P[0];
    int power = 1;

    for (int i = 1; i <= n; i++) {
        power *= x;
        result += P[i] * power;
    }

    return result;
}