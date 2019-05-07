#include <iostream>
#include <string>
#include <cstring>
#include "_classes/command.class.h"
#include "_classes/employee.class.h"
#include "_classes/company.class.h"

using namespace std;

int main(){

	string command = "man";	
	int i = command.compare("quit");

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
