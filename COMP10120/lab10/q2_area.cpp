/*
 * Author: Rajit Banerjee, 18202817
 * Pset 10, Q2 - area of different shapes
 * 16.04.2019
 */
#include <iostream>
#define M_PI 3.14159265358979323846 //setting the value of pi 
using namespace std;
/*****************************************************************************/
//function prototypes, some arguments have default values
float triangle(float height = 1.0, float base = 2.3); 
float square(float side = 10);
float rectangle(float width, float length = 20);
float rhombus(float diagonal1 = 10.2, float diagonal2 = 3.8);
float circle(float radius = 3.6);
float trapezoid(float height, float base1, float base2 = 8);
/*****************************************************************************/
int main() {
    int choice; //stores user choice from menu options 
    //variables to store user input for the dimensions of various shapes
    float height, base1, base2, side, length, diag1, diag2, radius, width;

    //loop until user chooses 0 to exit
    do {
        //display menu options to user
        cout<< "\n1. Area of triangle" 
            << "\n2. Area of square"
            << "\n3. Area of rectangle"
            << "\n4. Area of rhombus"
            << "\n5. Area of circle"
            << "\n6. Area of trapezoid"
            << "\nEnter your choice (0 to exit): "; 
        cin >> choice; //input user choice
        switch (choice) {
            case 0: //end run if choice is 0 to exit
                cout << "See you later!" << endl;
                break;
    
            case 1: //triangle
                cout << "\nEnter height: "; 
                cin >> height;
                cout << "Enter base: "; 
                cin >> base1;
                //display the area of shape with the default values set
                cout << "With default argument values, the area = "  
                    << triangle() << endl;
                //display the area using user input dimensions 
                cout << "Using user input, area of triangle = " 
                    << triangle(height, base1) << endl;
                break;

            case 2: //square 
                cout << "\nEnter side: "; 
                cin >> side;
                //display the area of shape with the default values set
                cout << "With default argument values, the area = "  
                    << square() << endl; 
                cout << "Using user input, area of square = " 
                    << square(side) << endl;
                break;

            case 3: //rectangle
                cout << "\nEnter length: "; 
                cin >> length;
                cout << "Enter width: "; 
                cin >> width;
                //display the area of shape with the default values set
                cout << "With default argument values, the area = "  
                    << rectangle(width) << endl; 
                //display the area using user input dimensions
                cout << "Using user input, area of rectangle = " 
                    << rectangle(width, length) << endl;
                break;

            case 4: //rhombus
                cout << "\nEnter diagonal 1: "; 
                cin >> diag1;
                cout << "Enter diagonal 2: "; 
                cin >> diag2;
                //display the area of shape with the default values set
                cout << "With default argument values, the area = "  
                    << rhombus() << endl; 
                //display the area using user input dimensions
                cout << "Using user input, area of rhombus = " 
                    << rhombus(diag1, diag2) << endl;
                break;
            
            case 5: //circle
                cout << "\nEnter radius: "; 
                cin >> radius;
                //display the area of shape with the default values set
                cout << "With default argument values, the area = " 
                    << circle() << endl; 
                //display the area using user input dimensions
                cout << "Using user input, area of circle = " 
                    << circle(radius) << endl;
                break;
            
            case 6: //trapezoid
                cout << "\nEnter base1: "; 
                cin >> base1;
                cout << "Enter base2: "; 
                cin >> base2;
                cout << "Enter height: "; 
                cin >> height;
                //display the area of shape with the default values set
                cout << "With default argument values, the area = " 
                    << trapezoid(height, base1) << endl; 
                //display the area using user input dimensions
                cout << "Using user input, area of trapezoid = " 
                    << trapezoid(height, base1, base2) << endl;
                break;
            
            default:
                cout << "\nInvalid choice! Try again!" << endl;
        }        
    } while (choice != 0); 
    return 0;
}
/*****************************************************************************/
//function definitions to return the areas of different shapes
float triangle(float height, float base) {
    return 0.5 * height * base;
}
float square(float side) {
    return side * side;
}
float rectangle(float width, float length) {
    return width * length;
}
float rhombus(float diagonal1, float diagonal2) {
    return 0.5 * diagonal1 * diagonal2;
}
float circle(float radius) {
    return M_PI * radius * radius;
}
float trapezoid(float height, float base1, float base2) {
    return 0.5 * (base1 + base2) * height;
}
/*****************************************************************************/