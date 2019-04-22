/*
Author: Rajit Banerjee, 18202817
Pset 7, Q1 - using macros to find minimum of 4 numbers
26.03.19
*/
#include <stdio.h>
#include <stdlib.h>
/*****************************************************************************/
//using the ternary conditional operator to find the minimum of two numbers
#define MIN(x, y) ((x < y) ? x : y)
/*****************************************************************************/
//re-use the macro MIN(x, y) to find minimum of four numbers
#define MIN_FOUR(p, q, r, s) (MIN(MIN(p, q), MIN(r, s)))
/*****************************************************************************/
//main() method, program takes command line arguments
int main(int argc, char *argv[])
{
    //array to store 4 numbers
    int nums[4];

    //print error message if number of arguments are invalid
    if (argc != 5)
    {
        printf ("\nInvalid number of arguments!\n");
        return 0;
    }

    //convert the strings in argv[] to integers and store them in nums[]
    for (int i = 0; i < 4; i++) 
        nums[i] = atoi(argv[i + 1]);
    
    //call macro to find minimum of 4 numbers entered
    printf("Minimum: %d\n", MIN_FOUR(nums[0], nums[1], nums[2], nums[3]));
    
    return 0;
}
/*****************************************************************************/
