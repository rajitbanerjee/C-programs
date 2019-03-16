/*
Author: Raj B (rajit.banerjee@ucdconnect.ie)
---
Decimal to binary conversion
---
15.10.18
*/

#include <stdio.h>
#define MAX 100
int main(void)
{
  int i, N, num, x = 0;
  int a[MAX];

  printf("\nEnter N: ");
  scanf("%d", &N);

  num = N; //making a copy variable num, to store N
  while(num > 0)
  {
    a[x++] = num%2; //storing binary digits in a[x] then incrementing x in each iteration of while loop
    num /= 2; //updating num
  }

  printf("Binary representation: ");
  for(i = x-1; i>=0; i--)
   printf("%d", a[i]); //printing out binary representation
  printf("\n");

  return 0;
}
