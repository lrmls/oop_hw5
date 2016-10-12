/*
	Definitions of different parts classes
*/

#include "std_lib_facilities.h"
#include "parts.h"


	//COMPONENT base for all parts
component::component(int num, string title, double pounds, double cost){
	part_num = num; 
	name = title; 
	weight = pounds;
	price = cost;
}
void component:: print(){
	cout << part_num << ", " << name << ", " << weight << ", " << price << endl;
} 
int component::get_part_num(){ return part_num; }
string component::get_name(){ return name; }
double component::get_weight(){ return weight; }
double component::get_price(){ return price; }
	//***************** HEAD *********************
head::head(int num, string title, double pounds, double price) 
	:component(num, title, pounds, price){
}
void head::print(){
	cout << "number: "<< part_num << ", name: " << name << ", weight: " << weight << "lbs, price: $" << price << endl;
}
	//***************** ARM ***************** 
arm::arm(int num, string title, double pounds, double price, double usage) 
	:component(num, title, pounds, price){
	energy_use = usage;
}
void arm::print(){
	cout << "number: " << part_num << ", name: " << name << ", weight: " << weight << "lbs, drain: " << energy_use << "watts, price: $" << price << endl;
}
double arm::get_usage(){ return energy_use; }	
	//***************** TORSO ***************** 
torso::torso(int num, string title, double pounds, double price, int amount) 
	: component(num, title, pounds, price){
	power_slots = amount;
}

void torso::print(){
	cout << "number: " << part_num << ", name: " << name << ", weight: " << weight << "lbs, battery slots: " << power_slots << ", price: $" << price << endl;
}
int torso::get_slots(){ return power_slots; }
	//***************** BATTERY ***************** 
battery::battery(int num, string title, double pounds, double price,  double power) 
	: component(num, title, pounds, price){
	supply = power;
}
void battery::print(){
	cout << "number: " << part_num << ", name: " << name << ", weight: " << weight << "lbs, power supply: " << supply << ", price: $" << price << endl;
}
double battery::get_power_supply(){ return supply; }
	//***************** MOTOR ***************** 
motor::motor(int num, string title, double pounds, double price, double usage, double spd)
	: component(num, title, pounds, price){
	energy_use = usage;
	max_spd = spd;
}

void motor::print(){
	cout << "number: " << part_num << ", name: " << name << ", weight: " << weight << "lbs, drain: " << energy_use << "watts, max speed: "<< max_spd << "mph, price: $" << price << endl;
}
double motor::get_usage(){ return energy_use; }
double motor::get_spd(){ return max_spd; }