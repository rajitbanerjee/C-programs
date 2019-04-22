/*
 * Author: Rajit Banerjee, 18202817
 * Pset 2, Q5
 * 05.02.2019
 */
#include <stdio.h>

//function prototype, prints binary representation of decimal number
//parameter: integer
void decToBin (int);

//main() function
int main(void)
{
    //variable to store decimal number entered by user
    int decimal;

    //prompt user for input
    printf("\nInput a decimal number: ");
    scanf("%d", &decimal);

    //display binary number by calling function decToBin (decimal)
    printf("%24s", "Binary number: ");
    decToBin(decimal);
    
    //print a new line
    printf("\n");
    return 0;
}

/*
 * Recursive function to convert decimal number to binary
 * 
 * parameter: integer num, i.e. decimal number entered by user
 * base case: exit function if num equals 0
 * 
 * Recursively call decToBin (num / 2) before printing anything.
 * This stores the values of num in a memory stack after each call.
 * 
 * Just before the base case statement is executed, the compiler finds
 * that there is a print statement ~after~ the recursive call statement.
 * 
 * Hence it accesses the memory stack that stored the values of num and 
 * prints (num % 2) in Last In First Out (LIFO) order.
 */
void decToBin(int num)
{
    //base case, exit function if num equals 0
    if (num == 0)
    {
        return;
    }

    //recursively call decToBin with (num / 2)
    decToBin (num / 2);

    //Access the memory stack that contains values of num
    //and prints (num % 2) them in LIFO order
    printf("%d", num % 2);
}