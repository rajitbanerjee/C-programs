/**
 * Author: Rajit Banerjee, 18202817
 * Pset 5, Q3 - rating political parties
 * 27.02.2019
 */
#include <stdio.h>

int main(void)
{
    //array of pointers to store political party names
    char *parties[5] = {"FineF", "FineG", "SinnF", "GreenP", "IndependA"};

    //array to store user ratings for the parties, initialised to 0 for all
    int ratings[5] = {0};

    //stores user number, initially 1
    int user = 1;

    //stores the value of rating that the user inputs in each iteration
    int rate;

    //choice variable: stores whether to proceed to next user or not
    char choice = 'y';

/*****************************************************************************/
    //display menu choices and input ratings for each party from each user 
    //end loop when no more users left
    do
    {
        /*current user number (iteration number) is stored in 'user',
        prompt current user to enter ratings for 5 political parties*/
        printf("\n--------------------------------------");
        printf("\n~ USER %d ~", user);
        printf("\nEnter rating (0-10) for the following parties:\n");
        for (int i = 0; i < 5; i++)
        {
            //reset rating to 0
            rate = 0;

            //prompt user for rating input for current party (displayed)
            printf("%-9s: ", parties[i]);
            scanf("%d", &rate);

            //add user's rating to the previous rating for current party
            ratings[i] += rate;
        }
        
        //ask if there are any more users to provide ratings
        printf("\nAre there any more users? (Y/N): ");
        scanf(" %c", &choice);

        //if there are more users, then increment user number and loop again
        if (choice == 'y' || choice == 'Y')
            user++;

        //exit loop if choice is 'n' or 'N' (no)
    } while (choice != 'n' && choice != 'N');

/*****************************************************************************/
    //initialise maximum and minimum ratings (indices)
    int max = 0, min = 0;

    //compute which party had highest ratings and which one had the lowest
    for (int i = 0; i < 5; i++)
    {
        if (ratings[i] > ratings[max])
        {
            //if a new maximum rating is found, store its index in max
            max = i;
        }
        
        if (ratings[i] < ratings[min])
        {
            //if a new minimum rating is found, store its index in min
            min = i;
        }
    }
/*****************************************************************************/
    //print results summary
    printf("\n~ Summary ~");
    printf("\nHighest rated:\n");
    for(int i = 0; i < 5; i++)
    {
        //display highest rated party or parties (if their rating is equal)
        //also display the average rating of said parties
        if (ratings[i] == ratings[max])
        {
            printf("%s (%.2f average)\n", parties[i], (float)ratings[i]/user);
        }
    }
/*****************************************************************************/    
    printf("\nLowest rated:\n");
    for(int i = 0; i < 5; i++)
    {
        //display lowest rated party or parties (if their rating is equal)
        //also display the average rating of said parties
        if (ratings[i] == ratings[min])
        {
            printf("%s (%.2f average)\n", parties[i], (float)ratings[i]/user);
        }
    }
    return 0;
}
/*****************************************************************************/
