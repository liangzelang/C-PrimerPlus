#include <iostream>


using namespace std;

int Fill_array(double ar[], int length)
{
	int i;
	double temp;
	for(i=0;i<length;i++)
	{
		cout << "Enter the " << i << " number : ";
		if(cin >> temp)
		{
			ar[i] = temp;
		}
		else
			break;
	}
	return i;
}

void Show_array(double ar[], int length)
{
	for(int i = 0 ; i < length ; i++ )
	{
		cout << "#" << i << ": " << ar[i] << "\n";
	}
}

void Reverse_array(double ar[] , int length )
{
	double temp;
	for(int i=0;i<(length / 2);i++)
	{
		temp = ar[i];
		ar[i] = ar[length-i-1];
		ar[length-i-1] = temp;
	}
}

int main()
{
	double temp[20]={0};
	int a = Fill_array(temp,20);
	cout << "the array is : \n";
	Show_array(temp,a);
	Reverse_array(temp,a);
	cout << "the reverse array is : \n";
	Show_array(temp,a);
	Reverse_array(temp+1,a-2);
	cout << "the second reverse array is : \n";
	Show_array(temp,a);
	system("pause");
	return 0;
}