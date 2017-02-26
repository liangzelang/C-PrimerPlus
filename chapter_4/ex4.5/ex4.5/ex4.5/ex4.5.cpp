#include <iostream>
//#include <string>
struct CandyBar{
	//std::string brand;   //这里为什么使用string类错了，好像是没有添加头文件.记得添加头文件
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
	//CandyBar snack { "Mocha Munch", 2.3, 350 } ;  //此处为什么一定要加等号，不加会报错  C++ primer plus p91
	CandyBar snack={ "Mocha Munch", 2.3, 350 } ;    //以上情况列表初始化是C++11的特性，但是vs2010对C++11特性不是全部支持
	display(snack);
	system("pause");
	return 0;
}
