/*
 * Author: Rajit Banerjee, 18202817
 * Pset 9, Q3 - stack implementation using linked list
 * 09.04.2019
 */
#include <stdio.h>
#include <stdlib.h>
/*****************************************************************************/ 
//self-referential structure to define a node  
typedef struct node 
{
    //each node contains a character
    char data;
    //pointer to next node    
    struct node *next;  
} node, *nodePtr;   
/*****************************************************************************/
//function prototypes  
void push(nodePtr *top, char value);
char pop(nodePtr *top);
void printStack(nodePtr top); 
void instructions(void);
/*****************************************************************************/ 
int main(void)
{
    //top points to the beginning (top) of the stack/linked list
    nodePtr top = NULL; //initially there are no nodes  
    int choice; //user's choice  
    char item; //char entered by user 
    char rep; //char used as replacement in replace function 
    
    instructions(); //display the menu  
    printf("\n? ");
    scanf("%d", &choice);

    //loop while user does not choose 3 (to end run)
    while (choice != 3) 
    {
        switch (choice)
        {
            //option to push(add) item to top of the stack
            case 1:
                printf("Enter a character: ");
                scanf("\n%c", &item);
                push(&top, item); //add item to stack 
                printf("Item succesfully pushed to stack: %c\n", item);
                printStack(top); //print stack after successful push 
                break; //end of case 1

            //option to pop(remove) the top element of the stack
            case 2:
                //if top index is null, then stack is empty
                if (top == NULL)
                    printf("Stack is empty.\n\n");
                else
                {
                    printf("Item successfully removed from stack: %c\n", 
                            pop(&top)); //remove top item from stack
                    printStack(top); //display stack after successful removal
                }
                break; //end of case 2

            //show error and instructions if an invalid choice is made
            default:
                printf("Invalid choice.\n\n");
                instructions();
        }   
        printf("\n? ");
        scanf("%d", &choice);
    }  
    printf("End of run.\n");
    return 0; 
} 
/*****************************************************************************/ 
//display program instructions to user  
void instructions(void)
{
    printf( "Enter your choice:\n"
        " 1 to push an element to the stack.\n"
        " 2 to pop an element from the stack.\n"
        " 3 to end.\n" );
}   
/*****************************************************************************/ 
//Insert a new value into the list in sorted order  
void push(nodePtr *top, char value)
{
    nodePtr newNode = malloc(sizeof(node)); //create node  
    if (newNode == NULL) 
        printf( "%c not inserted. No memory available.\n", value );
    else //if memory is available
    {   
        newNode->data = value; //place value in node  
        newNode->next = *top; //add temp to the top of the stack  
        *top = newNode; //make new node the top of the stack
    }   
} 
/*****************************************************************************/ 
//Remove (pop) an element from the top of the stack  
char pop(nodePtr *top)
{
    char item = (*top)->data; //store the character at the top of the stack
    nodePtr temp = *top; //hold on to the node being removed
    *top = (*top)->next; //de-thread the node
    free(temp); //free the de-threaded node
    return item; //return the character removed
}   
/*****************************************************************************/
//Print the stack  
void printStack(nodePtr top)
{  
    int t = 1; //flag to check if an element is the actual top of the stack
    //if stack is empty
    if (top == NULL) {
        printf( "Stack is empty.\n" );
    }   
    else 
    {
        printf( "The stack is:" );
        //while not the end of the stack; traverse  
        while (top != NULL) 
        {
            //if the item is the top of the current stack, display "TOP"
            if (t == 1)
            {
                //print the first element of the stack
                printf("\n\t\t%c  <-TOP", top->data);
                t = 0; //set flag t to 0
            }
            //print other elements of the stack
            else
                printf("\n\t\t%c", top->data); 
            top = top->next; //go to the next element in the stack
        } 
    }  
}  
/*****************************************************************************/