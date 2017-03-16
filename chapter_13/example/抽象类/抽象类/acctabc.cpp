#include "acctabc.h"

using namespace std;

// ABC methods
AcctABC::AcctABC(const string & s, long an, double bal)
{
	fullname = s;
	acctNum = an;
	balance = bal;
}

void AcctABC::Deposit(double amt)
{
	if(amt < 0)
		cout << "Negative Deposit is not allowed. deposit is cancelled.\n";
	else
		balance += amt;
}

void AcctABC::Withdraw(double amt)
{
	balance -= amt;
}

AcctABC::Formatting AcctABC::SetFormat() const
{
	//set up ###.## format
	Formatting f;
	f.flag = cout.setf(ios_base::fixed, ios_base::floatfield);
	f.pr = cout.precision(2);
	return f;
}

void AcctABC::Restore(AcctABC::Formatting & f) const
{
	cout.setf(f.flag, ios_base::floatfield);
	cout.precision(f.pr);
}
	
//Brass class methods
void Brass::Withdraw(double amt)
{
	if(amt < 0)
		cout << "Withdraw can not be negative, withdraw is cancelled. \n";
	else if(amt <= Balance())
		AcctABC::Withdraw(amt);
	else
		cout << "your Withdraw exceeds your balance, withdraw is cancelled.\n";
}

void Brass::ViewAcct() const
{
	Formatting f = SetFormat();
	cout << "Brass Client : " << FullName() << endl;
	cout << "Account Number : " << AcctNum() << endl;
	cout << "Balance : &" << Balance() << endl;
	Restore(f);  //这个其实没有太懂，SetFormat是设置，restore是存储，没搞懂
}


// BrassPlus methods
BrassPlus::BrassPlus(const string & s, long an, double bal, double ml, double r):AcctABC(s, an, bal)
{
	maxLoan = ml;
	rate = r;
	owesBank = 0.0;
}

BrassPlus::BrassPlus(const Brass & ba, double ml, double r) : AcctABC(ba)
{
	maxLoan = ml;
	rate = r;
	owesBank = 0.0;
}

void BrassPlus::Withdraw(double amt)
{
	Formatting f = SetFormat();
	double bal = Balance();
	if(amt <= bal)
		AcctABC::Withdraw(amt);
	else if( amt <= bal + maxLoan - owesBank)
	{
		double advance = amt - bal;
		owesBank += advance*(1.0 + rate);
		cout << "Bank advance : $" << advance << endl;
		cout << "Finnance charge: $" << advance * rate << endl;
		Deposit(advance);     //这个过程相当于先贷款，把贷款存上，在取钱，取得干干净净的。
		AcctABC::Withdraw(amt);
	}
	else
		cout << "Credit Limit exceeded, Transaction cancelled.\n";
	Restore(f);
}

void BrassPlus::ViewAcct() const
{
	Formatting f = SetFormat();
	cout << "BrassPlus Client: " << FullName() << endl;
	cout << "Account Number: " << AcctNum() << endl;
	cout << "Balance: $" << Balance() << endl;
	cout << "Maxium loan: " << maxLoan << endl;
	cout << "Owed to Bank: $" << owesBank << endl;
	cout.precision(3);
	cout << "Loan Rate: " << 100*rate << "%\n";
	Restore(f);
}
