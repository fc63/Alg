#include "h/functions.h"

static int arr[] = {12, 11, 13, 5, 6, 7, 9, 15, 21, 18, 25, 33, 42, 1, 4, 8, 19, 27, 50, 3};

void Omerge(int left, int mid, int right) {
    int i = 0, j = 0, k = left;
    int n1 = mid + 1 - left;
    int n2 = -mid + right;
    int L[n1], R[n2];

    while (i < n1 && j < n2) {
        L[i++] = arr[left + i];
        R[j++] = arr[mid + 1 + j];
    }
    if (i < n1)
            L[i++] = arr[left + i];
    else if (j < n2)
            R[j++] = arr[mid + 1 + j];

    i = 0;
    j = 0;

    while (i < n1 || j < n2) {
        if (i < n1 && j < n2) {
            if (L[i] <= R[j])
                arr[k++] = L[i++];
            else
                arr[k++] = R[j++];
        }
        else if(i < n1)
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
}
void OmergeSort(int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        OmergeSort(left, mid);
        OmergeSort(mid + 1, right);
        Omerge(left, mid, right);
    }
}
void OSort() {
    EndIndices indices = findEndIndices(SIZE(arr));
    OmergeSort(indices.leftIndex, indices.rightIndex);
}
int Oms() {
    printf("mergeSort \n\nGiven array is \n");
    printArray(arr,SIZE(arr));

    OSort();

    printf("\nSorted array is \n");
    printArray(arr,SIZE(arr));
    return 0;
}
