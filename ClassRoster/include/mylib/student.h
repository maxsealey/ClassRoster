/*
Student Class
student.h
 
Created by Max Sealey
*/


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
    const static int MAX_DAYS = 3;
    
    // Setter Declarations
    void setStudentID(string);
    void setFirstName(string);
    void setLastName(string);
    void setEmail(string);
    void setAge(int);
    void setDaysToComplete(const int []);
    void setDegreeProgram(DegreeProgram);
    
    // Getter Declarations
    string getStudentID() const;
    string getFirstName() const;
    string getLastName() const;
    string getEmail() const;
    int getAge() const;
    const int* getDaysToComplete();
    DegreeProgram getDegreeProgram() const;
    
    // print() function declaration
    // input: none
    // returns: none
    // displays student information
    void print();
    
    Student(); // default constructor
    
    Student(string initID, string initFirstName, string initLastName, string initEmail, int initAge, int initDays[], DegreeProgram initDegree); // constructor declaration with parameters
    
    ~Student(); // destructor
};


#endif /* student_h */
