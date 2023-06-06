//Jacob Smith, ID#001465673
//Scripting and Programming Applications - C867

#ifndef ROSTER_H
#define ROSTER_H

#include "student.h"

class Roster {
public:
    //Destructor (compiler provided default constructor used)
    ~Roster();

    //Other functions
    void parse(string dataRow);
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
private:
    const static int numStudents = 5; //Represents the number of Students in the provided list
    Student* classRosterArray[numStudents];
    int lastIndex = -1;
};

#endif