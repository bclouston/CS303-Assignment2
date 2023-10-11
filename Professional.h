//
//  Professional.h
//  CS303A2
//
//  Created by Brendan Clouston on 10/8/23.
//

#ifndef Professional_h
#define Professional_h
#include "Employee.h"

class Professional : public Employee {
protected:
    float monthlySalary;
public:
    //constructor, uses base class constructor for derived variables
    Professional() : Employee() {
        monthlySalary = 0;
    };
    
    //overloaded constructor, uses base class constructor for derived variables
    Professional(string n, float h, float v, float ins, float salary) :
    Employee(n, h, v, ins) {
        monthlySalary = salary;
    };
    
    //calculates weekly pay
    //PRE: employee salary variable populated
    //POST: returns weekly pay
    float weeklySalary() {
        float weeklyPay = (monthlySalary * 12) / 52;
        return weeklyPay;
    };
    
    //calculates vacation hours earned in one week
    //PRE: hours worked varaible populated
    //POST: returns vacation hours earned
    float vacationHoursEarned() {   //0.25 vacation hours earned per hour worked
        float vacHours = hoursWorked * 0.25;
        return vacHours;
    };
    
    //calculates company contribution to employees health insurance
    //PRE: healthcare premium variable populated
    //POST: returns company healthcare contribution (in dollars)
    float healthcareContrib() {     //75% healthcare contribution from employer
        float contrib = (insurancePremium / 52) * 0.75;
        return contrib;
    };
};

#endif /* Professional_h */
