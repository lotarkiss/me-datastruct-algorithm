#include <stdio.h>
#include <math.h>

int main()
{
    float x = 0;
    printf("Please enter a float: "); scanf("%f", &x);

    printf("The floor of %f is %f\n", x, floorf(x));
    printf("The ceil of %f is %f\n", x, ceilf(x));
    printf("The round of %f is %f\n", x, roundf(x));
    printf("The trunc of %f is %f\n", x, truncf(x));
    printf("The fract of %f is %f\n", x, x - truncf(x));

    return 0;
}