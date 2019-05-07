/**
* @file main.cpp
* @version 1.0
* @date 06/05/2019
* @author Fernando Igor Dantas
* @title Small Program in C++
* @brief for college
* @code
* */

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