/*
	Automated tester for shop (hw5 object oriented prog.)
*/

#include "std_lib_facilities.h"
#include "parts.h"
#include "manager.h"
#include "stock.h"
#include "view.h"
#include "robot.h"

#include <iostream>
#include <fstream>
#include <stdexcept>

struct line{ //storing file read data for auto initialize warehouse
		char flag;
		int x, y;
		double w, p, e, s;
		string n;
	};
int main(){
	cout << "_______code for testing creation of each part type____________\n\n";
	
	head testH(2468, "worst fo sho", 25, 100);
	testH.print();
	arm testA(4863, "worst fo sho", 25, 100, 25.6);
	testA.print();
	torso testT(6832, "worst fo sho", 25, 100, 3);
	testT.print();
	battery testB(8753, "worst fo sho", 25, 100, 100.0);
	testB.print();
	motor testM(9875, "worst fo sho", 25, 100, 50.0, 20.0);
	testM.print();
	
	//initialize stock and manager ******make singletons*****
	
	stock warehouse;
	view view;
	manager manager(&warehouse);

	//*********initialize warehouse with parts from data read from formatted file************* 
	//file format: 1) space delimited. 2) 1st char = flag indicating part type 3) string containing data in order per type  
	string data = "parts.txt";
	ifstream read{ data };
	if (!read){ cout << "failed to read data from" << data << endl; }
	else{ cout << data << " opened\n"; }
	line line;
	while (read >> line.flag){
		switch (line.flag){
		case 'h':{
			read >> line.x; read >> line.n; read >> line.w; read >> line.p;
			head head(line.x, line.n, line.w, line.p);
			warehouse.heads.push_back(head);
			break;}
		case 't':{
			read >> line.x; read >> line.n; read >> line.w; read >> line.p; read >> line.y;
			torso torso(line.x, line.n, line.w, line.p, line.y);
			warehouse.torsos.push_back(torso);
			break; }
		case 'a':{
			read >> line.x; read >> line.n; read >> line.w; read >> line.p; read >> line.e;
			arm arm(line.x, line.n, line.w, line.p, line.e);
			warehouse.arms.push_back(arm);
			break; }
		case 'b':{
			read >> line.x; read >> line.n; read >> line.w; read >> line.p; read >> line.e; 
			battery battery(line.x, line.n, line.w, line.p, line.e);
			warehouse.batteries.push_back(battery);
			break; }
		case 'm':{
			read >> line.x; read >> line.n; read >> line.w; read >> line.p; read >> line.e; read >> line.s;
			motor motor(line.x, line.n, line.w, line.p, line.e, line.s);
			warehouse.motors.push_back(motor);
			break; }
		}
	}
	read.close();
	//end reuseable code; start code for visual tests
	cout << "\n_______Pre-initialized warehouse____________\n\n";
	cout << "heads:\n";
	for (head part: warehouse.heads){
		part.print();
	}
	cout << "arms:\n";
	for (arm part : warehouse.arms){
		part.print();
	}
	cout << "torsos:\n";
	for (torso part : warehouse.torsos){
		part.print();
	}
	cout << "motors:\n";
	for (motor part : warehouse.motors){
		part.print();
	}
	cout << "heads:\n";
	for (battery part : warehouse.batteries){
		part.print();
	}
	//*************end warehouse initiailization tester*********

	//menu navigation 
	//************transition into main loop*************
	cout << "\n_______testing creating parts through manager/view and storing in stock____________\n\n";
	string input;
	int choice;
	do{
		view.startMen();
		fflush(stdin);  cin >> input;
		choice = view.valid_option(input, 4);
	} while (choice == -1);

	if (choice == 1)
	{
		do{
			view.managerMen();
			fflush(stdin);  cin >> input;  
			choice = view.valid_option(input, 2);
		}while (choice == -1);

			if (choice == 1)
			{
				manager.make_part();
			}
			else if (choice == 2)
			{
				vector<battery> batts;
				batts.push_back(warehouse.batteries[0]); batts.push_back(warehouse.batteries[1]); batts.push_back(warehouse.batteries[2]);
				robot first(warehouse.heads[0], warehouse.torsos[0], warehouse.arms[0], warehouse.motors[0], batts);
				warehouse.robots.push_back(first);
				
				cout << "_______first robot initialization test_____\n\n";		//move out
				warehouse.robots[0].print();
				/*do{               //commented out to make 1 robot for test
				view.partMen();
				cin >> input;
				choice = view.valid_option(input,5);
			}while (choice == -1);
				switch (choice){
				case 1:

					break;
				case 2:

					break;
				case 3:

					break;
				}*/
			}
		
	}
	else { cout << "Coming Soon! :)\n"; };
	

	keep_window_open();
}