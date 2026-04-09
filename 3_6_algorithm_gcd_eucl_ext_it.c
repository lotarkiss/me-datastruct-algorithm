#include <stdio.h>

typedef struct {
    int d_star;
    int x_star;
    int y_star;
} euclides_ext_rec_gcd_t;

euclides_ext_rec_gcd_t euclides_ext_gcd(int a, int b) {
    if (a < 0) a *= -1;
    if (b < 0) b *= -1;
    if (b > a) {
        int tmp = a;
        a = b;
        b = tmp;
    }

    int old_r = a, r = b;
    int old_s = 1, s = 0;
    int old_t = 0, t = 1;
    int step = 1;

    printf("Step\t | A\t | B\t | q\t | r\t | d*\t | x*\t | y*\n");

    while (r != 0) {
        int q = old_r / r;
        int rem = old_r % r;

        if (step == 1) {
            printf("%d\t | %d\t | %d\t | %d\t | %d\t | %d\t | n-%d\t | %d\t | %d\n",
                   step, old_r, r, q, rem, old_r, step, 1, 0);
        } else if (step == 2) {
            printf("%d\t | %d\t | %d\t | %d\t | %d\t | %d\t | n-%d\t | %d\t | %d\n",
                   step, old_r, r, q, rem, old_r, step, 0, 1);
        } else {
            int x_star = old_s;
            int y_star = old_t;
            printf("%d\t | %d\t | %d\t | %d\t | %d\t | %d\t | n-%d\t | %d\t | %d\n",
                   step, old_r, r, q, rem, rem, step, x_star, y_star);
        }

        int temp_r = r;
        r = old_r - q * r;
        old_r = temp_r;

        int temp_s = s;
        s = old_s - q * s;
        old_s = temp_s;

        int temp_t = t;
        t = old_t - q * t;
        old_t = temp_t;

        step++;
    }

    printf("%d\t | %d\t | %d\t | -\t | %d\t | %d\t | n-%d\t | %d\t | %d\n",
           step, old_r, r, old_r, old_r, step, old_s, old_t);

    return (euclides_ext_rec_gcd_t){old_r, old_s, old_t};
}

int main() {
    int a, b;

    printf("Please enter an integer for A: ");
    scanf("%d", &a);
    printf("Please enter an integer for B: ");
    scanf("%d", &b);

    euclides_ext_rec_gcd_t res = euclides_ext_gcd(a, b);

    printf("\nThe greatest common divisor of %d and %d is %d.\n",
           a, b, res.d_star);

    return 0;
}