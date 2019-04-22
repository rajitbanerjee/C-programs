/*
Author: Rajit Banerjee, 18202817
Pset 6, Q2 - random access files - video game catalogue
08.03.19
*/
#include <stdio.h>
#include <string.h>

//struct to store details about a video game
typedef struct gameData
{
    //game details
    int num; //game number (1-1000)
    char title[80];
    char platform[80];
    char developer[80];
    int year;

    //game borrower details
    char borrower_first_name[80];
    char borrower_last_name[80];
    char borrow_date[10];
} gameData;

//function prototypes
void fillGameDetails();
void updateBorrowDetails();
void borrowGame();
void returnGame();
void printRecords();

int main(void)
{
    FILE *fp;

    //create/rewrite videogames.txt file
    if((fp = fopen("videogames.txt", "wb")) == NULL)
    {
        //if file points to NULL, then display error
        printf("\nError: File cannot be opened.\n");
    }
    else
    {
        //initialise game variable of type gameData
        gameData game = {0, "", "", "", 0, "", "", ""};

        //create blank spaces in file to hold 1000 video game records
        for (int i = 0; i < 1000; i++)
        {
            fwrite(&game, sizeof(gameData), 1, fp);
        }
        //close file after user
        fclose(fp);
    }

    //call function to fill video games' basic details
    fillGameDetails();

    //call function to update details about the game's borrow status
    //i.e. who has borrowed the game and when
    updateBorrowDetails();

    return 0;
}

//function to add records/details of games to a file
void fillGameDetails()
{
    FILE *fp;
    //open file "videogames.txt" to modify (add game details)
    if((fp = fopen("videogames.txt", "rb+")) == NULL)
    {
        printf("\nError: File cannot be opened.\n");
    }
    else
    {
        //initialuse variable game of type gameData
        gameData game = {0, "", "", "", 0, "", "", ""};
        //choice variable to control loop
        int choice = 1;

        printf("\n~ Video game records ~");

        //continue taking user input of game details until choice is 0
        do
        {
            printf("\nGame number (1-1000): ");
            scanf("%d", &game.num);

            printf("Title: ");
            scanf(" %[^\n]%*c", game.title);

            printf("Platform: ");
            scanf(" %[^\n]%*c", game.platform);

            printf("Developer: ");
            scanf(" %[^\n]%*c", game.developer);

            printf("Year: ");
            scanf("%d", &game.year);

            //update file pointer fp to point just before required game number
            fseek(fp, (game.num - 1) * sizeof(gameData), SEEK_SET);

            //update game details for designated game number
            fwrite(&game, sizeof(gameData), 1, fp);

            //ask user if they want to continue data input 
            do
            {
                printf("\nContinue? (1 = yes/0 = no): ");
                scanf("%d", &choice);
            } while (choice != 1 && choice != 0);

            if (choice == 1)
                continue;
        
        } while (choice != 0);
        fclose(fp);
    }
}

//function to update game records by adding or removing borrower details
void updateBorrowDetails()
{
    //choice variable to control loop
    int choice = 0;

    //ask for user choice from menu until choice is 0 (exit)
    do
    {
        printRecords();
        printf("\n~ Update borrower details ~");
        printf("\n1. Borrow a game.");
        printf("\n2. Return a game.");
        printf("\nEnter choice (0 to exit):\n");
        scanf("%d", &choice);

        //if user chooses 1, call function to borrow a game
        if (choice == 1)
            borrowGame();
        
        //if user chooses 2, call function to return a game
        else if (choice == 2)
            returnGame();

    } while (choice != 0);
}

//function to add details of a game borrower and when the game was borrowed
void borrowGame()
{
    FILE *fp;

    //to store user-chosen game number
    int game_number;
    //to store name of person who borrows the game
    char f_name[80];
    char l_name[80];
    //to store the date when the game was borrowed
    char date[10];

    int flag = 0;

    //open videogames.txt file to modify it
    if((fp = fopen("videogames.txt", "rb+")) == NULL)
    {
        printf("\nError: File cannot be opened.\n");
    }
    else
    {
        //initialise game variable of type gameData
        gameData game = {0, "", "", "", 0, "", "", ""};

        printf ("\nEnter game number to borrow: ");
        scanf("%d", &game_number);

        printf("Enter borrower's first name: ");
        scanf(" %[^\n]%*c", f_name);

        printf("Enter borrower's last name: ");
        scanf(" %[^\n]%*c", l_name);

        printf("Enter borrow date: ");
        scanf(" %[^\n]%*c", date);

        //loop until end of file is reached
        while(!feof(fp))
        {
            //read from file into game variable
            int res = fread(&game, sizeof(gameData), 1, fp);

            /*if above read is successful (res is not 0) and game number 
            match is found, then set flag to 1 and exit loop*/
            if (res != 0 && game.num == game_number)
            {
                flag = 1;
                break;
            }
        }

        if (flag == 1)
        {
            //copy name and date into borrower name and borrow date
            strcpy(game.borrower_first_name, f_name);
            strcpy(game.borrower_last_name, l_name);
            strcpy(game.borrow_date, date);

            //update file pointer to point juts before current game number
            fseek(fp, (game.num - 1) * sizeof(gameData), SEEK_SET);

            //modify game record to add borrower name and borrow date
            fwrite(&game, sizeof(gameData), 1, fp);
        }
        else
        {
            printf("\nGame not found!\n");
        }
        //close file after use
        fclose(fp);
    }
}

//function to remove borrower details of chosen game, since it is being returned
void returnGame()
{
    FILE *fp;

    //to store which game is being returned
    int game_number;

    int flag = 0;

    //open file to modify records
    if((fp = fopen("videogames.txt", "rb+")) == NULL)
    {
        printf("\nError: File cannot be opened.\n");
    }
    else
    {
        //initialise game variable of type gameData
        gameData game = {0, "", "", "", 0, "", "", ""};

        printf ("\nEnter game number to return: ");
        scanf("%d", &game_number);

        //run loop until end of file is reached
         while(!feof(fp))
        {
            //read from file into game variable
            int res = fread(&game, sizeof(gameData), 1, fp);

            /*if above read is successful (res is not 0) and game number 
            match is found, then set flag to 1 and exit loop*/
            if (res!=0 && game.num == game_number)
            {
                flag = 1;
                break;
            }
        }

        if (flag == 1)
        {
            /*if flag is set, then re-initialise borrower name and borrow date
            so that the borrow record can be removed (since game is returned)*/
            strcpy(game.borrower_first_name, "");
            strcpy(game.borrower_last_name, "");
            strcpy(game.borrow_date, "");

            //set file pointer to point just before current game number
            fseek(fp, (game.num - 1) * sizeof(gameData), SEEK_SET);
            //modify record at current game number to remove borrower details
            fwrite(&game, sizeof(gameData), 1, fp);

            printf("\nGame has been returned!\n");
        }
        else
        {
            printf("\nGame not found!\n");
        }
        //close file after use
        fclose(fp);
    }
}

//function to display all the recorded video games and their details
void printRecords()
{
    FILE *fp;
    //open file to read from it
    if((fp = fopen("videogames.txt", "rb")) == NULL)
    {
        printf("\nError: File cannot be opened.\n");
    }
    else
    {
        //initialise game variable of type gameData
        gameData game = {0, "", "", "", 0, "", "", ""};

        printf("\n************************************************************");
        printf("\n~ VIDEO GAME RECORDS ~");
        printf("\nGAME NO.\tTITLE\t\tPLATFORM\tDEVELOPER\tYEAR\tBORROWER NAME\tBORROW DATE\n");

        //run loop until end of file is reached
        while(!feof(fp))
        {
            //read data from file into game variable
            int res = fread(&game, sizeof(gameData), 1, fp);

            //display records if read is successful and game number exists  
            if (res != 0 && game.num != 0)
            {
                //print the records
                printf("%5d\t%13s\t%13s\t%17s\t%4d\t%s %s\t%10s\n", 
                    game.num, game.title, game.platform,
                    game.developer, game.year, game.borrower_first_name, 
                    game.borrower_last_name, game.borrow_date);
            }
        }
        //close file after use
        fclose(fp);
    }
}
