/*
 * Author: Rajit Banerjee, 18202817
 * Pset 4, Q2 - Horse race
 * 19.02.19
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//function prototypes
void moveFirefoot( int *FirefootPtr);
void moveShadowfox( int *ShadowfoxPtr);
void printCurrentPositions(unsigned int, unsigned int);

int main(void)
{ 
    //seeding rand to get different random numbers
    srand(time(NULL));

    int Firefoot  = 1; // Firefoot  current position
    int Shadowfox = 1; // Shadowfox current position      
    int counter = 0; // counter used in loop controling the race.

    puts("\nThe Race has started!");
   
    // loop through the progress on the track
    while (Firefoot != 100 && Shadowfox != 100) 
    { 
        //neither of the horses has reached the end of the track
        //call functions to move horses on the track
        moveFirefoot(&Firefoot);
        moveShadowfox(&Shadowfox);
        printCurrentPositions(Firefoot, Shadowfox); 

        //increment number of iterations
        counter++;
    } 


    // determine the winner and print message - one horse has passed the end as it is outside the loop.
    if (Firefoot > Shadowfox) 
        printf("\nFirefoot has won!\n");

             
    else if (Shadowfox > Firefoot) 
        printf("\nShadowfox has won!\n");

    else
        printf("\nRace Tied!\n");

    //print total number of iterations
    printf("Iterations: %u\n", counter);
} 



// progress for Shadowfox
void moveShadowfox( int *ShadowfoxPtr)
{ 
    // generate random number from 1-10
    int x = rand() % 10 + 1;

    // determine progress
    if (x >= 1 && x <= 5) 
        // full speed 50% of the time
        *ShadowfoxPtr += 3;
    
    //progress 1 space 10% of the time
    if (x == 6)
        *ShadowfoxPtr += 1;
    
    //2 steps back 20% of the time
    if (x == 7 || x == 8)
        *ShadowfoxPtr -= 2;
        
    // check boundaries
    if (*ShadowfoxPtr < 1) 
        *ShadowfoxPtr = 1;
    
    if (*ShadowfoxPtr > 100) 
        *ShadowfoxPtr = 100;
} 



// progress for Firefoot 
void moveFirefoot ( int *FirefootPtr)
{ 
    // generate random number from 1-10
    int x = rand() % 10 + 1;

    // determine progress
    if (x >= 1 && x <= 5) 
        // full speed 50% of the time
        *FirefootPtr += 3;
    
    //progress 1 space 10% of the time
    if (x == 6)
        *FirefootPtr += 1;
    
    //2 steps back 20% of the time
    if (x == 7 || x == 8)
        *FirefootPtr -= 2;
    
    //10% of the time, x == 10 so don't move

    // check boundaries
    if (*FirefootPtr < 1) 
        *FirefootPtr = 1;
    
    if (*FirefootPtr > 100) 
        *FirefootPtr = 100;
} 



// display new position
void printCurrentPositions(unsigned int Firefoot, unsigned int Shadowfox)
{ 
    // loop through race
    for (unsigned int count = 1; count <= 100; ++count) 
    {
        /*
        This loop will print will 100 characters at each run: either F,S,T or a space to 
        give the user an idea of where the horse at every iteration.
        */
      
        if (count == Firefoot  && count == Shadowfox) 
            printf("T"); //Tied
        
        else if (count == Shadowfox) 
            printf("S"); //Shadowfox current position
        
        else if (count == Firefoot) 
            printf("F"); //Firefoot current position
        
        else 
            printf(" "); 
    }

    puts("");
} 
