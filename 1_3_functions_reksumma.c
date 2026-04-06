#include <stdio.h>

static int callCount = 0;

int RekSumma(int n)
{
    callCount++;
    printf("int RekSumma(%d) called.\n", n);

    int RetVal;
    if (n == 1) {
        RetVal = 1;
        printf("int RekSumma(%d) returned with %d.\n", n, RetVal);
        return RetVal;
    }
    else {
        RetVal = RekSumma(n - 1) + n;
        printf("int RekSumma(%d) returned with %d.\n", n, RetVal);
        return RetVal;
    }
}

int main()
{
    int n = 0;
    printf("Please enter an integer: "); scanf("%d", &n);

    int result = RekSumma(n);
    printf("The recursive sum of %d is %d\n", n, result);
    printf("RekSumma was called %d times.\n", callCount);
    return 0;
}