#include <iostream>
using std::cout;
#include "stringUser.h"

void callme1(StringUser &);
void callme2(StringUser);

int main()
{
	using std::endl;
	{
		cout << "Starting an inner block . \n";
		StringUser headline1("Celery Stalks at Midnight ");
		StringUser headline2("Lettuce Prey");
		StringUser sports("Spinach Leaves Bowl for Dollars");
		cout << "headline1: " << headline1 << endl;
		cout << "headline2: " << headline2 << endl;
		cout << "sports: " << sports << endl;
		
		callme1(headline1);
		cout << "headline1:" << headline1 << endl;
		callme2(headline2);
		cout << "headline2: "<< headline2 << endl;
		cout << "Initialize one object to another : \n";
		StringUser sailor = sports;
		cout << "sailor: " << sailor << endl;
		cout << "Assign one object to another : \n";
		StringUser knot;
		knot = headline1;
		cout << "knot: " << knot << endl;
		cout << "Exiting the block . \n";
	}
	cout << "End of main(). \n";
	system("pause");
	return 0;
}

void callme1(StringUser & rsb)
{
	cout << "String passed by reference : \n";
	cout << "   \" "<< rsb << " \" \n";

}

void callme2(StringUser sb)
{
	cout << "String passed by value : \n";
	cout << " \" " << sb << " \" \n";
}