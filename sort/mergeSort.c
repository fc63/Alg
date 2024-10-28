#include "h/functions.h"

static int arr[] = {12,11,13,5,6,7};

void merge(int left, int mid, int right) {

    int i = 0, j = 0, k = left; 
    int n1 = mid - left + 1; 
    int n2 = right - mid; 
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i]; 

    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0; 
    j = 0; 

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++; k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++; k++;
    }
}
void mergeSort(int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        merge(left, mid, right);
    }
}
int ms() {
    printf("mergeSort \n\nGiven array is \n");
    printArray(arr,SIZE(arr));

    mergeSort(0, SIZE(arr) - 1);

    printf("\nSorted array is \n");
    printArray(arr,SIZE(arr));

    return 0;
}