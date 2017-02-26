#include<iostream>
#include"brass.h"

int main()
{
	using namespace std;
	Brass Piggy("liangzelang",160459,13000.00);
	BrassPlus Hoggy("liuming",160461,10000.00);
	cout << sizeof(long) << ": long \n";
	cout << sizeof(int) << " : int \n";
	Piggy.ViewAcct();
	cout<<endl;
	Hoggy.ViewAcct();
	cout << endl;
	cout << " Deposit 1000 into liangelang account : \n";
	Piggy.Deposit(1000);
	cout << " liangzelang balance : $ " << Piggy.Balance() << endl;

	cout << "Withdrawing $4200 from the Hoggy \n";
	Hoggy.Withdraw(4200);
	Hoggy.ViewAcct();system("pause");
	return 0;
}