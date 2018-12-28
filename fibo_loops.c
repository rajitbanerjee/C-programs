/*
Author: Raj B (rajit.banerjee@ucdconnect.ie)
---
Fibonacci sequence - using for & while loops
---
08.10.2018
*/

#include <stdio.h>
int main(void)
{
  int n;
  while (1>0)
  {
  printf("\nEnter n: ");
  scanf("%d", &n);

  if(n <= 1)
  {
   printf("Fibonacci sequence:\t0\n");
   return 0;
  }
  else if (n == 2)
  {
  printf("Fibonacci sequence:\t0\t1\n");
  return 0;
  }
  else
   break;

  }

  //USING for loop
  int a = 0, b = 1, c = 0;
  printf("\nFibonacci sequence using for-loop:\t%d\t%d ", a, b);
  for(int i = 3; i <= n; i++)
  {
    c = a + b;
    printf("\t%d", c);
    a = b;
    b = c;
  }

  //USING while loop
  a = 0; b = 1; c = 0;
  printf("\nFibonacci sequence using while-loop:\t%d\t%d", a, b);
  while(n-->2)
  {
    c = a + b;
    printf("\t%d ", c);
    a = b;
    b = c;
  }

  printf("\n");
  return 0;
}
