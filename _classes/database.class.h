#ifndef DATABASE_CLASS_H_INCLUDED
#define DATABASE_CLASS_H_INCLUDED

#include <vector>
#include "company.class.h"

using namespace std;

/**
* @brief Classe Database onde ficam salvo os dados em tempo de execução visto que não foi ultilizado banco de dos nem manipulação de arquivos
* @author Fernando Iogr Dantas
*
* @since 06-05-2019
* */

class Database{
	
	private:
		vector<Company*> companies;
	public:

		/**
		*
		* @brief Construtor padrão
		* @param Recebe um vetor de objetos do tipo Company
		* */
		Database(vector<Company*> _companies);
		
		/**
		*
		* @brief pega um vetor com todas as empresas cadastradas
		* @return Retorna o vetor do tipo Company
		* */
		vector<Company*> getCompanies();

		/**
		*
		* @brief Calcula a médoa de funcionários por empresa (baseado no número total de funcionários e de empresas)
		* @return Retorna a média de funcionários
		* */
		int averageNumEmployee();

		/**
		*
		* @brief Exibe na tela uma lista com os nomes de todas as empresas cadastradas
		* */
		void showCompanies();

		/**
		*
		* @brief "Scanea" uma empresa dado o nome e exibe na tela todas as suas informçes
		* @param Recebe o nome da empresa cuja os dados serão mostrados 
		* */
		void scanCompanie(string name);

		/**
		*
		* @brief Retorna o número de empresas cadastradas 
		* @return  ?
		* */
		int getNumCompanies();

		/**
		*
		* @brief Valida se aquele nome de empresa ja existe
		* @param Recebe um nome que vai ser testado se ja está cadatrado como nome de empresa
		* @return Retorna 1 caso verdadeiro, caso contrário, retrna 0 
		* */
		int validateExistence(string name);

		/**
		*
		* @brief Adiciona/Cadastra uma nova empresa 
		* @param Recebe um objeto do tipo Company
		* */
		void addCompany(Company *c);


		~Database();
};
#endif