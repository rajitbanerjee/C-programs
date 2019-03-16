/*
Author: Raj B (rajit.banerjee@ucdconnect.ie)
---
Program to reverse a string
---
19.12.18
*/

#include <stdio.h>
#define M 100

int main(void)
{
    char msg[M+1];
    printf("\nInput string: ");
    gets(msg);
    int N = 0;
    
    while(N<M && msg[++N]!='\0'); //length of string 

    for(int i = 0; i < N/2; i++)
    {
        char t = msg[i];
        msg[i] = msg[N-i-1];
        msg[N-i-1] = t;
    }
    printf("\nReversed string: %s", msg);
    return 0;
}