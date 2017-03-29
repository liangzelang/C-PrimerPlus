#ifndef STUDENTC_H_
#define STUDENTC_H_
#include <iostream>
#include <string>
#include <valarray>

class Student
{
private:
	typedef std::valarray<double> ArrayDb;
	ArrayDb scores;
	std::string name;
	//private method for scores outpot
	std::ostream & arr_out(std::ostream &os) const;
public:
	Student() : name("Null Student"), scores(){}  //如果不出意外，这里可能会出现错误，因为需要和参数列表顺序相同
	explicit Student(const std::string & s) : name(s), scores(){}
	explicit Student(int n) : name("Null Student"), scores(n){}  //这里没有太懂
	Student(const std::string & s, int n) : name(s), scores(n){}
	Student(const std::string & s, const ArrayDb & a) : name(s), scores(a){}
	Student(const char * str, const double * pd, int n) : name(str), scores(pd, n){}
	~Student() {}
	double Average() const;
	const std::string & Name() const;
	double & operator[](int i);
	double operator[](int i) const;
	//friend
	friend std::istream & operator>>(std::istream & is, Student & std);
	friend std::istream & getline(std::istream & is, Student & stu);
	friend std::ostream & operator<<(std::ostream & os, const Student & stu);
};


#endif