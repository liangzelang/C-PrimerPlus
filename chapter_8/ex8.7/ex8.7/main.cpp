//tempover.cpp -- template overloading
#include <iostream>

template <typename T>
void ShowArray(T arr[], int n);

template <typename T>
void ShowArray(T * arr[], int n);

template <typename T>
T SumArray(T * arr[], int n);

template <typename T>
T SumArray(T arr[], int n);

struct debts
{
	char name[50];
	double amount;
};

int main()
{
	using namespace std;
	int things[6] = {13, 31, 103, 301, 310, 130};
	struct debts mr_E[3] = 
	{
		{"Ima Wolfe", 2400.0},
		{"Ura Foxe", 1300.0},
		{"Iby Stout", 1800.0}
	};
	double * pd[3];

	//set pointer to the amount members of the structures in mr_E
	for(int i = 0; i < 3; i++)
	{
		pd[i] = &mr_E[i].amount;
	}
	cout << "Listing Mr. E's counts of things: \n" ;
	//thing is an array of int
	ShowArray(things, 6);    //uses template A
	cout << endl;
	cout << "things SUM : " << SumArray(things, 6) << endl;
	cout << "Listing Mr.E's debrs:\n";
	//pd is an array of pointers to double
	ShowArray(pd, 3);
	cout << endl;
	cout << "pd SUM : " << SumArray(pd, 3) << endl;
	system("pause");
	return 0;
}

template <typename T>
void ShowArray(T arr[], int n)
{
	using namespace std;
	cout << "Template A \n";
	for( int i = 0; i < n; i ++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
}

template <typename T>
void ShowArray(T * arr[], int n)
{
	using namespace std;
	cout << "Template B \n";
	for(int i = 0; i < n ; i++)
	{
		cout << *arr[i] << ' ';
	}
	cout << endl;
}

template <typename T>
T SumArray(T * arr[], int n)
{
	T Sum = 0;
	for(int i = 0; i < n; i++)
	{
		Sum += *arr[i];
	}
	return Sum;
}

template <typename T>
T SumArray(T arr[], int n)
{
	T Sum = 0;
	for(int i = 0; i < n; i++)
	{
		Sum += arr[i];
	}
	return Sum;
}