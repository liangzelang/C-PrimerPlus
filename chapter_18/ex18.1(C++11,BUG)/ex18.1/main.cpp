// main.cpp -- using initializer_list ,C++ standard ,VS2010 isn't support

#include <iostream>
#include <initializer_list>

using namespace std;


template<typename T>
T average_list(initializer_list<T> il);

int main()
{
	auto q = average_list({15.4, 10.7, 9.0});
	cout << q << endl;

	cout << average_list({20, 30, 19, 17, 45, 38}) << endl;

	auto ad = average_list<double>({'A', 70, 65.33});
	cout << ad << endl;
	system("pause");
	return 0;
}

template<typename T>
T average_list(initializer_list<T> il)
{
	T  sum = 0;
	int i = 0;
	for(auto p = il.begin(); p != il.end(); P++,i++)
	{
		sum +=*p;
	}
	return sum/i;
}