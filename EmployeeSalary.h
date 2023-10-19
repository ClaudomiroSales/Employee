#ifndef EMPLOYEESALARY_H
#define EMPLOYEESALARY_H

#include "Employee.h"

#include <iostream>
using std::ostream;

class EmployeeSalary : public Employee
{
    friend ostream &operator<<( ostream &, const EmployeeSalary &);
public:
    EmployeeSalary( int, double, double );

    ~EmployeeSalary();

    double calcSalarioTotal( ) const { return salary + Employee::calcCommission( ); }

private:

    double salary;

};

#endif