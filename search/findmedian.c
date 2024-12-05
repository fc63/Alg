#include <stdio.h>

#define NEG_INFINITY (-2147483648)
#define POS_INFINITY  2147483647

double findMedianSortedArrays(int A[], int B[], int n) {
    int low = 0, high = n;

    while (low <= high) {
        int partitionA = (low + high) / 2;
        int partitionB = (n + n + 1) / 2 - partitionA;

        int maxLeftA, minRightA;
        int maxLeftB, minRightB;

        if (partitionA == 0) {
            maxLeftA = NEG_INFINITY;
        } else {
            maxLeftA = A[partitionA - 1];
        }
        if (partitionA == n) {
            minRightA = POS_INFINITY;
        } else {
            minRightA = A[partitionA];
        }

        if (partitionB == 0) {
            maxLeftB = NEG_INFINITY;
        } else {
            maxLeftB = B[partitionB - 1];
        }
        if (partitionB == n) {
            minRightB = POS_INFINITY;
        } else {
            minRightB = B[partitionB];
        }

        if (maxLeftA <= minRightB && minRightA > maxLeftB) {

            if ((n + n) % 2 == 1) {
                if (maxLeftA > maxLeftB) {
                    return (double)maxLeftA;
                } else {
                    return (double)maxLeftB;
                }
            }

            double leftMax, rightMin;

            if (maxLeftA > maxLeftB) {
                leftMax = maxLeftA;
            } else {
                leftMax = maxLeftB;
            }

            if (minRightA < minRightB) {
                rightMin = minRightA;
            } else {
                rightMin = minRightB;
            }

            return (leftMax + rightMin) / 2.0;
        }

        else if (maxLeftA > minRightB) {
            high = partitionA - 1;
        }

        else {
            low = partitionA + 1;
        }
    }

    return -1.0;
}

int median() {
    int A[] = {1, 3, 8};
    int B[] = {7, 9, 10};
    int n = sizeof(A) / sizeof(A[0]);

    double median = findMedianSortedArrays(A, B, n);
    printf("Median: %.2f\n", median);

    return 0;
}