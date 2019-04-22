/*
 * Author: Rajit Banerjee, 18202817
 * Pset 1, Q2
 * 30.01.2019
 */

#include <stdio.h>

//function to extract digits from student number and print them in separate lines
void extractDigits(int);

//function to return the sum of digits of the student number
int sumDigits(int);

//main function
int main(void)
{
    //variable to store student number entered by user
    int s_no;

    //prompt user for input (student number)
    printf("\nEnter student number: ");
    scanf("%d", &s_no);

    //call extractDigits() with s_no as paramter
    //this will print the digits in s_no in separate lines
    extractDigits(s_no);

    //call sumDigits() with parameter s_no
    //sumDigits(s_no) returns the sum of digits of student number (s_no)
    printf("Sum = %d\n", sumDigits(s_no));

    return 0;
}


//function: extractDigits(int n), prints the digits of n in separate lines
//paramter: n (student number)
void extractDigits(int n)
{
    if (n == 0)
        return; //base case

    //recursive call with new value n/10
    //this removes the last digit of n after each call
    //till base case is reached
    extractDigits(n/10);

    //displays the last digit of n
    //this is executed after all recursive calls 
    //so digits are actually printed in correct order
    //stack concept: LIFO
    printf("%d\n", n%10);
}


//function: sumDigits(int n), returns the sum of digits of n
//paramter: n (student number)
int sumDigits(int n)
{
    if (n == 0)
        return 0; //base case
    
    //keep on adding last digit of n, i.e. n%10
    //then remove the last digit of n by recursively calling sumDigits() with n/10
    return (n%10) + sumDigits(n/10);
}

