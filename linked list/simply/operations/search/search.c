#include <stdio.h>
#include <stdbool.h>
#include "search.h"
#include "../../utils/utils.h"

Node* search(LinkedList *l, int val) {
    Node *current = l->head;

    if (!isEmpty(l)) {
        while (current != NULL) {
            if (current->data == val) {
                return current;
            }
            current = current->next;
        }
        printf("[*] element %d doesn't exist.\n", val);
    } else {
        printf("[!] linked list is empty.\n");
    }
    
    return NULL;
}