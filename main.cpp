#include "Employee.h"
#include "Employee.cpp"

#include "EmployeeSalary.h"
#include "EmployeeSalary.cpp"

#include <iostream>
using std::cout;

#include "util.h"

int main( )
{
    map<string, double> variables;
    if( !loadConfig( variables, "config.txt" ) )
        return 1;

    Employee joao( variables["numeroVendas"], variables["ganhoPorVenda"] );
    EmployeeSalary maria( variables["numeroVendas"], variables["ganhoPorVenda"], variables["salary"] );
    cout << joao << '\n';
    cout << maria << '\n';

    return 0;
}