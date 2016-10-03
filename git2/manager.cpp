/*
	implementaion of manager class
*/

#include "std_lib_facilities.h"
#include "manager.h"
#include "parts.h"
#include "view.h"

manager::manager(stock *repo){
	warehouse = repo;
}

void manager::make_part(){
	//make a part and store it into warehouse 
	view view;
	int part_num;
	string name;
	double weight, price;
	string input;
	int option;
	//gather part information shared by all parts
	do{
		cout << "4 digit Part number: ";
		fflush(stdin);  cin.clear();  cin >> input;
		part_num = view.valid_part_num(input);
	}while(part_num == -1);
	cout << "Part name: ";
	fflush(stdin);  cin.ignore();  getline(cin,name);
	do{
		cout << "weight: ";
		fflush(stdin);  cin.ignore();  cin >> input;
		weight = view.valid_double(input);
	} while (weight == -1);
	do{
		cout << "price: ";
		fflush(stdin);  cin.ignore();  cin >> input;
		price = view.valid_double(input);
	} while (price == -1);
	//determine part type to gather part-unique data
	do{
		view.createMen();
		fflush(stdin);  cin.ignore(); cin >> input;  //have to input twice to continue BUG*****
		option = view.valid_option(input, 5);
	}while (option == -1);
	//options 1 head, 2 torso, 3 arm, 4 motor, 5 battery
	switch (option){
	case 1:
	{	head head(part_num, name, weight, price);
		warehouse->heads.push_back(head);
		 }break;
	case 2:
	{	int bat_num;
		do{
			cout << "Number of battery slots(max 4): ";
			fflush(stdin);  cin.ignore();  cin >> input;
			bat_num = view.valid_option(input, 4);
		} while (bat_num == -1);
		torso torso(part_num, name, weight, price, bat_num);
		warehouse->torsos.push_back(torso);
		}break; 
	case 3:
	{	double usage;
		do{
			cout << "Energy Usage(watts): ";
			fflush(stdin);  cin.ignore();  cin >> input;
			usage = view.valid_double(input);
		} while (usage == -1);
		arm arm(part_num, name, weight, price, usage);
		warehouse->arms.push_back(arm);
		 }break;
	case 4:
	{	double usage;
		double spd;
		do{
			cout << "Energy Usage(watts): ";
			fflush(stdin);  cin.ignore();  cin >> input;
			usage = view.valid_double(input);
		} while (usage == -1);
		do{
			cout << "Max speed(mph): ";
			fflush(stdin);  cin.ignore();  cin >> input;
			spd = view.valid_double(input);
		} while (spd == -1);
		motor motor(part_num, name, weight, price, usage, spd);
		warehouse->motors.push_back(motor);
		break; }
	case 5:
	{	double supply;
		do{
			cout << "Energy supply(kwh): ";
			fflush(stdin);  cin.ignore();  cin >> input;
			supply = view.valid_double(input);
		} while (supply == -1);
		battery battery(part_num, name, weight, price, supply);
		warehouse->batteries.push_back(battery);
		break; }
	}
}
