#include <stdio.h>
#include <math.h>

#define C1 1.61803398874989484820458683436563811772030917980576286213544862270526046281890
#define C2 0.61803398874989484820458683436563811772030917980576286213544862270526046281890

int fibonacci_linear(int n) {
    return (int)round((pow(C1, n) - pow(C2, n)) / sqrt(5));
}

int main()
{
    int x = 0;
    printf("Please enter an integer: "); scanf("%d", &x);

    printf("Fibonacci sequence up to %d:\n", x);
    for (int i = 0; i <= x; i++) {
        printf("%d ", fibonacci_linear(i));
    }
    printf("\n");
    return 0;
}