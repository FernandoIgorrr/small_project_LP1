#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include "command.class.h"
#include "database.class.h"
#include "company.class.h"
#include "employee.class.h"

vector<Company*> companies;

Database *b = new Database(companies);

using namespace std;

Command::Command(string command){

	this->command  = this->getWords(command);
	this->numWords = this->getNumWords(); 
	this->sendCommand();

}

vector<string> Command::getCommand(){
	return this->command;
}

void Command::sendCommand(){
	
	if(this->validateCommand() == 1){
		this->errorHandling(this->executeCommand());	
	}
	else{
		this->errorHandling(this->validateCommand());
	}

}

int Command::getNumWords(){
	return this->command.size();
}

void Command::errorHandling(int error){
	if(error == 0){
		cout << "comando não encontrado \n" ;
	}
	else if(error == -1){
		cout << "Muitos comandos juntos! não aguentamos processar isso tudo :(\n" ;
	}
	else if(error == -2){
		cout << "Você não digitou nada ¯\\_(ツ)_/¯\n" ;
	}
	else if(error == -3){
		cout << "Esse nome de empresa já existe, OLHA O PROCESSO EM!!!\n" ;
	}
	else if(error == -4){
		cout << "já existe uma empresa com esse CNPJ!\n" ;	
	}
	else if(error == -5){
		cout << "Você não quis dizer \"show companies\"?!\n" ;	
	}
	else if(error == -6){
		cout << "Nenhuma empresa com este nome!\n" ;	
	}
	else if(error == -7){
		cout << "Já existe um funcionário com esse ID!\n" ;	
	}
	else if(error == -8){
		cout << "Você não quis dizer \"list exp <nome da empresa>\"?!\n" ;	
	}

}

int Command::validateCommand(){

	if(this->getNumWords() > 3){
		return -1;
	}
	else{
		if(this->getNumWords() == 0){
			return -2;
		}
		else if(this->getNumWords() == 1){
			if(this->getCommand()[0].compare("average") !=0 && this->getCommand()[0].compare("quit") !=0 && this->getCommand()[0].compare("man")  != 0 && this->getCommand()[0].compare("clear")  != 0 && this->getCommand()[0].compare("quit") != 0){
				return 0;
			}
			else{
				return 1;
			}
		}
		else if(this->getNumWords() == 2){
			if(this->getCommand()[0].compare("create")  != 0 && this->getCommand()[0].compare("show")  != 0 && this->getCommand()[0].compare("list")  != 0
		    && this->getCommand()[0].compare("scan")    != 0 && this->getCommand()[0].compare("hire")  != 0){
				return 0;
			}
			else{
				return 1;
			}
		}
		else if(this->getNumWords() == 3){
			if(this->getCommand()[0].compare("dismiss")  != 0 && this->getCommand()[0].compare("increase")  != 0 && this->getCommand()[0].compare("list")){
				return 0;
			}
			else{
				return 1;
			}
		}
		else{
			return 0;
		}
	}

}


int Command::executeCommand(){
	
	if(this->getNumWords() == 1){
		if(!this->command[0].compare("man")){
			this->man();
			return 1;
		}
		else if(!this->command[0].compare("clear")){
			this->clear();
			return 1;
		}
		else if(!this->command[0].compare("average")){

			cout << "\n Média de funcionário por empresa: ";
			cout << b->averageNumEmployee() << " Funcionário(s) por empresa\n";
			return 1;
		}
		else if(!this->command[0].compare("quit")){
			return 1;
		}
	}
	else if(this->getNumWords() == 2){

		if(!this->command[0].compare("create")){

			for(unsigned int i = 0;i < b->getCompanies().size();i++){
				if(b->validateExistence(this->command[1])){
					return -3;
				}
			}

			string cnpj;
			setbuf(stdin, NULL);			
			cout << "Digite o CNPJ da empresa: ";
			getline(cin,cnpj);


			for(unsigned int i = 0;i < b->getCompanies().size();i++){
				if(!cnpj.compare(b->getCompanies()[i]->getCNPJ())){
					return -4;
				}
			}
			vector<Employee*> employees;
			Company *c = new Company(this->command[1],cnpj,employees);
			b->addCompany(c);

			return 1;
		}
		else if(!this->command[0].compare("show")){
			if(!this->command[1].compare("companies")){
				
				b->showCompanies();
				return 1;
			
			}
			else{
				return -5;
			}
		}
		else if(!this->command[0].compare("scan")){
			if(b->validateExistence(this->command[1])){
				b->scanCompanie(this->command[1]);
				return 1;
			}
			return -6;
		}
		else if(!this->command[0].compare("hire")){
			for(unsigned int i = 0; i < b->getCompanies().size();i++){
				if(!this->command[1].compare(b->getCompanies()[i]->getName())){
					
					string id;

					setbuf(stdin, NULL);			
					cout << "Digite o ID do empregado ";
					getline(cin,id);

					for(unsigned int j = 0; j < b->getCompanies()[i]->getEmployees().size();j++){
						if(!id.compare(b->getCompanies()[i]->getEmployees()[j]->getID())){
							return -7;
						}
					}

					string name,admissionDate;
					float salary;

					setbuf(stdin, NULL);			
					cout << "Digite o nome do funcionário: ";
					getline(cin,name);
					cout << "Digite o salário do funcionário: ";
					cin >> salary;
					setbuf(stdin, NULL);
					cout << "Digite a data (formato (dd/mm/yyyy) com zeros):\n";
					getline(cin,admissionDate);

					Employee *e = new Employee(admissionDate,id,name,salary);
					b->getCompanies()[i]->addEmployee(e);

					return 1;

				}
			}
			return -6;
		}
		else if(!this->command[0].compare("list")){
			for(unsigned int i = 0; i < b->getCompanies().size();i++){
				if(!this->command[1].compare(b->getCompanies()[i]->getName())){
					b->getCompanies()[i]->showEmployees();
					return 1;
				}
			}
		}
		return 0;
	}
	else if(this->getNumWords() == 3){
		if(!this->command[0].compare("list")){
			if(!this->command[1].compare("exp")){
				for(unsigned int i = 0;i < b->getCompanies().size();i++){
					if(!this->command[2].compare(b->getCompanies()[i]->getName())){
						if(b->getCompanies()[i]->getEmployees().size() == 0){
							cout << "Não tem nenhum funcionário nessa empresa!\n";
						}

						time_t t;
						struct tm *infoTime;
						
						time(&t);
						infoTime = localtime(&t);

						char *currentDate,admissionDate[10];
						string str = to_string(infoTime->tm_mday);

						currentDate = (char*)malloc(sizeof(char)*10);

						if(infoTime->tm_mday < 10){
							currentDate[0] = '0';
							currentDate[1] = str[0];
						}
						else{
							currentDate[0] = str[0];
							currentDate[1] = str[0];;
						}
						currentDate[2] = '/';
						str = to_string(infoTime->tm_mon+1);

						if(infoTime->tm_mon < 10){
							currentDate[3] = '0';
							currentDate[4] = str[0];
						}
						else{
							currentDate[3] = str[0];
							currentDate[4] = str[0];
						}
						str = to_string(infoTime->tm_year + 1900);						
						currentDate[5] = '/';
						currentDate[6] = str[0];
						currentDate[7] = str[1];
						currentDate[8] = str[2];
						currentDate[9] = str[3];
						currentDate[10] ='\0';

						cout << "Funcionário(s) em período de experiência: \n";
						cout << "-------------------------------------------\n";
						for(unsigned int j = 0;j < b->getCompanies()[i]->getEmployees().size();	j++){
						
							strcpy(admissionDate,b->getCompanies()[i]->getEmployees()[j]->getAdmissionDate().c_str());
							if(b->getCompanies()[i]->getEmployees()[j]->getNumberDays(admissionDate,currentDate) <= 90){
								cout << "ID: " << b->getCompanies()[i]->getEmployees()[j]->getID() << " | ";
  								cout << "Nome: " << b->getCompanies()[i]->getEmployees()[j]->getName() << " | "; 
    							cout << "Salário: " << b->getCompanies()[i]->getEmployees()[j]->getSalary() << " | "; 
    							cout << "Data de admissão: " << b->getCompanies()[i]->getEmployees()[j]->getAdmissionDate() << "\n" << endl;
							}
						}
						return 1;
				}
				return -6;
			}
			return -8;	
		}
		return 0;		
		}
		if(!this->command[0].compare("increase")){
			if(b->validateExistence(this->command[1])){
				for(int i = 0;i < b->getNumCompanies();i++){
					if(!b->getCompanies()[i]->getName().compare(command[1])){

						string::size_type sz;
						float increase = stof(command[2],&sz);
						b->getCompanies()[i]->increaseSalary(increase);

						return 1;
					}
				}
			}
			return -6;
		}
		else if(!this->command[0].compare("dismiss")){
			if(b->validateExistence(this->command[1])){
				for(int i = 0;i < b->getNumCompanies();i++){
					if(!b->getCompanies()[i]->getName().compare(command[1])){
						for(int j = 0;j < b->getCompanies()[i]->getNumEmployees();j++){
							if(!b->getCompanies()[i]->getEmployees()[j]->getID().compare(this->command[2])){
								b->getCompanies()[i]->deleteEmployee(b->getCompanies()[i]->getEmployees()[j]);
								return 1;
							}
						return -9;
						}
					}
				}
			}
			return -6;
		}
	}
	return 0;

}

vector<string> Command::getWords(string command){

	vector<string> commandWords;
	string aux(command);
	if(command.size() == 0 || command[0] == ' '){
		return commandWords;
	}
	else{
		istringstream iss(command);
		string token;
		while(getline(iss, token, ' ')){
			commandWords.push_back(token);
		}
	}

	return commandWords;

}

void Command::man(void){

	clear();
	
	cout << "##########################################################################################################################\n";
	cout << "#						Este é um pqueno projeto em C++				 	       	 #\n";
	cout << "##########################################################################################################################\n";
	cout << "#							Manual							   	 #\n";
	cout << "##########################################################################################################################\n";
	cout << "##########################################################################################################################\n";
	cout << "#														 	 #\n";
	cout << "#	create <nome da empresa>					- Cria uma empresa com o nome dado		 #\n";
	cout << "#	show companies 							- Mostra todas as empresas existentes		 #\n";
	cout << "#	scan <nome da empresa> 						- Mostra os dados da empresa			 #\n";
	cout << "#	hire <nome da empresa>	        				- Contrata (adiciona) um novo funcionário	 #\n";
	cout << "#	list <nome da empresa>	        				- Lista os dados dos funcionários da empresa dada#\n";
	cout << "#	list exp <nome da empresa>	        			- Lista os dados dos funcionários da empresa dada#\n";
	cout << "#	increase <nome da empresa> <um valor x float>   		- Aumenta em x% todos os salários da empresa dada#\n";
	cout << "#	dismiss <nome da empresa> <id do empregado>			- Demite (deleta) o empregado da empresa dada 	 #\n";
	cout << "#	man								- Mostra o manual do sistema			 #\n";
	cout << "#	average								- Mostra a média de funcionários por empresa	 #\n";
	cout << "#	clear								- Limpa a tela do sistema			 #\n";
	cout << "#	quit								- Sair do sistema				 #\n";
	cout << "#															 #\n";
	cout << "##########################################################################################################################\n\n";

}

void Command::clear(void){
	system("clear");
}

Command::~Command(){

}