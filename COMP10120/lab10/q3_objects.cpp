/*
 * Author: Rajit Banerjee, 18202817
 * Pset 10, Q3 - demonstrating the use of classes and objects
 * 19.04.2019
 */
#include <iostream>
#include <string>
using namespace std;
/*****************************************************************************/
class Student { //class definition
public:     
    //mutator to set student number
    void setStudentNo (int std_no) {
        this->std_no = std_no;
    }
    //accessor for student number
    int getStudentNo () const {
        return std_no;
    }
/*****************************************************************************/
    //mutator to set student name
    void setName (string name) {
        this->name = name;
    }
    //accessor for student name
    string getName () const {
        return name;
    }
/*****************************************************************************/
    //mutator to set student's address
    void setAddress(string address) {
        this->address = address;
    }
    //accessor for student's address
    string getAddress () const {
        return address;
    }
/*****************************************************************************/
    //mutator to set phone number 
    //phone number is a string to accommodate leading 0's or + and dashes (-)
    void setPhoneNo (string ph_no) {
        this->ph_no = ph_no;
    }
    //accessor for phone number
    string getPhoneNo () const {
        return ph_no;
    }
/*****************************************************************************/
    //mutator to set field of study
    void setStudyField (string field) {
        this->field = field;
    }
    //accessor for field of study
    string getStudyField () const {
        return field;
    }
/*****************************************************************************/
    //mutator to set student's stage of study
    void setStage (int stage) {
        this->stage = stage;
    }
    //accessor for student's stage of study
    int getStage () const {
        return stage;
    }
/*****************************************************************************/
    //mutator to set student's GPA
    void setGPA (float gpa) {
        this->gpa = gpa;
    }
    //accessor for student's GPA
    float getGPA () const {
        return gpa;
    } 
/*****************************************************************************/
    //function to increase the stage of a student
    void nextYear() {
        stage++;
    } 
    //function to increase the GPA of a student;
    void increaseGPA (float inc) {
        gpa += inc;
    }
    //function to decrease the GPA of a student;
    void decreaseGPA (float dec) {
        gpa -= dec;
    }
    void displayDetails() {
        //call accessor functions to display student details
        cout << "Student No.: " << getStudentNo() << endl;
        cout << "Name       : " << getName() << endl;
        cout << "Address    : " << getAddress() << endl;
        cout << "Phone No.  : " << getPhoneNo() << endl;
        cout << "Field      : " << getStudyField() << endl;
        cout << "Stage      : " << getStage() << endl;
        cout << "GPA        : " << getGPA() << endl;
        //display errors for too high or negative GPA
        if (getGPA() < 0 || getGPA() > 4.2) {
            cout << "\nINVALID GPA! Please re-check student data!" << endl;
        }
        //display warning for Fail GPA
        else if (getGPA() < 2) {
            cout << "\nWARNING: GPA below 2.0 is a failing grade!" << endl;
        }
    }
/*****************************************************************************/
private:
    //private data members of the class Student
    //used to store student details
    int std_no;
    string name;
    string address;
    string ph_no;
    string field;
    int stage;
    float gpa;
};
/*****************************************************************************/
//create objects and test Student class' member functions
int main() {
    //instantiate 2 students to demonstrate object behaviour
    Student A, B;

    //call mutator functions of student A to set student details
    A.setStudentNo(18202817);
    A.setName("Rajit Banerjee");
    A.setAddress("16/2Q Dover Lane");
    A.setPhoneNo("0899795988");
    A.setStudyField("Computer Science");
    A.setStage(1);
    A.setGPA(4.17);
    cout << "\n~ Student #1 ~ Initial data:" << endl;
    //call member function of class Student to show student data
    A.displayDetails(); 

    //demonstate use of other member functions of class Student with object A
    A.decreaseGPA(3); //GPA is decreased by 3 points
    //display updated GPA by calling accessor function getGPA()
    cout << "\nGPA decreased to " << A.getGPA() << endl;

    //display updated details of students after decreasing the GPA above
    cout << "\n~ Student #1 ~ Updated data:" << endl;
    A.displayDetails();
/*****************************************************************************/
    //call mutator functions of student B to set student details
    B.setStudentNo(18204728);
    B.setName("John Appleseed");
    B.setAddress("123 Apple Drive");
    B.setPhoneNo("+353-848836475");
    B.setStudyField("Computer Science");
    B.setStage(2);
    B.setGPA(4.01);
    cout << "\n~ Student #2 ~ Initial data:" << endl;
    //call member function of class Student to show student data
    B.displayDetails();

    //demonstate use of other member functions of class Student with object B
    B.nextYear(); //increment the Stage of student B
    B.increaseGPA(2); //increase the GPA of student B by 2 points

    cout << "\nStage and GPA updated!" << endl;
    //display the updated stage and GPA by calling accessor functions
    cout << "Stage: " << B.getStage() << "\nGPA: " << B.getGPA() << endl;
    //display updated details of student B after changing Stage and GPA above
    cout << "\n~ Student #2 ~ Updated data:" << endl;
    B.displayDetails();
}
/*****************************************************************************/
