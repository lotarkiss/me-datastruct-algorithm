#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STACK_CAPACITY 100

typedef struct {
    int data[STACK_CAPACITY];
    int top;
} Stack;

int main()
{
    Stack stack;
    stack.top = -1; 

    printf("Stack capacity: %d, in-memory size: %lu bytes\n", STACK_CAPACITY, sizeof(Stack));
    printf("The stack is currently empty. Top index: %d\n", stack.top);

    printf("Filling the stack with PUSH operations from 0 to %d...\n", STACK_CAPACITY - 1);

    // Pushing integers onto the stack
    for (int i = 0; i < STACK_CAPACITY; i++) {
        stack.data[++stack.top] = i; 
    }

    printf("Stack is full. Current top index: %d\n", stack.top);
    printf("Reading stack contents with POP operation (top to bottom): ");
    // Popping elements from the stack and printing them
    while (stack.top >= 0) {
        printf("%d ", stack.data[stack.top--]);
    }
    printf("\n");
    printf("The stack is currently empty. Top index: %d\n", stack.top);

    return 0;
}