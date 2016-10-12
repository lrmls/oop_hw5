/*
controller object
*/
#include "std_lib_facilities.h"
#include "parts.h"
#include "manager.h"
#include "stock.h"
#include "customer.h"
#include "seller.h"
#include "boss.h"


#ifndef __SHOP
#define __SHOP
class shop{
private:
	vector <customer> customers;
	vector <seller> sellers;

public:
	void run();

	int get_customer();

};
#endif