/*
Author: Raj B (rajit.banerjee@ucdconnect.ie)
---
A palindrome is	a sequence that	reads the same backwards as forwards.
a[]={1,2,3,4,5,4,3,2,1} is a palindrome.
---
31.10.18
*/

#include <stdio.h>
#define N 5

int main(void)
{
    int a[N], i, f = 0;

    printf("\nEnter elements in array:\n");
    for(i=0; i<N; i++)
        scanf("%d", &a[i]);

    //f = 1 if non-palindrome
    for(i = 0; i < N/2; i++)
        if(a[i] != a[N-i -1])
            f = 1;

    if(f==0)
        printf("Array a[] is a palindrome.\n");
    else
        printf("Array a[] is NOT a palindrome.\n");
    return 0;
}
