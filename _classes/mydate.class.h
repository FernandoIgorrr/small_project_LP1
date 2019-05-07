#ifndef MYDATE_CLASS_H_INCLUDED
#define MYDATE_CLASS_H_INCLUDED

#include <iostream>

using namespace std;

class MyDate{

	private:
		static map<int, int> month_map;
		month_map["Jan"] = 1;
		month_map["Feb"] = 2;
		month_map["Mar"] = 3;
		month_map["Apr"] = 4;
		month_map["May"] = 5;
		month_map["Jun"] = 6;
		month_map["Jul"] = 7;
		month_map["Aug"] = 8;
		month_map["Sep"] = 9;
		month_map["Oct"] = 10;
		month_map["Nov"] = 11;
		month_map["Dec"] = 12;

};

#endif