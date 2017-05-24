#ifndef EXC_MEAN_H_
#define EXC_MEAN_H_

#include <iostream>
#include <stdexcept>
#include <string>
#include <cmath> //or math.h unix users may need -lm flag

using namespace std;

class bad_hmean : public logic_error
{
private:

	string name;
public:
	double v1;
	double v2;
	explicit bad_hmean(double a = 0, double b = 0, const string & s = "Error in hmean()\n");
	string mesg();
	virtual ~bad_hmean() throw() {}
};

bad_hmean::bad_hmean(double a, double b, const string & s) :v1(a), v2(b), logic_error(s) 
{
	name = "hmean";
}

inline string bad_hmean::mesg()
{
	return "hmean() arguments a = -b should be div a+b =0 \n";
}




class bad_gmean : public bad_hmean
{
private:
	string name;
public:
	explicit bad_gmean(double a = 0, double b = 0, const string & s = "Error in gmean()\n");
	string mesg();
	virtual ~bad_gmean() throw() {}
};

bad_gmean::bad_gmean(double a, double b, const string & s) : bad_hmean(a,b,s) 
{
	name = "gmean";
}

inline string bad_gmean::mesg()
{
	return "gmean() arguments should be >= 0\n";
}
#endif