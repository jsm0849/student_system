//Jacob Smith, ID#001465673
//Scripting and Programming Applications - C867

#ifndef STUDENT_H
#define STUDENT_H

#include "degree.h"

using std::string;

class Student {
public:
    const static int numClasses = 3; //Represents the number of classes the Student is enrolled in.

    //Constructors
    Student();
    Student(string ID, string firstName, string lastName, string emailAddress, int studentAge, int numDays[], DegreeProgram degreeProgram);

    //Destructor
    ~Student();

    //Accessor functions
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmailAddress();
    int getStudentAge();
    int* getClassDays();
    DegreeProgram getDegreeProgram();

    //Mutator functions
    void setStudentID(string ID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmailAddress(string emailAddress);
    void setStudentAge(int studentAge);
    void setClassDays(int classDays[]);
    void setDegreeProgram(DegreeProgram degreeProgram);

    //other functions
    void print(); //prints all Student data.
    int getAverageClassDays(); //returns average days Student spends on a class.
private:
    string studentID, firstName, lastName, emailAddress;
    int classDays[numClasses], studentAge;
    DegreeProgram degreeProgram;
};

#endif