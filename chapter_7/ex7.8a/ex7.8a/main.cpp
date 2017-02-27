#include <iostream>
#include <array>
#include <string>

const int Seasons = 4;
const char * Sname[4] ={"spring","summer","fall","winter"};
void fill(double ar[]);
void show(const double ar[]);

int main()
{
	double expense[Seasons];
	fill(expense);
	show(expense);
	system("pause");
	return 0;
}

void fill(double ar[])
{
	using namespace std;
	for(int i=0;i<Seasons;i++) {
		cout <<" enter "<< Sname[i] << " expense : ";
		cin >> ar[i];
	}
}

void show(const double ar[])
{
	using namespace std;
	double total = 0.0;
	cout << "\n Expense :\n";
	for(int i=0;i<Seasons;i++) {
		cout << Sname[i] << " : $" << ar[i] << endl;
		total = total + ar[i];
	}
	cout << "Total expense : $ "<< total <<endl;
}