#include <iostream>

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

}