/*
	class for storing vectors of parts and robots
*/

#include "std_lib_facilities.h"
#include "parts.h"


#ifndef __STOCK_CLASS
#define __STOCK_CLASS

class stock{
public:

	//vector<robot> robots;
	vector<head> heads;
	vector<torso> torsos;
	vector<arm> arms;
	vector<battery> batteries;
	vector<motor> motors;

	/*
	Just wanna be ur friend
	friend void manager::make_part();
	*/
	};
#endif