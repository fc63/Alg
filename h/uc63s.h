#ifndef UC63S_H
#define UC63S_H
typedef struct Point {
    int x, y;
} Point;
int calculateRun(int size);
void insertionSort63(Point* arr, int left, int right, int (*compare)(const Point*, const Point*));
void merge63(Point* arr, int left, int mid, int right, int (*compare)(const Point*, const Point*));
void sortUniqueArray(Point* arr, int n, int (*compare)(const Point*, const Point*));
void UC63Sort(Point* arr, int size, int (*compare)(const Point*, const Point*));

#endif //UC63S_H
