


#include "std_lib_facilities.h"
#include "customer.h"

customer::customer(stock* stock) : warehouse{ stock } {}

void customer::print(){
	cout << name;
}

void customer::set_name(string title){
	name = title;
}

void customer::shop(){
	string input;
	int choice;
	view view;
	if (warehouse->get_qty_robot() == 0){ cout << "No available robots models\n"; return; };
	do{
		cout << "Select a Robot:\n";
		for (int i = 0; i < warehouse->get_qty_robot(); i++)
		{
			robot x = warehouse->get_robot(i);
			cout << "(" << i + 1 << ") ";
			x.print();
		}
		fflush(stdin); cin >> input;
		choice = view.valid_option(input, warehouse->get_qty_robot());
	} while (choice == -1);
	robot rob = warehouse->get_robot(choice - 1);
	cout << "Head:\n";	rob.get_head().print();
	cout << "Arms:\n";	rob.get_arm().print();
	cout << "Body:\n";	rob.get_torso().print();
	cout << "Motor:\n";	rob.get_motor().print();
	cout << "Batteries:\n";
	for (battery b : rob.get_battery()) {b.print(); }
	do {
		cout << "purchase this robot?\n  (1) Yes          (2) No\n";
		cin >> input;
		choice = view.valid_option(input,2);
	} while (choice == -1);
	if (choice == 1){ cout << "Coming Soon! :)\n"; }//{ return rob; }		add robot to sales report object
	if (choice == 2){ cout << "Coming Soon! :)\n"; }
}