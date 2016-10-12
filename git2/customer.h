
#include "std_lib_facilities.h"
#include "view.h"
#include "stock.h"


#ifndef __CUSTOMER
#define __CUSTOMER
class customer{
private:
	string name;
	stock* warehouse;
	
public:
	customer(stock*);
	void shop();
	void print();
	void set_name(string);
};
#endif