#include <iostream>

using namespace std;

long long calcu_Num(int a)
{
	int temp;
	long long sum = a;
	temp = a-1;
	if(temp != 0)
	{
		sum = a * calcu_Num(temp);
	}
	//return temp*calcu_Num(temp-1);  //好像数据结构书中说这样不好
	return sum ;
}

int main()
{
	int temp;
	cout << "Please enter one integer number :  ";
	while( cin >> temp )
	{
		cout << "the jie cheng is : " << calcu_Num(temp) << " \n";
		cout << " Please enter one integer number(q to quit) : ";
	}
	cin.clear();
	system("pause");
	return 0;

}