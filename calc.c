/*
Author: Raj Banerjee (rajit.banerjee@ucdconnect.ie)
Simple Calculator
02.10.2018
*/

#include <stdio.h>

int main(void)
{
  int a, b; //to store the operands
  char c; //to store the operator +, -, * or /

  printf("\nEnter the expression to be evaluated: ");
  //Taking input
  scanf("%d %c%d", &a, &c, &b);

  //Addition
  if (c == '+')
    printf("\n %d + %d = %d\n", a, b, (a+b));

  //Subtraction
  else if (c == '-')
    printf("\n %d - %d = %d\n", a, b, (a-b));

  //Multiplication
  else if (c == '*')
    printf("\n %d * %d = %d\n", a, b, (a*b));

  //Division
  else if (c == '/')
  {
    if (b == 0) //checking division by 0
      printf("Error. Division by zero.");
    else
      printf("\n %d / %d = %3.5f\n", a, b, ((double)a/(double)b)); 
      //type casting to double to avoid removal of remainder
  }

  //Wrong operator
  else
    printf("\nInvalid operator. Please try again.");
  return 0;
}
