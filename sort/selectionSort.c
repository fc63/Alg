#include "h/functions.h"

static int arr[] = {64,34,25,12,22,11,90};

void selectionSort() {
    for (int i = 0; i < SIZE(arr) - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < SIZE(arr); j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(& arr[i], & arr[min_idx]);
    }
}

int ss() {
    printf("selectionSort \n\nGiven array is \n");
    printArray(arr, SIZE(arr));

    selectionSort();

    printf("\nSorted array is \n");
    printArray(arr,SIZE(arr));

    return 0;
}