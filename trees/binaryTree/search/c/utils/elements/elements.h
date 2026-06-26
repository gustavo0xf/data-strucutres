#ifndef ELEMENTS_H
#define ELEMENTS_H

typedef struct node {
    int data;
    struct node *right;
    struct node *left;
} Node;

typedef struct {
    Node *root;
    int height;
    int nodes;
    int leaves;
} BinarySearchTree;

#endif