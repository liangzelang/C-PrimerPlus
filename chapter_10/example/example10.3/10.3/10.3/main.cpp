#include <iostream>
#include "stock.h"

int main()
{
	{
		Stock temp1 = Stock("Alibaba",100,79.992);
		temp1.show();

		Stock temp("Baidu",1000,98.99);
		temp.show();

		temp.buy(100000,40.001);
		temp.show();
		
		Stock top = temp.topval(temp1);
		top.show();

		temp.sell(15000,58.992);
		temp.show();

		
	}	                           //�������Զ��ж�����������ε�����������
	system("pause");
	return 0;
}