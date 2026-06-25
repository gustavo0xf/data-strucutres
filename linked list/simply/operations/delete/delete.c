#include <stdio.h>
#include <stdlib.h>
#include "delete.h"
#include "../../utils/utils.h"
#include "../search/search.h"

void deleteBeg(LinkedList *l) {
    Node *tmp = l->head;

    if (tmp == NULL) {
        printf("[!] linked list is empty.\n");
        exit(1);
    } else {
        l->head = tmp->next;
        free(tmp);
        l->size--;
        if (l->size == 0) l->tail = NULL;
    }
}

void deleteEnd(LinkedList *l) {
    Node *tmp = l->tail;
    
    if (isEmpty(l)) {
        printf("[!] linked list is empty.\n");
        exit(1);
    }
    
    if (l->head == l->tail) {
        l->head = l->tail = NULL;
    } else {
        Node *current = l->head;
        while (current->next != l->tail) {
            current = current->next;
        }
        current->next = NULL;
        l->tail = current;
    }
    free(tmp);
    l->size--;
}

void deleteAfter(LinkedList *l, int val) {
    Node *ref = search(l, val);

    if (ref == NULL) {
        printf("[!] doesn't exist any node equals to %d on the linked list.\n", val);
        exit(1);
    } 
    
    if (ref->next == NULL) {
        printf("[!] there is no node after %d to delete.\n", val);
        return;
    }

    Node *target = ref->next;
    ref->next = target->next;
    
    if (target == l->tail) {
        l->tail = ref;
    }

    free(target);
    l->size--;
}