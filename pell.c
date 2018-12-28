/*
Author: Raj B (rajit.banerjee@ucdconnect.ie)
---
Pell sequence P[0] = 0,	P[1] =	1, P[N]	= 2*P[N-1] + P[N-2]
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

  if(N < 0)
    printf("\nPlease enter N > 0.\n");
  else
   break;
  }

  int P[N]; //declaring VLA

  P[0] = 0; P[1] = 1;
  for(i = 2; i < N; i++)
   P[i] = 2 * P[i-1] + P[i-2]; //computing series

  printf("\nFirst %d Pell numbers: ", N);
  for(i = 0; i < N; i++)
   printf("%d ", P[i]); //printing series

  return 0;
}
