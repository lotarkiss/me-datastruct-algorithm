#include <stdio.h>

int main()
{
    int a = 0;
    printf("Please enter an integer: "); scanf("%d", &a);
    printf("The integer you entered is %d and its hexadecimal code is %X.\n", a, a);

    printf("The integer code in binary is");
    char *p = (char *)&a;
    for (int j = 0; j < sizeof(int); j++) {
        printf(" ");
            for (int i = 7; i >= 0; i--) 
                printf("%d", (*p >> i) & 1);
        p++;
    } 
    printf(".\n");

    int testVal = 1;
    printf("The system is %s endian, the first byte is %X.\n", 
        (*(unsigned char *)&testVal) ? "little" : "big", 
         *(unsigned char *)&a);

    return 0;
}