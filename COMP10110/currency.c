/*
Author: Raj B (rajit.banerjee@ucdconnect.ie)
---
Write a function to input an amount in Euros and convert it to Sterling,	
assuming 1E = 0.80 Stg.
---
19.11.18
*/

#include <stdio.h>
double convert(double a); //declare function

int main(void)
{
  double amt;

  printf("\nAmount in Euros:\t");
  scanf("%lf", &amt);

  //printing the value in Sterling by calling convert() function
  //area is printed correct to 2 decimal places 
  printf("Amount in Sterling:\t%.2f\n", convert(amt));

  return 0;
}
double convert(double a)
{
    //returning the amount in Sterling
    return 0.8 * a;
}
