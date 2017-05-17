//tv.cpp  -- methods for the tv class (Remote methods are incline)

#include <iostream>
#include "tv.h"
using namespace std;

bool TV::volup()
{
	if(volume < MaxVal)
	{
		volume ++;
		return true;
	}
	else
	{
		return false;
	}
}

bool TV::voldown()
{
	if(volume > MinVal)
	{
		volume--;
		return true;
	}
	else
	{
		return false;
	}
}

void TV::chanup()
{
	if(channel < maxchannel)
		channel++;
	else
		channel = 1;
}

void TV::chandown()
{
	if(channel > 1)
		channel --;
	else
		channel = maxchannel;
}

void TV::settings() const
{
	
	cout << "TV is " << (state == off ? "off" : "on")  << endl;
	if(state == on)
	{
		cout << "Volume setting = " << volume  << endl;
		cout << "Channel setting = " << channel << endl;
		cout << "Mode = " << (mode == Antenna ? "antenna" : "cable") << endl;
		cout << "Input = " << (input == tv ? "TV" : "DVD") << endl;
	}
}