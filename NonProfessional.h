//
//  NonProfessional.h
//  CS303A2
//
//  Created by Brendan Clouston on 10/8/23.
//

#ifndef NonProfessional_h
#define NonProfessional_h
#include "Employee.h"

class NonProfessional : public Employee {
protected:
    float hourlyRate;
public:
    //constructor, uses base class constructor for derived variables
    NonProfessional() : Employee() {
        hourlyRate = 0;
    };
    
    //overloaded constructor, uses base class constructor for derived variables
    NonProfessional(string n, float h, float v, float ins, float hourly) :
    Employee(n, h, v, ins) {
        hourlyRate = hourly;
    };
    
    //calculates weekly salary
    //PRE: employee pay rate and hours worked variables populated
    //POST: returns weekly pay
    float weeklySalary() {
        float weeklyPay = hourlyRate * hoursWorked;
        return weeklyPay;
    };
    
    //calculates vacation hours earned in one week
    //PRE: hours worked varaible populated
    //POST: returns vacation hours earned
    float vacationHoursEarned() {   //0.15 vacation hours earned per hour worked
        float vacHours = hoursWorked * 0.15;
        return vacHours;
    };
    
    //calculates company contribution to employees health insurance
    //PRE: healthcare premium variable populated
    //POST: returns company healthcare contribution (in dollars)
    float healthcareContrib() {     //50% healthcare contribution from employer
        float contrib = (insurancePremium / 52) * 0.50;
        return contrib;
    }
};
#endif /* NonProfessional_h */
