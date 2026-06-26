#include <stdio.h>
#include "count.h"

static int countNodesRec(Node *root) {
    if (root == NULL) return 0;
    return 1 + countNodesRec(root->left) + countNodesRec(root->right);
}

static int countLeavesRec(Node *root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return countLeavesRec(root->left) + countLeavesRec(root->right);
}

int countNodes(BinarySearchTree *bst) {
    return countNodesRec(bst->root);
}

int countLeaves(BinarySearchTree *bst) {
    return countLeavesRec(bst->root);
}