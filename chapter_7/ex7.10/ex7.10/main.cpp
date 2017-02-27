/*#include <iostream>

using namespace std;
double add(double x,double y)
{
	return x+y;
}


double calculate(double x,double y,double (*ptr)(double m,double n))
{
	double q = ptr(x,y);
	return q;
}

int main()
{
	double temp,temp1;
	double (*pf)(double,double) = add;
	cout << "Enter two double number :";
	cin >> temp >>temp1;
	temp = calculate(temp,temp1,pf);
	cout << "the result is  :  " << temp ;
	system("pause");
	return 0;

}*/

// 就是用了一个函数指针数组
#include <iostream>
using namespace std;

double plus(double, double);
double minus(double, double);
double multiple(double, double);
double calculate(double, double, double (*ptr)(double, double));
int main()
{
	double temp;
	char character[3] = {'+', '-', '*' };
	double (*pf[3])(double, double) = {plus, minus, multiple};
	for(int i = 0; i < 3; i++)
	{
		temp = calculate(3.8, 3.7, pf[i]);
		cout << "3.8 " << character[i] << " 3.7 = " << temp << ".\n";  
	}
	system("pause");
	return 0;
}

double plus(double a, double b)
{
	return a + b;
}
double minus(double a, double b)
{
	return a - b;
}
double multiple(double a, double b)
{
	return a * b;
}

double calculate(double a, double b, double (*ptr)(double, double))
{
	return ptr(a,b);
}