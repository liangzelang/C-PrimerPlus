//error4.cpp -- using exception classes

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
			cout << bg.what();
			cout << "Error message : " << bg.mesg() << endl;
			continue;
		}
		catch(bad_gmean & hg)
		{
			cout << hg.what();
			cout << "Error Message : " << hg.mesg() << endl;
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
		throw bad_hmean();
	return 2.0 * a * b /(a + b);
}

double gmean(double a, double b)
{
	if(a < 0 || b < 0)
		throw bad_gmean();
	return sqrt(a*b);
}