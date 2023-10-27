#include "Employee.h"
#include "Employee.cpp"

#include "EmployeeSalary.h"
#include "EmployeeSalary.cpp"

#include <iostream>
using std::cout;

#include "util.h"

bool askDayMonthYear( map< string, double > & );
int main( )
{
    // createInfos( "config.txt" );
    map<string, double> variables;
  /*if( !loadConfig( variables, "config.txt" ) )
        return 1; */

    if( !askDayMonthYear( variables ) ) 
            return 0;

    variables["id"] = 12123;
    cout << "id = " << variables["id"] << '\n';
    cout << "dia = " << variables["dia"] << '\n';
    cout << "mes = " << variables["mes"] << '\n';
    cout << "ano = " << variables["ano"] << '\n';
    
    //Employee joao( variables["numeroVendas"], variables["ganhoPorVenda"] );
    //EmployeeSalary maria( variables["numeroVendas"], variables["ganhoPorVenda"], variables["salary"] );
    //cout << joao << '\n';
    //cout << maria << '\n';

    return 0;
}

bool askDayMonthYear( map< string, double > &variables )
{
    cout << "Para jogar, insira sua data de nascimento (dia mês ano): ";
    if (!(cin >> variables["dia"] >> variables["mes"] >> variables["ano"] )) {
        cerr << "Entrada inválida!" << '\n';
        return false; // Exit with an error code
    }

    return true;
}