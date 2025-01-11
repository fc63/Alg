#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>
#include "bs.h"
#include "is.h"
#include "ms.h"
#include "qs.h"
#include "bt.h"
#include "hs.h"
#include "cs.h"
#include "o_cs.h"
#include "bp.h"
#include "bbp.h"
#include "bc.h"
#include "mb.h"
#include "optms.h"
#include "FinalCalismaAlani/final.h"

#define IS_STATIC_ARRAY(arr) (sizeof(arr) > sizeof(int*))
#define SIZE(arr) (IS_STATIC_ARRAY(arr) ? (sizeof(arr) / sizeof((arr)[0])) : size(arr))

#define MAX_STATIC(arr) ({                                \
int max = (arr)[0];                                   \
for (int i = 1; i < SIZE(arr); i++) {                 \
if ((arr)[i] > max) {                             \
max = (arr)[i];                               \
}                                                 \
}                                                     \
max;                                                  \
})

#define MAX_DYNAMIC(arr) ({                 \
int max = (arr)[0];                     \
for (int i = 1; i < size(arr); i++) {   \
if ((arr)[i] > max) {               \
max = (arr)[i];                 \
}                                   \
}                                       \
max;                                    \
})

#define MAX(arr) (IS_STATIC_ARRAY(arr) ? MAX_STATIC(arr) : MAX_DYNAMIC(arr))

struct BiNode {
    int data;
    struct BiNode* left;
    struct BiNode* right;
    struct BiNode* parent;
};
typedef struct {
    int leftIndex;
    int rightIndex;
} EndIndices;
void printArray(int A[], int size);
struct BiNode* newBiNode(int data, struct BiNode* parent);
void inorderTraversal(struct BiNode* root);
bool isCrossLinked(struct BiNode *root1, struct BiNode *root2);
bool detectCrossLink(struct BiNode* root1, struct BiNode* root2);

void swap(int * a, int * b);

int maxarr(int* arr, int arr_size);
int *Array(const int size, const bool notZero);
int size(int *arr);
void sfree(int *first, ...);
bool dynamicArrayValueAssignment (int * arr, const int values[], int values_size);
EndIndices findEndIndices(int size);

void selectionSort();
int ss();

double findMedianSortedArrays(int A[], int B[], int n);
int median();

#endif