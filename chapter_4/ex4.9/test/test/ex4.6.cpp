#include <iostream>
#include <string>
struct CandyBar{
	std::string brand;   
	//char brand[20];
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
	
	CandyBar *temp = new CandyBar [3];
	/*CandyBar temp[3] = {
		{"xiaobaitu", 2.2, 300},     //会出现从double到float截取，这是因为2.2在vs中默认的数据类型是double,把double（8字节）类型数据赋值给float（4字节），就需要截取一部分，需要warning一下
		{"dabaitu", 1.4, 100},
		{"aerbeisi",1.2, 200}
	};*/
	//需要符单值
	for(int i=0;i<3;i++) {
		cout << "this is "<< i<< " brand \n";
		display(temp[i]);		
	}

	//cout << "double 的字节长度为： "<< sizeof(double) << "\n";
	//cout << "float 的字节长度为： "<< sizeof(float);

	system("pause");
	delete [] temp;
	return 0;
}
