/*
 * Author: Rajit Banerjee, 18202817
 * Pset 3, Q2 - Operations on 2D arrays
 * 15.02.2019
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    //seeding rand to generate different random numbers
    srand(time(NULL));

    //variables for array indices and for-loop control
    size_t r, c, i, j, x = 0, y = 0;

    //prompt user for input in specified range
    do
    {
        printf("\nEnter size of arrays (no. of rows and columns) (range 1-20):\n");
        scanf("%d %d", &r, &c);
    } while (r > 20 || c > 20 || r < 1 || c < 1);

    //fill 1D arrays a[] and b[] with random numbers in given range
    //it's easier to work with 1D arrays for some calculations
    int a[r*c], b[r*c];
    for (i = 0; i < r*c; i++)
    {
        //range 100 - 1500, i.e., rand()%(1500 - 100 + 1) + 100
        a[i] = rand() % 1401 + 100;

        for (j = 0; j < i; j++)
            if(a[i] == a[j])
            {
                //if duplicate is found, then go back to index of last occurrence and redo loop
                i = j;
                break;
            }
    }
    for (i = 0; i < r*c; i++)
    {
        //range 100 - 1500, i.e., rand()%(1500 - 100 + 1) + 100
        b[i] = rand() % 1401 + 100;

        for (j = 0; j < i; j++)
            if(b[i] == b[j])
            {
                //if duplicate is found, then go back to index of last occurrence and redo loop
                i = j;
                break;
            }
    }

    //declaring 2D arrays to store random numbers contained in arrays a[] and b[]
    int arrayA[r][c];
    int arrayB[r][c];

    //fill arrayA and arrayB
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            arrayA[i][j] = a[x++];
            arrayB[i][j] = b[y++];
        }
    }
    //re-initialise x and y to 0 for later use
    x = 0;
    y = 0;
    
    //print arrays A and B
    printf("\nArray A:\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
            printf("%d\t", arrayA[i][j]);
        printf("\n");
    }
    printf("\n");

    printf("\nArray B:\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
            printf("%d\t", arrayB[i][j]);
        printf("\n");
    }
    
    //product of corresponding cells
    unsigned long long int product [r][c];

    //sum of corresponding cells
    int sum [r][c];

    //sum of corresponding rows
    int row_s [r];

    //sum of corresponding columns
    int col_s [c];

    //CALCULATIONS
    for (i = 0; i < r; i++)
    {
        row_s[x] = 0;
        for (j = 0; j < c; j++)
        {
            //calculating product of corresponding elements
            product[i][j] = arrayA[i][j] * arrayB[i][j];

            //calculating sum of corresponding elements
            sum[i][j] = arrayA[i][j] + arrayB[i][j];

            //calculating sum of corresponding rows
            row_s [x] += arrayA[i][j] + arrayB[i][j];
        }
        x++;
    }  

    for (i = 0; i < c; i++)
    {
        col_s[y] = 0;
        //calculating sum of corresponding columns
        for (j = 0; j < r; j++)
            col_s [y] += arrayA[j][i] + arrayB[j][i]; 
        y++;
    } 

    //stores frequency of common elements in arrayA and arrayB
    int common = 0; 

    //checking arrays a[] and b[] for common elements is same as checking arrayA and arrayB
    for (i = 0; i < r*c; i++)
    {
        for (j = 0; j < r*c; j++)
            if (a[i] == b[j])
            {
                common++;
                break;
            }
    }

    //printing results    
    printf ("\nArray containing the product of corresponding cells in arrayA and arrayB:\n\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
            printf("%llu\t", product[i][j]);
        printf("\n");
    }
     
    printf ("\nArray containing the sum of corresponding cells in arrayA and arrayB:\n\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
            printf("%d\t", sum[i][j]);
        printf("\n");
    }

    printf ("\nArray containing the sum of corresponding rows in arrayA and arrayB:\n\n");
    for (i = 0; i < r; i++)
        printf("%d\n", row_s[i]);
    

    printf ("\nArray containing the sum of corresponding columns in arrayA and arrayB:\n\n");
    for (i = 0; i < c; i++)
        printf("%d\t", col_s[i]);
    printf("\n");


    printf("\nNumber of common elements in arrayA and arrayB: %d\n", common);


    //print wow if arrayA and arrayB have same element at same index
    //same as checking if arrays a and b have same element at same index
    for (i = 0; i < r*c; i++)
    {
        if(a[i] == b[i])
        {
            printf("\nWow!\n");
            break;
        }  
    }

    return 0; 
}

