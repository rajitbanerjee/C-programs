/*
Author: Raj B (rajit.banerjee@ucdconnect.ie)
---
Program	to find and display the	largest	value in an integer array
that is	divisible by 3.
Sample	input and output:
1 15 2 16 3 17 4 18 5 19
The largest number divisible by 3 is 18
---
28.10.18
*/

#include <stdio.h>
#define N 10

int main(void)
{
  int a[N], max, i;

  printf("\nEnter array elements:\n");
  for(i = 0; i<N; i++)
    scanf("%d", &a[i]);
  max = a[0];

  for(i=0; i<N; i++)
    if(a[i]>max && a[i]%3==0)
      max = a[i];

  if(max%3!=0)
    printf("There is no element in the array that's divisible by 3.\n");
  else
    printf("The largest number divisible by 3 is %d.\n", max);
  return 0;
}
