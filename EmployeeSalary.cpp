#include "EmployeeSalary.h"

EmployeeSalary::EmployeeSalary( int numeroVendas, double ganhoPorVenda, double salary )
: Employee( numeroVendas, ganhoPorVenda )
{
    this->salary =  (salary > 0  ? salary  : 0 );
}

EmployeeSalary::~EmployeeSalary()
{
}

ostream &operator<<(ostream &out, const EmployeeSalary &employee)
{
    out << static_cast< Employee > ( employee );
	out << "Salario fixo: " << employee.salary << '\n';
	out << "Salario total " << employee.calcSalarioTotal( ) << '\n';
	
	return out;
}
