#ifndef ELEMENTS_H
#define ELEMENTS_H

typdef struct node {
    int data;
    struct node *right;
    struct node *left;
} Node;

typedef struct {
    Node *root;
    int heigth;
    int nodes;
    int leaves;
} BinarySearchTree;

#endif