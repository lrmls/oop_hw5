/*
	methods for view menus and data validation
*/

#include "std_lib_facilities.h"
#include "view.h"

void view::createMen(){
	cout << "Part Type:\n";
	cout << "  (1) head" << setw(8) << right << "(2) torso\n"
		<< "  (3) arm" << setw(8) << right << "(4) motor\n"
		<< "  (5) battery\n";
}

int view::valid_part_num(string input){
	if (input.length() != 4) { return -1; }
	for (int i = 0; i < input.length(); i++) { if (input[i]<'0' || input[i]>'9') return -1; }
	return stoi(input);
}

double view::valid_double(string input){
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
	if (option.length() > 1) { return -1; }
	if (option[0] < '1' || option[0] > '9') { return -1; }
	int num = stoi(option);
	if (num > max) { return -1; }
	return num;
}