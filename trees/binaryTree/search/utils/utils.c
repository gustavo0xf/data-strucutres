#include <stdio.h>
#include "utils.h"

int getMax(BinarySearchTree *bst) {
    Node *root = bst->root;
    while (root->right) root = root->right;
    return root->data;
}

int getMin(BinarySearchTree *bst) {
    if (!isEmpty(bst)) {
        Node *root = bst->root;
        while (root->left) root = root->left;
        return root->data;
    }
}

int getSize(BinarySearchTree *bst) {
    if (!isEmpty(bst)) {
        return bst->height;
    }
}

bool isEmpty(BinarySearchTree *bst) {
    return bst->height == 0;
}

void manageOps(BinarySearchTree *bst) {
    // tests
}