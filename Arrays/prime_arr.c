/*
Author: Raj B (rajit.banerjee@ucdconnect.ie)
---
On the ith iteration, if isprime[i] is true, set isprime[j] to false for all indices j which are 
multiples of i. Finally, write out all indices i for which isprime[i] is true.
---
31.10.18
*/

#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	int N, i, j;
	printf("\nEnter N: ");
  	scanf("%d", &N);

  	int a[N-2];
  	bool isprime[N-2];
  	for(i=0; i<N-2; i++)
  	{
   		a[i] = i+2;
    		isprime[i] = true;
  	}

  	for(i=0; i<N-2; i++)
    	    if(isprime[i]==true)
      	        for(j=i+1; j<N-2; j++)
        	    if((j+2)%(i+2)==0)
          	        isprime[j] = false;


  	printf("Prime numbers: ");
  	for(i=0; i<N-2; i++)
    	    if(isprime[i]==true)
      	        printf("%d ", a[i]);
  
  	return 0;
}
