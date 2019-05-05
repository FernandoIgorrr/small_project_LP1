#ifndef COMPANY_CLASS_H_INCLUDED
#define COMPANY_CLASS_H_INCLUDED

#include <vector>
#include <string>
#include "employee.class.h"

using namespace std;

class Company{

	private:
		string name;
		string cnpj;
		vector<Employee*> employees;
	public:
		/**
		 * Constructor
		 */
		Company(string newName, string newCNPJ, vector<Employee*> newEmployees);
		/**
		 * Funções Get
		 * */
		string getName(void);
		string getCNPJ(void);
		vector<Employee*> getEmployees(void);

		/**
		 * Funções Set
		 * */
		void setName(string newName);	
		void setCNPJ(string newCNPJ);
		
		/**
		 * Funções Add
		 * */
		void addEmployee(Employee *e);

		/**
		 * Funções Deletes
		 * */
		void deleteEmployee(Employee *e);
		
		/**
		 * Destructor
		 * */
		~Company();
};

#endif
