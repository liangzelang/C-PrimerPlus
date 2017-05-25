//smrtptrs.cpp  -- using three kinds of smart pointers
// requires support of C++11 shared_ptr and unique_ptr

#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Report
{
private:
	string str;
public:
	Report(const string s) : str(s) { cout << "Object created.\n";}
	~Report() {cout << "Object deleted.\n";}
	void comment() const { cout << str << endl;}
};

int main()
{
	/*
	{
		auto_ptr<Report> ps(new Report("using auto_ptr"));
		ps->comment();
	}
	{
		shared_ptr<Report> ps(new Report("using shared_ptr"));
		ps->comment();
	}
	{
		unique_ptr<Report> ps(new Report("using unique_ptr"));
		ps->comment();
	}
	*/
	unique_ptr<string> ps(new string("liangzelang"));
	unique_ptr<string> pd;
	pd = ps;
	cout << *pd << endl;
	cout << *ps << endl;
	system("pause");
	return 0;
}