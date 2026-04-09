#include <stdio.h>

void xchg(int* a, int *b) {
    int tmp = (*a);
    (*a) = (*b);
    (*b) = tmp;
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
        printf("Input: a=%d, b=%d, c=%d\n", a, b, c);
        // Get the last bits of a and b
        int p_a = a % 2;
        int p_b = b % 2;

        printf("Last bits: p_a=%d, p_b=%d\n", p_a, p_b);
        if (!p_a && !p_b) {
            // If both even, factor out 2
            c *= 2; 
            a /= 2;
            b /= 2;  
        }
        else if (!p_a && p_b) {
            // If a even only, divide a by 2
            a /= 2;
        }
        else if (p_a && !p_b) {
            // If b even only, divide b by 2
            b /= 2;
        }
        else if (p_a && p_b) {
            // If both odd, replace a with (a - b) / 2
            a = (a - b) / 2;
        }

        // Ensure a >= b for next iteration
        if (a < b) xchg(&a, &b);

        printf("Output: a=%d, b=%d, c=%d\n", a, b, c);
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