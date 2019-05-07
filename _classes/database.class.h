#ifndef DATABASE_CLASS_H_INCLUDED
#define DATABASE_CLASS_H_INCLUDED

#include <vector>
#include "company.class.h"

using namespace std;

class Database{
	
	private:
		vector<Company*> companies;
	public:


		Database(vector<Company*> _companies);
		
		vector<Company*> getCompanies();

		int averageNumEmployee();

		void showCompanies();

		void scanCompanie(string name);

		int getNumCompanies();

		int validateExistence(string name);

		void addCompany(Company *c);


		~Database();
};
#endif