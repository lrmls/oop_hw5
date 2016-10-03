/*
	Automated tester for shop (hw5 object oriented prog.)
*/

#include "std_lib_facilities.h"
#include "parts.h"


int main(){

	component base(12354,"Best in the World");
	base.print();
	head testH(24683, "worst fo sho", "aquamarine");
	testH.print();
	arm testA(48632, "worst fo sho", 25.6);
	testA.print();
	torso testT(68352, "worst fo sho", 3);
	testT.print();
	battery testB(87953, "worst fo sho", 100.0);
	testB.print();
	motor testM(98765, "worst fo sho", 50.0, 20.0);
	testM.print();
	keep_window_open();
}