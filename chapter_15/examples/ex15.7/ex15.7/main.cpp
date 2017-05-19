/*
//error1.cpp -- using the abort() to handle exception
#include <iostream>
#include <cstdlib>  // abort() 函数头文件

using namespace std;
double hmean(double a, double b);
int main()
{
	double x, y, z;
	while(cin >> x >> y)
	{
		z = hmean(x, y);
		cout << "The harmonic mean of " << x << " and " << y  << " is " << z << endl;
		cout << "Please enter next set of numbers : <q to quit>: " << endl;
	}
	cout << "Done.\n";
	system("pause");
	return 0;
}

double hmean(double a, double b)
{
	if(a == -b)
	{
		cout << "untenable arguments to hmean().\n";
		abort();
	}
	return 2.0 * a * b / ( a + b );
}
*/

/*
//error2.cpp -- returning an error code
#include <iostream>
#include <cfloat>

bool hmean(double a, double b, double * ans);

using namespace std;

int main()
{
	double x, y, z;
	cout << "Please enter one set of number : ";
	while(cin >> x >> y)
	{
		if(hmean(x, y, &z))
		{
			cout << "Harmonic mean of "<< x << " and " << y << " is " << z << endl;
		}
		else
		{
			cout << "One value should not be the negative of the other - try again.\n";
		}
		cout << "Please enter next set of numbers <q to quit >: ";
	}
	system("pause");
	return 0;
}

bool hmean(double a, double b, double * ans)
{
	if(a == -b)
	{
		*ans == DBL_MAX;
		return false;
	}
	else
	{
		*ans = 2.0 * a * b /(a + b);
		return true;
	}
}
*/

// error3.cpp  -- using an exception
#include <iostream>
#include <string>
double hmean(double a, double b);

using namespace std;

int main()
{
	double x, y, z;
	cout << "Enter one set of numbers : ";
	while(cin >> x >> y)
	{
		try{
			z = hmean(x, y);
		}
		catch(const char * s)
		{
			cout << s << endl;
			cout << "Enter next set of numbers : ";
			continue;
		}
		cout << "Harmonic mean of " << x << " and " << y << " is " << z << endl;
		cout << "Enter next set of numbers : ";
	}
	system("pause");
	return 0;
}

double hmean(double a, double b)
{
	if(a == -b)
		throw "bad hmean() arguments";
	return 2.0 * a * b /(a + b);
}