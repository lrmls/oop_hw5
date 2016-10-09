/*
	implementation of robot class
*/

#include "std_lib_facilities.h"
#include "robot.h"

//constructor for robot: Full member initialization done here
robot::robot(head head, torso torso, arm arm, motor motor, vector<battery> battery) :
skull{ head }, body{ torso }, grabber{ arm }, mover{ motor }  {
	for (int i = 0; i < battery.size(); i++)
	{
		energy.push_back(battery[i]);
		power += battery[i].get_power_supply();
		weight += battery[i].get_weight();
		price += battery[i].get_price();
	}
	weight += skull.get_weight() + body.get_weight() + grabber.get_weight() + mover.get_weight();
	energy_use += grabber.get_usage() + mover.get_usage();
	price += skull.get_price() + body.get_price() + grabber.get_price() + mover.get_price();
}
void robot::print(){

	cout << "Model: " << model_num << ", Name: " << name << ", Weight: " << weight << "lbs\nPrice: $" << price << ", Power Supply: " << power << "kwh, Power Usage: " << energy_use << "watts" << endl;
}

double robot::get_price(){return price;}
