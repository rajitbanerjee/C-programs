/*
Author: Raj B (rajit.banerjee@ucdconnect.ie)
---
Program	that asks the user to enter a number and then prints out the multiplication tables for the 
number. The output of the program should look something like this:
Which number would you like to print the tables for? 8
8	times	tables:
0	x	8	=	0
1	x	8	=	8
2	x	8	=	16
3	x	8	=	24
4	x	8	=	32
5	x	8	=	40
6	x	8	=	48
7	x	8	=	56
8	x	8	=	64
9	x	8	=	72
10	x	8	=	80
11	x	8	=	88
12	x	8	=	96
---
04.11.18
*/

#include <stdio.h>
int main(void)
{
  int n, i;
  printf("Which number would you like to print the tables for?\t");
  scanf("%d", &n);
  printf("%d times tables: ", n);
  for(i = 0; i<=12; i++)
    printf("\n%d x %d = %d", i, n, i*n);
  return 0;
}
