//
//  student.cpp
//  StudentRoster
//
//  Created by Max Sealey on 10/9/22.
//
#include <iostream> // input output stream
#include "student.h"

// Setter Function Definitions
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

// Getter Function Definitions
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
}; // may be incorrect

DegreeProgram Student::getDegreeProgram() const
{
    return degree;
};

void Student::print()
{
    cout << "Student ID: " << this->student_id << "\n" << endl;
    cout << "Name: " << this->first_name << " " << this->last_name << "\n" << endl;
    cout << "Student Email: " << this->email_address << "\n" << endl;
    cout << "Student Age: " << this->age << "\n" << endl;
    cout << "Degree Program: " << this->degree << "\n" << endl;
    cout << "Days to Complete Course 1: " << this->days_to_complete[0] << "\nDays to Complete Course 2: " << this->days_to_complete[1] << "\nDays to Complete Course 3: " << this->days_to_complete[2] << endl;
}

Student::Student()
{
    setStudentID("");
    setFirstName("");
    setLastName("");
    setEmail("");
    setAge(-1);
    setDegreeProgram(DEFAULT);
    //setDaysToComplete();
};

// Constructor Definition with parameters
Student::Student(string initID, string initFirstName, string initLastName, string initEmail, int initAge, int initDays[], DegreeProgram initDegree)
{
    setStudentID(initID);
    setFirstName(initFirstName);
    setLastName(initLastName);
    setEmail(initEmail);
    setAge(initAge);
    // setDaysToComplete();
    setDegreeProgram(initDegree);
};




