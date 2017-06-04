//useless.cpp -- an otherwise useless class with move semantics
#include <iostream>

using namespace std;

//interface
class Useless{
private:
	 int n;
	 char * pc;
	 static int ct;
	 void ShowObject() const;
public:
	Useless();
	explicit Useless(int k);
	Useless(int k, char ch);
	Useless(const Useless & f);
	Useless(Useless && f);   //move constructor
	~Useless();
	Useless operator+(const Useless & f) const;
	void ShowData() const;
};

// implementation
int Useless::ct = 0;

Useless::Useless()
{
	++ct;
	n = 0;
	pc = nullptr;
	cout << "default constructor called, number of objects: " << ct << endl;
	ShowObject();
}

Useless::Useless(int k) : n(k)
{
	++ct;
	cout << "int constructor called, number of objects: " << ct << endl;
	pc = new char[n];
	ShowObject();
}

Useless::Useless(int k, char ch) : n(k)
{
	++ct;
	cout << "int, char constructor called, number of object: " << ct << endl;
	pc = new char[n];
	for(int i = 0; i < n; i++)
		pc[i] = ch;
	ShowObject();
}

Useless::Useless(const Useless & f) : n(f.n)
{
	++ct;
	cout << "copy const called; number of object: " << ct << endl;
	pc = new char[n];
	for(int i = 0; i < n; i++)
		pc[i] = f.pc[i];
	ShowObject();
}

Useless::Useless(Useless && f) : n(f.n)
{
	++ct;
	cout << "move constructor called, number of object: " << ct << endl;
	pc = f.pc;
	f.pc = nullptr;
	f.n = 0;
	ShowObject();
}

Useless::~Useless()
{
	cout << "destuctror called; objects left: " << --ct << endl;
	cout << "deleted object : \n";
	ShowObject();
	delete [] pc;
}

Useless Useless::operator+(const Useless & f) const
{
	cout << "Entering operator+()\n";
	Useless temp = Useless(n+f.n);
	for(int i = 0; i < n; i++)
		temp.pc[i] = pc[i];
	for(int i = 0; i < temp.n; i++)
		temp.pc[i] = f.pc[i-n];
	cout << "temp object:\n";
	cout << "Leaving operator+()\n";
	return temp;
}

void Useless::ShowObject() const
{
	cout << "Number of element : "<< n;
	cout << "Data address : " << (void *) pc << endl;
}

void Useless::ShowData() const
{
	if(n == 0)
		cout << "object empty";
	else
		for(int i = 0; i < n; i++)
			cout << pc[i];
	cout << endl;
}

// application
int main()
{
	{
		Useless one(10, 'X');
		Useless two = one;  //���ƹ��캯��
		Useless three(10, 'o');
		Useless four(one + three); //move constructor + operator+
		cout << "object one: ";
		one.ShowData();
		cout << "object two: ";
		two.ShowData();
		cout << "object three: ";
		three.ShowData(); 
		cout << "object four: ";
		four.ShowData();
	}
	system("pause");
	return 0;
}