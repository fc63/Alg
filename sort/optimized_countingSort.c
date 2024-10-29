#include "h/functions.h"

static int arr[] = {4, 3, 12, 1, 5, 5, 3, 9};

void optimized_CountingSort() {
    int max = MAX(arr), i = 0, j = 0;
    int *pos = Array(max + 1, 0);

    for (i = 0; i < SIZE(arr); i++)
        pos[arr[i]]++;

    for (i = 0; i <= max; i++)
        while (pos[i]-- > 0)
            arr[j++] = i;

    sfree(pos, NULL);
}

int o_cs() {
    printf("countingSort \n\n");
    printf("Given array is \n");
    printArray(arr, SIZE(arr));

    optimized_CountingSort();

    printf("\nSorted array is \n");
    printArray(arr, SIZE(arr));
    return 0;
}