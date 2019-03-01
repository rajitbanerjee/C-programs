/*
Author: Raj B (rajit.banerjee@ucdconnect.ie)
---
Write a	function to compute the	area of	a triangle, according	
to the formula	[½ (base * height)].
---
19.11.18
*/

#include <stdio.h>
double area(double b, double h); //declare function

int main(void)
{
  double b, h;

  printf("Enter the base:\n");
  scanf("%lf", &b);
  printf("Enter the height:\n");
  scanf("%lf", &h);

  //printing the triangle area by calling area() function
  //area is printed correct to 2 decimal places for simplicity
  printf("\nArea of triangle: %.2f\n", area(b, h));

  return 0;
}
double area(double b, double h)
{
    //returning the traingle area value
    return 0.5 * b * h; 
}
