/*
	defines robot class
*/

#include "std_lib_facilities.h"
#include "parts.h"


#ifndef __ROBOT
#define __ROBOT
class robot{
private:
	int model_num = 99999;
	String name = "Temporary";
	double weight=0;
	double cost=0;
	double power=0;
	double energy_use=0;

	head skull;
	torso body;
	arm grabber;
	motor mover;
	vector<battery> energy;

public:
	robot(head, torso, arm, motor, vector<battery>);
	void print();
};
#endif