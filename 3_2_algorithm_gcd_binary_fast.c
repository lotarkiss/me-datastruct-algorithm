#include <stdio.h>

void xchg(int* a, int *b) {
    int tmp = (*a);
    (*a) = (*b);
    (*b) = tmp;
}

void printBinary(int n) {
    int leadingZero = 1;
    for (int i = 31; i >= 0; i--) {
        int bit = (n >> i) & 1;
        if (!leadingZero || bit) {
            printf("%d", bit);
            leadingZero = 0;
            if (i % 8 == 0) printf(" ");
        }
    }
}

int binary_gcd(int a, int b) {
    if (a < 0) a *= -1;
    if (b < 0) b *= -1;
    if (b > a) xchg(&a, &b);

    int c = 1;
    int step = 0;
    while (a && b) 
    {
        printf("-- Step %d --\n", ++step);
        printf("Input: a="); printBinary(a); printf(" b="); printBinary(b); printf(" c="); printBinary(c); printf("\n");
        int p_a = a & 1;
        int p_b = b & 1;

        printf("Last bits: p_a=%d, p_b=%d\n", p_a, p_b);
        if (!p_a && !p_b) {
            c <<= 1; 
            a >>= 1;
            b >>= 1;  
        }
        else if (!p_a && p_b) {
            a >>= 1;
        }
        else if (p_a && !p_b) {
            b >>= 1;
        }
        else if (p_a && p_b) {
            a = (a - b) >> 1;
        }

        if (a < b) xchg(&a, &b);

        printf("Output: a="); printBinary(a); printf(" b="); printBinary(b); printf(" c="); printBinary(c); printf("\n");
    }

    int d_star;
    if (!a) 
        d_star = c * b;
    else 
        d_star = c * a;
    return d_star;
}

int main()
{
    int a, b = 0;
    printf("Please enter an integer for A: "); scanf("%d", &a);
    printf("Please enter an integer for B: "); scanf("%d", &b);

    printf("The greatest common divisor of %d and %d is %d.\n", a, b, binary_gcd(a, b));
    return 0;
}