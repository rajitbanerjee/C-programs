/**
 * Author: Rajit Banerjee, 18202817
 * Pset 5, Q1 - Pointers to functions
 * 27.02.2019
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//function prototypes
void reverseArray(int arraySize, int a[]);
void randomiseArray(int arraySize, int a[]);
void printArray(int arraySize, int a[], 
                void (*arrayFunction)(int arraySize, int a[]));

int main(void)
{
    //seeding the random number generator
    srand(time(NULL));

    //array initialisation
    int myArray[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};

    //user choice variable
    unsigned int choice;

/*****************************************************************************/
    //display options and perform actions as long as user doesn't choose 0
    do
    {
        //display menu options to user and input user choice
        printf("\n-------------------------------------------\n");
        printf("(1) Reverse the order of array elements\n");
        printf("(2) Randomise array elements\n");
        printf("\nEnter choice (0 to exit): ");
        scanf("%u", &choice);

        //option to exit loop and stop operation
        if (choice == 0)
        {
            return 0;
        }

        //option to print array elements in reverse order
        else if (choice == 1)
        {
            //call printArray() with the pointer to function reverseArray()
            printArray(10, myArray, reverseArray);
        }

        //option to print array elements in random order
        else if (choice == 2)
        {
            //call printArray() with pointer to function randomiseArray()
            printArray(10, myArray, randomiseArray);
        }
        
        //default case: invalid input
        else
        {
            printf("\nInvalid option!\n");
        }
    } while (choice != 0);
    return 0;
}
/*****************************************************************************/
//function to reverse the order of elements in the array
void reverseArray(int arraySize, int a[])
{
    //iterate through array indices 0 to less than arraySize/2
    for (int i = 0; i < arraySize/2; i++)
    {
        //perform in-place swap
        //swap 1st with last element, 2nd with 2nd last element, etc.
        int swap = a[i];
        a[i] = a[arraySize - 1 - i];
        a[arraySize - 1 - i] = swap;
    }
}
/*****************************************************************************/
//function to randomise the order of elements in the array
void randomiseArray(int arraySize, int a[])
{
    //iterate through all the array indices in order
    for (int i = 0; i < arraySize; i++)
    {
        //generate a random array index (range 0 to arraySize - 1)
        int randomIndex = rand() % arraySize;

        //swap array element at current index i and at generated random index
        int swap = a[i];
        a[i] = a[randomIndex];
        a[randomIndex] = swap;
    }
}
/*****************************************************************************/
//function to print the array after performing user specified operation
void printArray(int arraySize, int a[], 
                void (*arrayFunction)(int arraySize, int a[]))
{
    //call function specified in parameter using pointer to the function
    (*arrayFunction)(arraySize, a);

    //print the 10 array elements
    printf("\nmyArray: ");
    for (int i = 0; i < 10; i++)
        printf("%d ", a[i]);
    printf("\n");
}
/*****************************************************************************/