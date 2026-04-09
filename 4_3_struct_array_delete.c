#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* delete_from_array(int *array, int length, int from_index) {
    if (from_index < 0 || from_index >= length) {
        return NULL; 
    }

    for (int i = from_index; i < length - 1; i++) {
        array[i] = array[i + 1];
    }

    int* result = realloc(array, sizeof(int) * (length - 1));
    if (result == NULL && length - 1 > 0) { 
        return NULL; 
    }   
    
    return result; 
}
int main() 
{
    int count;
    printf("Please enter a valid array length (e.g. 10): "); scanf("%d", &count);

    if (count <= 0) 
        return 1;

    int *array = malloc(sizeof(int) * count);

    srand(time(NULL));
    for (int i = 0; i < count; i++) {
        array[i] = rand() % 100; // Random numbers between 0 and 99
    }

    printf("Head of the array: %d\n", 0);
    printf("Tail of the array: %d\n", count - 1);
    printf("Length of the array: %d\n", count);
    printf("Size of the array: %lu bytes\n", sizeof(int) * count);
    printf("Array contents: ");
    for (int i = 0; i < count - 1; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    int s_idx;
    printf("Please enter an index to delete the value at: "); scanf("%d", &s_idx);
    array = delete_from_array(array, count, s_idx);
    count--;
    printf("Array contents: ");
    for (int i = 0; i < count - 1; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    free(array);

    return 0;
}

