#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STACK_CAPACITY 100

typedef struct StackNode {
    int value;
    struct StackNode *next;
} StackNode;

int main() {
    StackNode *top = NULL;

    printf("Filling the stack with PUSH operations from 0 to %d...\n", STACK_CAPACITY - 1);
    for (int i = 0; i < STACK_CAPACITY; i++) {
        StackNode *new_node = malloc(sizeof(StackNode));
        if (!new_node) {
            fprintf(stderr, "Memory allocation failed\n");
            return 1;
        }
        new_node->value = i;
        new_node->next = top;
        top = new_node;
    }

    printf("Stack is full. Reading stack contents with POP operation (top to bottom): ");
    while (top) {
        printf("%d ", top->value);  
        StackNode *temp = top;
        top = top->next;
        free(temp);
    }
    return 0;
}