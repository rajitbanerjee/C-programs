/*
Author: Raj B (rajit.banerjee@ucdconnect.ie)
---
Min and max element in array
---
19.12.2018
*/
#include <stdio.h>

int main(void)
{
  	int n;

 	while(1)
	{
 		printf("\nEnter the size of the array: ");
 		scanf("%d", &n);
 		if( n < 1)
  			printf("\nPlease enter n > 0.");
 		else
  			break;
 	}

	 double a[n];

 	printf("\nEnter %d numbers: ", n);
 	for(int i = 0; i< n; i++)
  		scanf("%lf", &a[i]);
 	double min = a[0], max = a[0];

  	for(int i = 0; i < n; i++)
    	if (a[i] < min)
      		min = a[i];
    	else if (a[i] > max)
      		max = a[i];

  printf("\nMin = %f, Max = %f\n", min, max);
  return 0;
}
