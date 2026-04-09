#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* insert_into_array(int *array, int length, int to_index, int value) {
    if (to_index < 0 || to_index > length) {
        return NULL; 
    }

    int* result = realloc(array, sizeof(int) * (length + 1));
    if (result == NULL) {   
        return NULL; 
    }   
    for (int i = length; i > to_index; i--) {
        result[i] = result[i - 1];
    }
    result[to_index] = value;   

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
    for (int i = 0; i < count + 1; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    int value, s_idx;
    printf("Please enter a value to insert: "); scanf("%d", &value);
    printf("Please enter an index to insert the value at: "); scanf("%d", &s_idx);
    array = insert_into_array(array, count, s_idx, value);
    count++;
    printf("Array contents: ");
    for (int i = 0; i < count + 1; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    free(array);

    return 0;
}