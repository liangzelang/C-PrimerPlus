#include "tebten.h"
#include <iostream>
using namespace std;

int main()
{
	TableTennisPlayer play1("Zhang", "JiKe", true);
	TableTennisPlayer play2("Ma", "long", false);
	play1.Name();
	if(play1.HasTable() == true)
		cout << " has a table .\n" << endl;
	else
		cout << "No table.\n " << endl;

	play2.Name();
	if(play2.HasTable() ==true)
		cout << " has a table . \n" << endl;
	else 
		cout << "hasn`t a table. \n" << endl;

	system("pause");
	return 0;
}