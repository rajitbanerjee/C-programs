/*
 * Author: Rajit Banerjee, 18202817
 * Pset 4, Q1 - printing sizes of variables of various datatypes
 * 19.02.19
 */

#include <stdio.h>

int main(void)
{
    char a;        //character
    int b;         //integer
    long c;        //long integer
    long long d;   //long long integer
    double e;      //double precision floating point
    long double f; //long double
    float g;       //single precision floating point

    int h[5];      //integer array of 5 integers

    int *i = h;    //pointer to integer array

    //print the respective sizes of different variable types using sizeof() operator
    printf("\nSizes of different variables ");
    printf("\n            char: %d",   sizeof(a));
    printf("\n             int: %d",   sizeof(b));
    printf("\n            long: %d",   sizeof(c));
    printf("\n       long long: %d",   sizeof(d));
    printf("\n          double: %d",   sizeof(e));
    printf("\n     long double: %d",   sizeof(f));
    printf("\n           float: %d",   sizeof(g));


    //int array is declared to be of size 5
    //since it contains 5 integers of size 4 bytes each, total size = 5 * 4 = 20
    printf("\n       int array: %d",   sizeof(h));


    //pointer to array points to 1st element of integer array h[]
    //so sizeof(i) prints 4 because the 1st element of h[] (i.e. every element) is integer (size 4 bytes)
    printf("\npointer to array: %d\n", sizeof(i));

    return 0 ;
}

