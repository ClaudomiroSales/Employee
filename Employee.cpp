
#include "Employee.h"

Employee::Employee( int numeroVendas, double ganhoPorVenda )
{
    this->numeroVendas =  (numeroVendas > 0  ? numeroVendas  : 0 );
	this->ganhoPorVenda = (ganhoPorVenda > 0 ? ganhoPorVenda : 0 );

}

Employee::~Employee()
{
}

ostream &operator<<(ostream &out, const Employee &employee)
{
    out << "Numero de vendas: " << employee.numeroVendas << '\n';
	out << "Ganho por venda: "  << employee.ganhoPorVenda<< '\n';
	out << "Comissao: "         << 	employee.numeroVendas * employee.ganhoPorVenda << '\n';

	return out;
}
