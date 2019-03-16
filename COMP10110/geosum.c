/*
Author: Raj B (rajit.banerjee@ucdconnect.ie)
---
Program	to check the formula for a geometric series. a + a r + a r^2 + … + a r^(N-1)
Then compute the expression: a * (1-r^N)/(1-r)
---
16.12.18
*/

#include <stdio.h>
#include <math.h> 
#include <stdlib.h>

int main(void)
{
    double a, r, sum = 0, sum2 = 0;
    int N;
    printf("Enter a, r, N:\n");
    scanf(" %lf%lf%d", &a, &r, &N);
    for(int i = 0; i<N; i++)
    {
        sum += a * pow(r, i);
    }
    sum2 = (a * (1 - pow(r, N)))/(1-r);
    printf("\nSum, using loop:\t%f\n", sum);
    printf("Sum, using formula:\t%f\n", sum2);
    printf("\nDifference: %f\n", fabs(sum-sum2));
    return 0;     
}