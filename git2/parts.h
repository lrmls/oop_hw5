/*
	Definition of class hierarchy for robot types
	base class			component
	derived classes		head, arm, torso, motor, battery
*/

#include "std_lib_facilities.h"


#ifndef __PARTS_CLASS
#define __PARTS_CLASS
class component{

public:
	int part_num;
	string name;
	double weight=0;
	double price=0;
	string comment;
	//friend robot::robot(head, torso, arm, motor, vector<battery>);   //just wanna be ur friend


	component(int, string, double, double);
	component(int, string, double, double, string); //for if initialized comment
	void print();		//for testing var init
};

class head : public component{
public:
	head();
	head(int, string, double, double);
	void print();		//for testing var init
};

class torso : public component{
private:
	int power_slots;
public:
	torso();
	torso(int, string, double, double, int);
	void print();		//for testing var init
};

class arm : public component{
private:
	
public:
	double energy_use;
	arm();
	arm(int, string, double, double, double);
	void print();		//for testing var init
};

class motor : public component{
private:
	
	double max_spd;
public:
	double energy_use;
	motor();
	motor(int, string, double, double, double, double);
	void print();		//for testing var init
};

class battery : public component{
private:
	
public:
	double supply;
	battery();
	battery(int, string, double, double, double);
	void print();		//for testing var init
};

#endif