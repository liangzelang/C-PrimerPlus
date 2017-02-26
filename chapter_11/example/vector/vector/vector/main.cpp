#include <iostream>
#include "vector.h"

int main()
{
	Vector temp;
	Vector temp1(1,1);
	Vector temp2(23,67.5,Vector::Pol);

	Vector temp3 = temp + temp2;
	std::cout << temp3;

	system("pause");
	return 0;
}