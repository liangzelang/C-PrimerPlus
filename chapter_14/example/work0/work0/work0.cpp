#include "work0.h"
#include <iostream>

using namespace std;

//Worker Methods
Worker::~Worker() {}

void Worker::Set()
{
	cout << "Enter worker's name: ";
	getline(cin, fullname);
	cout << "Enter worker's ID: ";
	cin >> id;
	while(cin.get() != '\n')
		continue;
}

void Worker::Show() const
{
 
}