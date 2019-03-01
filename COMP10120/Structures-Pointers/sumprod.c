/*
Author: Raj B (rajit.banerjee@ucdconnect.ie)
---
Sum and product of array elements using pointers and structs
---
19.12.18
*/

#include <stdio.h>

typedef struct Array
{
    int sum;
    int prod;
} Array;

Array getSumAndProduct(int a[], int len)
{
    Array arr;
    arr.sum = 0;
    arr.prod = 1;
    for(int i = 0; i<len; i++)
    {
        arr.sum += a[i];
        arr.prod *= a[i];
    }
    return arr;
}
void getSandP(int a[], int len, int *s, int *p)
{
    *s = 0;
    *p = 1;
    for(int i = 0; i<len; i++)
    {
        *s += a[i];
        *p *= a[i];
    }
}
int main(void)
{
    int s, p;
    int a[] = {1,2,3,4,5};
    int len = sizeof(a)/sizeof(a[0]);
  
    Array arr = getSumAndProduct(a, len);
    getSandP(a, len, &s, &p);
    printf("Sum = %d, Product = %d\n", arr.sum, arr.prod);
    printf("Sum = %d, Product = %d\n", s, p);
    return 0;
}