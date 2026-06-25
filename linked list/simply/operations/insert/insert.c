#include <stdio.h>
#include <stdlib.h>
#include "insert.h"
#include "../../utils/utils.h"
#include "../search/search.h"

void insertBeg(LinkedList *l, int data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    Node *head = l->head;

    if (newNode == NULL) {
        printf("[!] failed to allocate memory.\n");
        exit(1);
    } else {
        newNode->data = data;
        newNode->next = head;
        if (isEmpty(l)) {
            l->head = l->tail = newNode;
            l->size++;
        } else {
            l->head = newNode;
            l->size++;
        }
    }
}

void insertEnd(LinkedList *l, int data) {
    Node *newNode = (Node *) malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("[!] failed to allocate memory.\n");
        exit(1);
    } else {
        newNode->data = data;
        newNode->next = NULL;
        if (isEmpty(l)) {
            l->head = l->tail = newNode;
            l->size++;
        } else {
            l->tail->next = newNode;
            l->tail = newNode;
            l->size++;
        }
    }
}

void insertAfter(LinkedList *l, int val, int data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    Node *ref = search(l, val);

    if (newNode == NULL) {
        printf("[!] failed to allocate memory.\n");
        exit(1);
    } else {
        if (ref == NULL) {
            free(newNode);
            printf("[!] doesn't exist any node equals to %d on the linked list.\n", val);
            exit(1);
        } else {
            newNode->data = data;
            newNode->next = ref->next;
            ref->next = newNode;
            if (ref == l->tail) l->tail = newNode;
            l->size++;
        }
    }
}