#include <stdio.h>
#include <stdlib.h>

int steps = 0;

int bin_search_recursive(int *array, int low, int high, int value) {
    if (low > high) {
        return -1;  
    }

    int mid = (low + high) / 2;
    printf("Testing middle index %d of range %d..%d with value %d\n", mid, low, high, array[mid]);
    steps++;

    if (array[mid] == value) {
        return mid;
    } else if (array[mid] < value) {
        return bin_search_recursive(array, mid + 1, high, value);
    } else {
        return bin_search_recursive(array, low, mid - 1, value);
    }
}

int main() 
{
    int count;
    printf("Please enter a valid array length: "); scanf("%d", &count);

    if (count <= 0) 
        return 1;

    int *array = malloc(sizeof(int) * count);

    for (int i = 0; i < count; i++) {
        array[i] = i;
    }

    printf("Head of the array: %d\n", 0);
    printf("Tail of the array: %d\n", count - 1);
    printf("Length of the array: %d\n", count);
    printf("Size of the array: %lu bytes\n", sizeof(int) * count);
    
    int search, s_idx;
    printf("Please enter a value to search in the array (0..%d): ", count - 1); scanf("%d", &search);
    s_idx = bin_search_recursive(array, 0, count - 1, search);
    printf("Index of the value in the array, in %d steps: %d\n", steps, s_idx);
    free(array);

    return 0;
}