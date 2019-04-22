/*
 * Author: Rajit Banerjee, 18202817
 * Pset 3, Q3 - Product of two matrices
 * 12.02.2019
 */
#include <stdio.h>

/*
Sample output screen:

Enter size of matrix A: 3 3
Enter size of matrix B: 3 5

Enter matrix A elements:
Row 1: 1 2 3
Row 2: 4 5 6
Row 3: 7 8 9

Enter matrix B elements:
Row 1: 1 2 3 4 5
Row 2: 2 3 4 5 6
Row 3: 3 4 5 6 7

Product of matrices:
14      20      26      32      38
32      47      62      77      92
50      74      98      122     146
*/

int main(void)
{
    //row and column variables for two matrices
    int r1, c1, r2, c2;

    //prompt user to input sizes of matrices A and B
    printf("\nEnter size of matrix A: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter size of matrix B: ");
    scanf("%d %d", &r2, &c2);

    //check if matrix product is computable
    if (r2 != c1)
        printf("\nProduct impossible.\n");

    else
    {
        //for-loop control variables
        size_t i, j, k, l;

        //declaring two arrays to store matrix elements
        int A [r1][c1];
        int B [r2][c2];

        //array (matrix) to store product of matrices A and B
        int product [r1][c2];

        //sum variable required for step-by-step calculation
        int sum = 0;

        //prompt user to enter matrix A elements
        printf("\nEnter matrix A elements:\n");
        for (i = 0; i < r1; i++)
        {
            printf("Row %d: ", (i+1));
            for (j = 0; j < c1; j++)
            {
                scanf("%d", &A[i][j]);
            }
        }

        //prompt user to enter matrix B elements
        printf("\nEnter matrix B elements:\n");
        for (i = 0; i < r2; i++)
        {
            printf("Row %d: ", (i+1));
            for (j = 0; j < c2; j++)
            {
                scanf("%d", &B[i][j]);
            }
            
        }

        //compute product of two matrices
        for(i = 0; i < r1; i++)
        {
            for(j = 0; j < c2; j++)
            {
                for(k = 0; k < r2; k++)
                {
                    //multiplying ith row of A with jth column of B
                    //update sum with dot product of row and column
                    sum += A[i][k] * B[k][j];
                }

              //assigning sum to (i, j)th element in product matrix
              product[i][j] = sum;

              //making sum 0 again for next step of computation
              sum = 0;
            }
        }

        //display product matrix 
        printf("\nProduct of matrices:\n");
        for(i = 0; i < r1; i++){
            for(j = 0; j < c2; j++)
                printf("%d\t", product[i][j]);
            printf("\n");
        }
    }
}
    

