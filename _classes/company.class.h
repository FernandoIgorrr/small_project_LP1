#ifndef COMPANY_CLASS_H_INCLUDED
#define COMPANY_CLASS_H_INCLUDED

#include <vector>
#include <string>
#include "employee.class.h"

using namespace std;


/**
* @brief Classe Company
* @author Fernando Iogr Dantas
*
* @since 06-05-2019
* */
class Company{

	private:
		string name;
		string cnpj;
		vector<Employee*> employees;
	public:

		/**
		 *
		 * @brief Construtor Padrão
		 * @param newName
		 * @param newCNPJ
		 * @param newEmployees
		 */
		Company(string newName, string newCNPJ, vector<Employee*> newEmployees);
		
		/**
		*
		* @brief Exibe todos os funcionário da empresa na tela
		* */
		void showEmployees(void);

		/**
		 *
		 * @brief Pega o número de funcionários
		 * @return
		 * */
		int getNumEmployees();
		
		/**
		 *
		 * @brief pega o nome da empresa
		 * @return
		 * */
		string getName(void);
		
		/**
		 *
		 * @brief pega o CNPJ da empresa
		 * @return
		 * */
		string getCNPJ(void);
		
		/**
		 *
		 * @brief pega um vetor com todos os funcionários da empresa
		 * @return
		 * */
		vector<Employee*> getEmployees(void);

		/**
		 * 
		 * @brief "Seta" altera o nome da empresa
		 * @param newName
		 * */
		void setName(string newName);	
		
		/**
		 * 
		 * @brief "Seta" altera o CNPJ da empresa
		 * @param newCNPJ
		 * */
		void setCNPJ(string newCNPJ);
		
		/**
		 * 
		 * @brief aumenta todos os salários dos funcionários em x%
		 * @param Recebe um valor float que vai ser a percentagem que os salários vão aumentar
		 * */
		void increaseSalary(float increase);

		/**
		 * 
		 * @brief Adiciona "Contrata" um funcionário dado o objeto Employee e
		 * @param Recebe um objeto instânciado da classe Employee 
		 * */
		void addEmployee(Employee *e);

		/**
		 * 
		 * @brief Deleta "Demite" um funcionário dado o objeto Employee e
		 * @param Recebe um objeto instânciado da classe Employee 
		 * */
		void deleteEmployee(Employee *e);
		
		/*
		* @brief Destrutor padrão
		* */
		~Company();
};

#endif
