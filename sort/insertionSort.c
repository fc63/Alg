#include "h/functions.h"

static int arr[] = {12,11,13,5,6};

void insertionSort()
{
    int i = 0, j = 0, key = 0;
    for (i = 1; i < ARSZ(arr); i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
int is() {
    printf("insertionSort \n\nGiven array is \n");
    printArray(arr, ARSZ(arr));

    insertionSort();

    printf("\nSorted array is \n");
    printArray(arr,ARSZ(arr));
    return 0;
}
