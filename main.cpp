#include <iostream>
#include <string>
#include "_classes/employee.class.h"
#include "_classes/company.class.h"

using namespace std;

int main(){

	string name;
	float salary;
	vector<Employee*> employees;


	Company *c = new Company("nome fantasia","1232523434",employees);

	for(int i = 0;i < 3;i++){
		
		setbuf(stdin, NULL);
		cout << "Informe o nome do funcionário:\n";
		getline(cin,name);
		cout << "Informe o salário do dito cujo:\n";
		cin >> salary;
		
		Employee *e = new Employee(to_string(i+1),name,salary);

		c->addEmployee(e);	
	/**
	* cout << "ID: " << e->getID() << "\n";
	* cout << "Nome do funcionário: " <<  e->getName() << "\n";
	* cout << "Salário do dito cujo: " << e->getSalary() << "\n" << endl;
	* */
	}
	employees = c->getEmployees();

	for(int i = 0;i < employees.size();i++){
		cout << "ID: " << employees[i]->getID() << "\n";
		cout << "Nome:  " << employees[i]->getName() << "\n";
		cout << "Salário: " << employees[i]->getSalary() << "\n";
		cout << "-----------------------------------------\n";
	}

	cout << endl;
	return 0;
}
