/*
Roster Class
roster.h
 
Created by Max Sealey
*/

#ifndef roster_h
#define roster_h

#include <string>
#include "degree.h"
#include "student.h"

const int DATA_FIELDS = 9;
const int NBR_STUDENTS = 5;

class Roster
{
private:
    int currentIndex = 0; // used to dynamically track size of student array
    
    // Array of pointers to hold student data
    Student* classRosterArray[NBR_STUDENTS];
    
public:
    // add() function declaration
    // input: student information
    // returns: none
    // Sets instance variables in Student class and updates roster
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
    
    // remove() function declaration
    // input: Student ID (string)
    // returns: none
    // Removes students from the roster by student ID. If not found, displays error message
    void remove(string studentID);
    
    // printAll() function declaration
    // input: none
    // returns: none
    // displays tab-separated list of student data
    void printAll();
    
    // printAverageDaysInCourse() function declaration
    // input: Student ID (string)
    // returns: none
    // displays indicated student's average days in the three courses
    void printAverageDaysInCourse(string studentID);
    
    // printInvalidEmails() function declaration
    // input: none
    // returns: none
    // verifies student email addresses and displays all invalid email addresses
    void printInvalidEmails();
    
    // printByDegreeProgram() function declaration
    // input: DegreeProgram
    // returns: none
    // prints out student information in specified degree program
    void printByDegreeProgram(DegreeProgram degreeProgram);
    
    // parseEachStudent() function declaration
    // input: student information as an unparsed string
    // output: none
    // Parses string of student data, then creates & populates new Student object and adds to classRosterArray
    // DISCLAIMER: NEEDS TO BE REFACTORED
    void parseEachStudent(string student);
    
    // Getter function - returns pointer to element in classRosterArray at index 0
    Student** getClassRosterArray();
    
    // Default Constructor
    Roster();
    
    // Destructor
    ~Roster();
};


#endif /* roster_h */
