/*
 * Author: Rajit Banerjee, 18202817
 * Pset 2, Q1
 * 05.02.2019
 */
#include <stdio.h>
//defining the value of pi to use it in the formula for ellipsoid volume
#define M_PI 3.14159265358979323846

//function prototype
//parameters: 3 floats (values of 3 axes of ellipsoid
//returns volume of ellipsoid
float ellipsoidVol (float, float, float);

int main (void)
{
    //variables to store values of 3 axes of ellipsoid (user input)
    float a, b, c;

    //counter for number of times the calculation is done
    int counter = 0;

    //we are required to test the ellipsoidVol() function 4 times
    //the loop executes 4 times, and the counter keeps count
    while (counter++ < 4)
    {
        //prompt user for input
        printf("\nEnter values of a, b and c axes for ellipsoid %d:\n", counter);
        scanf("%f %f %f", &a, &b, &c);


        //call function ellipsoidVol() to find volume of ellipsoid
        //rounding off volume to 3 d.p. for simplicity 
        printf("Volume of ellipsoid %d: %.3f\n", counter, ellipsoidVol (a, b, c));
    }

    return 0;
}


//parameters: 3 floats (values of 3 axes of ellipsoid)
//returns volume of ellipsoid as float
float ellipsoidVol(float a, float b, float c)
{
    //function calculates and returns ellipsoid vol
    //formula is (4/3)* pi * abc
    return (4.0/3.0) * M_PI * a * b * c;
}