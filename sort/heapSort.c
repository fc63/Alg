#include "h/functions.h"

static int arr[] = {9,4,3,8,10,2,5};

void heapify(int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < ARSZ(arr) && arr[l] > arr[largest])
        largest = l;

    if (r < ARSZ(arr) && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(& arr[i],& arr[largest]);
        heapify(largest);
    }
}
void heapSort() {
    int i = 0;

    for (i = ARSZ(arr) / 2 - 1; i >= 0; i--) {
        heapify(i);
    }

    for (i = ARSZ(arr) - 1; i > 0; i--) {
        swap(& arr[0],& arr[i]);
        heapify(i);
    }
}
int hs() {
    printf("heapSort \n\nGiven array is \n");
    printArray(arr, ARSZ(arr));

    heapSort();

    printf("Sorted array is \n");
    printArray(arr, ARSZ(arr));
    return 0;
}
