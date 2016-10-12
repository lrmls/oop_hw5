/*
	defines robot class
*/

#include "std_lib_facilities.h"
#include "parts.h"


#ifndef __ROBOT
#define __ROBOT
class robot{
private:
	int model_num;
	String name;
	double weight=0;
	double price=0;
	double power=0;
	double energy_use=0;

	head skull;
	torso body;
	arm grabber;
	motor mover;
	vector<battery> energy;

public:
	robot(head, torso, arm, motor, vector<battery>, string, int);
	void print();
	double get_price();
	arm get_arm();
	head get_head();
	torso get_torso();
	motor get_motor();
	vector<battery> get_battery();
};
#endif