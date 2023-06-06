//Jacob Smith, ID#001465673
//Scripting and Programming Applications - C867

#include "student.h"

using std::cout;
using std::to_string;

//Constructor definitions
Student::Student() {
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->studentAge = 0;
    for (int i = 0; i < numClasses; i++) {
        this->classDays[i] = 0;
    }
    this->degreeProgram = UNDECIDED;
}
Student::Student(string ID, string firstName, string lastName, string emailAddress, int studentAge, int numDays[], DegreeProgram degreeProgram) {
    this->studentID = ID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->studentAge = studentAge;
    for (int i = 0; i < numClasses; i++) {
        this->classDays[i] = numDays[i];
    }
    this->degreeProgram = degreeProgram;
}

//Destructor defninition
Student::~Student(){}

//Accessor definitions
string Student::getStudentID() {
    return this->studentID;
}
string Student::getFirstName() {
    return this->firstName;
}
string Student::getLastName() {
    return this->lastName;
}
string Student::getEmailAddress() {
    return this->emailAddress;
}
int Student::getStudentAge() {
    return this->studentAge;
}
int* Student::getClassDays() { //Returns a pointer to the existing int array classDays.
    return this->classDays;
}
DegreeProgram Student::getDegreeProgram() {
    return this->degreeProgram;
}

//Mutator definitions
void Student::setStudentID(string ID) {
    this->studentID = ID;
}
void Student::setFirstName(string firstName) {
    this->firstName = firstName;
}
void Student::setLastName(string lastName) {
    this->lastName = lastName;
}
void Student::setEmailAddress(string emailAddress) {
    this->emailAddress = emailAddress;
}
void Student::setStudentAge(int studentAge) {
    this->studentAge = studentAge;
}
void Student::setClassDays(int classDays[]) {
    for (int i = 0; i < numClasses; i++) {
        this->classDays[i] = classDays[i];
    }
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) {
    this->degreeProgram = degreeProgram;
}

//Other function definitions
void Student::print() {
    //outputString has been divided into multiple lines for readability.
    string outputString = studentID + ",   First Name: " + firstName + ",   Last Name: " + lastName + 
                          ",   Email Address: " + emailAddress + ",   Age: " + to_string(studentAge) + 
                          ", daysInCourse: { " + to_string(classDays[0]) + ", " + to_string(classDays[1]) + 
                          ", " + to_string(classDays[2]) + " }, Degree Program: " + degreePrograms[degreeProgram];
    cout << outputString << std::endl;
}
int Student::getAverageClassDays() { //Returns the average # of days a Student spends on a class, in whole days.
    int totalDays = 0;
    for (int i = 0; i < numClasses; i++) {
        totalDays += this->classDays[i];
    }
    return (totalDays / numClasses);
}