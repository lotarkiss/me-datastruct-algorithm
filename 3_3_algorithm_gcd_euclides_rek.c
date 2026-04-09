#include <stdio.h>

int euclides_rec_gcd(int a, int b) {
    if (a < 0) a *= -1;
    if (b < 0) b *= -1;
    if (b > a) {
        int tmp = a;
        a = b;
        b = tmp;
    }
    
    static int step = 0;
    printf("-- Step %d --\n", ++step);
    if (b == 0) 
        return a;
    else {
        printf("Input: a=%d, b=%d\n", a, b);
        printf("Output: a=%d, b=%d\n", b, a % b);
        return euclides_rec_gcd(b, a % b);
    }
}

int main()
{
    int a, b = 0;
    printf("Please enter an integer for A: "); scanf("%d", &a);
    printf("Please enter an integer for B: "); scanf("%d", &b);

    printf("The greatest common divisor of %d and %d is %d.\n", a, b, euclides_rec_gcd(a, b));
    return 0;
}