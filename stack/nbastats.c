#include <stdio.h>
#include <stdlib.h>

#define SIZE 30

typedef struct {
        int mvps, fmvps, rings;
} Prizes;

typedef struct {
        char name[SIZE];
        Prizes prizes;
} Player;

typedef struct node {
        Player p;
        struct node *next;
} Node;

Player getPlayer() {
        Player p;
        printf("\n[+] insert a player and how many mvps, fmvps and rings he has\n");
        scanf("%30[^\n]%d%d%d", &p.name, &p.prizes.mvps, &p.prizes.fmvps, &p.prizes.rings);
        return p;
}

void printPlayer(Player p) {
        printf("%s is a %d-time mvp, %d-time fmvp and has %d championships\n", p.name, p.prizes.mvps, p.prizes.fmvps, p.prizes.rings);
}

Node* push(Node *top) {
        Node *tmp = (Node *) malloc(sizeof(Node));
        if (tmp) {
                tmp->p = getPlayer();
                tmp->next = top;
                return tmp;
        } else {
                printf("[!] failed to allocate memory\n");
                exit(1);
        }
        return NULL;
}

Node* pop(Node **top) {
        if (*top) {
                Node *remove = *top;
                *top = remove->next;
                return remove;
        } else {
                printf("[!] there is no players!\n");
        }
        return NULL;
}

void printStack(Node *top) {
        printf("--------------------------------------------------------------------HALL OF FAME--------------------------------------------------------------------\n");
        while (top) {
                printPlayer(top->p);
                top = top->next;
        }
        printf("----------------------------------------------------------------------------------------------------------------------------------------------------\n");
}

int main(void) {
        Node *remove, *top = NULL;
        int option;

        do {
                printf("\n0 - exit\n1 - push a player \n2 - pop a player\n3 - show\n");
                scanf("%d", &option);
                getchar();

                switch (option) {
                        case 1:
                                top = push(top);
                                break;
                        case 2:
                                remove = pop(&top);
                                if (remove) {
                                        printf("\n[!] this node was sucessfull removed:\n");
                                        printPlayer(remove->p);
                                } else {
                                        printf("[!] there is no node to remove!\n");
                                }
                                break;
                        case 3:
                                printStack(top);
                                break;
                        default:
                                if (option != 0) printf("[!] invalid operation\n");
                }
        } while (option != 0);

        return 0;
}
