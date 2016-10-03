/*
	Definition of class hierarchy for robot types
	base class			component
	derived classes		head, arm, torso, motor, battery
*/

#include "std_lib_facilities.h"

#ifndef __PARTS_CLASS
#define __PARTS_CLASS
class component{
protected:
	int part_num;
	string name;
	double weight;
	double price;
	string comment;

public:
	component(int, string, double, double);
	component(int, string, double, double, string);
	void print();		//for testing var init
};

class head : public component{
public:
	head(int, string, double, double);
	void print();		//for testing var init
};

class torso : component{
private:
	int power_slots;
public:
	torso(int, string, double, double, int);
	void print();		//for testing var init
};

class arm : component{
private:
	double energy_use;
public:
	arm(int, string, double, double, double);
	void print();		//for testing var init
};

class motor : component{
private:
	double energy_use;
	double max_spd;
public:
	motor(int, string, double, double, double, double);
	void print();		//for testing var init
};

class battery: component{
private:
	double supply;
public:
	battery(int, string, double, double, double);
	void print();		//for testing var init
};

#endif