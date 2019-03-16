/*
Author: Raj B (rajit.banerjee@ucdconnect.ie)
---
Pavodan numbers P[1] = P[2] = P[3] = 1, P[N] = P[N-2] + P[N-3], N>=4.
---
08.10.2018
*/

#include <stdio.h>

int main(void)
{
  int N = 0, i;

  while(1 > 0) //always true
  {
  printf("\nEnter N: ");
  scanf("%d", &N); //input N

  if(N < 4)
    printf("\nPlease enter N >= 4.\n");
  else
   break;
  }

  int P[N]; //declaring array
  P[0] = 1; P[1] = 1; P[2] = 1; //first 3 elements = 1

  for(i = 3; i < N; i++)
    P[i] = P[i-2] + P[i-3]; //computing series

  printf("\nFirst %d Pavodan numbers: ", N);
  for(i = 0; i < N; i++)
   printf("%d ", P[i]); //printing series

  return 0;
}
