#include <stdio.h>

#define NEG_INFINITY (-2147483648) 
#define POS_INFINITY  2147483647 

double findMedianSortedArrays(int Sol[], int Sag[], int size) {
    int low = 0, high = size;

    while (low <= high) {
        int partition_Sol = (low + high) / 2;
        int partition_Sag = (size + size + 1) / 2 - partition_Sol;

        int ortaninSolu_Sol, orta_Sol; 
        int ortaninSolu_Sag, orta_Sag; 

        if (partition_Sol == 0) {
            ortaninSolu_Sol = NEG_INFINITY; 
        } else {
            ortaninSolu_Sol = Sol[partition_Sol - 1];
        }
        if (partition_Sol == size) {
            orta_Sol = POS_INFINITY; 
        } else {
            orta_Sol = Sol[partition_Sol];
        }

        if (partition_Sag == 0) {
            ortaninSolu_Sag = NEG_INFINITY; 
        } else {
            ortaninSolu_Sag = Sag[partition_Sag - 1];
        }
        if (partition_Sag == size) {
            orta_Sag = POS_INFINITY; 
        } else {
            orta_Sag = Sag[partition_Sag];
        }

        if (ortaninSolu_Sol <= orta_Sag && orta_Sol > ortaninSolu_Sag) {

            if ((size + size) % 2 == 1) {
                if (ortaninSolu_Sol > ortaninSolu_Sag) {
                    return (double)ortaninSolu_Sol;
                } else {
                    return (double)ortaninSolu_Sag;
                }
            }

            double ortaninSolu_Max, orta_Min;

            if (ortaninSolu_Sol > ortaninSolu_Sag) {
                ortaninSolu_Max = ortaninSolu_Sol;
            } else {
                ortaninSolu_Max = ortaninSolu_Sag;
            }

            if (orta_Sol < orta_Sag) {
                orta_Min = orta_Sol;
            } else {
                orta_Min = orta_Sag;
            }

            return (ortaninSolu_Max + orta_Min) / 2.0;
        }

        else if (ortaninSolu_Sol > orta_Sag) {
            high = partition_Sol - 1;
        }

        else {
            low = partition_Sol + 1;
        }
    }

    return -1.0;
}

int median() {
    int A[] = {1, 2, 7, 9}; 
    int B[] = {4, 5, 6, 8}; 
    int n = sizeof(A) / sizeof(A[0]); 

    double median = findMedianSortedArrays(A, B, n); 
    printf("Median: %.2f\n", median); 

    return 0;
}
