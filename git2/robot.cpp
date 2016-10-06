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
		power += battery[i].supply;
		weight += battery[i].weight;
		cost += battery[i].price;
	}
	weight += skull.weight + body.weight + grabber.weight + mover.weight;
	energy_use += grabber.energy_use + mover.energy_use;
	cost += skull.price + body.price + grabber.price + mover.price;
}
void robot::print(){

	cout << "Model: " << model_num << ", Name: " << name << ", Weight(lbs): " << weight << "\nPrice($): " << cost << ", Power Supply(kwh):" << power << ", Power Usage(watts): " << energy_use << endl;
}
