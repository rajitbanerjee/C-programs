/*
Author: Raj B (rajit.banerjee@ucdconnect.ie)
---
Program	that gives the user three attempts to guess a number between 1 and 10.	
---
03.11.18
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h> //used becuase time(NULL) is used for srand()

int main(void)
{
  srand(time(NULL));
  int ans = rand()%10 + 1; //generates random integer between 1 and 10 inclusive
  int c = 3, guess;

  while(1)
  {
    printf("\nPlease enter your guess between 1 and 10: ");
    scanf("%d", &guess);

    while(guess<1 || guess >10){
      printf("The number you entered was outside the range of 1 to 10.\n---");
      printf("\nPlease enter another number: ");
      scanf("%d", &guess);
    }

    if(guess == ans)
    {
      printf("You guessed correctly, the answer is %d.\n", ans);
      break;
    }

    else if (guess > ans)
      printf("You guessed incorrectly, the answer is smaller.");

    else
      printf("You guessed incorrectly, the answer is greater.");

    c--;
    printf("\nYou have %d guess(es) remaining.\n---", c);

    if(c==0)
    {
      printf("\nThe answer was %d.\n", ans);
      break;
    }
  }
  return 0;
}
