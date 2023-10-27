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
    //Maps
    map<string, double> variables_0;
    map<string, double> variables_1;

    if( !loadConfig( variables_0, "config.txt" ) )
       {
           //Input of variables
           if( !askDayMonthYear( variables_0 ) ) 
                return 0;   
           cout << "Entre com o id:\n";
           cin >> variables_0["id"];
        }

    if( !saveConfigs( variables_0, "config.txt" ) )
        return 0;

    cout << "id = " << variables_0["id"] << '\n';
    cout << "dia = " << variables_0["dia"] << '\n';
    cout << "mes = " << variables_0["mes"] << '\n';
    cout << "ano = " << variables_0["ano"] << '\n';

    //Apenas para verificar o que foi salvo no arquivo
    if( !loadConfig( variables_1, "config.txt" ) )
        return 0;

    cout << "Se passaram 20 anos.\n";
    cout << "id = " << variables_1["id"] << '\n';
    cout << "dia = " << variables_1["dia"] << '\n';
    cout << "mes = " << variables_1["mes"] << '\n';
    variables_1["ano"] += 20;
    cout << "ano = " << variables_1["ano"] << '\n';

    if( !saveConfigs( variables_1, "config.txt" ) )
        return 0;
    
    //Employee joao( variables["numeroVendas"], variables["ganhoPorVenda"] );
    //EmployeeSalary maria( variables["numeroVendas"], variables["ganhoPorVenda"], variables["salary"] );
    //cout << joao << '\n';
    //cout << maria << '\n';

    return 0;
}

bool askDayMonthYear( map< string, double > &variables )
{
    cout << "Para jogar, insira sua data de nascimento (dia mes ano): ";
    if (!(cin >> variables["dia"] >> variables["mes"] >> variables["ano"] )) {
        cerr << "Entrada invalida!" << '\n';
        return false; // Exit with an error code
    }

    return true;
}