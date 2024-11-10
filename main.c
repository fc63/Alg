#include "h/functions.h"

int main() {
    int i = 0, j = 0;

    printf("1. Sort\n2. Btr\n3. Brute Force\n4. Polynomial Evaluation\n5. Closest Pair\n\nYour choice:");
    scanf("%d", &i);
    switch(i) {
        case 1:
            printf("1. Bubble Sort\n2. Insertion Sort\n3. Merge Sort\n4. Quick Sort\n5. Heap Sort\n6. Counting Sort\n7. Optimized Counting Sort\n8. Selection Sort\n\nYour choice: ");
            scanf("%d", &j);
            printf("\n");
            switch(j) {
                case 1: return bs();
                case 2: return is();
                case 3: return ms();
                case 4: return qs();
                case 5: return hs();
                case 6: return cs();
                case 7: return o_cs();
                case 8: return ss();
            }
            break;
        case 2:
            return bt();
        case 3:
            printf("1. Brute Force Polynomial\n2. Better Brute Force Polynomial\n\nYour choice: ");
            scanf("%d", &j);
            printf("\n");
            switch(j) {
                case 1: {
                    int P[] = {1, 2, 3};
                    int x = 2;
                    bruteForcePoly(P, SIZE(P) - 1, x);
                    break;
                }
                case 2: {
                    int P[] = {1, 2, 3};
                    int x = 2;
                    printf("Better Brute Force Polynomial result: %d\n", betterBruteForcePoly(P, SIZE(P) - 1, x));
                    break;
                }
            }
            break;
        case 4:
            printf("1. Brute Force Inversion Count\n2. Divide and Conquer Inversion Count\n\nYour choice: ");
            scanf("%d", &j);
            printf("\n");
            switch(j) {
                case 1: {
                    int A[] = {5, 3, 2, 1, 4};
                    bruteForceInversionCount(A, SIZE(A));
                    break;
                }
                case 2: {
                    int A[] = {5, 3, 2, 1, 4};
                    divideAndConquerInversionCount(A, SIZE(A));
                    break;
                }
            }
            break;
        case 5:
            runClosestPair();
        break;
        default:
            printf("Invalid choice.\n");
    }
    return 0;
}