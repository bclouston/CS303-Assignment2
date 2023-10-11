//
//  Employee.cpp
//  CS303A2
//
//  Created by Brendan Clouston on 10/9/23.
//
#include "Employee.h"

Employee::Employee() {
    name = "Unknown";
    hoursWorked = 0;
    vacationHours = 0;    
    insurancePremium = 0;
}

Employee::Employee(string n, float h, float v, float ins) {
    name = n;
    hoursWorked = h;
    vacationHours = v;
    insurancePremium = ins;
}

