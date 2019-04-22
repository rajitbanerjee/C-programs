/*
Author: Rajit Banerjee, 18202817
Pset 6, Q1 - copy a string in uppercase, modify it to remove consonants
05.03.19
*/
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#define MAX 100

//function prototypes
void modifyString(char *copy, char *slogan);
bool isConsonant(char c);
/*****************************************************************************/
int main(void)
{
    char *slogan = "Comp10120 is my favourite module";

    //declare array to store new "copy" string
    char copy[MAX];

    //call function to modify string
    modifyString(copy, slogan);

    printf("\nOriginal string: %s", slogan);
    printf("\nModified string: %s\n", copy);

    return 0;    
}
/*****************************************************************************/
/*
Function copies slogan into copy string
it also removes all the consonants from the string, and 
converts all letters to uppercase
*/
void modifyString(char *copy, char *slogan)
{  
    //iterate through slogan string until null terminator is reached  
    while (*slogan != '\0')
    {
        //if the current character is not a consonant, then copy it
        if (isConsonant(*slogan) == false)
        {
            //convert character to uppercase and store in copy string
            *copy = toupper(*slogan);

            //increment copy pointer
            copy++;
        }
        //increment slogan pointer (original string)
        slogan++;
    }
    //null terminate new string
    *copy = '\0';
}
/*****************************************************************************/
/*
Function takes a character as parameter and returns
true,  if character is a consonant
false, otherwise
*/
bool isConsonant(char c)
{
    //initialise flag to 0
    int f = 0;

    //convert character c to uppercase and assign it to c again
    c = toupper(c);

    //if c is a vowel then set flag to 1
    if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        f = 1;

    /*if flag is not set (c is not  vowel), and c is an alphabet,
    that means c is a consonant, so return true*/
    if (f == 0 && isalpha(c) != 0)
        return true;

    //return false if c is not a consonant
    return false;
}
/*****************************************************************************/