#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 5;
// queue's elements
typedef struct node {
    int data;
    struct node *next;
} Node;
// manage the queue properly
typedef struct {
    Node *head;
    Node *tail;
    int size;
    int capacity;
} Queue;
// initialize the queue
static void initQueue(Queue *q, int capacity) {
    q->head = q->tail = NULL;
    q->size = 0;
    q->capacity = capacity;
}
// check if queue doesn't have elements
bool isEmpty(Queue *q) {
    return q->size == 0;
}
// queue limit reached
bool isFull(Queue *q) {
    return q->size == q->capacity;
}
// enqueue operation: add an element at the queue's tail (FIFO)
static void enqueue(Queue *q, int data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    Node *tmp = q->tail;

    if(newNode == NULL) {
        printf("[!] failed to allocate memory!\n");
        exit(1);
    } else if (!isFull(q)) {
        newNode->data = data;
        newNode->next = NULL;

        if(isEmpty(q)) {
            q->head = q->tail = newNode;
            q->size++;
        } else {
            q->tail = newNode;
            tmp->next = newNode;
            q->size++;
        }
    } else {
        printf("[!] queue is already full!\n");
    }
}
// dequeue operation: remove an element from the queue's head (FIFO)
static void dequeue(Queue *q) {
    Node *tmp = q->head;

    if(tmp == NULL) {
        printf("[!] failed to allocate memory!\n");
        exit(1);
    } else if (!isEmpty(q)) {
        q->head = tmp->next;
        free(tmp);
        q->size--;
    } else {
        printf("[!] queue is empty!\n");
    }
}
// value of the first node
int peek(Queue *q) {
    if (!isEmpty(q)) {
        return q->head->data;
    }
}
// queue's size
int fetchSize(Queue *q) {
    return q->size;
}
// print all nodes
static void printQueue(Queue *q) {
    if (!isEmpty(q)) {
        Node *current = q->head;
        while(current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}
// tests
void manageOps(Queue *q) {
    // operations
}

int main(void) {
    Queue queue;
    initQueue(&queue, SIZE);
    manageOps(&queue);
    printf("[*] queue: \n");
    printQueue(&queue);
    printf("\n[*] first element: %d\n", peek(&queue));
    printf("[*] current size: %d\n", fetchSize(&queue));

    return 0;
}
