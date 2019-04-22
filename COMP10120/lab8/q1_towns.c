/*
Author: Rajit Banerjee, 18202817
Pset 8, Q1 - using structs and files
03.04.2019
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*****************************************************************************/
//defines a county with name, abbreviation & population
struct county
{
    char *longName; 
    char *shortName;
    unsigned int population;
};
/*****************************************************************************/
//defines a town with name, population & county details
struct town
{
    char *name;
    unsigned int population;
    struct county aCounty;
}; 
/*****************************************************************************/
int main(void)
{
    //This portion of code assigns county data to array of Counties

    FILE *fp; //file pointer to access files

    //if file pointer cannot open counties.txt to read; display error
    if ((fp = fopen("counties.txt", "r")) == NULL)
        printf("\nFile could not be opened!\n");
    else
    {
        //array of structs to store details of 4 counties
        struct county Counties[4];
        //allocate memory for long name and abbreviation of all counties
        for(int i = 0; i < 4; i++)
        {
            //assign 10 bytes memory to county's long name
            Counties[i].longName  = (char *)malloc(10);
            //assign 3 bytes memory to county's short name
            Counties[i].shortName = (char *)malloc(3);
        }

        //iterate through the 4 rows of data in counties.txt
        for (int i = 0; i < 4; i++)
        {
            //scan in details from file row-wise
            fscanf(fp, "%s %s%u", Counties[i].longName, 
            Counties[i].shortName, &Counties[i].population);
        }
/*****************************************************************************/
        //This portion of code assigns appropriate county details to each town

        //if file pointer cannot open towns.txt to read; display error
        if ((fp = fopen("towns.txt", "r")) == NULL)
            printf("\nFile could not be opened!\n");
        else
        {
            //array of structs to store details of 5 towns
            struct town Towns[5];
            //string to store name of county for each town
            char county_name[10];
            //allocate 15 bytes memory for each town name
            for(int i = 0; i < 5; i++)
                Towns[i].name = (char *)malloc(15);
            
            //iterate through the 5 rows of data in towns.txt
            for (int i = 0; i < 5; i++)
            {
                //scan in details from file, row-wise
                fscanf(fp, "%s%u %s", 
                    Towns[i].name, &Towns[i].population, county_name);
                for (int j = 0; j < 4; j++)
                {   
                    //if match is found, assign county details to town
                    if (strcmp(county_name, Counties[j].longName) == 0)
                    {
                        Towns[i].aCounty = Counties[j];
                        break;
                    }
                }
            }
            fclose(fp); //close file after use
/*****************************************************************************/
            //This portion of code displays all town and county details 
            printf("\nTOWN\t\tPOPULATION\tCOUNTY\t\tSHORT\tCOUNTY POPULATION");
            //iterate through 5 towns and display details as asked
            for (int i = 0; i < 5; i++)
            {
                //print data in tabular format
                printf("\n%-11s\t%u\t\t%s\t\t%s\t%u", 
                    Towns[i].name, Towns[i].population,
                    Towns[i].aCounty.longName, Towns[i].aCounty.shortName,
                    Towns[i].aCounty.population);
            }
            printf("\n");
        }
    }
    return 0;
}
/*****************************************************************************/