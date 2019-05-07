#ifndef EMPLOYEE_CLASS_H_INCLUDED
#define EMPLOYEE_CLASS_H_INCLUDED

#include <string>
#include <cstring>
#include <ctime>

using namespace std;


/**
* @brief Classe Company, Classe responsável por representar uma representar uma funcionário com seus métodos e atributos
* @author Fernando Iogr Dantas
*
* @since 06-05-2019
* */

class Employee{

	private:		 
		string admissionDate;
		string id;
		string name;
		float salary;

	public:
		/**
		* @brief Construtor padrão
		* @param "data de admissão"
		* @param id
		* @param nome
		* @param salário
		* */
		Employee(string _admissionDate, string _ID,string _name,float _salary);

		/**
		*
		* @brief exibe na tela os dados do funcionário 
		* */
		void showEmployee(void);

		/**
		 *
		 * @brief Função que pega duas datas e retorna a diferença em dias delas  
		 * @param startDate que é a data inicial
		 * @param endDate que é a data final
		 * @return Retorna um inteiro com a difenrencia em dias das duas datas
		 * */
		int getNumberDays(const char *startDate, const char *endDate);
		
		/**
		 *
		 * @brief pega a data de admissão do funcionário
		 * @return
		 * */
		string getAdmissionDate(void);
		

		/**
		 *
		 * @brief pega o salário do funcionário
		 * @return
		 * */
		float getSalary(void);
		
		/**
		 *
		 * @brief pega o nome do funcionário
		 * @return
		 * */
		string getName(void);
		
		/**
		 *
		 * @brief pega o ID do funcionário
		 * @return
		 * */
		string getID(void);

		/**
		 *
		 * @brief altera a data de admissão do funcionário
		 * @param string admissionDate
		 * */
		void setAdmissionDate(string _admissionDate);
		
		/**
		 *
		 * @brief altera o nome do funcionário
		 * @param string nome
		 * */
		void setName(string _name);
		
		/**
		 *
		 * @brief alterao nome do funcionáro
		 * @param float salário
		 * */
		void setSalary(float _salary);
		
		/**
		 *
		 * @brief altera o id do funcionário
		 * @param String ID
		 * */
		void setID(string _ID);

		/**
		 *
		 * @brief Destrutor padrão
		 * */
		~Employee();
};

#endif
