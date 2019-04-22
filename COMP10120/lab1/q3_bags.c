/*
 * Author: Rajit Banerjee, 18202817
 * Pset 1, Q3
 * 29.01.2019
 */

#include <stdio.h>

int main(void)
{
    //variables for number of bags and total cost
    int bags;
    float cost = 0; //initialise cost to 0

    //prompt user for input: no. of bags
    printf("\nNumber of bags: ");
    scanf("%d", &bags);

    //check for invalid input
    if (bags < 0)
    {
        printf("\nSorry! Number of bags can't be negative.\n");
        return 0; //exit
    }

    //calculate cost of bags

    //case A: 1-10 bags
    if (bags <= 10)
        cost = bags * 10;


    //case B: 11-50 bags
    if (bags > 10 && bags <= 50)
        cost = 10*10 + 9.5*(bags - 10);


    //case C: 51+ bags
    if (bags > 50)
        cost = 10*10 + 9.5*40 + 9*(bags - 50);


    //display total cost
    //Euro symbol isn't used because random characters are getting printed instead of it
    printf("Total cost: EUR %.2f\n", cost);
    return 0;
}
