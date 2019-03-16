/*
Author: Raj B (rajit.banerjee@ucdconnect.ie)
---
Program	that continuously reads	a floating point number	from the user,	which represents a value of money in	euro. Conversion rate is 1 euro = 1.37 dollars.
---
04.11.18
*/

#include <stdio.h>
int main(void)
{
  float eur = 0;
  while(1)
  {
    printf("\nEnter value in EUR: ");
    scanf("%f", &eur);
    if(eur<0)
      break;
    printf("Value in USD: %.2f\n", (1.0/1.37) * eur);
  }
  return 0;
}
