/*
 * Author: Rajit Banerjee, 18202817
 * Pset 3, Q1 - Ticket sales at a stadium
 * 14.02.2019
 */
#include <stdio.h>

//function to increment number of people in stadium
void enter();

//function to decrement number of people in stadium
void leave();

//function to calculate/print amount collected from ticket sales
void amountCollected(int);

//function to print the total number of people inside stadium
void numPeople();

//global variable to store the number of people inside the stadium
int people = 0;


int main(void)
{
    //variable to store user choice from the menu
    int choice;

    do
    {
        //display options
        printf("\n-----------------------------------------------------");
        printf("\nWelcome to the Aviva Stadium!\n");
        printf("\n(1) Enter stadium (fee EUR 20)");
        printf("\n(2) Leave stadium (no re-entry without repayment)");
        printf("\n(3) Print total amount of money from ticket sales\n");
        printf("\nEnter your choice (0 to exit): ");
        
        //take input from user
        scanf("%d", &choice);

        switch(choice)
        {
            case 0: printf("Bye! Have a nice day!\n");
                    return 0;

            case 1: enter(); 
                    amountCollected(choice); 
                    numPeople(); 
                    break;

            case 2: if (people != 0)
                        leave(); 
                    else
                        printf("\nNobody left in the stadium!\n");
                    numPeople(); 
                    break;

            case 3: amountCollected(choice); 
                    break;

            default: printf("\nInvalid option. Please try again!\n");
        }   

    } while (choice != 0);

    return 0;
}



//function increments the number of people inside the stadium
void enter()
{
    people += 1;
}



//function decrements the number of people inside the stadium
void leave()
{
    people -= 1;
}



//function calculates/prints amount collected from ticket sales
void amountCollected(int ch)
{
    //local static variable
    static int amount = 0;

    //if user choice ch is 3, i.e. display total amount
    if (ch == 3)
        printf("Amount collected: EUR %d\n", amount);

    //if user choice != 3, then total amount is updated by 20
    //this case only occurs when a new person enters and this function is called
    else
        amount += 20;
}
    
//function to print the total number of people inside the stadium
void numPeople()
{
    printf("Total number of people: %d\n", people);
}



