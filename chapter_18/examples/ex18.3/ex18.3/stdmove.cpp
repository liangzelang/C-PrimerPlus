//stdmove.cpp -- using std::move()
#include <iostream>
#include <utility>

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
	Useless & operator=(const Useless & f);
	Useless & operator=(Useless && f);
	void ShowData() const;
};

// implementation
int Useless::ct = 0;

Useless::Useless()
{
	++ct;
	n = 0;
	pc = nullptr;
}

Useless::Useless(int k) : n(k)
{
	++ct;
	pc = new char[n];
}

Useless::Useless(int k, char ch) : n(k)
{
	++ct;
	pc = new char[n];
	for(int i = 0; i < n; i++)
		pc[i] = ch;
}

Useless::Useless(const Useless & f) : n(f.n)
{
	++ct;
	pc = new char[n];
	for(int i = 0; i < n; i++)
		pc[i] = f.pc[i];
}

Useless::Useless(Useless && f) : n(f.n)
{
	++ct;
	pc = f.pc;
	f.pc = nullptr;
	f.n = 0;
}

Useless::~Useless()
{
	delete [] pc;
}

Useless Useless::operator+(const Useless & f) const
{
	Useless temp = Useless(n+f.n);
	for(int i = 0; i < n; i++)
		temp.pc[i] = pc[i];
	for(int i = n; i < temp.n; i++)
		temp.pc[i] = f.pc[i-n];
	return temp;
}

void Useless::ShowObject() const
{
	cout << "Number of element : "<< n;
	cout << "Data address : " << (void *) pc << endl;
}

Useless & Useless::operator=(const Useless & f)
{
	cout << "Copy Assignment operator called;\n";
	if(this == &f)
		return *this;
	delete [] pc;
	n = f.n;
	pc = new char[n];
	for(int i = 0; i < n ; i++)
		pc[i] = f.pc[i];
	return * this;
}


Useless & Useless::operator=(Useless && f)
{
	cout << "move assignment operator called: \n";
	if(this == &f)
		return * this;
	delete [] pc;
	n = f.n;
	pc = f.pc;
	f.n = 0;
	f.pc = nullptr;
	return * this;
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
		Useless one(10, '0');
		Useless two = one +one;  //���ƹ��캯��
		cout << "object one: ";
		one.ShowData();
		cout << "object two: ";
		two.ShowData();

		Useless three, four;
		three = one;
		cout << "three = one\n";
		three.ShowData();
		
		four = one + two;
		cout << "now object four =";
		four.ShowData();

		cout << "four = move(one)\n";
		four = move(one);
		four.ShowData();

		cout << "object one =";
		one.ShowData();

	}
	system("pause");
	return 0;
}