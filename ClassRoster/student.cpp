/*
Student Class
student.cpp
 
Created by Max Sealey
*/

#include <iostream>
#include "student.h"

//
// Setter Function Definitions
//

void Student::setStudentID(string id)
{
    this->student_id = id;
};

void Student::setFirstName(string first)
{
    this->first_name = first;
};

void Student::setLastName(string last)
{
    this->last_name = last;
};

void Student::setEmail(string email)
{
    this->email_address = email;
};

void Student::setAge(int studentAge)
{
    this->age = studentAge;
};

void Student::setDaysToComplete(const int daysComplete[])
{
    for (int i = 0; i < MAX_DAYS; i++) {
        this->days_to_complete[i] = daysComplete[i];
    }
};

void Student::setDegreeProgram(DegreeProgram degreeProgram)
{
    this->degree = degreeProgram;
};

//
// Getter Function Definitions
//

string Student::getStudentID() const
{
    return student_id;
};

string Student::getFirstName() const
{
    return first_name;
};

string Student::getLastName() const
{
    return last_name;
};

string Student::getEmail() const
{
    return email_address;
};

int Student::getAge() const
{
    return age;
};

const int* Student::getDaysToComplete()
{
    return days_to_complete;
};

DegreeProgram Student::getDegreeProgram() const
{
    return degree;
};

// print() function definition
// input: none
// returns: none
// displays student information separated by tabs
void Student::print()
{
    string tempDegree = "";

    switch(getDegreeProgram())
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
    
    cout << this->getStudentID() << "\tFirst Name: " << getFirstName() << "\tLast Name: " << this->getLastName() << "\tEmail Address: " << getEmail() << "\tAge: " << this->getAge() << "\tDays in courses: {" << getDaysToComplete()[0] << "," << getDaysToComplete()[1] << "," << getDaysToComplete()[2] << "}" << "\tDegree Program: " << tempDegree << endl;
}

// Default Constructor
Student::Student()
{
    this->student_id = "";
    this->first_name = "";
    this->last_name = "";
    this->email_address = "";
    this->age = -1;
    for(int i = 0; i < MAX_DAYS; i++) {
        this->days_to_complete[i] = -1;
    }
    this->degree = DEFAULT;
};

// Constructor with parameters
Student::Student(string initID, string initFirstName, string initLastName, string initEmail, int initAge, int initDays[], DegreeProgram initDegree)
{
    this->student_id = initID;
    this->first_name = initFirstName;
    this->last_name = initLastName;
    this->email_address = initEmail;
    this->age = initAge;
    for(int i = 0; i < MAX_DAYS; i++) {
        this->days_to_complete[i] = initDays[i];
    }
    this->degree = initDegree;
};

// Destructor
Student::~Student()
{
    // Not needed
};




