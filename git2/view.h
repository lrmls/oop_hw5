/*
	view class
	displays all the menus and does data validation on input
*/

#include "std_lib_facilities.h"

#ifndef __VIEW
#define __VIEW

class view{
public:
	void startMen();
	void managerMen();
	void partMen();
	void assocMen();
	void customerMen();
	void bossMen();
	

	int valid_option(string, int);
	int valid_part_num(string);
	double valid_double(string);
};
#endif