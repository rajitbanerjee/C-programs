/*
Author: Raj Banerjee (rajit.banerjee@ucdconnect.ie)
---
Sort 4 values w, x, y, z and modify them as w < x < y < z
---
08.10.2018
*/

#include <stdio.h>
int main(void)
{
  double w, x, y, z; //variable declaration
  printf("\nEnter 4 floating point values: ");
  scanf("%lf%lf%lf%lf", &w, &x, &y, &z); //input

  double a[4]; //declare array
  a[0] = w; a[1] = x;
  a[2] = y; a[3] = z;

  //Bubble sort
  for(int i = 0; i < 3; i++)
   for(int j = 0; j < 3-i; j++)
    if(a[j] > a[j + 1])
    {
      double t = a[j];
      a[j] = a[j+1];
      a[j+1] = t; //swap
    }
  w = a[0]; x = a[1];
  y = a[2]; z = a[3];

  //printing output
  printf("\nw = %f", w);
  printf("\nx = %f", x);
  printf("\ny = %f", y);
  printf("\nz = %f\n", z);

  return 0;
}
