#include "h/functions.h"

int values[] = {4, 3, 12, 1, 5, 5, 3, 9};
int* arr= NULL;

void countingSort() {

    int* n_arr = Array(size(arr),true);
    int * pos = Array(MAX(arr) + 1, 0);
    int i = 0;

    for (i = 0; i < size(arr); i++)
        pos[arr[i]]++;

    for (i = 1; i <= MAX(arr); i++)
        pos[i] += pos[i - 1];

    for (i = size(arr) - 1; i >= 0; i--)
        n_arr[--pos[arr[i]]] = arr[i];

    sfree(pos, arr, NULL);

    arr = n_arr;
}

void dynamiccs() {
    printf("countingSort \n\n");
    printf("Given array is \n");
    printArray(arr, size(arr));

    countingSort();

    printf("\nSorted array is \n");
    printArray(arr, size(arr));
}

int cs() {
    arr=Array(SIZE(values), false);
    dynamicArrayValueAssignment(arr, values, SIZE(values));
    dynamiccs();
    sfree(arr, NULL);
    return 0;
}