/*
 * Author: Rajit Banerjee, 18202817
 * Pset 9, Q2 - linked list
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
void insert(nodePtr *start, char value);
char delete(nodePtr *start, char value);
char replace(nodePtr *start, char value, char replacement);
void printList(nodePtr start); 
void instructions(void);
/*****************************************************************************/ 
int main(void)
{
    //start points to the beginning of the linked list
    nodePtr start = NULL; //initially there are no nodes  
    int choice; //user's choice  
    char item; //char entered by user 
    char rep; //char used as replacement in replace function 
    
    instructions(); //display the menu  
    printf("? ");
    scanf("%d", &choice);

    //loop while user does not choose 4 (to end run)
    while (choice != 4) 
    {
        switch (choice)
        {
            //option to insert an element into the list
            case 1:
                printf("Enter a character: ");
                scanf("\n%c", &item);
                insert(&start, item); //insert item in list  
                printList(start); 
                break; //end of case 1

            //option to delete an element from the list
            case 2:
            //if list is not empty  
                if (start == NULL)
                    printf("List is empty.\n\n");
                else 
                {
                    printf("Enter character to be deleted: ");
                    scanf("\n%c", &item);

                    //if character is found, remove it 
                    if (delete(&start, item)) 
                    {  
                        printf("%c deleted.\n", item);
                        printList(start);
                    }  
                    else 
                        printf("%c not found.\n\n", item); 
                }    
                break; //end of case 2

            //option to replace an element in the list
            case 3:
                if (start == NULL)
                    printf("List is empty.\n\n");
                else
                {
                    printf("Enter character to be replaced: ");
                    scanf("\n%c", &item);

                    printf("Enter replacement character: ");
                    scanf("\n%c", &rep);

                    //print original list before replacement
                    printList(start);
                    //if item is found, replace it with rep
                    if(replace(&start, item, rep))
                    {
                        printf("%c replaced with %c.\n\n", item, rep);
                        printList(start); //print new list to reflect changes
                    }
                    else
                        printf("%c not found.\n\n", item);
                }
                break; //end of case 3

            default:
                printf("Invalid choice.\n\n");
                instructions();
        }   
        printf("? ");
        scanf( "%d", &choice );
    }  
    printf("End of run.\n");
    return 0; 
} 
/*****************************************************************************/ 
//display program instructions to user  
void instructions(void)
{
    printf( "Enter your choice:\n"
        " 1 to insert an element into the list.\n"
        " 2 to delete an element from the list.\n"
        " 3 to replace an element in the list with another element.\n"
        " 4 to end.\n" );
}   
/*****************************************************************************/ 
//Insert a new value into the list in sorted order  
void insert(nodePtr *start, char value)
{
    nodePtr temp = malloc(sizeof(node)); //create node  
    if (temp == NULL) 
        printf( "%c not inserted. No memory available.\n", value );
    else //if memory is available
    {   
        temp->data = value; //place value in node  
        temp->next = NULL; //node does not initially link to another node  

        nodePtr prev = NULL;  //pointer to previous node in list  
        nodePtr curr = *start; //pointer to current node in list  

        //loop to find the correct location in the list  
        while (curr != NULL && value > curr->data)
        {
            prev = curr;       //walk to ...  
            curr = curr->next; //... next node  
        } 

        //insert new node at beginning of list  
        if (prev == NULL) 
        {
            temp->next = *start;
            *start = temp;
        }  
        else 
        { 
            //insert new node between prev and curr  
            prev->next = temp;
            temp->next = curr;
        }  
    }   
} 
/*****************************************************************************/ 
//Delete a list element  
char delete(nodePtr *start, char value)
{
    //delete first node  
    if ((*start)->data == value)
    { 
        nodePtr temp = *start; 
        *start = (*start)->next; //de-thread the node
        free(temp);
        return value;
    } 
     
    else 
    {
        nodePtr prev = *start;
        nodePtr curr = (*start)->next;

        //loop to find the correct location in the list  
        while (curr != NULL && curr->data != value) 
        {
            prev = curr; //walk to ...  
            curr = curr->next; //... next node  
        }  

        //delete node at curr  
        if (curr != NULL) //value exists in list
        {
            nodePtr temp = curr;
            prev->next = curr->next;
            free(temp);
            return value;
        }  
    } 
    return '\0';
}  
/*****************************************************************************/ 
//Replace an element in the list with another element  
char replace(nodePtr *start, char value, char replacement)
{
    nodePtr prev = NULL;
    nodePtr curr = *start;

    //loop to find the correct location in the list  
    while (curr != NULL && curr->data != value) 
    {
        prev = curr; //walk to ...  
        curr = curr->next; //... next node  
    }  

    //replace node at curr  
    if (curr != NULL) //value exists in list
    {
        //assign the replacement to the data at current node
        curr->data = replacement;
        return value;
    }  
    //return null terminator if replacement is unsuccessful
    return '\0';
} 
/*****************************************************************************/
//Print the list  
void printList(nodePtr start)
{
    //if list is empty  
    if (start == NULL)
        printf( "List is empty.\n\n" ); 
    else 
    {
        printf( "The list is:\n" );

        //while not the end of the list; traverse  
        while (start != NULL) 
        {
            printf("%c --> ", start->data);
            start = start->next;
        } 
        printf("NULL\n\n");
    }  
}  
/*****************************************************************************/