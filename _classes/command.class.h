#ifndef COMMAND_CLASS_H_INCLUDED
#define COMMAND_CLASS_H_INCLUDED

#include <string>
#include <cstring>
#include <vector>

using namespace std;



/**
* @brief Classe Command, reponsável por pegar, válidar, filtar e executar os comandos dados
* @author Fernando Iogr Dantas
*
* @since 06-05-2019
* */
class Command{
	
	private:
		vector<string> command;
		int numWords;
	public:
		
		/**
		*
		* @brief Construtor padrão
		* @param Recebe a tring cmd (comando)
		* */
		Command(string cmd);

		/**
		* 
		* @brief pega o comando
		* @return Retorna um vetor de string (onde cada string do vetor é uma palavra do comando)
		* */
		vector<string> getCommand();

		/**
		*
		* @brief quebra o comando em vetor de palavras para ser filtrado/executado/validado
		* @param cmd
		* @return Retorna um vetor de string (onde cada string do vetor é uma palavra do comando)
		* */
		vector<string> getWords(string cmd);
		
		/**
		*
		* @brief pega o número de palavras que o comando tem
		* @return 
		* */
		int getNumWords();

		/**
		*
		* @brief envia o comando para ser executado
		* @return
		* */
		void sendCommand();
		
		/**
		*
		* @brief valida o comando para depois ser enviado para ser executado
		* @return Retorna 1 caso o comando for valido, caso contráio, reotrna 0
		* */
		int validateCommand();
			
		/**
		*
		* @brief executa o comando após ser filtrado e validado respectivamente
		* @return  Retorna 1 caso o comando tenha sido executado com sucesso, caso contráio, reotrna 0
		* */
		int executeCommand();
		
		/**
		*
		* @brief ler um número (das funções de validações e execuções) e exibe o erro respectivo ao número na tela
		* @param um inteiro que representa o núero do erro
		* */
		void errorHandling(int error);
		
		/**
		*
		* @brief Exibe o manual do programa na tela
		* */
		void man(void);
		
		/**
		*
		* @brief Limpa o console
		* */
		void clear(void);

		~Command();
};
#endif