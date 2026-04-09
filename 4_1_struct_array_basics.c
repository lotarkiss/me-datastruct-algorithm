#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int search_in_array(int *array, int length, int value) {
    for (int i = 0; i < length; i++) {
        if (array[i] == value) {
            return i;
        }
    }
    return -1; 
}

int minimum_idx_of_array(int *array, int length) {
    if (length <= 0) return -1; 
    return 0;
}

int maximum_idx_of_array(int *array, int length) {
    if (length <= 0) return -1; 
    return length - 1;
}

int next_idx_of_array(int *array, int length, int idx) {
    if (idx < 0 || idx >= length - 1) return -1; 
    return idx + 1;
}

int prev_idx_of_array(int *array, int length, int idx) {
    if (idx <= 0 || idx >= length) return -1; 
    return idx - 1;
}

int main() 
{
    int count;
    printf("Please enter a valid array length: "); scanf("%d", &count);

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
    
    int search, s_idx;
    printf("Please enter a value to search in the array (0..99): "); scanf("%d", &search);
    s_idx = search_in_array(array, count, search);
    printf("Index of the value in the array: %d\n", s_idx);
    printf("Minimum index of the array: %d\n", minimum_idx_of_array(array, count));
    printf("Maximum index of the array: %d\n", maximum_idx_of_array(array, count));
    printf("Next index of the array: %d\n", next_idx_of_array(array, count, s_idx));
    printf("Previous index of the array: %d\n", prev_idx_of_array(array, count, s_idx));

    free(array);

    return 0;
}