/*
Author: Raj B
Exam 2015 Q5 using struct
19.12.18
*/
#include <stdio.h>
typedef struct Time
{
    int h;
    int m;
    int s;
} Time;
Time convert_secs(int totalsecs)
{
    Time t;
    t.h = totalsecs / 3600;
    t.m = (totalsecs / 60) %60;
    t.s = totalsecs % 60;
    return t;
}
int main(void)
{
    Time t = convert_secs(4000);
    printf("Time is %d:%d:%d\n", t.h, t.m, t.s);
    return 0;  
}
