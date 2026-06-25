#ifndef UTILS_H
#define UTILS_H
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
    int size;
} LinkedList;

void initLinkedList(LinkedList *l);
bool isEmpty(LinkedList* l);
int fetchSize(LinkedList *l);
void printLinkedList(LinkedList *l);
void manageOps(LinkedList *l);

#endif