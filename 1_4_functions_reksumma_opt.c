#include <stdio.h>

static int callCount = 0;

int RekSumma(int n, int m)
{
    callCount++;
    printf("int RekSumma(%d, %d) called.\n", n, m);

    int RetVal = 0;
    if (n == m) {
        RetVal = m;
        printf("int RekSumma(%d, %d) returned with %d.\n", n, m, RetVal);
        return RetVal;
    }
    else {
        RetVal = RekSumma(n, (n + m) / 2) + RekSumma((n + m) / 2 + 1, m);
        printf("int RekSumma(%d, %d) returned with %d.\n", n, m, RetVal);
        return RetVal;
    }
}

int main()
{
    int n = 0;
    printf("Please enter an integer: "); scanf("%d", &n);

    int result = RekSumma(1, n);
    printf("The recursive sum of %d is %d\n", n, result);
    printf("RekSumma was called %d times.\n", callCount);
    return 0;
}