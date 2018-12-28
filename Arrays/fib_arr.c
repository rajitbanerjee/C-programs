/*
Author: Raj Banerjee (rajit.banerjee@ucdconnect.ie)
---
Fibonacci sequence - for large number of terms
---
08.10.2018
*/

#include <stdio.h>
int main(void)
{
  int n, i;
  printf("\nEnter n: ");
  scanf("%d", &n);
  //for large number of terms n (e.g. n = 50), we can use an array to store the sequence
  //also, we should store the numbers as double, not int,to get greater precision
  //this is because the numbers become greater than allowed size for int

  double fibo[n];
  fibo[0] = 0; fibo[1] = 1;

  for(i = 2; i < n; i++)
    fibo[i] = fibo [i-1]  + fibo[i-2];//Computing series

  printf("\nFibonnaci sequence: ");
  for(i = 0; i < n; i++)
   printf("%.0f ", fibo[i]); //printing series

  printf("\n");
  return 0;
}
