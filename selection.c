/*
Author: Raj B (rajit.banerjee@ucdconnect.ie)
---
Program to compute the kth largest value > 0.5 in an array
---
15.10.18
*/

#include <stdio.h>
#define MAX_SIZE 5000

int main(void)
{
  int i, j, k, maxindx, n;
  double a[MAX_SIZE];
  double tmp, max;

  printf("\nEnter no. of array elements: ");
  scanf("%d", &n);

  printf("Enter array elements:\n");
  for(i = 0; i < n; i++)
   scanf("%lf", &a[i]);


  printf("\nEnter the vaue of k: ");
  scanf("%d", &k);

  for (i = 0;i < k;i++)
  {
   max = a[i];
   maxindx = i;
   for (j = i + 1; j < n; j++)
	 {
	  if (a[j]>max && a[j] > 0.5)
	    {
	      max = a[j];
	      maxindx = j;
	    }
  	}
    tmp = a[i];
    a[i] = a[maxindx];
    a[maxindx] = tmp;
   }

   if(a[k-1] <= 0.5)
     printf("There are fewer than %d numbers > 0.5 in the array.\n", k);
   else
     printf("The %dth largest number greater than 0.5 is %lf\n", k, a[k-1]);
  return 0;
}
