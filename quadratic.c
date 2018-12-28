/*
Author: Raj B (rajit.banerjee@ucdconnect.ie)
---
Write a	function to compute the roots of a	
quadratic equation, which takes three floating point	
numbers	a, b, c as arguments, as well as an integer argument,	
to indicate which of the two roots to return.
---
19.11.18
*/

#include <stdio.h>
#include <math.h>
double root(double a, double b, double c, int n); //declare function
int main(void)
{
  double a, b, c;

  printf("\nEnter a: ");
  scanf("%lf", &a);
  printf("Enter b: ");
  scanf("%lf", &b);
  printf("Enter c: ");
  scanf("%lf", &c);

  if(a == 0)
  {
      //equation is linear, not quadratic
      printf("\nEquation is linear.");
      printf("\nSolution: %f\n", (-c/b));  
  }
  else if (b*b - 4*a*c < 0)
  {
      //discriminant is less than 0 => roots are imaginary
      printf("\nRoots are imaginary.\n");
  }
  else
  {
      //roots are real
      //printing the roots by calling root() function twice
      printf("\nRoots are real.");
      printf("\nRoot 1:\t%f\n", root(a, b, c, 1));
      printf  ("Root 2:\t%f\n", root(a, b, c, 2));
  }

  return 0;
}
double root(double a, double b, double c, int n)
{
    if(n == 1)
        return (-b + sqrt(b*b - 4*a*c))/(2*a);
    else
        return (-b - sqrt(b*b - 4*a*c))/(2*a);
}
