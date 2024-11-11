#include "h/functions.h"

int calculateRun(int size) {
    if (size <= 16) {
        return 4;
    } else if (size <= 32) {
        return 8;
    } else if (size <= 64) {
        return 16;
    } else if (size <= 1024) {
        return 32;
    } else {
        return 64;
    }
}

void insertionSort63(Point* arr, int left, int right, int (*compare)(const Point*, const Point*)) {
    for (int i = left + 1; i <= right; i++) {
        Point temp = arr[i];
        int j = i - 1;
        while (j >= left && compare(&arr[j], &temp) > 0) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void merge63(Point* arr, int left, int mid, int right, int (*compare)(const Point*, const Point*)) {
    int len1 = mid - left + 1, len2 = right - mid;
    Point* leftArr = (Point*)malloc(len1 * sizeof(Point));
    Point* rightArr = (Point*)malloc(len2 * sizeof(Point));

    for (int i = 0; i < len1; i++) leftArr[i] = arr[left + i];
    for (int i = 0; i < len2; i++) rightArr[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < len1 && j < len2) {
        if (compare(&leftArr[i], &rightArr[j]) <= 0) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
    }

    while (i < len1) arr[k++] = leftArr[i++];
    while (j < len2) arr[k++] = rightArr[j++];

    free(leftArr);
    free(rightArr);
}

void sortUniqueArray(Point* arr, int n, int (*compare)(const Point*, const Point*)) {
    int run = calculateRun(n);

    for (int i = 0; i < n; i += run) {
        insertionSort63(arr, i, (i + run - 1 < n - 1) ? i + run - 1 : n - 1, compare);
    }

    for (int size = run; size < n; size = 2 * size) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = left + size - 1;
            int right = (left + 2 * size - 1 < n - 1) ? left + 2 * size - 1 : n - 1;

            if (mid < right) merge63(arr, left, mid, right, compare);
        }
    }
}

void UC63Sort(Point* arr, int size, int (*compare)(const Point*, const Point*)) {
    sortUniqueArray(arr, size, compare);
}
