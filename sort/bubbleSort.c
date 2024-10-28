#include "h/functions.h"

static int arr[] = {64,34,25,12,22,11,90};

void bubbleSort() {
    int i = 0, j = 0;
    bool swapped = false;

    for (i = 0; i < SIZE(arr) - 1; i++) {
        swapped = false;
        for (j = 0; j < SIZE(arr) - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}
int bs() {
    printf("bubbleSort \n\nGiven array is \n");
    printArray(arr, SIZE(arr));

    bubbleSort();

    printf("\nSorted array is \n");
    printArray(arr,SIZE(arr));

    return 0;
}