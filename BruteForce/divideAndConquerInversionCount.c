#include "h/functions.h"

int MergeAndCountSplit(int arr[], int temp[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;
    int invCount = 0;

    while ((i <= mid) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            invCount += (mid - i + 1);
        }
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return invCount;
}

int mergeSortAndCount(int arr[], int temp[], int left, int right) {
    int mid, invCount = 0;
    if (right > left) {
        mid = (right + left) / 2;

        invCount += mergeSortAndCount(arr, temp, left, mid);

        invCount += mergeSortAndCount(arr, temp, mid + 1, right);

        invCount += MergeAndCountSplit(arr, temp, left, mid, right);
    }
    return invCount;
}

void divideAndConquerInversionCount(int arr[], int n) {
    int *temp = (int *)malloc(n * sizeof(int));
    int invCount = mergeSortAndCount(arr, temp, 0, n - 1);
    free(temp);
    printf("Total number of inversions using divide and conquer is: %d\n", invCount);
}
