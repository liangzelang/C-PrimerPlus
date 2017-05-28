#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int reduce(long ar[], int n);
void display(const double dd);

int main()
{
	long val[10] = {1,2,2,64,24,6,324,6,5,2};
	int nums = reduce(val, 10);
	for(int i = 0; i < nums; i++)
		cout << val[i]<< ' ';
	cout << endl;
	system("pause");
	return 0;
}

int reduce(long ar[], int n)
{
	set<double> a(ar, ar+n);
	//for_each(a.begin(), a.end(),display);
	set<double>::iterator di;
	int i = 0;
	for(di = a.begin(); di != a.end(); di++ )
	{
		ar[i] = *di;
		i++;
	}
	return i;

}

void display(const double dd)
{
	cout << dd << ' ';
}