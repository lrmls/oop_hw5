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
	//HEAD
head::head(int num, string title, double pounds, double price) 
	:component(num, title, pounds, price){
}
void head::print(){
	cout << part_num << ", " << name << ", " << weight << ", " << price << endl;
}
	//ARM
arm::arm(int num, string title, double pounds, double price, double usage) 
	:component(num, title, pounds, price){
	energy_use = usage;
}
void arm::print(){
	cout << part_num << ", " << name << ", " << weight << ", " << price << ", " << energy_use << endl;
}
	//TORSO
torso::torso(int num, string title, double pounds, double price, int amount) 
	: component(num, title, pounds, price){
	power_slots = amount;
}
void torso::print(){
	cout << part_num << ", " << name << ", " << weight << ", " << price << ", " << power_slots << endl;
}
	//BATTERY
battery::battery(int num, string title, double pounds, double price,  double power) 
	: component(num, title, pounds, price){
	supply = power;
}
void battery::print(){
	cout << part_num << ", " << name << ", " << weight << ", " << price << ", " << supply << endl;
}
	//MOTOR
motor::motor(int num, string title, double pounds, double price, double usage, double spd) 
	: component(num, title, pounds, price){
	energy_use = usage;
	max_spd = spd;
}
void motor::print(){
	cout << part_num << ", " << name << ", " << weight << ", " << price << ", " << max_spd << ", " << energy_use << endl;
}