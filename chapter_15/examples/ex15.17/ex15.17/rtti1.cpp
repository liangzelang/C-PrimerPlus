/*
// rtti1.cpp -- using the rtti dynamic_cast operator
// dynamic_case<> Ҳ�����������ã�������ָ���÷����в�ͬ��û�����ָ����ڵ�����ֵ���޷�ʹ�����������ֵָʾʧ�ܣ����dynamic_case������bad_cast���쳣 P646
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Grand{
private:
	int hold;
public:
	Grand(int h = 0) : hold(h) {}
	virtual void Speak() const { cout << "I am a grand class!\n";}
	virtual int Value() const { return hold;}
};

class Superb : public Grand
{
public:
	Superb(int h = 0) : Grand(h) {}
	void Speak() const {cout << "I am a Superb class!!\n";}
	virtual void Say() const { cout << "I holde the superb value of " << Value() << "!!\n";}
};

class Magnificent : public Superb
{
private:
	char ch;
public:
	Magnificent(int h = 0, char c = 'A') : Superb(h), ch(c) {}
	void Speak() const { cout << "I am a magnificent class \n";}
	void Say() const { cout << "I hold the character " << ch << "and the integer " << Value() << "\n";}
};

Grand * GetOne();

int main()
{
	srand(time(0));   //srand() cstdlib  time(0) ctime
	Grand * pg;
	Superb * ps;
	for(int i = 0; i < 5; i++)
	{
		pg = GetOne();
		pg->Speak();
		if(ps = dynamic_cast<Superb * >(pg))
			ps->Say();
	}
	system("pause");
	return 0;
}

Grand * GetOne()
{
	Grand * p;
	switch(rand() % 3)
	{
	case 0:
		p = new Grand(rand() % 100);
		break;
	case 1:
		p = new Superb(rand() % 100);
		break;
	case 2:
		p = new Magnificent(rand() % 100, 'A' + rand() % 26);
		break;
	} 
	return p;
}
*/


//rtti2.cpp -- using dynamic_cast , typeid and type_info
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Grand{
private:
	int hold;
public:
	Grand(int h = 0) : hold(h) {}
	virtual void Speak() const { cout << "I am a grand class!\n";}
	virtual int Value() const { return hold;}
};

class Superb : public Grand
{
public:
	Superb(int h = 0) : Grand(h) {}
	void Speak() const {cout << "I am a Superb class!!\n";}
	virtual void Say() const { cout << "I holde the superb value of " << Value() << "!!\n";}
};

class Magnificent : public Superb
{
private:
	char ch;
public:
	Magnificent(int h = 0, char c = 'A') : Superb(h), ch(c) {}
	void Speak() const { cout << "I am a magnificent class \n";}
	void Say() const { cout << "I hold the character " << ch << "and the integer " << Value() << "\n";}
};

Grand * GetOne();

int main()
{
	srand(time(0));   //srand() cstdlib  time(0) ctime
	Grand * pg;
	Superb * ps;
	for(int i = 0; i < 5; i++)
	{
		pg = GetOne();
		cout << "Now processing type " << typeid(*pg).name() << endl;
		pg->Speak();
		if(ps = dynamic_cast<Superb *>(pg))
			ps->Say();
		if(typeid(Magnificent) ==typeid(*pg))
			cout << "Yes, you're really magnificent.\n";
	}
	system("pause");
	return 0;
}

Grand * GetOne()
{
	Grand * p;
	switch(rand() % 3)
	{
	case 0:
		p = new Grand(rand() % 100);
		break;
	case 1:
		p = new Superb(rand() % 100);
		break;
	case 2:
		p = new Magnificent(rand() % 100, 'A' + rand() % 26);
		break;
	} 
	return p;
}