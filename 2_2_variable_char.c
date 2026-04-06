#include <stdio.h>
#include <math.h>

int main()
{
    printf("On Windows use \"chcp 65001\" to set UTF-8 code page for correct character input.\n");
    
    char buf[5] = {0}, *p = buf;
    printf("Please enter an character: "); scanf("%4s", buf);

    printf("The character you entered is '%s' and its UTF-8 code is", buf);
    while (*p) {
        printf(" %02X", (unsigned char)*p);
        p++;
    }  
    printf(".\n");

    printf("The character's UTF-8 code in binary is");
    p = buf;
    while (*p) {
        printf(" ");
        for (int i = 7; i >= 0; i--) 
            printf("%d", ((*p >> i) & 1));
        p++;
    }
    printf(".\n");

    return 0;
}