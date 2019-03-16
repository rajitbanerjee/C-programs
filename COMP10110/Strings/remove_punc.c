/*
Author: Raj B (rajit.banerjee@ucdconnect.ie)
---
Remove all punctuation marks
I: Too, many, punctuation marks:; by far!!
O: Too many punctuation marks by far
Note: punctuation marks are !’?;:,.
---
17.11.18
*/

#include <stdio.h>
#define MAX 100
int main(void)
{
    char msg[MAX+1];
    printf("\nEnter a sentence:\n");
    fgets(msg, MAX+1, stdin);
    int i, j, len = 0;
    printf("\n%d\n", sizeof(msg));
    while (len < MAX && msg[++len] != '\0'); //finds len

    for(i = 0; i < len; i++)
    {
        switch(msg[i])
        {
            case '!':   case '\'': case '\\':  case '?': 
            case ';':   case ':' : case ',':   case '.':   
            for(j = i; j < len - 1; j++)
                msg[j] = msg[j+1];
            len--;
            i--;
            break;
        }
    }
    msg[len] = '\0';
    printf("\n%s\n", msg);
    return 0;
}