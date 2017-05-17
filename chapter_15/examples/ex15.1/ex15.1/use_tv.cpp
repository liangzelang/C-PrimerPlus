// use_tv.cpp -- using the tv and remote classes

#include <iostream>
#include "tv.h"

using namespace std;

int main()
{
	TV s42;
	cout << "Initial settings for s42: \n";
	s42.settings();
	s42.onoff();
	s42.chanup();
	cout << "Adjusted setting for s42:\n";
	s42.chanup();
	cout << "Adjusted \n";
	s42.settings();

	Remote grey;

	grey.set_chan(s42, 10);
	grey.volup(s42);
	grey.voldown(s42);

	cout << "settings after using remote: \n";
	s42.settings();

	TV s58(TV::on);
	s58.set_mode();
	grey.set_chan(s58,28);
	cout << "s58 settings:\n";
	s58.settings();
	system("pause");
	return 0;
}