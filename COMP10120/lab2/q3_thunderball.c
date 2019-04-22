/*
 * Author: Rajit Banerjee, 18202817
 * Pset 2, Q3
 * 05.02.2019
 */
#include <stdio.h>
#include <time.h> 
#include <stdlib.h> //to access rand()

//function prototype, prints 5 unique main numbers
void getMainNums(void);

int main(void)
{
    //makes use of the computer's internal clock to control the choice of the seed
    srand(time(NULL));

    //printing 5 main numbers (range 1-39)
    //duplicates aren't allowed for the 5 main numbers
    printf("\n%20s", "Main numbers: ");
    //call function to generate main numbers
    getMainNums(); 
   
    //printing thunderball number (range 1-14)
    //thunderball number is allowed to be the same as one of the main numbers
    printf("\nThunderball number: %d\n", rand () % 14 + 1);

    return 0;
}

/*
function checks for duplicates and 
hence prints 5 unique main numbers
*/
void getMainNums(void)
{
    //array to store main numbers
    int nums [5];
    int i, j; //for-loop control variables

    for (i = 0; i < 5; i++)
    {
        //stores in nums[i], a random number between 1 and 39
        nums[i] = rand() % 39 + 1;
        for (j = i; j >= 0; j--)
        {
        /*
        If last number stored in nums[i] already exists, then 
        index i goes back to the index of duplicate occurrence, j.
        A new random integer (1-39 range) is put into the current 
        index i. Again if a duplicate occurs, the index goes back to
        the duplicate element index. So the process continues till
        all elements in nums[] are unique.
        */
            if (nums [i] == nums[j])
            {
                i = j;
            }
        }
    } 

    //display 5 unique main numbers in nums[]
    for (i = 0; i < 5; i++)
    {
        printf("%d ", nums[i]);
    }
}