//
//  Employee.h
//  CS303A2
//
//  Created by Brendan Clouston on 10/8/23.
//

#ifndef Employee_h
#define Employee_h
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    float hoursWorked;
    float vacationHours;        
    float insurancePremium;     //yearly premium
public:
    //default constructor, all values = 0
    Employee();
    
    //overloaded constructor
    Employee(string n, float h, float v, float ins);
    
    //functions defined within derived classes Professional and NonProfessional
    virtual float weeklySalary() = 0;
    virtual float vacationHoursEarned() = 0;    //0.25h/hour worked for professional, 0.15h/hour worked for non professional
    virtual float healthcareContrib() = 0;      //75% for professional and 50% for nonprofessional
};

#endif /* Employee_h */
