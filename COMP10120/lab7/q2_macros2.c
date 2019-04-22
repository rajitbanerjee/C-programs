/*
Author: Rajit Banerjee, 18202817
Pset 7, Q2 - using macros for array functions
26.03.19
*/
#include <stdio.h>
//macro takes array and array size as parameters and prints array
#define PRINT(arr, size) { \
    for (int i = 0; i < size; i++) \
        printf("%d\t", arr[i]); \
}
/*****************************************************************************/
//macro takes array and array size as parameters and prints array in reverse
#define PRINT_REV(arr, size) { \
    for (int i = size - 1; i >= 0; i--) \
        printf("%d\t", arr[i]); \
}
/*****************************************************************************/
int main(void)
{
    //initialise array
    int myArray[5] = {1, 4, 8, 16, 32};

    printf("\n         myArray: ");
    //call macro to print myArray
    PRINT(myArray, 5);

    printf("\nmyArray(reverse): ");
    //call macro to print myArray in reverse order
    PRINT_REV(myArray, 5);

    printf("\n");
    return 0;
}
/*****************************************************************************/

