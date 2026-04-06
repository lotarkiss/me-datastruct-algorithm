#include <stdio.h>

int main()
{
    int a, b = 0;
    printf("Please enter a boolean for A (0 or 1): "); scanf("%d", &a);
    printf("Please enter a boolean for B (0 or 1): "); scanf("%d", &b);

    printf("Unary operations on A:\n");
    printf("Negation (!A) is %d\n", !a);
    printf("Identity (A) is %d\n", a);

    printf("Binary operations on A and B:\n");
    printf("Disjunction (A || B) is %d\n", a || b);
    printf("Conjunction (A && B) is %d\n", a && b);
    printf("Ambivalence (A ^ B) is %d\n", a ^ b);
    printf("Equivalence (A == B) is %d\n", a == b);
    printf("Implication (A -> B) is %d\n", !a || b);
    printf("Peirce's arrow (A NOR B) is %d\n", !(a || b));
    printf("Sheffer's stroke (A NAND B) is %d\n", !(a && b));

    return 0;
}