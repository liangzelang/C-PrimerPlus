#include <iostream>

double average(double & a, double & b)
{
	double Aver = 2.0 * a * b /(a + b);
	return Aver;    //这里将生成一个临时变量
}

int main()
{
	using namespace std;
	double first_one;
	double second_one;
	cout << "Enter two numbers ,the first one :";
	cin >> first_one;
	cout << "the second one: ";
	cin >> second_one;
	while(first_one&&second_one) {
		double temp_Aver = average(first_one,second_one);
		cout << "The average is : " << temp_Aver << ". \n ";

		cout << "Enter two numbers ,the first one :";
		cin >> first_one;
		cout << "the second one: ";
		cin >> second_one;
	}
}