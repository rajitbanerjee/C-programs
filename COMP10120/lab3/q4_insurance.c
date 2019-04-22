/*
 * Author: Rajit Banerjee, 18202817
 * Pset 3, Q4 - Insurance company & drivers
 * 12.02.2019
 */
#include <stdio.h>
#include <stdbool.h>

/*
Sample output screen:

Enter driver number: 3

Driver 3 summary:
Acceleration Recordings: 5, 6, 7, 6, 5, 3, 3, 3, 3, 3
Max. average acceleration for Driver 3: 7
Average acceleration over all of Driver 3 trips: 4.40
Discount: No discount to be applied
The average acceleration of all drivers over all trips is: 3.46
*/

int main(void)
{
    //Array to store data of 5 drivers
    int data[5][10] = 
    {{3, 1, 3, 4, 6, 7, 3, 2, 5, 3},  //Driver 1
     {2, 2, 2, 3, 4, 4, 3, 3, 3, 2},  //Driver 2
     {5, 6, 7, 6, 5, 3, 3, 3, 3, 3},  //Driver 3
     {3, 3, 3, 3, 4, 4, 3, 2, 1, 3},  //Driver 4
     {2, 3, 4, 6, 6, 2, 5, 1, 3, 3}   //Driver 5
    }; 

    //variable to store user's choice of driver
    int driver;

    //prompt user to enter driver number
    //if choice is not in specified range then ask again 
    do 
    {
        printf("\nEnter driver number: ");
        scanf("%d", &driver);
    } while (driver < 1 || driver > 5);
    
    
    //for-loop control variables
    size_t i, j; 


    //variables to store sum of data for entered driver and also the total sum
    float driver_sum = 0, total_sum = 0;

    //variable to store whether discount will be applied or not
    bool discount = true;

    //declare and initailise maximum value of driver's avg. acceleration
    int max_acc = data[driver-1][0];


    //compute results by traversing through data[][] array
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 10; j++)
        {
            //if entered driver number is found
            if (i + 1 == driver)
            {
                //update sum of driver's data
                driver_sum += data[i][j];

                //update max. acceleration if greater number is found
                if (data[i][j] > max_acc)
                    max_acc = data[i][j];
            }

            //update total sum, i.e. for all drivers, all trips
            total_sum += data [i][j];
        }
    }

    //if driver's avg. acceleration for 10 trips is > 5, then remove discount
    //if max acceleration > 6, that means that single trip was more than allowed limit for discount
    if (driver_sum/10 > 5 || max_acc > 6)
    {
        discount = false;
    }
    
    //print all results

    //display driver summary
    printf("\nDriver %d summary:", driver);


    //display individual driver's data
    printf("\nAcceleration Recordings: ");
    for (i = 0; i < 10; i++)
    {
        if(i == 9)
            printf("%d", data[driver-1][i]);
        else
            printf("%d, ", data[driver-1][i]);
    }

    //display maximum acceleration value for chosen driver
    printf("\nMax. average acceleration for Driver %d: %d", driver, max_acc);

    //display average acceleration for all of chosen driver's trips
    printf("\nAverage acceleration over all of Driver %d trips: %.2f", driver, driver_sum/10);

    //display if discount is applied or not
    if (discount == true)
        printf("\nDiscount: Applied");
    else
        printf("\nDiscount: No discount to be applied");
    
    //display avg. acceleration value of all drivers over all trips
    printf("\nThe average acceleration of all drivers over all trips is: %.2f\n", total_sum/50);

    return 0;
}