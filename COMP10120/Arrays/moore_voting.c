/* 
Author: Raj B (rajit.banerjee@ucdconnect.ie)
---
Find, if it exists, a value that occurs more than N/2 times in
an array a[]. 
Moore's Voting Algorithm 
---
28.12.2018
*/

#include <stdio.h>
#define N 5

int main(void)
{
  int a[N], counter, val, i;

  printf("\nEnter array elements:\n");
  for (i = 0; i < N; i++)
     scanf("%d", &a[i]);
    

  counter = 0;
  for (i = 0; i < N; i++)
    {
      if (counter == 0)
	      val = a[i];
      if (a[i] == val)
	      counter++;
      else
	      counter--;
    }
  
  counter = 0;
  for (i = 0; i < N; i++)
    if (a[i] == val)
      counter++;
  printf("\nValue = %d, frequency = %d\n", val, counter);

  if (counter > N/2)
    printf("There is a majority value in the array.\n");
  else
    printf("There is no majority value in the array.\n");

  return 0;
}
      
  
  