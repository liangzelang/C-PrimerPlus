// tempparm.cpp -- template as parameters
#include <iostream>
#include "stacktp.h"

using namespace std;

template <template<typename T> class Thing>
class Crab
{
private:
	Thing<int> s1;
	Thing<double> s2;
public:
	Crab() {};
	//assume the thing class has push() and pop() memebers
	bool push(int a, double x) {return s1.push(a)&&s2.push(x);}
	bool pop(int & a, double & x) {return s1.pop(a)&&s2.pop(x);}

};

int main()
{
	Crab<Stack> nebula;
	//Stack must match template <typenamte T>
	int ni;
	double nb;
	cout << "Enter int double pairs, such as 4 3.5 (0 0 to end) : \n";
	while(cin >> ni >> nb && ni > 0 && nb > 0)
	{
		if(!nebula.push(ni,nb))
			break;
	}
	while(nebula.pop(ni,nb))
		cout << ni << " , " << nb << endl;
	cout << "Done. \n";
	system("pause");
	return 0;
}