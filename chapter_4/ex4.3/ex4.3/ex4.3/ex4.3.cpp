#include <iostream>
#include <cstring>

void display(char a[])
{
	std::cout << "here's the information in a single string : " << a <<std::endl;
}
int main()
{
	char first_name[20];
	char second_name[20];
	char total[30];
	using namespace std;
	cout << "enter your first name : ";
	(cin >> first_name).get();
	cout << "enter your second name: ";
	(cin >> second_name).get();
	strcpy(total,first_name);
	strcpy(&total[strlen(first_name)],", ");
	strcpy(&total[strlen(first_name)+2],second_name);
	display(total);
	system("pause");
	return 0;
}