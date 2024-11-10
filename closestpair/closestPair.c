#include "h/functions.h"
#include <math.h>
#include <float.h>

typedef struct Point {
    int x, y;
} Point;

double distance(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

int compareX(const void* a, const void* b) {
    Point* p1 = (Point*)a;
    Point* p2 = (Point*)b;
    return p1->x - p2->x;
}

int compareY(const void* a, const void* b) {
    Point* p1 = (Point*)a;
    Point* p2 = (Point*)b;
    return p1->y - p2->y;
}

double bruteForce(Point points[], int n) {
    double minDist = DBL_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (distance(points[i], points[j]) < minDist)
                minDist = distance(points[i], points[j]);
    return minDist;
}

double stripClosest(Point strip[], int size, double d) {
    double minDist = d;
    qsort(strip, size, sizeof(Point), compareY);

    for (int i = 0; i < size; ++i)
        for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < minDist; ++j)
            if (distance(strip[i], strip[j]) < minDist)
                minDist = distance(strip[i], strip[j]);
    return minDist;
}

double closestUtil(Point points[], int left, int right) {
    if (right - left <= 3)
        return bruteForce(points + left, right - left + 1);

    int mid = left + (right - left) / 2;
    Point midPoint = points[mid];

    double dl = closestUtil(points, left, mid);
    double dr = closestUtil(points, mid + 1, right);

    double d = fmin(dl, dr);

    Point strip[right - left + 1];
    int j = 0;
    for (int i = left; i <= right; i++)
        if (fabs(points[i].x - midPoint.x) < d)
            strip[j++] = points[i];

    return fmin(d, stripClosest(strip, j, d));
}

double closestPair(Point points[], int n) {
    qsort(points, n, sizeof(Point), compareX);
    return closestUtil(points, 0, n - 1);
}

void runClosestPair() {
    Point points[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    int n = sizeof(points) / sizeof(points[0]);
    double result = closestPair(points, n);
    printf("The smallest distance is: %lf\n", result);
}
