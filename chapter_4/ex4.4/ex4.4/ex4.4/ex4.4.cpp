#include <iostream>
#include <string>

void display(std::string a)
{
	std::cout << "Here's the information in a single string : " << a << std::endl;
}


int main()
{
	using namespace std;
	string first_name,second_name;
	cout << "ener your first name : ";
	getline(cin,first_name);
	cout << "enter your second name :";
	getline(cin,second_name);
	string total = first_name + ", " + second_name;
	display(total);
	system("pause");
	return 0;
}