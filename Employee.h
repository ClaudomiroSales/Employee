#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
using std::ostream;

class Employee
{
    friend ostream &operator<<( ostream &, const Employee &);
public:
    Employee( int, double );

    ~Employee();

    double calcCommission( ) const { return numeroVendas * ganhoPorVenda; }

private:

    int numeroVendas;

	double ganhoPorVenda;

};

#endif