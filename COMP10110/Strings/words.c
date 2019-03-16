/*
Author: Raj B (rajit.banerjee@ucdconnect.ie)
---
Program to count the number of words in a string.
---
19.12.18
*/

#include <stdio.h>
#define M 100
int wordCount(char msg[]);

int main(void)
{
    char msg[M+1];
    printf("\nEnter a sentence:\n");
    fgets(msg, M+1, stdin);

    int c = 0;
    while(c<M && msg[++c]!='\0');

    printf("\nNumber of words:\t%d", wordCount(msg));
    printf("\nNo. of characters:\t%d\n", c-1);

    return 0;
}
int wordCount(char msg[])
{
    int len, c = 0;
    while(len < M && msg[++len]!='\0');
    if (len==0)
        return 0; //0 words edge case

    for(int i = 0; i<len; i++)
        if(msg[i] == ' ' || msg[i] == '\t' || msg[i] == '\n') c++; //counting number of spaces
    if (c==0)
        return 1; //1 word with no spaces edge case

    c = 0;
    for(int i = 0; i<len-1; i++)
    {
        if ((msg[i+1] == ' ' || msg[i+1] == '\t' || msg[i+1] == '\n') &&  msg[i] != ' ' 
             && msg[i] != '\t' && msg[i] != '\n')
        c++;
    }
    return c;
}   
    
    


    
    
