/*
Author: Raj Banerjee (rajit.banerjee@ucdconnect.ie)
---
find the roots of a quadratic equation
---
01.10.2018
*/

#include <stdio.h>
#include <math.h>

int main(void)
{
  double a, b, c; //input values - coefficents
  double r1, r2; //output - roots
  double d; //discriminant

  //Prompting user for input - which is stored in variables a, b & c
  printf("\nEnter the coeffients a, b & c: ");
  scanf("%lf%lf%lf", &a, &b, &c);

  //Special case check: when equation is not quadratic, but linear instead
  if(a == 0)
  {
    printf("\nWhen a = 0, the equation is not quadratic, but linear.");
    printf("\nSolution: %3.2f\n", (-c/b));
    return;
  }

  d = b*b - 4*a*c; //calculate discriminant b^2 - 4ac

  r1 = (-b + sqrt(d))/(2*a); //first root
  r2 = (-b - sqrt(d))/(2*a); //second root

  if(d == 0)
  {
    printf("\nRoots are real and equal."); //case for real and equal roots, r1 = r2
    printf("\nSolution: %3.2f\n", r1);
  }


  else if (d < 0)
    printf("\nRoots are imaginary.\n"); //roots are complex, not real

  else
  {
   printf("\nRoots are real and distinct."); //roots are real, distinct and computable
   printf("\nRoot r1: %3.2f", r1) ;
   printf("\nRoot r2: %3.2f\n", r2) ;
  }

  //When value of a is much less than the value of b, eg. a = 10e-5, b = 10e5, c = 1.0
  //then instead of %f, we can use %e format specifier to give the answer in scientific notation
  return 0;
}
