#include "h/functions.h"

static int arr[] = {10,7,8,9,1,5};

int part(int low, int high) {
    int i = low - 1;
    int j = 0;

    for (j = low; j <= high - 1; j++) {
        if (arr[j] < arr[high])
            swap(& arr[i++], & arr[j]);
    }
    swap(& arr[i + 1],& arr[high]);
    return i + 1;
}
void quickSort(int low, int high) {
    if (low < high) {
        int pi = part(low, high);

        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}
int qs() {
    printf("quickSort \n\nGiven array is \n");
    printArray(arr, SIZE(arr));

    quickSort(0, SIZE(arr) - 1);

    printf("\nSorted array is \n");
    printArray(arr,SIZE(arr));

    return 0;
}