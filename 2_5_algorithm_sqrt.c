#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct {
    char group;
    int64_t testval;
    char probe;
    int64_t _double;
    int64_t prod;
    int64_t remainder;
} STEP;

double book_sqrt(double s, int nstep) {
    STEP *steps = calloc(nstep, sizeof(STEP));
    memset(steps, 0, nstep * sizeof(STEP));
    printf("Calculating the square root of %f with %d steps.\n", s, nstep);

    int divisionCount = 0;
    int muliplicationCount = 0;
    while ((int64_t)(s) > 0) { 
      s /= 100.0;
      divisionCount++;
    }
    printf("Initial scaled value: %f\n", s);
    printf("Number of divisions by 100: %d\n", divisionCount);

    double retVal = 0;
    for (int i = 0; i < nstep; i++) {
        s = s * 100.0;
        steps[i].group = (int64_t)(s) % 100;
        steps[i].testval = 
          (i == 0 ? 0 : steps[i - 1].remainder) * 100 + 
          steps[i].group;

        steps[i].probe = 10;
        do 
        {
            steps[i].probe--; 
            steps[i]._double = 0;
            for (int j = 0; j < i; j++) {
                steps[i]._double *= 10;
                steps[i]._double += steps[j].probe;
            }
            steps[i]._double *= 2;
            steps[i].prod    = (steps[i]._double * 10 + steps[i].probe) * steps[i].probe;
        }
        while (steps[i].prod > steps[i].testval);
        steps[i].remainder = steps[i].testval - steps[i].prod;
        retVal = retVal * 10 + steps[i].probe;
        muliplicationCount++;

        printf("Step %d: group=%d, testval=%lld, probe=%d, double=%lld, prod=%lld, remainder=%lld\n", 
            i + 1, steps[i].group, steps[i].testval, steps[i].probe, steps[i]._double, steps[i].prod, steps[i].remainder);

        if (steps[i].remainder == 0)
          break;
    } 

    printf("Final result before scaling back: %f\n", retVal);
    printf("Number of multiplications by 10: %d\n", muliplicationCount);
    for (int i = 0; i < muliplicationCount - divisionCount * 2 + 1; i++) {
        retVal /= 10.0;
    }

    printf("Scaled back result: %f\n", retVal);
    free(steps);
    return retVal;
}

int main()
{
    double x = 0;
    printf("Please enter a double: "); scanf("%lf", &x);

    if (x < 0) {
        printf("Negative input, square root is not defined in real numbers.\n");
    } 
    else {   
        printf("The square root of %f is approximately %f\n", x, book_sqrt(x, 5));
    }

    return 0;
}