//error4.cpp -- using exception classes
#include <iostream>
#include <cmath>   //or math.h unix users may need -lm flag
#include "exc_mean.h"

//function prototypes
using namespace std;
double hmean(double a, double b);
double gmean(double a, double b);
int main()
{
	double x, y, z;
	cout << "Enter two numbers: ";
	while(cin >> x >> y)
	{
		try{
			z = hmean(x, y);
			cout << "Harmonic mean : " << z << endl;
			cout << "Geometric mean : " << gmean(x, y) << endl;
			cout << "Enter next set of numbers <q to quit>: ";
		}
		catch(bad_hmean & bg)
		{
			bg.mesg();
			cout << "Try again.\n";
			continue;
		}
		catch(bad_gmean & hg)
		{
			cout << hg.mesg();
			cout << "Sorry , you don't get to play any more.\n";
			break;
		}
	}
	system("pause");
	return 0;
}


double hmean(double a, double b)
{
	if(a == -b)
		throw bad_hmean(a,b);
	return 2.0 * a * b /(a + b);
}

double gmean(double a, double b)
{
	if(a < 0 || b < 0)
		throw bad_gmean(a,b);
	return sqrt(a*b);
}