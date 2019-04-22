/*
Author: Rajit Banerjee, 18202817
Pset 7, Q3 - array of pointers to characters
26.03.19
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
/*****************************************************************************/
//function prototypes
void jumble (char *words[]);
void display(char *words[]);
void select_rand(char *words[]);
/*****************************************************************************/
int main (void)
{
    //seeding the random number generator
    srand(time(NULL));

    //store the provided words in array of pointers
    char *words[12] = {"COMP10120", "is", "my", "favourite", "module", "and",
        "I", "learn", "lots", "of", "interesting", "things"};

    //stores user choice
    int choice;
    //display options until choice is 0 to exit 
    do
    {
        printf("\n1. Jumble words.");
        printf("\n2. Print words.");
        printf("\n3. Select a word at random.");
        printf("\nEnter your choice (0 to exit): ");
        scanf("%d", &choice);

        //perform operations according to user choice
        switch (choice)
        {
            //exit if they choose 0
            case 0: return 0;
            //jumble the words if they choose 1
            case 1: jumble(words); break;
            //print the words if they choose 2
            case 2: display(words); break;
            //select and print a random word if they choose 3
            case 3: select_rand(words); break;
            //display error message in all other cases
            default: printf("\nInvalid choice.\n");
        }
    } while (choice != 0);
}
/*****************************************************************************/
void jumble (char *words[])
{
    //pointer to store address of word while performing swap
    char *swap;

    //iterate though the array indices 0-11
    for (int i = 0; i < 12; i++)
    {
        //choose a random array index (0-11)
        int random_index = rand() % 12;

        //swap the address of words at current index and random index
        swap = words[i];
        words[i] = words[random_index];
        words[random_index] = swap;
    }
    printf("\nWords have been jumbled!\n");
}
/*****************************************************************************/
void display (char *words[])
{
    printf("\nSentence: ");
    //iterate thorugh the words array and display each word
    for (int i = 0; i < 12; i++)
        printf("%s ", words[i]);
    printf("\n");
}
/*****************************************************************************/
void select_rand (char *words[])
{
    //generate a random array index (0-11)
    int random_index = rand() % 12;

    //display word at random index from words array
    printf("\nRandom word: %s\n", words[random_index]);
}
/*****************************************************************************/