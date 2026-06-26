#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "../operations/insert/insert.h"
#include "../operations/delete/delete.h"
#include "../operations/search/search.h"
#include "./print/print.h"
#include "./count/count.h"

void initBST(BinarySearchTree *bst) {
    bst->root   = NULL;
    bst->height = 0;
    bst->nodes  = 0;
    bst->leaves = 0;
}

void getMax(BinarySearchTree *bst) {
    if (!isEmpty(bst)) {
        Node *current = bst->root;
        while (current->right != NULL) current = current->right;
        printf("[*] max node: %d \n", current->data);
    } else {
        printf("[!] binary search tree is empty.\n");
    }
}

void getMin(BinarySearchTree *bst) {
    if (!isEmpty(bst)) {
        Node *current = bst->root;
        while (current->left != NULL) current = current->left;
        printf("[*] min node: %d \n", current->data);
    } else {
        printf("[!] binary search tree is empty.\n");
    }
}

int getSize(BinarySearchTree *bst) {
    return bst->height;
}

bool isEmpty(BinarySearchTree *bst) {
    return bst->root == NULL;
}

void manageOps(BinarySearchTree *bst) {

    printf("[*] inserting elements...\n");
    insertLeave(bst, 50);
    insertLeave(bst, 30);
    insertLeave(bst, 70);
    insertLeave(bst, 20);
    insertLeave(bst, 40);
    insertLeave(bst, 60);
    insertLeave(bst, 80);

    printf("[+] tree heigth: %d\n", getSize(bst));
    printf("[+] nodes: %d\n", countNodes(bst));
    printf("[+] leaves: %d\n", countLeaves(bst));
    getMin(bst);
    getMax(bst);
    printf("\n");

    printf("[-] in-order   (growing): "); inOrder(bst);
    printf("[-] pre-order  (root->left->right): "); preOrder(bst);
    printf("[-] post-order (left->right->root): "); postOrder(bst);
    printf("\n");

    searchValRecursive(bst, 30);
    searchValIterative(bst, 80);
    searchValRecursive(bst, 99);

    deleteLeave(bst);
    deleteNodeG1(bst);
    deleteNodeG2(bst);
}