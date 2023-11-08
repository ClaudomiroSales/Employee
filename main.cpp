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
    map<string, double> variablesDouble_0;
    map<string, string> variablesString_0;
    map<string, double> variablesDouble_1;
    map<string, string> variablesString_1;

    if( !loadConfig( variablesString_0, variablesDouble_0, "config.txt" ) )
       {
           //Input of variables
           if( !askDayMonthYear( variablesDouble_0 ) ) 
                return 0;   
           cout << "Entre com o id:\n";
           cin >> variablesString_0["id"];
        }

    cout << "Nome = " << variablesString_0["nome"] << '\n';
    cout << "id = " << variablesString_0["id"] << '\n';
    cout << "Weapon = " << variablesString_0["weapon"] << '\n';

    cout << "dia = " << variablesDouble_0["dia"] << '\n';
    cout << "mes = " << variablesDouble_0["mes"] << '\n';
    cout << "ano = " << variablesDouble_0["ano"] << '\n';

    if( !saveConfigs( variablesString_0, variablesDouble_0, "config.txt" ) )
        return 0;    

    
    //Apenas para verificar o que foi salvo no arquivo
    if( !loadConfig( variablesString_1, variablesDouble_1, "config.txt" ) )
        return 0;

    cout << "Se passaram 20 anos.\n";
    cout << "Nome = " << variablesString_1["nome"] << '\n';
    cout << "id = " << variablesString_1["id"] << '\n';
    cout << "Weapon = " << variablesString_1["weapon"] << '\n';
    cout << "dia = " << variablesDouble_1["dia"] << '\n';
    cout << "mes = " << variablesDouble_1["mes"] << '\n';
    variablesDouble_1["ano"] += 20;
    cout << "ano = " << variablesDouble_1["ano"] << '\n';

    
    if( !saveConfigs( variablesString_1, variablesDouble_1, "config.txt" ) )
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