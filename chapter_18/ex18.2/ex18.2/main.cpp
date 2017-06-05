// using move constructor and move assignment
#include <iostream>
#include <string>

using namespace std;

class Cpmv{
public:
	struct Info{
		string qcode;
		string zcode;
	};
private:
	Info * pi;
public:
	Cpmv();
	Cpmv(string q, string z);
	Cpmv(const Cpmv & cp);
	Cpmv(Cpmv && mv);
	~Cpmv();
	Cpmv & operator=(const Cpmv & cp);
	Cpmv & operator=(Cpmv && mv);
	Cpmv operator+(const Cpmv & obj) const;
	void display() const;
};

Cpmv::Cpmv()
{
	pi = new Info;
	pi->qcode = "None";
	pi->zcode = "None";
	cout << "Default constructor\n";
	display();
}

Cpmv::Cpmv(string q, string z)
{
	pi = new Info;
	pi->qcode = q;
	pi->zcode = z;
	cout << "String constructor\n";
	display();
}

Cpmv::Cpmv(const Cpmv & cp)
{
	pi = new Info;
	cout << "copy constructor.\n";
	pi->qcode = cp.pi->qcode;
	pi->zcode = cp.pi->zcode;
	display();
}

Cpmv::Cpmv(Cpmv && mv)
{
	pi = new Info;
	cout << "Move constructor.\n";
	pi->qcode = mv.pi->qcode;
	pi->zcode = mv.pi->zcode;
	mv.pi->qcode = "None";
	mv.pi->zcode = "None";
	display();
}

Cpmv::~Cpmv()
{
	cout << "Destructor.\n";
	delete pi;
}

Cpmv & Cpmv::operator=(const Cpmv & cp)
{
	if(this == &cp)
		return * this;
	pi->qcode = cp.pi->qcode;
	pi->zcode = cp.pi->zcode;
	display();
	return * this;
}

Cpmv & Cpmv::operator=(Cpmv && mv)
{
	if(this == &mv)
		return *this;
	pi->qcode = mv.pi->qcode;
	pi->zcode = mv.pi->zcode;
	mv.pi->qcode = "None";
	mv.pi->zcode = "None";
	display();
	return *this;
}

Cpmv Cpmv::operator+(const Cpmv & obj) const
{
	Cpmv temp;
	temp.pi->qcode = pi->qcode + obj.pi->qcode;
	temp.pi->zcode = pi->zcode + obj.pi->zcode;
	return temp;
}

void Cpmv::display() const
{
	cout << pi->qcode << ", " << pi->zcode << endl;
}


int main()
{
	{
		Cpmv zero, one("one", "one");
		cout << "Zero: " ;
		zero.display();

		cout << "One: ";
		one.display();

		Cpmv two = one + zero;  // move cons  , 
		cout << "Two: ";
		two.display();

		Cpmv three, four;
		cout << "Three: ";
		three = one;   //cony cons
		three.display();
		cout << "One: ";
		one.display();

		four = one + two;  //move cons
		cout << "Four: ";
		four.display();

		cout << "Four = move(one)";
		four = move(one);
		cout << "Four: ";
		four.display();
		cout << "One: ";
		one.display();
		system("pause");
		return 0;
	}
}