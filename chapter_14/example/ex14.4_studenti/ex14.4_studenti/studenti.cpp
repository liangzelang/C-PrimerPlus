//studenti.cpp -- Student class using private inheritance
#include "studenti.h"
using std::ostream;
using std::endl;
using std::istream;
using std::string;

//public methods

double Student::Average() const
{
	if(ArrayDb::size() > 0)
		return ArrayDb::sum()/ArrayDb::size();
	else
		return 0;
}

double & Student::operator[](int i)
{
	return ArrayDb::operator[](i);   //调用基类方法
}

double Student::operator[](int i) const
{
	return ArrayDb::operator[](i);   //这个是不改变*this这个对象 ，其中*this这个对象是什么呢，
}

const std::string & Student::Name() const
{
	return (const string &)(*this);   //使用作用域解析运算符可以访问基类的方法，但是要访问基类对象，则只能采用强制类型转换，访问string对象成员name
}


//private methods
std::ostream & Student::arr_out(ostream & os) const
{
	int i ;
	int lim = ArrayDb::size();
	if(lim > 0)
	{
		for(i = 0; i < lim; i ++)
		{
			os << ArrayDb::operator[](i) << " ";
			if(i % 5 == 4)
				os << endl;
		}
		if(i % 5 !=0)
			os << endl;
	}
	else
		os << " empty array ";
	return os;
}

//friends 
//using String version of operator>>()
std::istream & operator>>(std::istream & is, Student & stu)//1 word
{
	is >> (string&)stu;  //要访问基类对象只有强制类型转换
	return is;
}

std::istream & getline(std::istream & is, Student & stu)//1 line
{
	getline(is, (string &)stu);
	return is;
}

std::ostream & operator<<(std::ostream & os, const Student & stu)
{
	os << "Scores for " << (const string &)stu << ":\n";
	stu.arr_out(os);   //use private method for scores
	return os;
}