/*
Author: Rajit Banerjee, 18202817
Pset 7, Q4 - variable argument list
29.03.19
*/
#include <stdio.h>
#include <stdarg.h>
/*****************************************************************************/
//function prototypes
int adder(int, ...);
int multiplier (int, ...);
void myPrinter (char *, ...);
/*****************************************************************************/
int main(void)
{
    //variables to store sum and product of arguments
    int sum, prod;

    printf("____________________________________________");
    //testing adder function to compute sum of integer arguments
    printf("\nadder:");
    sum = adder(5, 10, 20, 30, 40, 50);
    printf("\n10 + 20 + 30 + 40 + 50 = %d\n", sum);
    sum = adder(2, 300, 200);
    printf("300 + 200 = %d\n", sum);
    sum = adder(3, 15, 20, 25);
    printf("15 + 20 + 25 = %d\n", sum);
    printf("____________________________________________");

    //testing multiplier function to compute product pf integer arguments
    printf("\nmultiplier:");
    prod = multiplier(3, 10, 20, 30);
    printf("\n10 x 20 x 30 = %d\n", prod);
    prod = multiplier(2, 400, 2);
    printf("400 x 2 = %d\n", prod);
    prod = multiplier(4, 2, 4, 6, 8);
    printf("2 x 4 x 6 x 8 = %d\n", prod);
    printf("____________________________________________");

    /*testing myPrinter function multiple times to print 
     variable number of arguments of any type*/
    printf("\nmyPrinter:\n");
    myPrinter("sffs", "~ 1 ~", 4987.76, 1323.322, "Hello"); printf("\n");
    myPrinter("sfcds", "~ 2 ~", 3231.33, ':', 16, "World"); printf("\n");
    myPrinter("ss", "~ 3 ~", "Programming");
    printf("____________________________________________");
}
/*****************************************************************************/
//function takes in variable number of integers and returns their sum
int adder(int n, ...)
{
    //initialise sum to 0
    int sum = 0;

    //stores information needed by va_start and va_end
    va_list args;
    //initialises the va_list object
    va_start(args, n);

    //iterate through the list of arguments
    for (int i = 0; i < n; i++)
        //update the sum of the arguments
        sum += va_arg(args, int);
    
    //clean up the variable-length argument list
    va_end(args);
    return sum;
}
/*****************************************************************************/
//function takes in variable number of integers and returns their product
int multiplier(int n, ...)
{
    //initialise product to 1
    int prod = 1;

    //stores information needed by va_start and va_end
    va_list args;
    //initialises the va_list object
    va_start(args, n);

    //iterate through the list of arguments
    for (int i = 0; i < n; i++)
        //update the product of the arguments
        prod *= va_arg(args, int);
    
    //clean up the variable-length argument list
    va_end(args);
    return prod;
}
/*****************************************************************************/
/*Function takes in variable number of arguments, after a string saying what
  data type the arguments belong to.
  Output: prints the arguments on separate lines
  */
void myPrinter(char *type, ...)
{
    //stores information needed by va_start and va_end
    va_list args;
    //initialises the va_list object
    va_start(args, type);

    /* go through the string containing the information regarding what data
       type the arguments are; do so until the null terminator is reached*/
    while (*type != '\0') 
    {
        //print the argument according to its type
        switch (*type) 
        {
            //character argument
            case 'c':
                printf("%c\n", (char)va_arg(args, int));
                break;
            //string argument 
            case 's':
                printf("%s\n", va_arg(args, char *));
                break;
            //integer argument
            case 'd':
                printf("%d\n", va_arg(args, int));
                break;
            //floating-point argument
            case 'f':
                printf("%f\n", va_arg(args, double));
                break;
        }
        //incrementing pointer value
        type++;
    }
    //clean up the variable-length argument list
    va_end(args);
}
/*****************************************************************************/
