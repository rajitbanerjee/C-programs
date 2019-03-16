/*
Author: Raj B (rajit.banerjee@ucdconnect.ie)
---
Simple substitution code for an	alphabetic string.
char perm[] = “qjczieaungsdfxmphybklortvw”
Now, given a message string e.g.
char msg[] = “secret message to encode”;
Replace	all occurrences	of ‘a’ with ‘q’ (since	perm[0]=’q’)
Replace all occurrences of ‘b’ with ‘j’ (since	perm[1]=’j’)
…
Replace	all occurrences	of ‘z’ with ‘w’ (since	perm[25]=’w’)
So that, the message is	modified to
“bicyik fibbqai km ixcmzi”
Improve	your solution to handle upper case.
char msg[] = “Secret Message To Encode”;
the message is modified to
“Bicyik Fibbqai Km Ixcmzi”
---
06.11.18
*/
#include <stdio.h>
#define MAX 100
int main(void)
{
  char perm[] = "qjczieaungsdfxmphybklortvw";
  char msg[] = "Secret Message To Encode";
  
  //printf("\nEnter message: ");
  //gets(msg);

  printf("\nOriginal Message: %s\n", msg);
  int i = 0;

  while(i < MAX && msg[i] != '\0')
  {
    if(msg[i]>='a' && msg[i]<='z') //for lowercase
      msg[i] = perm[msg[i] - 'a']; //encode

    else if (msg[i]>='A' && msg[i]<='Z') //for uppercase
      msg[i] = perm[msg[i] - 'A'] - ('a' - 'A'); //encode, then convert to uppercase

    i++;//increment index
  }

  printf("Encoded message: %s\n", msg);
  return 0;
}
