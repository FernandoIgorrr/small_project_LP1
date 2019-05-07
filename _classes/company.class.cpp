#include "company.class.h"
#include "employee.class.h"

/**
 * Constructor
 * */

Company::Company(string name, string cnpj, vector<Employee*> employees){
	this->name	= name;
	this->cnpj	= cnpj;
	this->employees	= employees;
}

void Company::showEmployees(void){
	for(int i = 0; i < this->getNumEmployees();i++){
		this->getEmployees()[i]->showEmployee();
	}
}

/**
 * Funções Get
 * */

int Company::getNumEmployees(){
	return (int)this->getEmployees().size();
}

string Company::getName(void){
	return this->name;
}
string Company::getCNPJ(void){
	return this->cnpj;
}
vector<Employee*> Company::getEmployees(void){
	return this->employees;
}

/**
 * Funções Set
 * */

void Company::setName(string name){
	this->name = name;
}
void Company::setCNPJ(string cnpj){
	this->cnpj = cnpj;
}

/*
*
* */
void Company::increaseSalary(float increase){
	for(int i = 0;i < this->getNumEmployees();i++){
		this->getEmployees()[i]->setSalary((increase/100)*this->getEmployees()[i]->getSalary() + this->getEmployees()[i]->getSalary());
	}
}

/**
 * Funções Add
 * */

void Company::addEmployee(Employee *e){
	this->employees.push_back(e);
}

/**
 * Funções Deletes
 * */

void Company::deleteEmployee(Employee *e){

	for(unsigned int i = 0; i < this->employees.size();i++){
		if(e->getID() == this->employees[i]->getID()){
			this->employees.erase(this->employees.begin() + i);
		}
	}
}
