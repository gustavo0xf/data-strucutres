#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 5;
// stack's elements
typedef struct node {
    int data;
    struct node *next;
} Node;
// manage the stack properly
typedef struct {
    Node *top;
    int capacity;
    int size;
} Stack;
// initialize the stack
static void initStack(Stack *s, int capacity) {
    s->top = NULL;
    s->capacity = capacity;
    s->size = 0;
}
// checks if stack doesn't have elements
bool isEmpty(Stack *s) {
    return s->size == 0;
}
// stack overflow
bool isFull(Stack *s) {
    return s->size == s->capacity;
}
// push operation: add a new element to stack top
static void push(Stack *s, int data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    
    if (newNode == NULL) {
        free(newNode);
        exit(1);
    }

    if (isFull(s)) {
        printf("[!] stack overflow!\n");
        exit(1);
    } else {
        newNode->data = data;
        newNode->next = s->top;
        s->top = newNode;
        s->size++;
    }
}
// pop operation: remove from the top
static void pop(Stack *s) {
    if(isEmpty(s)) {
        printf("[!] stack is empty.\n");
    } else {
        Node *remove = s->top;
        s->top = remove->next;
        free(remove);
        s->size--;
    }
}
// peek operation: return the value from the top
int peek(Stack *s) {
    return s->top->data;
}
// stack size
int fetchSize(Stack *s) {
    return s->size;
}
// show the stack
static void printStack(Stack *s) {
    if(isEmpty(s)) {
        printf("[!] stack is empty.\n");
    } else {
        Node *current = s->top;
        while (current != NULL) {
            printf("-> %d\n", current->data);
            current = current->next;
        }
        printf("\n");
    }
}
// tests
void makeOps(Stack *s) {
    // operations
}

int main(void) {
    Stack stack;
    initStack(&stack, SIZE);
    makeOps(&stack);
    printf("[*] stack: \n");
    printStack(&stack);
    printf("[+] current top value: %d\n", peek(&stack));
    printf("[+] current stack size: %d\n", fetchSize(&stack));

    return 0;
}
