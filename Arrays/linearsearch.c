/* 
Author: Raj B
---
Program to explore boolean datatype with simple linear search
---
18.10.18
*/

#include <stdio.h>
#include <stdbool.h>
int main(void)
{
	int a[] = {1, 2, 3, 4, 5};
	int i = 0, index = 0, n;
	bool found;
	
	printf("\nEnter item to search: ");
	scanf("%d", &n);
	
	while(i++<5 && !found)
		if (a[i] == n){
			found = true;
		    index = i;
		}
	if(found == true)
		printf("Element found at index %d.\n", index);
	else 
		printf("Element not found.\n");
}


	

 
