#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QUEUE_CAPACITY 100

typedef struct QueueNode {
    int value;
    struct QueueNode *next;
} QueueNode;

int main() {
    QueueNode *front = NULL;
    QueueNode *rear = NULL;

    printf("Filling the queue with ENQUEUE operations from 0 to %d...\n", QUEUE_CAPACITY - 1);
    for (int i = 0; i < QUEUE_CAPACITY; i++) {
        QueueNode *new_node = malloc(sizeof(QueueNode));
        if (!new_node) {
            fprintf(stderr, "Memory allocation failed\n");
            return 1;
        }
        new_node->value = i;
        new_node->next = NULL;
        if (rear) {
            rear->next = new_node;
        } else {
            front = new_node;
        }
        rear = new_node;
    }

    printf("Queue is full. Reading queue contents with DEQUEUE operation (front to rear): ");
    while (front) {
        printf("%d ", front->value);
        QueueNode *temp = front;
        front = front->next;
        free(temp);
    }
    return 0;
}