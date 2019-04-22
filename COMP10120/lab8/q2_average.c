/*
Author: Rajit Banerjee, 18202817
Pset 8, Q2 - dynamic memory allocation
02.04.2019
*/
#include <stdio.h>
#include <stdlib.h>
/*****************************************************************************/
//prototype
char inputType(void);
/*****************************************************************************/
int main(void) 
{
    char type; //to store type of array elements required (%d or %f)
    int n; //to store number of array elements

    //call function to input type of elements wanted in array
    type = inputType();
    if (type == 'x')  
        return 0; //quit program if user choice is 'x'

    //ask for number of array elements wanted
    printf("Enter the number of elements you wish to store: ");
    scanf("%d", &n);

    int   *arr1; //pointer to integer: to act as array of integers
    float *arr2; //pointer to float: to act as array of floats
    float sum = 0; //initialise sum of array elements to 0
/*****************************************************************************/
    /*This portion of code deals with initial array input and 
        computes the average value*/
    printf("Enter %d values:\n", n); 
    //if user chooses to enter integers in array
    if (type == 'd') 
    {
        //allocate memory to integer array with n elements
        arr1 = (int *)calloc(n, sizeof(int));
        for (int i = 0; i < n; i++) 
        {
            scanf("%d", &arr1[i]); //input integer elements
            sum += arr1[i]; //update sum of elements
        }
    } 
    //if user chooses to enter floats in array
    else 
    {
        //allocate memory to float array with n elements
        arr2 = (float *)calloc(n, sizeof(float));
        for (int i = 0; i < n; i++) 
        {
            scanf("%f", &arr2[i]); //input float elements
            sum += arr2[i]; //update sum of elements
        }
    }
    //display the average of array elements: sum/(no. of elements)
    printf("\nAverage = %f\n", sum/n);
/*****************************************************************************/
    /*This portion of code deals with adding extra elements to our array and 
        computing the new average value*/
    int choice; //to store choice to continue input or not
    
    do //loop until choice is not 1 (yes)
    {
        //ask if user wants to add elements to array and store choice
        printf("\nAre there more elements to be added? (1 = yes, 0 = no): ");
        scanf("%d", &choice);
        
        if (choice != 1)
        {
            printf("See you later!\n");
            return 0; //exit program if user choice is not 1 for yes
        }
    
        int extra = 0; //to store number of additional elements in array
        printf("Enter number of additional elements: ");
        scanf("%d", &extra);

        printf("Enter %d more values:\n", extra);
        //if user had originally chosen to input integer elements
        if (type == 'd') 
        {
            //reallocate memory to array to accommodate extra integers
            arr1 = (int *)realloc(arr1, n + extra);
            for (int i = 0; i < extra; i++) 
            {
                scanf("%d", &arr1[n + i]); //input additional integers
                sum += arr1[n + i]; //update sum by the extra integers
            }
        } 
        //if user had originally chosen to input float elements
        else 
        {
            //reallocate memory to array to accommodate extra floats
            arr2 = (float *)realloc(arr2, n + extra);
            for (int i = 0; i < extra; i++) 
            {
                scanf("%f", &arr2[n + i]); //input additional floats
                sum += arr2[n + i]; //update sum by the extra floats
            }
        }
        //important: update the number of elements by adding extra elements
        n += extra;
        //display the new average, which considers additional elements too
        printf("\nNew average = %f\n", sum/n);
    } while (choice == 1);
    return 0;
}
/*****************************************************************************/
//function returns a character to indicate the data type chosen by user
char inputType(void)
{
    char choice; //to store user choice
    //loop until user provides a data type for array elements or exits
    do 
    {
        //display menu options to user and input choice (d/f/x)
        printf("\nEnter the type of numbers you wish to store:\n"
              "\t1. choose d for integers\n"
              "\t2. choose f for floats\n"
              "\t3. choose x to exit...\n" 
               "Enter your choice (d/f/x): ");
        scanf("%c", &choice);
        //tell user what they have chosen
        switch (choice)
        {
            case 'd': 
                printf("Integers chosen!\n");
                break;
            case 'f':
                printf("Floats chosen!\n");
                break;
            case 'x':
                printf("See you later!\n");
                break;
        }        
        printf("\n");
    } while(choice != 'd' && choice != 'f' && choice != 'x');
    return choice;
}
/*****************************************************************************/