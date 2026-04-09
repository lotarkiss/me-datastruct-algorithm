#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QUEUE_CAPACITY 100

typedef struct {
    int data[QUEUE_CAPACITY];
    int front;
    int rear;
} Queue;

int main()
{
    Queue queue ;
    queue.front = -1;
    queue.rear = -1;

    printf("Queue capacity: %d, in-memory size: %lu bytes\n", QUEUE_CAPACITY, sizeof(Queue));
    printf("The queue is currently empty. Front index: %d, Rear index: %d\n", queue.front, queue.rear);

    printf("Filling the queue with ENQUEUE operations from 0 to %d...\n", QUEUE_CAPACITY - 1);

    // Enqueueing integers into the queue
    for (int i = 0; i < QUEUE_CAPACITY; i++) {
        queue.data[++queue.rear] = i; 
    }

    printf("Queue is full. Current rear index: %d\n", queue.rear);
    printf("Reading queue contents with DEQUEUE operation (front to rear): ");
    // Dequeueing elements from the queue and printing them
    while (queue.front < queue.rear) {
        printf("%d ", queue.data[++queue.front]);
    }
    printf("\n");
    printf("The queue is currently empty. Front index: %d, Rear index: %d\n", queue.front, queue.rear);

    return 0;
}