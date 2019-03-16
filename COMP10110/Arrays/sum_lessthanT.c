/*
Author: Raj B (rajit.banerjee@ucdconnect.ie)
---
Program	that reads in an integer array a[] and an integer value T and outputs the sum of values	in a[] that
are less than T e.g. if a[]={1,2,3,4,5,4,3,2,1} and T = 4, then	the program should output 12 (1+2+3+3+2+1).
---
31.10.18
*/

#include <stdio.h>
#define N 5

int main(void)
{
  int a[N], i = 0, T = 0, sum = 0;

  printf("\nEnter array elements: \n");
  for(i=0; i<N; i++)
    scanf("%d", &a[i]);


  printf("Enter T: ");
  scanf("%d", &T);

  //calculation
  for(i=0; i<N; i++)
    if(a[i]<T) sum += a[i];

  printf("\nSum of numbers less than %d is %d.\n", T, sum);
  return 0;
}
