// studenti.h -- defining a Student class using private inheritance
#ifndef STUDENTI_H_
#define STUDENTI_H_

#include <iostream>
#include <valarray>
#include <string>

class Student : private std::string, private std::valarray<double>
{
private:
	typedef std::valarray<double> ArrayDb;
	//private methods for scores output
	std::ostream & arr_out(std::ostream & os) const;

public:
	Student() : std::string("Null Student"),ArrayDb(){};
	explicit Student(const std::string & s) : std::string(s), ArrayDb(){};
	explicit Student(int n): std::string("Nully"), ArrayDb(n){};
	Student(const std::string & s, int n) : std::string(s), ArrayDb(n){};
	Student(const std::string & s, const ArrayDb & a) : std::string(s), ArrayDb(a){};
	Student(const char * Str, const double * pd, int n) : std::string(Str), ArrayDb(pd,n){};

	~Student() {};
	double Average() const;
	double & operator[](int i);
	double operator[](int i) const;  //��������������ʲô���������Ǹ����ص���һ��double���͵�����ʱʲô��
	const std::string & Name() const;

//friends
	//input
	friend std::istream & operator>>(std::istream & is, Student & stu);//1 word
	friend std::istream & getline(std::istream & is, Student & stu);//1 line
	//output
	friend std::ostream & operator<<(std::ostream & os, const Student & stu);
};

#endif