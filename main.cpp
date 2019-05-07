#include <iostream>
#include <string>
#include <cstring>
#include "_classes/command.class.h"
#include "_classes/employee.class.h"
#include "_classes/company.class.h"

using namespace std;


/**
* @brief Função main
* @author Fernando Iogr Dantas
*
* @since 06-05-2019
* */

int main(){

	string command = "man";	
	int i = command.compare("quit");

	/**
	*@brief loop que mantém o prorama funcionando até digitar quit ou ele crashar
	* */
	while(i){
	
        setbuf(stdin, NULL);
		cout << "->";	
		getline(cin,command);
		Command *c = new Command(command);
		c->getCommand();
		i   = command.compare("quit");
		
	}
	return 0;
}
