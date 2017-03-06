#include <iostream>

using namespace std;

template <typename T>
T max5(T temp[]);

int main()
{
	int a[5] = {4,7,2,456,456};
	double b[5] = {324.3, 324.8, 0.0, 342.3, 435.9 };
	cout << "a[5] Maxium : " << max5<int>(a) << endl;
	cout << "b[5] Maxium : " << max5<double>(b) << endl;
	system("pause");
	return 0;
}

template <typename T>
T max5(T temp[])
{
	T tmp = temp[0];
	for(int i = 1; i < 5; i++)
	{
		tmp = (temp[i-1] > temp[i])?temp[i-1]:temp[i];
	}
	return tmp;
}