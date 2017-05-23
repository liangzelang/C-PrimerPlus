//using  const_cast<>
#include <iostream>

using namespace std;

void change(const int * pt, int n);

int main()
{
	int pop1 = 300;
	const int pop2 = 400;

	cout << "src : " << pop1 << pop2 << endl;
	change(&pop1, 10);
	change(&pop2, 10);
	cout << "dst : " << pop1 << pop2 << endl;
	system("pause");
	return 0;
}

void change(const int * pt, int n)
{
	int * pc;
	pc = const_cast<int *>(pt);
	*pc += n;
}