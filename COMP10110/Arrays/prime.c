/*
Author: Raj B (rajit.banerjee@ucdconnect.ie)
---
Filter an array of numbers from 2 to (N - 1) to keep only the prime numbers
---
24.10.18
*/
#include <stdio.h>
#define MAX 5000
int prime(int a);

int main(void)
{
  int a[MAX], N, i, j, k = 0; //declaration and initialisation
  printf("\nEnter N: ");
  scanf("%d", &N);

  for(i=0; i<N-2; i++)
    a[i] = i+2; //storing numbers in array: 2 to N-1


  printf("Original array\t: ");
  for(i=0; i<N-2; i++)
    printf(" %d", a[i]); //print orignal array

  for(i=0; i<N-2; i++)
    for(j=i+1; j<N-2; j++)
      if(a[j]%a[i]==0 && a[i]!=1) //checking for non-primes
        a[j]=1;

  for(i=0; i<N-2; i++)
    if(a[i]!=1) a[k++] = a[i]; //now a[] contains the primes till index k

  printf("\nPrime array\t: ");
  for(i=0; i<k; i++)
    printf(" %d", a[i]); //printing primes

  printf("\n");
  return 0;
}
