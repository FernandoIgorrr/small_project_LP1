#ifndef COMMAND_CLASS_H_INCLUDED
#define COMMAND_CLASS_H_INCLUDED

#include <string>
#include <cstring>
#include <vector>

using namespace std;

class Command{
	
	private:
		vector<string> command;
		int numWords;
	public:
		
		/**
		* Constructor
		* */

		Command(string cmd);

		/**
		* Funçẽos Get
		* */

		vector<string> getCommand();
		vector<string> getWords(string cmd);
		int getNumWords();

		void sendCommand();
		
		int validateCommand();
		int executeCommand();
		void errorHandling(int error);
		void man(void);
		void clear(void);

		/**
		* Destructor
		* */

		~Command();
};
#endif