/*
Author: Raj B (rajit.banerjee@ucdconnect.ie)
---
Program to remove all spaces from a string
---
19.12.18
*/

#include <stdio.h>
#define M 100

int main(void)
{
    char msg[M+1], msg2[M+1];
    printf("\nEnter string: ");
    gets(msg);
    int len = 0, x = 0;
    while(len < M && msg[++len]!='\0');
    for(int i = 0; i < len; i++)
    {
        if(msg[i]!=' ')
            msg2[x++] = msg[i];
    }
    for(int i = 0; i < x; i++)
        msg[i] = msg2[i];
    msg[x] = '\0';
    printf("\nModified message: %s", msg);
    return 0;
}