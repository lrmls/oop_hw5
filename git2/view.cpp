/*
	methods for view menus and data validation
*/

#include "std_lib_facilities.h"
#include "view.h"


void view::startMen(){
	//initial menu display 
	cout << "User Level:\n";
	cout << "  (1) Product Manager" << endl << "  (2) Sales Associate\n"
		<< "  (3) Beloved Customer" << endl << "  (4) Wonderfully Haired Boss\n";
}

void view::managerMen(){
	//product manager's options 
	cout << "Select option:\n";
	cout << "  (1) Create Part" << setw(20) << right << " (2) Create Robot\n";
}

void view::partMen(){
	//menu display for part type
	cout << "Part Type:\n";
	cout << "  (1) head" << setw(20) << right << "(2) torso\n"
		<< "  (3) arm" << setw(21) << right << "(4) motor\n"
		<< "  (5) battery\n";
}
void view::robomen(){
	//base menu display for robot creation
	
}

int view::valid_part_num(string input){
	//vaidates string input returns valid 4 digit integer number
	if (input.length() != 4) { return -1; }
	for (int i = 0; i < input.length(); i++) { if (input[i]<'0' || input[i]>'9') return -1; }
	return stoi(input);
}

double view::valid_double(string input){
	//validates a double variable from string input, limit 1 decimal.
	int decimal = 0;
	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] == '.') { decimal++; continue; }
		if (input[i]<'0' || input[i]>'9') return -1;
	}
	if (decimal > 1) { return -1; }
	return stod(input);

}
int view::valid_option(string option, int max){
	//validates a single digit number from string iput between 1 and MAX(variable by call)
	if (option.length() > 1) { return -1; }
	if (option[0] < '1' || option[0] > '9') { return -1; }
	int num = stoi(option);
	if (num > max) { return -1; }
	return num;
}