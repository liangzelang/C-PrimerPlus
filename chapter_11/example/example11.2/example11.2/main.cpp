#include <iostream>
#include "time.h"


int main()
{
	Time time1(1,3);
	Time time2(2,59);
	Time total;
	Time operator_total;
	Time _total;

	std::cout << "Time1 : \n";
	time1.Show();

	std::cout << "Time2 : \n";
	time2.Show();

	std::cout << "Sum : \n";
	total = time1.Sum(time2);
	total.Show();

	std::cout << "OP : \n";
	operator_total = time1 + time2;
	operator_total.Show();

	std::cout << "func : \n";
	_total = time1.operator+(time2);
	_total.Show();

	system("pause");
	return 0;
}