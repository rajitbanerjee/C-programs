/*
Author: Raj Banerjee (rajit.banerjee@ucdconnect.ie)
---
Factorial - (i) using for, (ii) using while, (ii) computing backwards
---
08.10.2018
*/

#include <stdio.h>
int main(void)
{
  int n;
  printf("\nEnter n to compute factorial: ");
  scanf("%d", &n);
  int f = 1, i;

  //(i) USING for-loop
  for(i = 1; i<=n; i++)
   f *= i;
  printf("\nFactorial using for-loop: %d", f);

  //(ii) USING while-loop
  f = 1; i = 0;
  while(++i <= n)
    f *= i;
  printf("\nFactorial using while-loop: %d", f);

  //(iii) Computing factorial backwards
  f = 1;
  for(i = n; i>0 ; i--)
   f *= i;
  printf("\nFactorial (computing backwards): %d\n", f);

  return 0;
}
