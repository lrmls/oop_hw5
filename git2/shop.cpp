
#include "std_lib_facilities.h"
#include "parts.h"
#include "manager.h"
#include "stock.h"
#include "view.h"
#include "robot.h"
#include "shop.h"

#include <iostream>
#include <fstream>
#include <stdexcept>


struct line{ 
	//storing file read data for auto initialize warehouse
	//fix and get rid of
		char flag;
		int x, y;
		double w, p, e, s;
		string n;
	};


void shop::run(){
	
	stock warehouse;
	view view;
	manager manager(&warehouse);
	
	// pre-initialize parts
	string data = "parts.txt";
	ifstream read{ data };
	if (!read){ cout << "failed to read data from" << data << endl; }
	line line;
	while (read >> line.flag){
		switch (line.flag){
		case 'h':{
			read >> line.x; read >> line.n; read >> line.w; read >> line.p;
			head head(line.x, line.n, line.w, line.p);
			warehouse.add_part_h(head);
			break; }
		case 't':{
			read >> line.x; read >> line.n; read >> line.w; read >> line.p; read >> line.y;
			torso torso(line.x, line.n, line.w, line.p, line.y);
			warehouse.add_part_t(torso);
			break; }
		case 'a':{
			read >> line.x; read >> line.n; read >> line.w; read >> line.p; read >> line.e;
			arm arm(line.x, line.n, line.w, line.p, line.e);
			warehouse.add_part_a(arm);
			break; }
		case 'b':{
			read >> line.x; read >> line.n; read >> line.w; read >> line.p; read >> line.e;
			battery battery(line.x, line.n, line.w, line.p, line.e);
			warehouse.add_part_b(battery);
			break; }
		case 'm':{
			read >> line.x; read >> line.n; read >> line.w; read >> line.p; read >> line.e; read >> line.s;
			motor motor(line.x, line.n, line.w, line.p, line.e, line.s);
			warehouse.add_part_m(motor);
			break; }
		}
	}
	read.close();
	
	//************menu navigation******************
	
	string input;
	int choice;
	while (true){
		do{
			view.startMen();
			fflush(stdin);  cin >> input;
			choice = view.valid_option(input, 5);
		} while (choice == -1);
		if (choice == 5){ return; };
		if (choice == 1)
		{			//manager menus
			do{
				view.managerMen();
				fflush(stdin);  cin >> input;
				choice = view.valid_option(input, 3);
			} while (choice == -1);
			if (choice == 1)
			{
				manager.make_part();
			}
			else if (choice == 2)
			{
				manager.make_robot();
			}
			else if (choice == 3)
			{
				warehouse.print_inventory();
			}
		}
		else if (choice == 3)
		{		//customer menus
			int cust_num;
			customer customer(&warehouse);
			do{
				do{		//determine customer
					view.customerMen();
					fflush(stdin);  cin >> input;
					choice = view.valid_option(input, 2);
				} while (choice == -1);
				if (choice == 1)
				{
					cout << "name: ";
					cin >> input; cout << '\n';
					customer.set_name(input);
					customers.push_back(customer);
					cust_num = 0;
				}
				else if (choice == 2)
				{
					cust_num = get_customer();
					if (cust_num != -1){ customer = customers[cust_num]; }
				}
			} while (cust_num == -1);

			do{		//customer option selection
				view.customer_options();
				fflush(stdin);  cin >> input;
				choice = view.valid_option(input, 3);
			} while (choice == -1);
			if (choice == 1)
			{
				customer.shop();
			}
			else if (choice == 2)
			{
				cout << "Coming Soon! :)\n";
			}
			else if (choice == 3)
			{
				cout << "Coming Soon! :)\n";
			}
		}
		else { cout << "Coming Soon! :)\n"; };
	}
}
int shop::get_customer(){
	if (customers.size() == 0){ cout << "there are no existing customers\n"; return -1; }
	else{
		view view;
		int i = 0;
		int choice;
		string input;
		do{
			cout << "name?\n";
			for (customer c : customers)
			{
				cout << "(" << i+1 << ") "; c.print(); cout << endl; i++;
			}
			cin >> input;
			choice = view.valid_option(input, customers.size());
		} while (choice == -1);
		return choice-1;
	}
}