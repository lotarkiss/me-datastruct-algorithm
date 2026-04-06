#include <stdio.h>
#include <stdint.h>

int main() {
    float a;
    printf("Please enter a float: ");
    scanf("%f", &a);

    uint32_t bits = *(uint32_t *)&a; 
    printf("Float: %f, hex: %08X\n", a, bits);

    uint32_t exp_raw = (bits >> 23) & 0xFF;  
    int exp = (int)exp_raw - 127;         
    uint32_t mantissa = bits & 0x7FFFFF; 
    printf("Mantissa and exponent (binary, normalised): 1."); 
    for (int i = 22; i >= 0; i--) {
        printf("%d", (mantissa >> i) & 1);
    }
    printf(" x 2^%d\n", exp);

    printf("Bits: ");
    for (int i = 31; i >= 0; i--) {   
        printf("%d", (bits >> i) & 1);
        if (i == 31 || i == 23) printf(" "); 
    }
    printf("\n");
}