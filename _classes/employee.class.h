#ifndef EMPLOYEE_CLASS_H_INCLUDED
#define EMPLOYEE_CLASS_H_INCLUDED

#include <stringi>
#include <ctime>

using namespace std;

class Employee{

	private:
		string id;
		string name;
		float  salary;

	public:
		/**
		 * Constructor
		 * */

		Employee(string newID,string newName,float newSalary);

		/**
		 *Funções Get
		 *
		 * */
		float getSalary(void);
		string getName(void);
		string getID(void);

		/**
		 *Funções Set
		 *
		 * */
		void setName(string newName);
		void setSalary(float newSalary);
		void setID(string newID);

		/**
		 * Destructor
		 * */
		~Employee();
};

#endif
