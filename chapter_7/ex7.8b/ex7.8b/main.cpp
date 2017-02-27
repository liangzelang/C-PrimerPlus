#include <iostream>

const int Seasons = 4;
const char * Sname[4] = {"Spring", "Summer", "Fall", "Winter"};
void fill(double *);
void show(const double *);
struct Expense
{
	double ar[Seasons];
};
int main()
{
	using namespace std;
	Expense  expense;
	fill(expense.ar);
	show(expense.ar);
	system("pause");
	return 0;
}

void fill(double * ar)
{
	using namespace std;
	for(int i = 0; i <Seasons; i++)
	{
		cout << Sname[i] << " expense : " << endl;
		cin >> ar[i];
		if(!cin)
		{
			cin.clear();
			cout << "Please input right number" << endl;
			break;
		}
	}
}

void show(const double * ar)
{
	using namespace std;
	for(int i = 0; i< Seasons; i++)
	{
		cout << Sname[i] << " expense : " << ar[i] << ". \n";
	}
}