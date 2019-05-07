#include <iostream>
#include "employee.class.h"

using namespace std;

/**
 * Constructor
 * */

Employee::Employee(string admissionDate,string id,string name,float salary){
	this->admissionDate = admissionDate;
	this->id 			= id;
	this->name 			= name;
	this->salary 		= salary;
}

void Employee::showEmployee(){

    cout << "ID: " << this->getID() << " | ";
    cout << "Nome: " << this->getName() << " | "; 
    cout << "Salário: " << this->getSalary() << " | "; 
    cout << "Data de admissão: " << this->getAdmissionDate() << "\n" << endl;

}

int Employee::getNumberDays(const char *startDate, const char *endDate){

    int month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int startDay;
    int startMonth;
    int startYear;
    int endDay;
    int endMonth;
    int endYear;
    int nDays = 0;
    
    startDay   = ((startDate[0] & 0xF) * 10) + (startDate[1] & 0xF);
    startMonth = ((startDate[3] & 0xF) * 10) + (startDate[4] & 0xF);
    startYear  = ((startDate[6] & 0xF) * 1000) + ((startDate[7] & 0xF) * 100) + ((startDate[8] & 0xF) * 10) + (startDate[9] & 0xF);

    endDay   = ((endDate[0] & 0xF) * 10) + (endDate[1] & 0xF);
    endMonth = ((endDate[3] & 0xF) * 10) + (endDate[4] & 0xF);
    endYear  = ((endDate[6] & 0xF) * 1000) + ((endDate[7] & 0xF) * 100) + ((endDate[8] & 0xF) * 10) + (endDate[9] & 0xF);

    if(startDay == endDay && startMonth == endMonth && startYear == endYear) return 0;

    if(!(startYear % 4)){
        if(startYear % 100){
			month[1] = 29; // ano bissesto
        }
        else if(!(startYear % 400)) month[1] = 29; // ano bissesto
    }

    for(;;)
    {
        int i;
        
        for(i = 1; i < 13; i++){
            if(startMonth == i){
                if(startDay == month[i - 1]){ // se é o ultimo dia do mês
                    startDay = 1;
                    if(startMonth != 12){
                        startMonth++;
                    }
                    else{ // se é o ultimo mês do ano
                        startMonth = 1;
                        startYear++;

                        if(!(startYear % 4)){
                            if(startYear % 100){
                            	month[1] = 29; // ano bissesto
                            }
                            else{
                                if(!(startYear % 400)){ 
                                	month[1] = 29;
                                }
                                else{
                                	month[1] = 28;
                            	}
                            }
                        }
                        else{
                        	month[1] = 28;
                    	}
                    }
                }
                else{
                    startDay++;
                }
                break;
            }
        }
        nDays++;
        if(startDay == endDay && startMonth == endMonth && startYear == endYear){
        	return nDays + 1;
        }
    }
}

/**
 *Funções Get
 *
 *
 * */
string Employee::getAdmissionDate(void){
	return this->admissionDate;
}

float Employee::getSalary(void){
	return this->salary;
}

string Employee::getName(void){
	return this->name;
}

string Employee::getID(void){
	return this->id;
}

/**
 *Funçẽos Set
 *
 * */

void Employee::setAdmissionDate(string admissionDate){
	this->admissionDate = admissionDate;
}

void Employee::setSalary(float salary){
	this->salary = salary;
}

void Employee::setName(string name){
	this->name = name;
}
void Employee::setID(string id){
	this->id = id;
}

/**
 * Destructor
 * */
Employee::~Employee(){
	//Default destructor
}
