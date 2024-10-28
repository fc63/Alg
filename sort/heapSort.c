#include "h/functions.h"

static int arr[] = {9,4,3,8,10,2,5};

void heapify(int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(& arr[i],& arr[largest]);
        heapify(n,largest);
    }
}
void heapSort() {
    int i = 0;

    for (i = SIZE(arr) / 2 - 1; i >= 0; i--) {
        heapify(SIZE(arr),i);
    }

    for (i = SIZE(arr) - 1; i > 0; i--) {
        swap(& arr[0],& arr[i]);
        heapify(i,0);
    }
}
int hs() {
    printf("heapSort \n\nGiven array is \n");
    printArray(arr, SIZE(arr));

    heapSort();

    printf("Sorted array is \n");
    printArray(arr, SIZE(arr));
    return 0;
}