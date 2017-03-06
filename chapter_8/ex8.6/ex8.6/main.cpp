#include <iostream>
#include <cctype>

using namespace std;

template <typename T>
T maxn(T a[], int nums);

template <> char * maxn<char *>(char * a[], int nums);

int main()
{
	int x[6] = {32,1,6,7,8,345};
	double y[4] = {45.2, 3.4, 76.0, 34.9};
	char * a[5] = {"liang", "zlangboy", "lang", "handsome", "boy"};
	cout << "X[6] Maxium : " << maxn(x, 6) << endl;
	cout << "y[4] Maxium : " << maxn(y, 4) << endl;
	cout << "a[5] Maxium Address : " <<  static_cast<const void *>(maxn(a, 5)) << endl;
	system("pause");
	return 0;
}

template <typename T>
T maxn(T a[], int nums)
{
	T tmp;
	tmp = a[0];
	for(int i = 1; i < nums; i ++)
	{
		tmp = a[i-1] > a[i] ? a[i-1] : a[i];
	}
	return tmp;
}

template <>
char * maxn<char *>(char * a[], int nums )
{
	char * temp ;
	int flag = 0;
	//temp = new char[strlen(a[0])+1];
	//strcpy(temp, a[0]);
	temp = a[0];
	for(int i = 1; i < nums; i++)
	{
		if(strlen(temp) < strlen(a[i]))
		{
			temp = a[i];
			flag = 0;
		}	
		else if(strlen(temp) > strlen(a[i]))
		{}
		else
		{
			temp = a[0];
			flag = 1;
		}
	}
	if(flag)
		return a[0];
	else
		return temp;
}