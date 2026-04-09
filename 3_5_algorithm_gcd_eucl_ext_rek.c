#include <stdio.h>

typedef struct {
    int d_star;
    int x_star;
    int y_star;
} euclides_ext_rec_gcd_t;

int step = 1;

euclides_ext_rec_gcd_t euclides_ext_rec_gcd(int a, int b) {
    if (a < 0) a *= -1;
    if (b < 0) b *= -1;
    if (b > a) {
        int tmp = a;
        a = b;
        b = tmp;
    }

    if (b == 0) {
        printf("%d\t | %d\t | %d\t | -\t | %d\t | %d\t | %d\t | %d\n",
               step--, a, b, a, a, 1, 0);
        return (euclides_ext_rec_gcd_t){a, 1, 0};
    }

    step++;
    euclides_ext_rec_gcd_t temp = euclides_ext_rec_gcd(b, a % b);

    int x = temp.y_star;
    int y = temp.x_star - (a / b) * temp.y_star;

    printf("%d\t | %d\t | %d\t | %d\t | %d\t | %d\t | %d\t | %d\n",
           step--, a, b, a / b, a % b,
           temp.d_star, x, y);

    return (euclides_ext_rec_gcd_t){temp.d_star, x, y};
}

int main() {
    int a, b;

    printf("Please enter an integer for A: ");
    scanf("%d", &a);
    printf("Please enter an integer for B: ");
    scanf("%d", &b);

    printf("Step\t | A\t | B\t | q\t | r\t | d*\t | x*\t | y*\n");

    euclides_ext_rec_gcd_t res = euclides_ext_rec_gcd(a, b);

    printf("\nThe greatest common divisor of %d and %d is %d.\n",
           a, b, res.d_star);

    return 0;
}