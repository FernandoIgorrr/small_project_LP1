#ifndef EMPLOYEE_CLASS_H_INCLUDED
#define EMPLOYEE_CLASS_H_INCLUDED

#include <string>
#include <cstring>
#include <ctime>

using namespace std;

class Employee{

	private:
		 
		string admissionDate;
		string id;
		string name;
		float salary;

	public:
		/**
		 * @brief Constructor
		 * */

		Employee(string _admissionDate, string _ID,string _name,float _salary);

		/**
		*
		* */
		void showEmployee(void);

		/**
		 *Funções Get
		 *
		 * */
		int getNumberDays(const char *startDate, const char *endDate);
		string getAdmissionDate(void);
		float getSalary(void);
		string getName(void);
		string getID(void);

		/**
		 *Funções Set
		 *
		 * */
		void setAdmissionDate(string _admissionDate);
		void setName(string _name);
		void setSalary(float _salary);
		void setID(string _ID);

		/**
		 * Destructor
		 * */
		~Employee();
};

#endif
