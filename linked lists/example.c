#include <stdio.h>
#include <stdlib.h>

typedef struct node {
        int data;
        struct node *next;
} Node;
// insert at beginning
void prepend(Node **list, int val) {
        Node *head = (Node *) malloc(sizeof(Node));

        if (head) {
                head->data = val;
                head->next = *list;
                *list = head;
        } else {
                printf("[!] failed to allocate memory to node\n");
                exit(1);
        }
}

void append(Node **list, int val) {
        Node *tmp, *tail = (Node *) malloc(sizeof(Node));

        if (tail) {
                tail->data = val;
                tail->next = NULL;
                // é o primeiro?
                if (*list == NULL) {
                        *list = tail;
                } else {
                        tmp = *list;
                        while (tmp->next) {
                                tmp = tmp->next;
                        }
                        tmp->next = tail;
                }
        } else {
                printf("[!] failed to allocate memory to node\n");
                exit(1);
        }
}

void insertNode(Node **list, int val, int prev) {
        Node *tmp, *node = (Node *) malloc (sizeof(Node));

        if (node) {
                node->data = val;
                // é o primeiro?
                if (*list == NULL) {
                        node->next = NULL;
                        *list = node;
                } else {
                        tmp = *list;
                        while (tmp->data != prev && tmp->next) {
                                tmp = tmp->next;
                        }
                        node->next = tmp->next;
                        tmp->next = node;
                }
        } else {
                printf("[!] failed to allocate memory to node\n");
                exit(1);
        }
}

void printList(Node *node) {
        printf("\nlist: \n");
        while (node) {
                printf("%d ", node->data);
                node = node->next;
        }
        printf("\n");
}

int main(void) {
        Node *list = NULL;
        int option, num, ref;

        do {
                printf("\n0 - exit\n1 - add at the beginning \n2 - add at the end\n3 - add at the middle\n4 - show list\n");
                scanf("%d", &option);
                getchar();

                switch (option) {
                        case 1:
                                printf("\ndigite um valor: ");
                                scanf("%d", &num);
                                prepend(&list, num);
                                break;
                        case 2:
                                printf("\ndigite um valor: ");
                                scanf("%d", &num);
                                append(&list, num);
                                break;
                        case 3:
                                printf("\ndigite um valor para inserir e depois de qual valor: ");
                                scanf("%d %d", &num, &ref);
                                insertNode(&list, num, ref);
                                break;
                        case 4:
                                printList(list);
                                break;
                        default:
                                if (option != 0) printf("[!] invalid operation\n");
                }
        } while (option != 0);

        return 0;
}
