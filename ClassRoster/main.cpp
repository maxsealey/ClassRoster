/*
Project: Class Roster
Course: WGU C867 Performance Assessment
Name: Max Sealey
Date Started: October 9th, 2022
Date Submitted: October 11th, 2022

Requirements:
 - In the main file, display author and course information.
 - Add data in the form of a string.
 - Create roster object with default constructor
 - Roster object parses the information for each student, creates a new Student object for each one, and stores as an array of pointers.
 - Roster class also has methods to print all of the student data, print emails that have been formatted incorrectly, print the average number of days spent in each course, print by degree program, and remove students by ID.
 
Functions and features I'm in the process of developing:
 - Read in data from a .csv file (which would include more student data: birthdate, gpa, grades, instructor names, course names).
 - Take user input to add/remove/edit/search students.
 - Organize student objects into a more efficient data structure for searching.
 - Ensure quality of information and input.
 
main.cpp
*/
 
#include <iostream>
#include <string>
#include <stdlib.h>

#include "roster.h"

using namespace std;

int main() {
    
    // Display Project & Author Information
    cout << "----------------------------------------------------------------" << endl;
    cout << "Course: Scripting & Programming - Applications (WGU C867)" << endl;
    cout << "Programming Language: C++ (compiled in Xcode)" << endl;
    cout << "Name: Max Sealey" << endl;
    cout << "Student ID: 010332991" << endl;
    cout << "----------------------------------------------------------------\n" << endl;
    
    // Data
    const string studentData[] =
    {"A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Max,Sealey,gsealey@wgu.edu,25,4,5,55,SOFTWARE"};
    
    Roster classRoster; // creates new Roster object with default constructor
    
    for (int i = 0; i < NBR_STUDENTS; i++) {
        classRoster.parseEachStudent(studentData[i]);
    }; // parses each element of studentData array
    cout << "" << endl;
    
    // self-explanatory
    classRoster.printAll();
    cout << "" << endl;
    
    // prints list of emails that are incorrectly formatted
    classRoster.printInvalidEmails();
    cout << "" << endl;
    
    // loops through array of students in Roster object and displays average of days taken to complete courses
    for(int j = 0; j < NBR_STUDENTS; j++)
    {
        classRoster.printAverageDaysInCourse(classRoster.getClassRosterArray()[j]->getStudentID());
    };

    // cout << "testing getClassRosterArray()" << endl;
    // classRoster.getClassRosterArray()[4]->print();
    
    // prints list of students in the software program
    classRoster.printByDegreeProgram(SOFTWARE);
    
    classRoster.remove("A3");
    classRoster.printAll();
    
    classRoster.remove("A3");
    classRoster.printAll();
    return 0;
}
