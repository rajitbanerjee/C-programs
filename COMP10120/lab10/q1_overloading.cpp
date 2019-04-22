/*
 * Author: Rajit Banerjee, 18202817
 * Pset 10, Q1 - function overloading
 * 16.04.2019
 */
#include <iostream>
using namespace std;
/*****************************************************************************/
//function prototypes
float addTwo(float, float);
int addTwo(int, int);
double addTwo(double, double);
long addTwo(long, long);
/*****************************************************************************/
int main() {
    //variables to store user input
    int choice; 
    float  f1, f2;
    int    i1, i2;
    double d1, d2;
    long   l1, l2;

    //loop until choice is 0 to exit
    do {
        cout<< "\n1. Add two floats" 
            << "\n2. Add two integers"
            << "\n3. Add two doubles"
            << "\n4. Add two longs"
            << "\nEnter your choice (0 to exit): "; 
        cin >> choice;

        switch (choice) {
            case 0: //exit
                cout << "See you later!" << endl;
                break;

            case 1: //add two floats
                cout << "\nEnter two floats:\n";
                cin >> f1 >> f2;
                cout << "Sum = " << addTwo(f1, f2) << endl;
                break;

            case 2: //add two integers
                cout << "\nEnter two integers:\n";
                cin >> i1 >> i2;
                cout << "Sum = " << addTwo(i1, i2) << endl;
                break;

            case 3: //add two double values
                cout << "\nEnter two doubles:\n";
                cin >> d1 >> d2;
                cout << "Sum = " << addTwo(d1, d2) << endl;
                break;

            case 4: //add two long values
                cout << "\nEnter two longs:\n";
                cin >> l1 >> l2;
                cout << "Sum = " << addTwo(l1, l2) << endl;
                break;
            
            default: //invalid input for choice
                cout << "\nInvalid choice! Try again!" << endl;
        }        
    } while (choice != 0); 
}
/*****************************************************************************/
//overloaded function definitions to add two numbers of different types
float addTwo (float a, float b) {
    return a + b;
}
int addTwo (int a, int b) {
    return a + b;
}
double addTwo (double a, double b) {
    return a + b;
}
long addTwo (long a, long b) {
    return a + b;
}
/*****************************************************************************/

