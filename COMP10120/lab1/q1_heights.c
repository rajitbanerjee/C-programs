/*
 * Author: Rajit Banerjee, 18202817
 * Pset 1, Q1
 * 29.01.2019
 */

#include <stdio.h>

int main(void)
{
    //Array to store heights of 3 children in class
    float heights [3];

    //Variables to store tallest, shortest and average height
    float max;
    float min;
    float avg;

    //Prompt user to input 3 heights
    printf("\nInput three heights: ");
    scanf("%f %f %f", &heights[0], &heights[1], &heights[2]);

    //initialise max and min to first element of array
    //this is done so that they can be compared with other array elements
    //and can be updated if necessary
    max = heights[0];
    min = heights[0];

    for (int i = 1; i < 3; i++)
    {
        //update max if heights[i] is greater than previous max
        if (heights[i] > max)
            max = heights[i];

        //update min if heights[i] is smaller than previous min
        if (heights[i] < min)
            min = heights[i];
    }

    //get the average height by dividing the sum of array elements (heights) by 3
    avg = (heights[0] + heights[1] + heights[2])/3;

    //print average, tallest and shortest heights (correct to 1 decimal place)
    printf("Average is %.1f\n", avg);
    printf("Tallest is %.1f\n", max);
    printf("Shortest is %.1f\n", min);

    return 0;
}
