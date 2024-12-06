#include <stdio.h>

bool isMaxHeap(int arr[], int n, int i) {
    for(int i = 1; i < n; i++){
        for(int j = 2*i; j < 2*i + 2 && j < n; j++)
        {
            if(arr[i-1]<arr[j-1]){
                return false;
            }
        }
    }
    return true;
}

int mh() {
    // max_heap
    int arr1[] = {10, 7, 8, 6, 5, 4, 3};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    // max_heap değil
    int arr2[] = {10, 15, 8, 7, 6, 5};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    printf("arr1 max heap %s.\n", isMaxHeap(arr1, n1, 0) ? "true" : "false");
    printf("arr2 max heap %s.\n", isMaxHeap(arr2, n2, 0) ? "true" : "false");

    return 0;
}
