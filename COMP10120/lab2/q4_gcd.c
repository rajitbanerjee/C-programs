/*
 * Author: Rajit Banerjee, 18202817
 * Pset 2, Q4
 * 05.02.2019
 */
#include <stdio.h>

//function prototype: 2 integers as parameters
//returns greatest common divisor as integer
int gcd (int, int);

//main() function
int main(void)
{
    //variables to store 2 numbers entered by user
    int x, y;

    //prompt user for input
    printf("\nEnter two numbers:\n");
    scanf("%d %d", &x, &y);

    //display GCD by calling gcd(x, y)
    printf("\nGreatest common divisor is %d.\n", gcd(x, y));


    return 0;
}


//function takes 2 integers as parameters
//returns greatest common divisor as integer
//Euclid's algorithm for computing GCD
int gcd(int x, int y)
{
    //base case, returns x if y is 0
    if (y == 0)
    {
        return x;
    }

    //recursive case
    else
    {
        return gcd(y, x % y);
    }
}