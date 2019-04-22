/**
 * Author: Rajit Banerjee, 18202817
 * Pset 5, Q2 - array x 10 & demonstrate sizeof()
 * 27.02.2019
 */
#include <stdio.h>

//function prototype
void multByTen (int arraySize, int a[]);

int main(void)
{
    int arraySize;
    printf("\nEnter number of elements: ");
    scanf("%d", &arraySize);

    //variable length array
    int array[arraySize];

    printf("Enter array elements:\n");
    for (int i = 0; i < arraySize; i++)
    {
        scanf("%d", &array[i]);
    }
    
    //call function to modify array
    multByTen(arraySize, array);

    printf("Modified array [array x 10]:\n");
    for (int i = 0; i < arraySize; i++)
    {
        //use pointer/offset notation to print array elements
        printf("%d ", *(array + i));
    }
    printf("\n");
/*****************************************************************************/
    //demonstrate use of sizeof() operator
    printf("\n\nUsing sizeof() operator:\n");

    /*display the size of the array and size of each element,
    use sizeof() operator to find how many bytes the array occupies*/
    printf("\nSize of array in bytes: %d", sizeof(array));

    //display size of each element
    printf("\nSize of each element in bytes: %d", sizeof(array[0]));

    /*divide size occupied by the array by that occupied by the 1st element:
    gives the number of elements in the array*/
    printf("\nNumber of elements: %d\n", sizeof(array)/sizeof(array[0]));
    
    return 0;
}
/*****************************************************************************/
//function to multiply each array element by 10
void multByTen(int arraySize, int a[])
{
    for (int i = 0; i < arraySize; i++)
    {
        //use the pointer/offset notation to multiply each element by 10
        *(a + i) *= 10;
    }
}
/*****************************************************************************/


