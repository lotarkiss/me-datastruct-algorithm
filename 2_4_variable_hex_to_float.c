#include <stdio.h>
#include <stdint.h>

int main() {
    uint32_t bits = 0;
    printf("Please enter a float in hexadecimal: ");
    scanf("%08X", &bits);

    float a = *(float *)&bits; 
    printf("Float: %f, hex: %08X\n", a, bits);

    uint32_t exp_raw = (bits >> 23) & 0xFF;  
    int exp = (int)exp_raw - 127;         
    uint32_t mantissa = bits & 0x7FFFFF; 
    printf("Mantissa and exponent (binary, normalised): 1."); 
    for (int i = 22; i >= 0; i--) {
        printf("%d", (mantissa >> i) & 1);
    }
    printf(" x 2^%d\n", exp);

    if (exp_raw == 0xFF) {
        if (mantissa == 0) {
            printf("The float is %s infinity.\n", (bits >> 31) ? "negative" : "positive");
        } else {
            printf("The float is NaN.\n");
        }
    } else if (exp_raw == 0) {
        printf("The float is a denormalized number.\n");
    } else {
        printf("The float is a normalized number.\n");
    }

    printf("Bits: ");
    for (int i = 31; i >= 0; i--) {   
        printf("%d", (bits >> i) & 1);
        if (i == 31 || i == 23) printf(" "); 
    }
    printf("\n");
}