#include "h/functions.h"

void bruteForceInversionCount(int A[], int n) {
    int numInversions = 0;

    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (A[i] > A[j]) {
                printf("(%d, %d) is an inversion\n", A[i], A[j]);
                numInversions++;
            }

    printf("Total number of inversions is: %d\n", numInversions);
}