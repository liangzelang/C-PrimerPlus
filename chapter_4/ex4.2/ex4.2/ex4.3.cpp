#include <iostream>
#include <string>

int main()
{
	using namespace std;
	string name;
	string dessert;
	cout << "enter your name :  ";
	//attention
	getline(cin,name);
	cout << "enter your favorite dessert : ";
	//attention
	getline(cin,dessert);
	cout <<"I have some delicios "<<dessert << "for you " << name;
	system("pause");
	return 0;
}