/*
Author: Rajit Banerjee, 18202817
Pset 6, Q2 - student records and GPA
08.03.19
*/
#include <stdio.h>
#include <string.h>
/*****************************************************************************/
//variables to store student details
char first_name[30];
char last_name[30];
char field_study[30];
int std_no; 
long int phone_no; 
float gpa;

char gpa_class [15];

//while-loop control variables   
int counter;
int choice;
/*****************************************************************************/
//function prototypes
void fillData();
void processData();
/*****************************************************************************/
int main(void)
{
    
    //call function to fill data in file
    fillData();
    //call function to process file and print student number and gpa class
    processData();

    return 0;
}
/*****************************************************************************/
//fill students.txt file with details of students (user input)
void fillData()
{
    //create/reopen student.txt file
    FILE *fp = fopen("students.txt", "w");

    //initialise student counter and user choice to 1
    counter = 1;
    choice = 1;

    //fill data in file as long as user choice is not 0 
    do
    {
        //display current student number (counter)
        printf("\n        ~ Student %d: ~\n", counter);

        printf("%16s", "First name: ");
        scanf(" %[^\n]%*c", first_name);

        printf("%16s", "Last name: ");
        scanf(" %[^\n]%*c", last_name);
/*****************************************************************************/
        //initialise student number to 0 for each iteration
        std_no = 0;

        //input valid (positive) student number
        while (std_no <= 0)
        {
            printf("Student number: ");
            scanf("%d", &std_no);

            //print error if negative or 0 (invalid) student number is input
            if (std_no <= 0)
                printf("\nPlease enter valid data!\n\n");
        } 
/*****************************************************************************/
        //initialise phone numebr to 0 for each iteration        
        phone_no = 0;

        //input valid (positive) student number
        while (phone_no <= 0)
        {
            printf("%16s", "Phone number: ");
            scanf("%li", &phone_no);
            
            //print error if negative or 0 (invalid) phone number is input
            if (phone_no <= 0)
                printf("\nPlease enter valid data!\n\n");
        }
/*****************************************************************************/
        printf("Field of study: ");
        scanf(" %[^\n]%*c", field_study);
/*****************************************************************************/
        //initialise gpa for each iteration
        gpa = 0;

        //input gpa in valid range
        while (gpa <= 0 || gpa > 4.2)
        {
            printf("%16s", "GPA: ");
            scanf("%f", &gpa);

            //print error if gpa outside valid range is input
            if (gpa <= 0 || gpa > 4.2)
                printf("\nPlease enter valid data!\n\n");
        }
/*****************************************************************************/
        //print student data to file 
        fprintf(fp, "%15s%15s\t%d\t%li\t%35s\t%.2f\n", 
            first_name, last_name, std_no, phone_no, field_study, gpa);
/*****************************************************************************/
        //ask user if they want to continue data input
        do
        {
            printf("\nContinue? (1 = yes/0 = no): ");
            scanf("%d", &choice);
        } while (choice != 1 && choice != 0);
        
        //increment counter if user chooses to continue with next student input
        if (choice == 1)
            counter++;

    } while (choice != 0);

    //close file after use
    fclose(fp);
}
/*****************************************************************************/
//proccess students.txt file and print student number and gpa class
void processData()
{    
    FILE *fp;

    if((fp = fopen("students.txt", "r")) == NULL)
    {
        //display error if file does not exist
        printf("\nError: File could not be opened!\n");
    }
    else
    {
        printf("\n******************************************************");
        printf("\nSTUDENT NUMBER\tGPA CLASS\n");

        //scan in student details from file  
        fscanf(fp, "%s %s %d%li %s %f",
            first_name, last_name, &std_no, &phone_no, field_study, &gpa);
/*****************************************************************************/
        //continue loop until end of file is reached
        while (!feof(fp))
        {
            //compute GPA class based on GPA range
            if (gpa >= 3.68)
                strcpy(gpa_class, "1st Class Honours");
            else if (gpa >= 3.08 && gpa <= 3.67)
                strcpy(gpa_class, "2nd Class Honours, Grade 1");
            else if (gpa >= 2.48 && gpa <= 3.07)
                strcpy(gpa_class, "2nd Class Honours, Grade 2");
            else if (gpa >= 2.00 && gpa <= 2.47)
                strcpy(gpa_class, "Pass");
            else
                strcpy(gpa_class, "Fail");
/*****************************************************************************/
            //display student number and GPA class
            printf("%14d\t%s\n", std_no, gpa_class); 

            //scan next student's details
            fscanf(fp, "%s %s %d%li %s %f",
                first_name, last_name, &std_no, &phone_no, field_study, &gpa);
        } 
        printf("******************************************************\n");
    }
    //close file after use
    fclose(fp);
}
/*****************************************************************************/