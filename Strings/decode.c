/*
Author: Raj B (rajit.banerjee@ucdconnect.ie)
---
Given the same permutation string, can decode a
message	that was encoded with the method in encode.c
char perm[] = "qjczieaungsdfxmphybklortvw";
---
06.11.18
*/
#include <stdio.h>
#define MAX 100
int main(void)
{
  char perm[] = "qjczieaungsdfxmphybklortvw";
  char msg[] = "Bicyik Fibbqai Km Ixcmzi";

  printf("\nEncoded message: %s\n", msg);

  char ch; int i = 0, j;

  while(i < MAX && msg[i] != '\0')
  {
    ch = msg[i]; //character at index i of msg[]
    for(j = 0; j < 26; j++)
    {
      if(ch == perm[j]) //checking when lowercase
        msg[i] = j + 'a'; //decoding; implicit conversion from int to char

      else if(ch == (perm[j] - ('a' - 'A'))) //checking when uppercase
        msg[i] = j + 'A'; //decoding; implicit conversion from int to char
    }
    i++; //increment index
  }

  printf("Decoded message: %s\n", msg);
  system("cls"); //clear screen
  return 0;
}
