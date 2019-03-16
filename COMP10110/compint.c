/*
Author: Raj Banerjee (rajit.banerjee@ucdconnect.ie)
---
Compound Interest
---
01.10.2018
*/

#include <stdio.h>
#include <math.h>

int main(void)
{
  double A, P, r, n;
  int k, op;

  k = 12; //Assume k = 12

  printf("\nWhich one do you want to compute? Choose 1, 2, 3 or 4.");
  printf("\n1. Final Amount, A");
  printf("\n2. Principal Amount, P");
  printf("\n3. Simple Interest Rate, r");
  printf("\n4. Time in years, n");
  printf("\n\nChoice: ");
  scanf("%i", &op);

  //Case 1: Computing A
  if(op == 1)
  {
    printf("\nPlease enter the starting principal (P): ");
    scanf("%lf", &P);
    printf("Please enter the interest rate (as percentage rate per annum) (r): ");
    scanf("%lf", &r);
    printf("Please enter the number of years (n): ");
    scanf("%lf", &n);

    if(P < 0 || r < 0 || n < 0)
    {
      printf("\nError in input values. Please try again.");
      return 0;
    }

    A = P * pow(1 + r/(100*k), n*k);
    printf("\nThe final accumulated amount (A): %.2f", A);

  }

  //Case 2: Computing P
  else if(op == 2)
  {
    printf("\nPlease enter the final accumulated (A): ");
    scanf("%lf", &A);
    printf("Please enter the interest rate (as percentage rate per annum) (r): ");
    scanf("%lf", &r);
    printf("Please enter the number of years (n): ");
    scanf("%lf", &n);

    if(A < 0 || r < 0 || n < 0)
    {
      printf("\nError in input values. Please try again.");
      return 0;
    }

    P = A / pow(1 + r/(100*k), n*k);
    printf("\nThe starting principal (P) is: %.2f", P);

  }

  //Case 3: Computing r
  else if(op == 3)
  {
    printf("\nPlease enter the final accumulated (A): ");
    scanf("%lf", &A);
    printf("Please enter the principal ammount (P): ");
    scanf("%lf", &P);
    printf("Please enter the number of years (n): ");
    scanf("%lf", &n);

    if(A < 0 || P < 0 || n < 0)
    {
      printf("\nError in input values. Please try again.");
      return 0;
    }

    r = (pow(A/P, 1/(n*k)) - 1) * 100 * k;
    printf("\nThe interest rate (as percentage rate per annum) (r): %.2f", r);

  }

  //Case 4: Computing n
  else if(op == 4)
  {
    printf("\nPlease enter the final accumulated (A): ");
    scanf("%lf", &A);
    printf("Please enter the principal ammount (P): ");
    scanf("%lf", &P);
    printf("Please enter the interest rate (as percentage rate per annum) (r): ");
    scanf("%lf", &r);

    if(A < 0 || P < 0 || r < 0)
    {
      printf("\nError in input values. Please try again.");
      return 0;
    }

    n = log(A/P) / (log (1 + r/(100*k)) * k);
    printf("\nThe number of years required to reach this amount (n): %.2f", n);

  }

  else
    printf("Wrong choice. Please try again.");

  return 0;
}
