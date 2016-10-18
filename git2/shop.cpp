
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
	//pre-initialize 1 associate
	seller bob("Robert");
	sellers.push_back(bob);
	seller jane("Diane");
	sellers.push_back(jane);
	//initialize a couple robots and customers for testing
	customer joe(&warehouse);
	joe.set_name("Joey");
	customers.push_back(joe);
	joe.set_name("Tabitha");
	customers.push_back(joe);
	battery one(132, "test", 2.2, 5.5, 32.2);
	vector<battery> power;
	power.push_back(one);
	robot Payton(warehouse.get_head(2), warehouse.get_torso(2), warehouse.get_arm(2), warehouse.get_motor(1), power, "Unit X32H", 95137);
	warehouse.add_robot(Payton);
	robot Jone(warehouse.get_head(0), warehouse.get_torso(1), warehouse.get_arm(2), warehouse.get_motor(1), power, "Unit P23I", 37159);
	warehouse.add_robot(Jone);

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
			int seller_index;
			customer customer(&warehouse);

			//determine customer
			do{				
				do{		
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
			//customer option selection
			do{		
				view.customer_options();
				fflush(stdin);  cin >> input;
				choice = view.valid_option(input, 3);
			} while (choice == -1);
			if (choice == 1)
			{	//purchase
				if (warehouse.get_qty_robot() == 0 ){ cout << "No available robots models\n"; }
				else if(sellers.size() == 0) { cout << "No avalaible associates to help\n"; }
				else{ 
					vector<robot> purchases = customer.shop(sellers, &seller_index);	//
					if (purchases.size() == 0){ continue; }
					seller associate = get_seller(seller_index);
					order order(customer, associate, purchases);
					orders.push_back(order);
				}
			}	//order history
			else if (choice == 2)
			{
				customer.order_nav(orders);
				
			}	//bill
			else if (choice == 3)
			{
				customer.show_bill(orders);
			}
		}	
			//end scope of individual customer object
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

seller shop::get_seller(int index){
	return sellers[index];
}