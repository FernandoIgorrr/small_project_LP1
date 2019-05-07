#include <iostream>
#include "database.class.h"
#include "company.class.h"

using namespace std;

Database::Database(vector<Company*> companies){
	this->companies = companies;
}
		
vector<Company*> Database::getCompanies(){
	return this->companies;
}

int Database::getNumCompanies(){
	return this->companies.size();
} 

void Database::showCompanies(){
	cout <<"\nLista de empresas: \n";
	cout << "------------------------------------------------\n";
	if(this->getNumCompanies() == 0){
		cout << "Não tem nenhuma empresa cadastrada!\n";
	}
	for(int i = 0; i < this->getNumCompanies();i++){
		cout << this->getCompanies()[i]->getName() << "\n";
	}
	cout << "------------------------------------------------\n";
}

void Database::scanCompanie(string name){

	for(int i = 0; i < this->getNumCompanies();i++){
		if(!name.compare(this->getCompanies()[i]->getName())) {
			cout << "----------------------------------------------\n"; 
			cout << "nome da empresa: " << this->getCompanies()[i]->getName() << "\n"; 
			cout << "CNPJ da empresa: " << this->getCompanies()[i]->getCNPJ() << "\n"; 
			cout << "Número de empregados: " << this->getCompanies()[i]->getNumEmployees() << "\n";
			cout << "----------------------------------------------\n"; 
		}
	}
}

int Database::averageNumEmployee(){
	
	int average; 
	int totalEmployee = 0;

	for(int i = 0;i < this->getNumCompanies();i++){
		totalEmployee =  totalEmployee + this->getCompanies()[i]->getNumEmployees();
	}
	average = (int)totalEmployee/(this->getNumCompanies());

	return average;
}

int Database::validateExistence(string name){
	for(int i = 0;i < this->getNumCompanies();i++){
		if(!name.compare(this->getCompanies()[i]->getName())){
			return 1;
		}
	}
	return 0;
}

void Database::addCompany(Company *c){
	this->companies.push_back(c);
}

Database::~Database(){

}
