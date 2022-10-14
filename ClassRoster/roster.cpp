/*
Roster Class
roster.cpp
 
Created by Max Sealey
*/

#include <iostream>
#include <sstream>
#include "roster.h"

// add() function definition
// input: student information
// output: none
// sets instance variables from Student class and updates roster
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)
{
    int days[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
    
    classRosterArray[currentIndex] = new Student(studentID, firstName, lastName, emailAddress, age, days, degreeprogram); // creates new student and adds to classRosterArray
    
    // display confirmation of each student being added
    cout << getClassRosterArray()[currentIndex]->getFirstName() << " " << getClassRosterArray()[currentIndex]->getLastName() << " added to roster at index " << currentIndex << endl;
    
    currentIndex++; // increment roster size tracker
};


// parseEachStudent() function definition
// input: student information as an unparsed string
// output: none
// Parses string of student data, then creates & populates new Student object and adds to classRosterArray
// NOTE: This is definitely not the fastest way to parse a string, but it's an original solution. Doesn't use vectors, but uses too many placeholder variables. Not space efficient. NEEDS TO BE REFACTORED
// Source for information about sstream:
void Roster::parseEachStudent(string student)
{
    // Variables to hold items to be passed into add() function
    string studentID = "", firstName = "", lastName = "", emailAddy = "";
    int age, day1, day2, day3, count = 0;
    DegreeProgram degree = DEFAULT;
    
    // Variables to hold data as strings temporarily, before being converted and assigned to int and DegreeProgram variables
    // Again, not space efficient
    string tempDay1, tempDay2, tempDay3, tempAge, tempDegree;
    
    istringstream ss(student);
    
    // loops through once for every element, assigns each string between commas to variables
    while (count < DATA_FIELDS){
        switch(count)
        {
            case 0:
                getline(ss, studentID, ',');
                break;
            case 1:
                getline(ss, firstName, ',');
                break;
            case 2:
                getline(ss, lastName, ',');
                break;
            case 3:
                getline(ss, emailAddy, ',');
                break;
            case 4:
                getline(ss, tempAge, ',');
                break;
            case 5:
                getline(ss, tempDay1, ',');
                break;
            case 6:
                getline(ss, tempDay2, ',');
                break;
            case 7:
                getline(ss, tempDay3, ',');
                break;
            case 8:
                getline(ss, tempDegree, ',');
                break;
        };
        count++;
    };
    
    // turns strings in temporary variables into ints
    age = stoi(tempAge);
    day1 = stoi(tempDay1);
    day2 = stoi(tempDay2);
    day3 = stoi(tempDay3);
    
    // turns string for degree type into DegreeProgram enumerated type
    if(tempDegree == "SECURITY") { degree = SECURITY; };
    if(tempDegree == "NETWORK") { degree = NETWORK; };
    if(tempDegree == "SOFTWARE") { degree = SOFTWARE; };
    if(tempDegree == "DEFAULT") { degree = DEFAULT; };
    
    // add to roster
    add(studentID, firstName, lastName, emailAddy, age, day1, day2, day3, degree);
};

// remove() function definition
// input: Student ID
// output: none
// Removes students from the roster by student ID. If not found, prints error message.
// Note: I struggled with this one function for hours, and eventually asked a friend of mine (SWE), to look over it and give feedback/help debug.

void Roster::remove(string studentID)
{
    bool doesExist = false;
    
        for (int i = 0; i < currentIndex; i++) // loops through all visible/remaining elements in the array
        {
            if(studentID == getClassRosterArray()[i]->getStudentID()) // check if student ID matched one of the elements in classRosterArray
            {
                cout << "Removing " << getClassRosterArray()[i]->getFirstName() << " " << getClassRosterArray()[i]->getLastName() << "..." << endl << endl;
                
                doesExist = true;
                
                Student *temp = getClassRosterArray()[i]; // points temporary placeholder to element where the student to be removed is located.
                
                getClassRosterArray()[i] = getClassRosterArray()[NBR_STUDENTS - 1]; // element to be removed now points to end of array
                
                getClassRosterArray()[NBR_STUDENTS - 1] = temp; // points element to be removed to the end of the array
                
//                used to track indices in testing
//                cout << i << endl;
//                cout << currentIndex << endl;
                
                --currentIndex;
                break;
            };
        };

    switch ((int)doesExist) {
        case 0: // element does not exist
            cout << "\nError: No student on the roster matches that ID." << endl << endl;
            break;
            
        case 1: // Success!
            cout << "Successfully removed." << endl << endl;
            break;
    }
    
};

// printAll() function definition
// input: none
// returns: none
// displays tab-separated list of student data
void Roster::printAll()
{
    cout << "List of Students:" << endl;
    cout << "-------------------------------------------" << endl;
    for (int i = 0; i < currentIndex; i++)
    {
        this->getClassRosterArray()[i]->print();
    }; // loops through classRosterArray and prints data, separated by tabs, to the console.
    cout << "-------------------------------------------" << endl;
};

// printAverageDaysInCourse() function definition
// input: Student ID (string)
// returns: none
// displays indicated student's average days in the three courses
void Roster::printAverageDaysInCourse(string studentID)
{
    int totalDays = 0;
    for (int i = 0; i < NBR_STUDENTS; i++)
    {
        if(studentID == getClassRosterArray()[i]->getStudentID())
        {
            cout << "Average number of days that it took " << getClassRosterArray()[i]->getFirstName()
            << " " << getClassRosterArray()[i]->getLastName() << " to finish their courses: "; // display message
            
            totalDays = getClassRosterArray()[i]->getDaysToComplete()[0]+getClassRosterArray()[i]->
            getDaysToComplete()[1]+getClassRosterArray()[i]->getDaysToComplete()[2]; // store sum of all elements
            
            cout << (double)totalDays/3.0 << endl << endl;
        };
    };
};

// printInvalidEmails() function definition
// input: none
// returns: none
// verifies student email addresses and displays all invalid email addresses
void Roster::printInvalidEmails()
{
    cout << "Invalid Emails:" << endl;
    cout << "-------------------------------------------" << endl; // formatting
    // loop through array
    for(int i = 0; i < NBR_STUDENTS; i++)
    {
        if(getClassRosterArray()[i]->getEmail().find(" ") != string::npos)
        {
            cout << getClassRosterArray()[i]->getEmail() << "\n";
            continue;
        }
        if(getClassRosterArray()[i]->getEmail().find("@") == string::npos)
        {
            cout << getClassRosterArray()[i]->getEmail() << "\n";
            continue;
        }
        if(getClassRosterArray()[i]->getEmail().find(".") == string::npos)
        {
            cout << getClassRosterArray()[i]->getEmail() << "\n";
            continue;
        };
    };
    cout << "-------------------------------------------" << endl; // formatting
};


// printByDegreeProgram() function definition
// input: DegreeProgram
// returns: none
// prints out student information in specified degree program
void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
    string tempDegree = "";

    switch(degreeProgram)
    {
        case SECURITY:
            tempDegree = "Security";
            break;
        case NETWORK:
            tempDegree = "Network";
            break;
        case SOFTWARE:
            tempDegree = "Software";
            break;
        case DEFAULT:
            tempDegree = "Default";
            break;
    };
    
    cout << "Students in the " << tempDegree << " program:" << endl;
    cout << "-------------------------------------------" << endl;
    for(int i = 0; i < NBR_STUDENTS; i++)
    {
        if(getClassRosterArray()[i]->getDegreeProgram() == degreeProgram)
        {
            getClassRosterArray()[i]->print();
        };
    };
    cout << "-------------------------------------------" << endl;
    cout << "" << endl; 
};

// Getter function - returns pointer to classRosterArray
Student** Roster::getClassRosterArray()
{
    return *&classRosterArray; // returns reference to a pointer
};

// Default Constructor
Roster::Roster()
{
    for(int i = 0; i < NBR_STUDENTS; i++)
    {
        getClassRosterArray()[i] = nullptr;
    }; // initially sets each ptr to null in classRoster array
    
};

// Destructor
Roster::~Roster()
{
    for(int i = 0; i < currentIndex + 1; i++)
    {
        delete classRosterArray[i]; // deallocates memory for each student object in array
        classRosterArray[i] = nullptr;
    };
};
