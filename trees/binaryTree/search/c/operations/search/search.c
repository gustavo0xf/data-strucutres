#include <stdio.h>
#include "search.h"

static Node* searchRec(Node *root, int val) {
    if (root == NULL || root->data == val) {
        return root;
    }
    if (val < root->data) {
        return searchRec(root->left, val);
    }
    return searchRec(root->right, val);
}

void searchValRecursive(BinarySearchTree *bst, int val) {
    Node *result = searchRec(bst->root, val);
    if (result != NULL) {
        printf("[*] %d found on binary search tree!\n", val);
    } else {
        printf("[!] %d doesn't exist on binary search tree.\n", val);
    }
}

void searchValIterative(BinarySearchTree *bst, int val) {
    Node *current = bst->root;
    while (current != NULL) {
        if (val == current->data) {
            printf("[*] %d found on binary search tree!\n", val);
            return;
        }
        if (val < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    printf("[!] %d doesn't exist on binary search tree.\n", val);
}