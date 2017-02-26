#include <iostream>
	using namespace std;

int input_Result(double * temp_Result, int limit);
void aver_Result(const double * temp_Result, const int limit);
void show_Result(const double * temp_Result, const int limit);

int main()
{

	double golf_Result[10] = {0};
	input_Result(golf_Result,10);
	show_Result(golf_Result,10);
	aver_Result(golf_Result,10);
	system("pause");
	return 0;
}

int input_Result(double * temp_Result, int limit)
{
	int i;
	double temp;
	cout << "Begin to enter golf Result.\n";
	for(i = 0;i < limit;i++)
	{
		cout << "please enter the " << (i+1) << " golf reuslt : ";
		cin >> temp;  //如果输入类型是double型，cin就不会阻塞
		if(!cin) //输入阻塞
		{
			cin.clear();
			while(cin.get() != '\n')   //如果不是换行符
				continue;
			cout << "bad input, enter a number;\n ";
			break;    //
		}
		if(temp < 0)
			break;   //输入为负，则退出
		temp_Result[i] = temp;
	}
	return  i;   //返回输入个数
}

void show_Result(const double * temp_Result, const int limit)
{
	for(int i = 0; i < limit ; i++)
	{
		cout << " Score #" << (i+1) << " : " << temp_Result[i] << "\n";
	}
}

void aver_Result(const double * temp_Result, const int limit)
{
	double sum =0;
	double temp_Aver;
	for(int i = 0;i < limit; i ++)
	{
		sum += temp_Result[i];
	}
	temp_Aver = sum / limit ;
	cout << "the average score is : " << temp_Aver;
}