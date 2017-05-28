#include <iostream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

template<class T> int reduce(T ar[], int n);

int main()
{
	string str[10] = {"str", "ni", "liang", "ze", "lean", "Mike", "lsj", "sldjf", "erggr", "sal"};
	long val[10] = {1,2,2,64,24,6,324,6,5,2};

	cout << "Example: double \n" << endl;
	int valnums = reduce(val, 10);
	for(int i = 0; i < valnums; i++)
		cout << val[i]<< ' ';
	cout << endl;

	cout << "Example: string \n" << endl;
	int strnums = reduce(str, 10);
	for(int i = 0; i < strnums; i++)
		cout << str[i]<< ' ';
	cout << endl;
	system("pause");
	return 0;
}

template<class T> 
int reduce(T ar[], int n)
{
	set<T> a(ar, ar+n);
	//for_each(a.begin(), a.end(),display);
	set<T>::iterator di;
	int i = 0;
	for(di = a.begin(); di != a.end(); di++ )
	{
		ar[i] = *di;
		i++;
	}
	return i;	
}