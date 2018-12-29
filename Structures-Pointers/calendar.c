/*
Author: Raj B (rajit.banerjee@ucdconnect.ie)
---
Program to convert totaldays to month and day in month
Using structs and pointers
---
19.12.18
*/
#include <stdio.h>
typedef struct Year{
    int month;
    int day;
} Year;
Year convert_date(int totaldays, int daysinmonth[])
{
    Year y;
    int i = 0;
    while(totaldays > daysinmonth[i++])
        totaldays -= daysinmonth[i];
    y.month = i;
    y.day = totaldays;
    return y;
}
void convert(int totaldays, int daysinmonth[], int *m, int *d)
{
    int mon, day, i = 0;
    while(totaldays > daysinmonth[i++])
        totaldays -= daysinmonth[i];
    *m = i;
    *d = totaldays;
}
int main(void)
{
    int daysinmonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int m, d;
    Year y = convert_date(12, daysinmonth);
    convert(64, daysinmonth, &m, &d);
    printf("Month = %d, Day = %d\n", y.month, y.day); //using struct
    printf("Month = %d, Day = %d\n", m, d); //using pointers
    return 0;
}