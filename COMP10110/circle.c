/*
Author: Raj B (rajit.banerjee@ucdconnect.ie)
---
Write a function to compute the area	
of a circle, as PI*radius*radius.
---
19.11.18
*/

#include <stdio.h>
#include <math.h>
double area(double r); //declare function
int main(void)
{
  double r;

  printf("Enter the radius:\n");
  scanf("%lf", &r);

  //printing the circle area by calling area() function
  //area is printed correct to 2 decimal places for simplicity
  printf("\nArea of circle: %.2f\n", area(r));

  return 0;
}
double area(double r)
{
    //returning the circle area value
    return M_PI * r * r;
}
