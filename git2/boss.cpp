

#include "boss.h"
#include "parts.h"
#include <iostream>
#include <fstream>

boss::boss(string title) :name{ title }{};

void boss::load(stock* warehouse, vector<order> orders, vector<seller> sellers, vector<customer> customers){
	//file format: 1) space delimited. 2) 1st char = flag indicating data type 3) string containing data in order per type
	//data types= parts::  h: head, a: arm, t:torso, b:battery, m:motor, r:robot
	//           people::  c: customer, s:seller, o:order
	char flag;
	int item_num, pow_slots, h_num, t_num, a_num, m_num, b_num, i;						//variables for part initialization
	double weight, price, pow_use, pow_sup, spd;
	vector<battery> power;
	string name;

	string data = "poop";
	ifstream read{ data };
	if (!read){ cout << "failed to read data from" << data << endl; }
	while (read >> flag){
		switch (flag){				//**************parts*****************
		case 'h':{							
			read >> item_num; read >> name; read >> weight; read >> price;
			head head(item_num, name, weight, price);
			warehouse->add_part_h(head);
			break; }
		case 't':{
			read >> item_num; read >> name; read >> weight; read >> price; read >> pow_slots;
			torso torso(item_num, name, weight, price, pow_slots);
			warehouse->add_part_t(torso);
			break; }
		case 'a':{
			read >> item_num; read >> name; read >> weight; read >> price; read >> pow_use;
			arm arm(item_num, name, weight, price, pow_use);
			warehouse->add_part_a(arm);
			break; }
		case 'b':{
			read >> item_num; read >> name; read >> weight; read >> price; read >> pow_sup;
			battery battery(item_num, name, weight, price, pow_sup);
			warehouse->add_part_b(battery);
			break; }
		case 'm':{
			read >> item_num; read >> name; read >> weight; read >> price; read >> pow_use; read >> spd;
			motor motor(item_num, name, weight, price, pow_use, spd);
			warehouse->add_part_m(motor);
			break; }
		case 'r':{					//**************robots*****************
			read >> item_num >> name >> price >> h_num >> t_num >> a_num >> m_num;
			//gets messy because i set up my get_part methods to operate by index chosen through menu, now im reading in by part num, must search each part
			
			head head;
			for (i = 0; i < warehouse->get_qty_h(); i++) { head = warehouse->get_head(i); if (head.get_part_num() == h_num){ break; }; }
			torso torso;
			for (i = 0; i < warehouse->get_qty_t(); i++) { torso = warehouse->get_torso(i); if (torso.get_part_num() == t_num){ break; }; }
			arm arm;
			for (i = 0; i < warehouse->get_qty_a(); i++) { arm = warehouse->get_arm(i); if (arm.get_part_num() == a_num){ break; }; }
			motor motor;
			for (i = 0; i < warehouse->get_qty_m(); i++) { motor = warehouse->get_motor(i); if (motor.get_part_num() == m_num){ break; }; }
			battery battery;
			for (i = 0; i < torso.get_slots(); i++){ 
				read >> b_num; 
				for (i = 0; i < warehouse->get_qty_b(); i++) { battery = warehouse->get_battery(i); if (battery.get_part_num() == b_num){ break; }; }
				power.push_back(battery);
			}
				robot rob(head, torso, arm, motor, power, name, item_num);
				warehouse->add_robot(rob);
			break; }
		case 'c':{					//**************people*****************

			break; }
		case 's':{

			break; }
		case 'o':{					//**************orders*****************

			break; }
		}
	}
	read.close();
}

void boss::save(stock* warehouse, vector<order> orders, vector<seller> sellers, vector<customer> customers){
	// **********ORDER IMPORTANT*********************
	// Must store parts before robots                Store all before orders
	
	string file = "shop_image.txt";
	ofstream store{ file };
	if (!store){ cout << "Failed to open " << file << "for writing\n"; return; }
	
	int i = 0;
	//*************************parts***************
	for (i = 0; i < warehouse->get_qty_h(); i++){
		head h =warehouse->get_head(i);
		store << "h " << h.get_part_num() << " " << h.get_name() << " " << h.get_weight() << " " << h.get_price() << "\n";
	}
	for (i = 0; i < warehouse->get_qty_t(); i++){
		torso t = warehouse->get_torso(i);
		store << "t " << t.get_part_num() << " " << t.get_name() << " " << t.get_weight() << " " << t.get_price() << " " << t.get_slots() << "\n";
	}
	for (i = 0; i < warehouse->get_qty_a(); i++){
		arm a = warehouse->get_arm(i);
		store << "a " << a.get_part_num() << " " << a.get_name() << " " << a.get_weight() << " " << a.get_price() << " " << a.get_usage() << "\n";
	}
	for (i = 0; i < warehouse->get_qty_m(); i++){
		motor m = warehouse->get_motor(i);
		store << "m " << m.get_part_num() << " " << m.get_name() << " " << m.get_weight() << " " << m.get_price() << " " << m.get_usage() << " " << m.get_spd() << "\n";
	}
	for (i = 0; i < warehouse->get_qty_b(); i++){
		battery b = warehouse->get_battery(i);
		store << "b " << b.get_part_num() << " " << b.get_name() << " " << b.get_weight() << " " << b.get_price() << " " << b.get_power_supply() << "\n";
	}
	//*************************robots***************
	for (i = 0; i < warehouse->get_qty_robot(); i++){
		robot r = warehouse->get_robot(i);
		store << "r " << r.get_model_num() << " " << r.get_name() << " " << r.get_price() << " " << r.get_head().get_part_num() << " " << r.get_torso().get_part_num() << " "
			<< r.get_arm().get_part_num() << " " << r.get_motor().get_part_num() << " ";
		for (battery b:r.get_battery()){  store << b.get_part_num() << " ";  }
		store << "\n";
	}
	//*************************people***************

	

	//*************************orders***************
	store.close();
}

bool boss::evaluate(vector<order> orders, vector<seller> associates){
	
	string input;
	int choice;
	view view;
	do{
		cout << "Select an associate to appraise:\n";
		int i = 0;
		for (seller s : associates){  cout << "(" << ++i << ") " << s.get_name() << endl;  }
		fflush(stdin);  cin >> input;
		choice = view.valid_option(input, associates.size());
	} while (choice == -1);
	cout << associates[choice - 1].get_name() << "'s sales:\n";
	for (order o : orders)
	{
		if (associates[choice - 1].get_name() == o.get_seller_name())
		{
			o.print_info();
		}
	}
	do{
		cout << "Give " << associates[choice - 1].get_name() << " a raise?\n  (1) No          (2) Yes\n";
		fflush(stdin);  cin >> input;
		choice = view.valid_option(input, 2);
	} while (choice == -1);
	return (bool)(choice-1);

}