#include <stdio.h>
void swap(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}
int main(void)
{
    int a = 10, b = 20;
    swap(&a, &b);
    printf("\na = %d, b = %d\n", a, b);
    return 0;
}