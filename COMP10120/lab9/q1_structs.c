/*
 * Author: Rajit Banerjee, 18202817
 * Pset 9, Q1 - structs and binary file applications
 * 09.04.2019
 */
#include <stdio.h>
#define NUM_CUSTOMERS 5 //declaring number of customers
/*****************************************************************************/
//defines an area, with a zip code and number of customers living there
struct zip_custs
{
    int zip_code;
    int customer_count;
};
/*****************************************************************************/
int main(void)
{
    //array stores zip code and customer count of 5 areas
    int myCustomers [5][2] = {{86956, 1}, {36568, 3}, {6565, 0}, 
        {999555, 22}, {85446, 88}};

    //array of 5 structs, each with a zip code and customer count
    struct zip_custs Customers[NUM_CUSTOMERS];

    //fill the details of the 5 structs from myCustomers array
    for (int i = 0; i < NUM_CUSTOMERS; i++)
    {
        Customers[i].zip_code = myCustomers[i][0];
        Customers[i].customer_count = myCustomers[i][1];
    }

    //array of 5 structs to store data read from binary file customers.dat
    struct zip_custs read_customers[NUM_CUSTOMERS];
/*****************************************************************************/
    FILE *fp; //file pointer
    //create binary file to read and re-write (discard previous contents)
    if ((fp = fopen("customers.dat", "wb+")) == NULL)
    { 
        //display error if file cannot be opened
        printf("\nFile could not be opened!\n");
    }
    else
    {
        //iterate through all customers and write structs to customers.dat
        for (int i = 0; i < NUM_CUSTOMERS; i++)
            fwrite(&Customers[i], sizeof(struct zip_custs), 1, fp);

        //set the file position to the beginning of the file, for reading
        rewind(fp);

        //iterate through all customers and read data into new array of structs
        for (int i = 0; i < NUM_CUSTOMERS; i++)
            fread(&read_customers[i], sizeof(struct zip_custs), 1, fp);
        
        //display the contents of the structs read from binary file
        printf("\nZIP CODE\tCUSTOMER COUNT\n");
        for (int i = 0; i < NUM_CUSTOMERS; i++)
        {
            printf("%d\t\t%d\n", read_customers[i].zip_code,
                read_customers[i].customer_count);
        }
        fclose(fp); //close file after use
    }
    return 0;
}
/*****************************************************************************/