/*
Author: Raj B (rajit.banerjee@ucdconnect.ie)
---
Star pattern
---
19.12.18
*/

#include <stdio.h>

int main(void)
{
    int n;
    printf("\nEnter no. of lines: ");
    scanf("%d", &n);
    for(int i = 1; i<=n;i++)
    {
        for(int j = 1; j<=i; j++)
            printf("*");
        printf("\n");
    }
    return 0;
}
