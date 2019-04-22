/*
 * Author: Rajit Banerjee, 18202817
 * Pset 2, Q2
 * 05.02.2019
 */
#include <stdio.h>
#include <math.h>
#include <string.h>
/*
 * q is the day of the month
 * m is the month (3 = March, 4 = April, 5 = May, ..., 14 = February)
 * K the year of the century (year%100)
 * J is the zero-based century (year/100)
 */
int dayOfWeek (int q, int m, int K, int J);

//function prototype
//parameter: month name
//returns month number
int monthNum (char month[10]);


//main() function
int main(void)
{
    //variables to store day number, month name and year
    int day;
    char month [10];
    int year;

    //prompt user to enter date in the specified format
    //full name of the month name required (1st letter in capitals)
    printf("\nEnter date (Eg. 16 April 1967): ");
    scanf("%d %s %d", &day, month, &year);

    //call monthNum and store answer in mon_num
    //eg. for month = "March", mon_num = 3
    int mon_num = monthNum(month);

    switch (mon_num)
    {
        //for January, mon_num = 1 becomes 13
        //for February, mon_num = 2 becomes 14
        case 1: mon_num = 13; //no break; fall through occurs
        case 2: mon_num = 14;

        //if month is January or February, the year is decremented by 1
        year --;
        break;

        //case where monthNum() returns -1
        //i.e. input doesn't match specified format
        case -1: printf("\nPlease follow the input format specified.\nE.g. 15 February 2001\n");
        return 0;
    }
    

    //find weekday number by calling function dayOfWeek
    int weekday = dayOfWeek(day, mon_num, year%100, year/100);

    //array to store names of days
    char days[7][10] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    
    printf("%32s", "Day of the week: ");
    for (int i = 0; i < 7; i++)
    {
        //if calculated weekday number matches array index, print the day name
        if (weekday == i)
        {
            printf("%s\n", days[i]);
            break;
        }
    }
    
    return 0;
}


/*
 * Zeller's congruence
 * Original formula: 
 * day of week = q + (13*(m + 1))/5 +  K + K/4 + J/4 - 2 * J) % 7;
 * 
 * The formula relies on the mathematician's definition of modulo division, 
 * which means that −2 mod 7 is equal to positive 5. For software implementation,
 * we must replace − 2J by + 5J.
 */
int dayOfWeek (int q, int m, int K, int J)
{
    /*
    The floor [...] function in the mathematician's formula
    can be ignored because it is taken care of by integer division (/) in C.
    It automatically gets rid of the decimal places.
    So using floor() is not necessary.
    */ 
    return (q + (13 * (m + 1))/5 +  K + K/4 + J/4 + 5 * J) % 7;
}


//parameter: month name
//returns month number, e.g. March = 3
int monthNum (char month[10])
{
    //array to store month names
    char month_names[12][10] = {"January", "February", "March", "April", "May", 
    "June", "July", "August", "September", "October", "November", "December"};
    
    //comparing month entered with all the month names
    //if a match is found, then month number is returned
    for (int i = 0; i<12; i++)
        if (strcmp(month, month_names[i]) == 0)
            return i+1;

    //return -1 if input month is invalid  
    return -1;
}



    



