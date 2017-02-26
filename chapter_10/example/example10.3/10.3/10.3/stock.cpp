#include <iostream>
#include "stock.h"


Stock::Stock()
{
	std::cout << " Default constructor called \n";
	company = "no name";
	shares = 0;
	shares_val = 0.0;
	total_val = 0.0;
}
Stock::Stock(const std::string &co , long n, double pr)
{
	std::cout << " Constructor using \n";
	company = co;
	if(n < 0) {
		std::cout << "Number of shares cann`t be negative ;" << company << " shares set to 0 \n";
	} 
	else shares = n;
	shares_val = pr;
	set_tot();
}

Stock::~Stock()
{
	std::cout << "bye "<< company <<" !\n";
}

void Stock::buy(long num, double price)
{
	if(num < 0) {
		std::cout << "Number of shares purchased cann`t be the negative ;"<< "Transaction is aborted .\n";
	} 
	else {
		shares += num;
		shares_val = price;
		set_tot();
	}	
}

void Stock::sell(long num, double price)
{
	if(num < 0) {
		std::cout << "Number of shares sold cann`t be the negative ;"<< "Transaction is aborted .\n";
	} else if(num > shares) {
		std::cout << "Number of shares sell more than you have ;"<< "Transaction is aborted .\n";
	} else {
		shares -= num;
		shares_val = price;
		set_tot();
	}
}

void Stock::update(double price)
{
	shares_val = price;
	set_tot();
}

void Stock::show() const
{

	using std::ios_base ;
	ios_base::fmtflags orig = 
		std::cout.setf(ios_base::fixed, ios_base::floatfield);
	std::streamsize prec = std::cout.precision(3);
	std::cout << "Company: "<<company << " Shares: "<< shares << "\n"	
		<<" Share price: $ " << shares_val << "\n" ;
	std::cout.precision(2);
	std::cout <<" Total worth: " << total_val << "\n";
	std::cout.setf(orig,ios_base::floatfield);
	std::cout.precision(prec);
}

const Stock & Stock::topval(const Stock & s) const
{
	if(s.total_val > total_val)
		return s;
	else
		return *this;
}