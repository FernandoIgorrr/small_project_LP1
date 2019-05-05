#include "employee.class.h"

/**
 * Constructor
 * */

Employee::Employee(string id,string name,float salary){
	this->id	= id;
	this->name	= name;
	this->salary	= salary;
}

/**
 *Funções Get
 *
 *
 * */

float Employee::getSalary(void){
	return this->salary;
}

string Employee::getName(void){
	return this->name;
}

string Employee::getID(void){
	return this->id;
}

/**
 *Funçẽos Set
 *
 * */

void Employee::setSalary(float salary){
	this->salary = salary;
}

void Employee::setName(string name){
	this->name = name;
}
void Employee::setID(string id){
	this->id = id;
}

/**
 * Destructor
 * */
Employee::~Employee(){
	//Default destructor
}
