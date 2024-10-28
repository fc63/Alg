#include "h/functions.h"

static int arr[] = {4,3,12,1,5,5,3,9};

void countingSort() {

    int max = maxarr(arr, ARSZ(arr)), i = 0;
    int min = minarr(arr, ARSZ(arr)), n_arr[ARSZ(arr)];
    int * pos = array0(max + 1 - min);

    for (i = 0; i < ARSZ(arr); i++)
        pos[arr[i] - min]++; 

    for (i = 1; i <= max; i++)
        pos[i] += pos[i - 1]; 

    for (i = ARSZ(arr) - 1; i >= 0; i--) 
        n_arr[pos[arr[i] - min]-- - 1] = arr[i]; 

    free(pos);

    for (i = 0; i < ARSZ(arr); i++)
        arr[i] = n_arr[i];
}
int cs() {
    printf("countingSort \n\n");

    printf("Given array is \n");
    printArray(arr, ARSZ(arr));

    countingSort();

    printf("\nSorted array is \n");
    printArray(arr, ARSZ(arr));

    return 0;
}
