#include <stdio.h>
#include "print.h"

void preOrderRec(Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrderRec(root->left);
        preOrderRec(root->right);
    }
}

void inOrderRec(Node *root) {
    if (root != NULL) {
        inOrderRec(root->left);
        printf("%d ", root->data);
        inOrderRec(root->right);
    }
}

void postOrderRec(Node *root) {
    if (root != NULL) {
        postOrderRec(root->left);
        postOrderRec(root->right);
        printf("%d ", root->data);
    }
}

void preOrder(BinarySearchTree *bst) { preOrderRec(bst->root); printf("\n"); }
void inOrder(BinarySearchTree *bst) { inOrderRec(bst->root); printf("\n"); }
void postOrder(BinarySearchTree *bst) { postOrderRec(bst->root); printf("\n"); }