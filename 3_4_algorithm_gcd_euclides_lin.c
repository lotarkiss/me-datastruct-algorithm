#include <stdio.h>

int euclides_gcd(int a, int b) {
    if (a < 0) a *= -1;
    if (b < 0) b *= -1;
    if (b > a) {
        int tmp = a;
        a = b;
        b = tmp;
    }

    int step = 0;
    while (b) {
        printf("-- Step %d --\n", ++step);
        printf("Input: a=%d, b=%d\n", a, b);
        int r = a % b;
        a = b;
        b = r;
        printf("Output: a=%d, b=%d\n", a, b);
    }
    return a;
}

int main()
{
    int a, b = 0;
    printf("Please enter an integer for A: "); scanf("%d", &a);
    printf("Please enter an integer for B: "); scanf("%d", &b);

    printf("The greatest common divisor of %d and %d is %d.\n", a, b, euclides_gcd(a, b));
    return 0;
}