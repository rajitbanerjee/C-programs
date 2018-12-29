/*
Author: Raj B (rajit.banerjee@ucdconnect.ie)
---
Swap 2 numbers
---
19.12.18
*/

#include <stdio.h>
void swap(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}
int main(void)
{
    int a = 10, b = 20;
    swap(&a, &b);
    printf("\na = %d, b = %d\n", a, b);
    return 0;
}