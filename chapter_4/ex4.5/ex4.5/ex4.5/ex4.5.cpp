#include <iostream>
//#include <string>
struct CandyBar{
	//std::string brand;   //����Ϊʲôʹ��string����ˣ�������û�����ͷ�ļ�.�ǵ����ͷ�ļ�
	char brand[20];
	float weight;
	int calory;
};

void display(const CandyBar &a)
{
	std::cout << "Brand : " << a.brand << " \n";
	std::cout << "Weight: " << a.weight<< " \n";
	std::cout << "Calory: " << a.calory<< " \n";
}

int main()
{
	using namespace std;
	//CandyBar snack { "Mocha Munch", 2.3, 350 } ;  //�˴�Ϊʲôһ��Ҫ�ӵȺţ����ӻᱨ��  C++ primer plus p91
	CandyBar snack={ "Mocha Munch", 2.3, 350 } ;    //��������б��ʼ����C++11�����ԣ�����vs2010��C++11���Բ���ȫ��֧��
	display(snack);
	system("pause");
	return 0;
}
