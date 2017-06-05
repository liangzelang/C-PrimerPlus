// using C++11 standard
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

long double sum_value(){return 0;}

template<class T>
long double sum_value(const T & value)
{
	return value;
}

template<class T, class... Args>
long double sum_value(const T & value, const Args & ... args)
{
	return value + sum_value(args);
}

int main()
{
	int n = 14;
	double x = 2.7;
	long y = 2000;
	char ch = 'a';
	cout << "Sum of : " << sum_value(n, x, y, ch) << endl;
	system("pause");
	return 0;
}