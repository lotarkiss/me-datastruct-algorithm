#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int value;
    struct Node *next, *prev;
} Node;

void destroy_list(Node *head) {
    Node *current = head;
    while (current) {
        Node *next = current->next;
        free(current);
        current = next;
    }
}

Node *tail_of_list(Node *head) {
    Node *current = head;
    while (current->next) {
        current = current->next;
    }
    return current;
}

Node *search_in_list(Node *head, int value) {
    Node *current = head;
    while (current) {
        if (current->value == value) {
            return current;
        }
        current = current->next;
    }
    return NULL; 
}

Node *insert_into_list(Node *head, int value, Node *after) {
    Node *new_node = malloc(sizeof(Node));
    if (!new_node) return NULL; 
    new_node->value = value;
    new_node->next = after->next;
    new_node->prev = after;
    after->next = new_node;
    if (new_node->next) {
        new_node->next->prev = new_node;
    }
    return new_node; 
}

void delete_from_list(Node **head, Node *node) {
    if (!node) return; 
    if (node->prev) {
        node->prev->next = node->next;
    } else {
        *head = node->next; 
    }
    if (node->next) {
        node->next->prev = node->prev;
    }
    free(node);
}

Node *next_in_list(Node *node) {
    if (!node) return NULL; 
    return node->next;
}

Node *prev_in_list(Node *node) {
    if (!node) return NULL; 
    return node->prev;
}

int main() 
{
    int count;
    printf("Please enter a valid list length: "); scanf("%d", &count);

    Node *head = malloc(sizeof(Node));
    head->value = 0;
    head->next = NULL;
    head->prev = NULL;

    srand(time(NULL));
    for (int i = 1; i < count; i++) {
        insert_into_list(head, rand() % 100, tail_of_list(head));
    }

    printf("Head of the list: %d\n", head->value);
    printf("Tail of the list: %d\n", tail_of_list(head)->value);
    printf("Length of the list: %d\n", count);
    printf("Size of the list: %lu bytes\n", sizeof(Node) * count);  
    printf("List contents: ");
    for (Node *current = head; current; current = next_in_list(current)) {
        printf("%d ", current->value);
    }
    printf("\n");

    printf("Please enter a value to search in the list (0..99): ");
    int search; scanf("%d", &search);
    printf("Please enter a value to insert after the specified node of the list: ");
    int insert_val; scanf("%d", &insert_val);
    Node *found = search_in_list(head, search);
    if (found) {
        printf("Value found in the list: %d\n", found->value);
        printf("Next value in the list: %d\n", next_in_list(found) ? next_in_list(found)->value : -1);
        printf("Previous value in the list: %d\n", prev_in_list(found) ? prev_in_list(found)->value : -1);
    } else {
        printf("Value not found in the list.\n");
    }   
    insert_into_list(head, insert_val, found ? found : tail_of_list(head));
    printf("Value inserted into the list.\n");
    printf("List contents after insertion: ");
    for (Node *current = head; current; current = next_in_list(current)) {  
        printf("%d ", current->value);
    }
    printf("\n");

    delete_from_list(&head, found ? found : tail_of_list(head));
    printf("Value deleted from the list.\n");
    printf("List contents after deletion: ");
    for (Node *current = head; current; current = next_in_list(current)) {
        printf("%d ", current->value);
    }
    printf("\n");

    destroy_list(head);
    return 0;
}