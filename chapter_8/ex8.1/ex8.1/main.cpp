#include <iostream>

using namespace std;
int Times;
void show(const char * , int );

int main()
{
	int temp;
	char * ps = "Hello CPP.\n";
	cout << "Please enter your number: ";
	cin >> temp;
	show(ps, temp);
	show(ps, temp);
	system("pause");
	return 0;
}

void show(const char * Str, int temp)
{
	Times++;
	cout << "��" << Times << "�ε���\n" << endl;
	for(int i = 0; i < Times; i++)
		cout << Str << endl;
}