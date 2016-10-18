/*
	implementation of robot class
*/

#include "std_lib_facilities.h"
#include "robot.h"

//constructor for robot: Full member initialization done here
robot::robot(head head, torso torso, arm arm, motor motor, vector<battery> battery, string title, int model) :
skull{ head }, body{ torso }, grabber{ arm }, mover{ motor }, name{ title }, model_num{ model } {
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

	cout << "Model: " << model_num << ", Name: " << name << ", Weight: " << weight << "lbs\n    Price: $" << price << ", Power Supply: " << power << "kwh, Power Usage: " << energy_use << "watts" << endl;
}

void robot::print_parts(){
	cout << "Head:\n";	skull.print();
	cout << "Arms:\n";	grabber.print();
	cout << "Body:\n";	body.print();
	cout << "Motor:\n";	mover.print();
	cout << "Batteries:\n";
	for (battery b : energy) { b.print(); }
}
double robot::get_price(){return price;}
arm robot::get_arm(){ return grabber; }
head robot::get_head(){ return skull; }
torso robot::get_torso(){ return body; }
motor robot::get_motor(){ return mover; }
vector<battery> robot::get_battery(){ return energy; }
