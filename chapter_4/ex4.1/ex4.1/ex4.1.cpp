#include <iostream>

struct student 
{
	char first_name[20];
	char last_name[20];
	char grade;
	int age;
};

void display(student a)
{
	std::cout << "Name : " << a.last_name <<", "<< a.first_name <<"\n";
	std::cout << "Grade :" << char(a.grade+1) << "\n";
	std::cout << "Age : " << a.age << "\n"; 
}
int main()
{
	using namespace std;
	student *lzl = new student;
	cout << "enter your first name : ";
	cin.getline(lzl->first_name,20);
	cout << "what is your last name :";
	cin.getline(lzl->last_name,20);
	cout << "waht is letter grade do you deserve ?";
	cin >> lzl->grade;
	cout << "what is your age ?";
	cin >> lzl->age;
	display(*lzl);
	system("pause");
	return 0;
}