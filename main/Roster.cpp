//Jacob Smith, ID#001465673
//Scripting and Programming Applications - C867

#include "roster.h"

using std::string; //These are included here for readability below.
using std::cout;
using std::endl;

//Destructor definition
Roster::~Roster() {
    cout << "Destructor called.\n";
    for (int i = 0; i <= Roster::lastIndex; i++) {
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
        //Deletes the Student that classRosterArray[i] is pointing to, then points the pointer to nothing.
    }
}

//Other function definitions
void Roster::parse(string dataRow) {
    const int numClasses = 3; //Number of classes each Student is enrolled in
    int classDays[numClasses];
    DegreeProgram degreeProgram = UNDECIDED;
    int rightHand = dataRow.find(','); //rightHand is the right hand side of the first substring + 1

    string studentID = dataRow.substr(0, rightHand); //Student ID
    int leftHand = rightHand + 1; //leftHand is the left hand side of the next substring
    rightHand = dataRow.find(',', leftHand); //rightHand moves to the next comma, starting at leftHand

    string firstName = dataRow.substr(leftHand, rightHand - leftHand); //Student first name
    leftHand = rightHand + 1;
    rightHand = dataRow.find(',', leftHand);

    string lastName = dataRow.substr(leftHand, rightHand - leftHand); //Student last name
    leftHand = rightHand + 1;
    rightHand = dataRow.find(',', leftHand);

    string emailAddress = dataRow.substr(leftHand, rightHand - leftHand); //Student email address
    leftHand = rightHand + 1;
    rightHand = dataRow.find(',', leftHand);

    int studentAge = stoi(dataRow.substr(leftHand, rightHand - leftHand)); //Student age

    for (int i = 0; i < numClasses; i++) {
        leftHand = rightHand + 1;
        rightHand = dataRow.find(',', leftHand);
        classDays[i] = stoi(dataRow.substr(leftHand, rightHand - leftHand));
    }

    leftHand = rightHand + 1;

    switch (dataRow.at(dataRow.length() - 1)) { //Using the last character of the string to determine degree program, since
    case 'Y':                                   //each program ends with a different character.
        degreeProgram = SECURITY;
        break;
    case 'K':
        degreeProgram = NETWORK;
        break;
    case 'E':
        degreeProgram = SOFTWARE;
        break;
    default:
        break;
    }
    add(studentID, firstName, lastName, emailAddress, studentAge, classDays[0], classDays[1], classDays[2], degreeProgram);
    //Initializing and adding the Student to the Roster.
}
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    int classDays[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
    classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, classDays, degreeProgram);
    //Initializes and adds the new Student to the Roster and increments lastIndex, thereby increasing the number of listed Students.
}
void Roster::remove(string studentID) {
    bool studentRemoved = false; //Identifies whether a Student has been removed during this specific function call.
    for (int i = 0; i <= Roster::lastIndex; i++) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            if (i < Roster::lastIndex) { //If the current Student is not the last Student in the array
                delete classRosterArray[i];//Delete the Student the pointer is pointing to, then point the pointer to the last Student in the array.
                classRosterArray[i] = classRosterArray[Roster::lastIndex];
                //The current Student is replaced with the last Student in the array, then the number of Students is 
                //decremented, effectively removing the student at the end of the array.
            }
            studentRemoved = true;
            Roster::lastIndex--; //Reducing the number of listed Students since one was removed.
        }
    }
    if (studentRemoved) {
        cout << "Student " << studentID << " was removed.\n\n";
    } else {
        cout << "Student " << studentID << " not found.\n\n";
    }
}
void Roster::printAll() {
    cout << "Printing all student data in the following format:\n\tStudent ID, Student Name (First, Last), Email Address, Age, Days Spent on Courses, Degree Program.\n\n";
    for (int i = 0; i <= Roster::lastIndex; i++) {
        classRosterArray[i]->print();
    }
    cout << endl;
}
void Roster::printAverageDaysInCourse(string studentID) { //Prints the average days a student takes to complete a course, in whole days.
    cout << "Student " << studentID << ": " << classRosterArray[stoi(studentID.substr(1, 1)) - 1]->getAverageClassDays() << endl;
}
void Roster::printInvalidEmails() {
    cout << "Checking validity of email addresses...\n";
    for (int i = 0; i <= Roster::lastIndex; i++) {
        string email = classRosterArray[i]->getEmailAddress();
        //If a space character was found, or if an '@' character was not found, or if a '.' character was not found
        if ((email.find(' ') != string::npos) || (email.find('@') == string::npos) || (email.find('.') == string::npos)) {
            cout << "Student " << classRosterArray[i]->getStudentID() << ": Invalid email address \"" << email << "\"\n";
        }
    }
    cout << endl;
}
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    bool programPresent = false; //Identifies whether anyone in the Roster is a part of Degree Program degreeProgram
    for (int i = 0; i <= Roster::lastIndex; i++) {
        if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
            if (!programPresent) { //If programPresent is still false, this is the first Student found to be in the program and an appropriate header is printed.
                cout << "Students in the " << degreePrograms[degreeProgram] << " program:\n";
                programPresent = true;
            }
            classRosterArray[i]->print();
        }
    }
    if (!programPresent) {
        cout << "No one from the " << degreePrograms[degreeProgram] << " program is on the roster.\n";
    }
    cout << endl;
}