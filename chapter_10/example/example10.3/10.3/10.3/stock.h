#ifndef STOCK_H_
#define STOCK_H_

#include <string>

class Stock
{
private:
	std::string company;
	long shares;
	double shares_val;
	double total_val;
	void set_tot() { total_val = shares * shares_val; }
public:
	Stock();   //default constructor
	Stock(const std::string &co , long n = 0, double pr = 0.0);
	~Stock();   //noisy constructor
	//void acquire(const std::string & co, long n, double pr);
	void buy(long num, double price);
	void sell(long num, double price);
	void update(double price);
	void show() const;
	const Stock & topval(const Stock &) const;
};

#endif