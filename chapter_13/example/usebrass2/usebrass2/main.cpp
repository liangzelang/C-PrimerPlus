#include<iostream>
#include<string>
#include"brass.h"
const int CLIENTS = 2;
int main()
{
	using namespace std;

	Brass * p_clients[CLIENTS];   //创建了一个基类的指针数组
	string temp;
	long tempnum;
	double tempbal;
	char kind;

	for(int i = 0; i < CLIENTS; i++)
	{
		cout << "Enter client's name: ";
		cin >> temp;
		cin.get();
		cout << "Enter client's accout number: ";
		cin >> tempnum;
		cin.get();
		cout << "Enter opening balance: $";
		cin >> tempbal;
		cin.get();
		cout << "Enter 1 for Brass Accout or 2 for BrassPlus Accout: ";
		while( cin >> kind && (kind != '1' && kind != '2'))
			cout << "Enter either 1 or 2 : ";
		if(kind == '1')
			p_clients[i] = new Brass(temp, tempnum, tempbal);
		else
		{
			double tmax, trate;
			cout << "Enter the overdraft limit: $";
			cin >> tmax;
			cin.get();
			cout << "Enter the interest rate as a decimal fraction: ";
			cin >> trate;
			cin.get();
			p_clients[i] = new BrassPlus(temp, tempnum, tempbal, tmax, trate);
		}
		while(cin.get() != '\n')
			continue;
	}
	cout << endl;
	for(int i = 0; i < CLIENTS; i++)
	{
		p_clients[i]->ViewAcct();
		cout << endl;
	}
	for(int i = 0; i < CLIENTS; i++)
	{
		delete p_clients[i];
	}
	system("pause");
	return 0;
}