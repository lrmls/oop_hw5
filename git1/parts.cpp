/*
	Definitions of different parts classes
*/

#include "std_lib_facilities.h"
#include "parts.h"

	//COMPONENT
component::component(int num, string title){
	part_num = num; 
	name = title; 
}
void component:: print(){
	cout << part_num << ", " << name << endl;
} 
	//HEAD
head::head(int num, string title, string eyes) :component(num, title){
	eye_color = eyes;
}
void head::print(){
	cout << part_num << ", " << name << ", " << eye_color << endl;
}
	//ARM
arm::arm(int num, string title, double usage) :component(num, title){
	energy_use = usage;
}
void arm::print(){
	cout << part_num << ", " << name << ", " << energy_use << endl;
}
	//TORSO
torso::torso(int num, string title, int amount) : component(num, title){
	power_slots = amount;
}
void torso::print(){
	cout << part_num << ", " << name << ", " << power_slots << endl;
}
	//BATTERY
battery::battery(int num, string title, double power) : component(num, title){
	supply = power;
}
void battery::print(){
	cout << part_num << ", " << name << ", " << supply << endl;
}
	//MOTOR
motor::motor(int num, string title, double cost, double spd) : component(num, title){
	energy_use = cost;
	max_spd = spd;
}
void motor::print(){
	cout << part_num << ", " << name << ", " << energy_use << ", " << max_spd << endl;
}