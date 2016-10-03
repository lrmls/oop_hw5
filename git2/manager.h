/*
	product manager class
	responsibilities:	create parts,			  store parts in stock
						create robots from parts, store robots in stock
*/

#include "std_lib_facilities.h"
#include "parts.h"
#include "stock.h"

#ifndef __MANAGER_CLASS
#define __MANAGER_CLASS
class manager{
private:
	stock *warehouse;
public:
	manager(stock*);
	void make_part();
	void make_robot();
};
#endif