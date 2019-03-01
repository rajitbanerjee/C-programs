/*
Author: Raj B (rajit.banerjee@ucdconnect.ie)
---
secs to h:m:s using pointers
---
19.12.18
*/

#include <stdio.h>
void convert_secs(int totalsecs, int *h, int *m, int *s)
{
    *h = totalsecs / 3600;
    totalsecs %= 3600;
    *m = totalsecs / 60;
    *s = totalsecs % 60;
}
int main(void)
{
    int h, m, s;
    convert_secs(4000, &h, &m, &s);
    printf("Time is %d:%d:%d\n", h,m,s);
    return 0;
}