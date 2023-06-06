//Jacob Smith, ID#001465673
//Scripting and Programming Applications - C867

#include "roster.h"

using namespace std;

int main() {
    //Array of provided student information, with my own information added under student ID A5.
    const string studentData[] = { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", 
                                   "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", 
                                   "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", 
                                   "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", 
                                   "A5,Jacob,Smith,jsm0849@wgu.edu,25,14,21,30,SOFTWARE" };
    cout << "Scripting and Programming - Applications: C867, Written in C++, #001465673 Jacob Smith\n\n";
    Roster classRoster;
    for (int i = 0; i < 5; i++) { //parsing the provided data and adding Students to the Roster.
        classRoster.parse(studentData[i]);
    }
    classRoster.printAll();
    classRoster.printInvalidEmails();
    cout << "Printing the average days spent in a course by each student (in whole days):\n";
    for (int i = 0; i < 5; i++) {
        classRoster.printAverageDaysInCourse(studentData[i].substr(0, 2)); //passes the student ID of the current student into the function to identify the student.
    }
    cout << endl; //Added for spacing
    classRoster.printByDegreeProgram(SOFTWARE);
    classRoster.remove("A3"); //Deletes Student A3 and removes them from the Roster.
    classRoster.printAll();
    classRoster.remove("A3"); //Should output an error since A3 was already removed.
    classRoster.~Roster(); //Deleting dynamically created Students in classRoster.
    return 0;
}