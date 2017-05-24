//str1.cpp -- introducing the string class
#include <iostream>
#include <string>
// using string constructors

int main()
{
	using namespace std;
	string one("liangzelang");   //#1
	cout << one << endl;
	
	string two(20, '$');    //#2
	cout << two << endl;

	string three(one);  //#3
	cout << three << endl;

	string four = one + two;   // #4
	cout << four << endl;

	char alls[] = "All is well that ends well";
	string five(alls, 20);
	cout << five << endl;

	string six(alls+3, alls+9);
	cout << six << endl;

	string seven(&five[4], &five[9]);
	cout << seven << endl;

	string eight(four, 2, 4);
	cout << eight << endl;

	system("pause");
	return 0;
}  