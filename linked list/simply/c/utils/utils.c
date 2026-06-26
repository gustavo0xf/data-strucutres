#include <stdio.h>
#include "utils.h"
#include "../operations/insert/insert.h"
#include "../operations/delete/delete.h"
#include "../operations/search/search.h"

void initLinkedList(LinkedList *l) {
    l->head = l->tail = NULL;
    l->size = 0;
}

bool isEmpty(LinkedList* l) { 
    return l->size == 0;
}

int fetchSize(LinkedList *l) {
    if (!isEmpty(l)) {
        return l->size;
    } else {
        return 0;
    }
}

void printLinkedList(LinkedList *l) {
    if (!isEmpty(l)) {
        Node *current = l->head;
        
        while (current != NULL) {
            printf("( %d )", current->data);
            if (current->next != NULL) {
                printf(" -> ");
            }
            current = current->next;
        }
        printf("\n");
    } else {
        printf("[!] linked list is empty.\n");
    }
}

void manageOps(LinkedList *l) {
    insertBeg(l, 10);
    insertEnd(l, 20);
    insertBeg(l, 5);
    insertEnd(l, 30);

    printf("[*] linked list: \n");
    printLinkedList(l);
    printf("[*] current size: %d\n", fetchSize(l));

    printf("\n[+] inserting 15 after 10...\n");
    insertAfter(l, 10, 15);
    printLinkedList(l);

    printf("\n[+] searching for 15...\n");
    Node *found = search(l, 15);
    if (found != NULL) {
        printf("[-] %d found on the linked list!\n", found->data);
    }

    printf("\n[+] deleting the first node...\n");
    deleteBeg(l);
    printLinkedList(l);

    printf("\n[+] deleting the last node...\n");
    deleteEnd(l);
    printLinkedList(l);

    printf("\n[+] deleting the element after 10...\n");
    deleteAfter(l, 10); 
    printLinkedList(l);

    printf("\n[*] final linked list:\n");
    printLinkedList(l);
    printf("\n[*] final size: %d\n", fetchSize(l));
}