#include "h/functions.h"

static int arr[] = {12,11,13,5,6,7};

void merge(int left, int mid, int right) {
    int i = 0, j = 0, k = left; 
    int n1 = mid + 1 - left;
    int n2 = -mid + right;
    int L[n1], R[n2];

    while (i < n1)
        L[i++] = arr[left + i];

    while (j < n2)
        R[j++] = arr[mid + 1 + j];

    i = 0; j = 0;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}
void mergeSort(int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        merge(left, mid, right);
    }
}
void Sort() {
    EndIndices indices = findEndIndices(SIZE(arr));
    mergeSort(indices.leftIndex, indices.rightIndex);
}
int ms() {
    printf("mergeSort \n\nGiven array is \n");
    printArray(arr, SIZE(arr));

    Sort();

    printf("\nSorted array is \n");
    printArray(arr, SIZE(arr));
    return 0;
}
