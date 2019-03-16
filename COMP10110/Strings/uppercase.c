/*
Author: Raj B (rajit.banerjee@ucdconnect.ie)
---
Count uppercase character frequency
Convert all lowercase to uppercase
---
06.11.18
*/
#include <stdio.h>
#define MAX 100
int main(void)
{
  char msg[MAX+1];
  printf("Enter message:\n");
  gets(msg);

  printf("\nOriginal message: %s\n", msg);
  int i = 0, c = 0;

  while(i<MAX && msg[i] != '\0')
  {
    if(msg[i] >= 'A' && msg[i] <= 'Z')
    	c++;
    i++;
  }
  printf("\nUppercase Characters: %d\n", c);

  i = 0;
  while(i < MAX && msg[i] != '\0')
  {
    if(msg[i] >= 'a' && msg[i] <= 'z') //checking if msg[i] is lowercase in ASCII
      msg[i] = msg[i] - ('a' - 'A'); //converting msg[i] from lowercase  to uppercase
    i++;
  }

  printf("Message in uppercase: %s\n", msg);
  return 0;
}
