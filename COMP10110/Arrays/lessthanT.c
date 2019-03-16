/*
Author: Raj B (rajit.banerjee@ucdconnect.ie)
---
Program	that reads in an integer array a[] and an integer value T and counts the number	of values	
in a[] that are	less than T e.g. if a[]={1,2,3,4,5,4,3,2,1} and	T=4, then the program should
output 6 since there are 6 values in the array less than 4.
---
28.10.18
*/

#include <stdio.h>
#define N 10

int main(void)
{
    int a[N], T, i, c = 0;

    printf("\nEnter %d elements: ", N);
    for(i=0; i<N; i++)
        scanf("%d", &a[i]);

    printf("Enter T: ");
    scanf("%d", &T);

    for(i=0; i<N; i++)
        if(a[i] < T) c++;

    printf("There are %d elements less than %d.\n", c, T);
    return 0;
}
