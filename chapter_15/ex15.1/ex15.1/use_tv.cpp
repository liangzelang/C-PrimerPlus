// use_tv.cpp -- using the tv and remote classes

#include <iostream>
#include "tvfm.h"

using namespace std;

int main()
{
	Tv s42;
	Remote grey;
	grey.mode_show();
	cout << "Initial setings for s42:\n";
	s42.settings();
	s42.onoff();
	s42.chanup();
	cout << "Adjusted settings for 42: ";
	s42.settings();

	s42.set_rmode(grey);
	grey.set_chan(s42, 10);
	grey.volup(s42);
	grey.volup(s42);
	cout << "s42 settings after using remote: ";
	s42.settings();

	Tv s58(Tv::on);
	s58.set_mode();
	grey.set_chan(s58,28);
	cout << "s58 settings:\n";
	s58.settings();
	s58.set_rmode(grey);
	system("pause");
	return 0;
}