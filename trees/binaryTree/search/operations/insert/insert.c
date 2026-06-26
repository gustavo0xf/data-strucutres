#include <stdio.h>
#include <stdlib.h>
#include "insert.h"

static Node* insertNode(Node *root, int data, bool *inserted) {
    if (root == NULL) {
        Node *newNode = (Node *) malloc(sizeof(Node));
        if (!newNode) {
            printf("[!] failed to allocate memory.\n");
            exit(1);
        }
        newNode->data = data;
        newNode->left = newNode->right = NULL;
        *inserted = true;
        return newNode;
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data, inserted);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data, inserted);
    } else {
        printf("[!] no duplicates.\n", data);
    }
    return root;
}

static int evalHeight(Node *root) {
    if (root == NULL) return 0;
    int leftH = evalHeight(root->left);
    int rightH = evalHeight(root->right);
    return (leftH > rightH ? leftH : rightH) + 1;
}

void insertLeave(BinarySearchTree *bst, int data) {
    bool inserted = false;
    bst->root = insertNode(bst->root, data, &inserted);
    if (inserted) {
        bst->nodes++;
        bst->height = evalHeight(bst->root);
    }
}