/*
	Definition of class hierarchy for robot types
	base class			component
	derived classes		head, arm, torso, motor, battery
*/

#include "std_lib_facilities.h"


class component{
protected:
	int part_num;
	string name;
	double weight;
	double cost;
	string comment;

public:
	component(int, string);
	void print();		//for testing var init
};

class head : public component{
private:
	string eye_color;
public:
	head(int, string, string);
	void print();		//for testing var init
};

class torso : component{
private:
	int power_slots;
public:
	torso(int, string, int);
	void print();		//for testing var init
};

class arm : component{
private:
	double energy_use;
public:
	arm(int, string, double);
	void print();		//for testing var init
};

class motor : component{
private:
	double energy_use;
	double max_spd;
public:
	motor(int, string, double, double);
	void print();		//for testing var init
};

class battery: component{
private:
	double supply;
public:
	battery(int, string, double);
	void print();		//for testing var init
};