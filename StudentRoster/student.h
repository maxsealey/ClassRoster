//
//  student.h
//  StudentRoster
//
//  Created by Max Sealey on 10/9/22.
//

#ifndef student_h
#define student_h

#include <string>
#include "degree.h"

using namespace std;

class Student
{
private:
    string student_id;
    string first_name;
    string last_name;
    string email_address;
    int age;
    int days_to_complete[3];
    DegreeProgram degree;
    
public:
    const int MAX_DAYS = 3;
    
    // setter declarations
    void setStudentID(string);
    void setFirstName(string);
    void setLastName(string);
    void setEmail(string);
    void setAge(int);
    void setDaysToComplete(const int []);
    void setDegreeProgram(DegreeProgram);
    
    // getter declarations
    string getStudentID() const;
    string getFirstName() const;
    string getLastName() const;
    string getEmail() const;
    int getAge() const;
    const int* getDaysToComplete();
    DegreeProgram getDegreeProgram() const;
    
    void print(); //prints student information
    
    Student(); // default constructor
    Student(string initID, string initFirstName, string initLastName, string initEmail, int initAge, int initDays[], DegreeProgram initDegree); // constructor declaration with parameters
};


#endif /* student_h */
