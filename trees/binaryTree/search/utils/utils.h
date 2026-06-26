#ifndef PRINT_H
#define PRINT_H
#include "./elements/elements.h"
#include <stdbool.h>

void getMax(BinarySearchTree *bst);
void getMin(BinarySearchTree *bst);
int getSize(BinarySearchTree *bst);
bool isEmpty(BinarySearchTree *bst);
void manageOps(BinarySearchTree *bst);

#endif