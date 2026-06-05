#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 30

typedef struct node {
        char name[SIZE];
        struct node *next;
} Node;

void enqueue(Node **queue, const char *player) {
        Node *tmp, *newNode = (Node *) malloc(sizeof(Node));
        if (newNode) {
                strcpy(newNode->name, player);
                newNode->next = NULL;
                if (*queue) {
                        tmp = *queue;
                        while (tmp->next) {
                                tmp = tmp->next;
                        }
                        tmp->next = newNode;
                } else {
                        *queue = newNode;
                }
        } else {
                printf("[!] failed to allocate memory\n");
        }
}

Node* dequeue(Node **queue) {
        Node *remove = NULL;

        if (*queue) {
                remove = *queue;
                *queue = remove->next;
        } else {
                printf("[!] empty queue!");
        }
        return remove;
}

void printQueue(Node *queue) {
        printf("-----------------------------ICE DEPORT-----------------------------\n");
        while (queue) {
                printf("- %s\n", queue->name);
                queue = queue->next;
        }
        printf("-------------------------------------------------------------------\n");
}

int main(void) {
        Node *queue, *r = NULL;
        int option;
        char name[SIZE];

        do {
                printf("\n0 - exit\n1 - enqueue \n2 - dequeue\n3 - show\n");
                scanf("%d", &option);
                getchar();

                switch (option) {
                        case 1:
                                printf("\n[!] player that you want to report to ICE: ");
                                scanf("%29s", &name);
                                enqueue(&queue, name);
                                break;
                        case 2:
                                r = dequeue(&queue);
                                if (r) {
                                        printf("\n[!] this player is now out of the queue: %s\n", r->name);
                                        free(r);
                                } else {
                                        printf("\n[!] there is no node to dequeue!\n");
                                }
                                break;
                        case 3:
                                printQueue(queue);
                                break;
                        default:
                                if (option != 0) printf("[!] invalid operation\n");
                }
        } while (option != 0);

        return 0;
}
