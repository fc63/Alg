#include "h/functions.h"

int bt() {

    struct BiNode* root1 = newBiNode(1, NULL);
    root1->left = newBiNode(2, root1);
    root1->right = newBiNode(3, root1);
    root1->left->left = newBiNode(4, root1->left);
    root1->left->right = newBiNode(5, root1->left);

    struct BiNode* root2 = newBiNode(6, NULL);
    root2->left = newBiNode(7, root2);
    root2->right = newBiNode(8, root2);
    root2->left->left = newBiNode(9, root2->left);

    root1->left->right->left = root2;
    root1->left->right->left->parent=root1->left->right;

    printf("In-order traversal of Tree 1: ");
    inorderTraversal(root1);
    printf("\nIn-order traversal of Tree 2: ");
    inorderTraversal(root2);
    printf("\n");

    if (!detectCrossLink(root1, root2)) {
        printf("No cross-link found.\n");
    }

    return 0;
}
