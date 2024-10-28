#include "h/functions.h"

void printArray(int A[], int size) {
    int i = 0;
    for (i = 0; i < size; i++)
        printf("%5d ", i);
    printf("\n");
    for (i = 0; i < size; i++)
        printf("%5d ", A[i]);
    printf("\n");
}

struct BiNode* newBiNode(int data, struct BiNode* parent) {
    struct BiNode* BiNode = (struct BiNode*)malloc(sizeof(struct BiNode));
    BiNode->data = data;
    BiNode->left = NULL;
    BiNode->right = NULL;
    BiNode->parent = parent;
    return BiNode;
}

void inorderTraversal(struct BiNode* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

bool isCrossLinked(struct BiNode *root1, struct BiNode *root2) {
    if (root1 == NULL || root2 == NULL)
        return false;

    if (root1 == root2 || root1 == root2->left || root1 == root2->right)
        return true;

    return isCrossLinked(root1, root2->left) || isCrossLinked(root1, root2->right);
}

bool detectCrossLink(struct BiNode* root1, struct BiNode* root2) {
    if (root1 == NULL)
        return false;

    if (isCrossLinked(root1, root2)) {
        printf("Cross-link found at Node %d\n", root1->data);
        return true;
    }

    return detectCrossLink(root1->left, root2) || detectCrossLink(root1->right, root2);
}

void swap(int * a, int * b) {
    int t = * a;
    * a = * b;
    * b = t;
}

int* array0(int size) {
    int* arr = calloc(size, sizeof(int));

    if (arr == NULL) {
        return NULL;
    }

    return arr;
}

int maxarr(int input_array[], int array_size) {
    int max_val = input_array[0];
    for (int i = 1; i < array_size; i++) {
        if (input_array[i] > max_val) {
            max_val = input_array[i];
        }
    }
    return max_val;
}

int minarr(int input_array[], int array_size) {
    int min_val = input_array[0];
    for (int i = 1; i < array_size; i++) {
        if (input_array[i] < min_val) {
            min_val = input_array[i];
        }
    }
    return min_val;
}
