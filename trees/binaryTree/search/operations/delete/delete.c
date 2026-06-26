#include <stdio.h>
#include <stdlib.h>
#include "delete.h"

static Node* findMin(Node* root) {
    while (root->left != NULL) root = root->left;
    return root;
}

static Node* deleteRecursive(Node* root, int data) {
    if (root == NULL) return root;

    if (data < root->data) root->left = deleteRecursive(root->left, data);
    else if (data > root->data) root->right = deleteRecursive(root->right, data);
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteRecursive(root->right, temp->data);
    }
    return root;
}

void deleteLeave(BinarySearchTree *bst) {
    bst->root = deleteRecursive(bst->root, 20);
    bst->nodes--;
}

void deleteNodeG1(BinarySearchTree *bst) {
    bst->root = deleteRecursive(bst->root, 80);
    bst->nodes--;
}

void deleteNodeG2(BinarySearchTree *bst) {
    bst->root = deleteRecursive(bst->root, 30);
    bst->nodes--;
}